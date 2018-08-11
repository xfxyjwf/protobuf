// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#include <algorithm>
#include <fstream>
#include <map>
#include <string>

#include <google/protobuf/compiler/command_line_interface.h>
#include <google/protobuf/compiler/cpp/cpp_generator.h>
#include <google/protobuf/compiler/csharp/csharp_generator.h>
#include <google/protobuf/compiler/java/java_generator.h>
#include <google/protobuf/compiler/js/js_generator.h>
#include <google/protobuf/compiler/objectivec/objectivec_generator.h>
#include <google/protobuf/compiler/parser.h>
#include <google/protobuf/compiler/php/php_generator.h>
#include <google/protobuf/compiler/python/python_generator.h>
#include <google/protobuf/compiler/ruby/ruby_generator.h>
#include <google/protobuf/io/tokenizer.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/stubs/stringprintf.h>
#include <google/protobuf/util/json_util.h>

#include "util.pb.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif  // __EMSCRIPTEN__

using namespace std;

namespace google {
namespace protobuf {
namespace compiler {
map<string, std::unique_ptr<CodeGenerator>> CreateCodeGenerators() {
  map<string, std::unique_ptr<CodeGenerator>> generators;
  generators["C++"].reset(new cpp::CppGenerator());
  generators["Java"].reset(new java::JavaGenerator());
  generators["Python"].reset(new python::Generator());
  generators["PHP"].reset(new php::Generator());
  generators["Ruby"].reset(new ruby::Generator());
  generators["C#"].reset(new csharp::Generator());
  generators["Objective C"].reset(new objectivec::ObjectiveCGenerator());
  generators["Javascript"].reset(new js::Generator());
  return std::move(generators);
}

map<string, std::unique_ptr<CodeGenerator>> code_generators =
    CreateCodeGenerators();

bool Parse(const string &name, const string &content,
           io::ErrorCollector *error_collector, FileDescriptorProto *proto) {
  io::ArrayInputStream stream(content.data(), content.size());
  io::Tokenizer tokenizer(&stream, error_collector);
  Parser parser;
  parser.RecordErrorsTo(error_collector);
  proto->set_name(name);
  return parser.Parse(&tokenizer, proto);
}

class MemoryErrorCollector : public io::ErrorCollector,
                             public DescriptorPool::ErrorCollector {
 public:
  MemoryErrorCollector(const string &filename) : filename_(filename) {}
  // Inherited via ErrorCollector
  void AddError(int line, int column, const string &message) override {
    error_count_++;
    error_ += StringPrintf("%s:%d:%d: %s\n", filename_.c_str(), line, column,
                           message.c_str());
  }

  // Inherited via ErrorCollector
  void AddError(const string &filename, const string &element_name,
                const Message *descriptor, ErrorLocation location,
                const string &message) override {
    error_count_++;
    error_ += StringPrintf("%s:%s: %s\n", filename_.c_str(),
                           element_name.c_str(), message.c_str());
  }

  int error_count() const { return error_count_; }

  string GetErrorString() { return error_; }

 private:
  const string filename_;
  int error_count_ = 0;
  string error_;
};

class ResultContext : public GeneratorContext {
 public:
  // Inherited via GeneratorContext
  io::ZeroCopyOutputStream *Open(const string &filename) override {
    return new io::StringOutputStream(&files_[filename]);
  }

  map<string, string> GetFiles() const { return files_; }

 private:
  map<string, string> files_;
};

wasm::util::GeneratorOutput Generate(const string &name, const string &content,
                                     const string &language,
                                     const string &parameters) {
  wasm::util::GeneratorOutput result;
  if (name.empty()) {
    result.set_error("Invalid file name: " + name);
    return result;
  }

  CodeGenerator *generator = code_generators[language].get();
  if (generator == nullptr) {
    result.set_error("Language not supported: " + language);
    return result;
  }

  MemoryErrorCollector error_collector(name);
  FileDescriptorProto proto;
  if (!Parse(name, content, &error_collector, &proto) ||
      error_collector.error_count() > 0) {
    result.set_error(error_collector.GetErrorString());
    return result;
  }
  DescriptorPool pool;
  const FileDescriptor *file =
      pool.BuildFileCollectingErrors(proto, &error_collector);
  if (file == nullptr) {
    result.set_error(error_collector.GetErrorString());
    return result;
  }
  string error;
  ResultContext context;
  if (!generator->GenerateAll({file}, parameters, &context, &error)) {
    result.set_error(error);
    return result;
  }
  map<string, string> files = context.GetFiles();
  result.mutable_files()->insert(files.begin(), files.end());
  return result;
}

wasm::util::GeneratorOutput GenerateUsingJsonInput(const string &json) {
  wasm::util::GeneratorInput input;
  wasm::util::GeneratorOutput output;
  auto status = util::JsonStringToMessage(json, &input);
  if (!status.ok()) {
    output.set_error(string(status.error_message()) + "\nInput type is:\n" +
                     wasm::util::GeneratorInput::descriptor()->DebugString());
    return output;
  }
  return Generate(input.name(), input.content(), input.language(),
                  input.parameters());
}

string GenerateUsingJson(const string &input) {
  wasm::util::GeneratorOutput output = GenerateUsingJsonInput(input);
  string result;
  auto status = util::MessageToJsonString(output, &result);
  if (!status.ok()) {
    cerr << "Failed to convert result message to json: " << status << endl;
  }
  return result;
}

string ReadFile(const string &name) {
  string result;
  string line;
  ifstream fin(name.c_str());
  while (getline(fin, line)) {
    result += line + "\n";
  }
  return result;
}
}  // namespace compiler
}  // namespace protobuf
}  // namespace google

extern "C" {
#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif  // __EMSCRIPTEN__
char *Generate(const char *input);

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif  // __EMSCRIPTEN__
char *ListLanguages();
}

static char *ToJavascriptString(const string &value) {
  char *buffer = static_cast<char *>(malloc(value.size() + 1));
  memcpy(buffer, value.data(), value.size() + 1);
  return buffer;
}

char *Generate(const char *input) {
  string result = google::protobuf::compiler::GenerateUsingJson(input);
  return ToJavascriptString(result);
}

char *ListLanguages() {
  google::protobuf::compiler::wasm::util::LanguageList list;
  for (const auto &p : google::protobuf::compiler::code_generators) {
    list.add_languages(p.first);
  }
  string result;
  auto status = google::protobuf::util::MessageToJsonString(list, &result);
  if (!status.ok()) {
    cerr << "Failed to convert result message to json: " << status << endl;
  }
  return ToJavascriptString(result);
}

int main(int argc, char *argv[]) {
#ifndef __EMSCRIPTEN__
  for (int i = 1; i < argc; i++) {
    string name = argv[i];
    auto result = google::protobuf::compiler::Generate(
        name, google::protobuf::compiler::ReadFile(name), "Javascript", "");
    if (result.error().empty()) {
      for (auto p : result.files()) {
        cout << "// " << p.first << endl;
        cout << p.second << endl;
      }
    } else {
      cout << "Error: " << result.error() << endl;
    }
  }
#endif  // __EMSCRIPTEN__
}
