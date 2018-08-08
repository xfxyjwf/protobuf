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

#include <google/protobuf/stubs/wasm.h>

#ifdef __EMSCRIPTEN__
typedef int (*SystemHelperType)(int, int, int);
static constexpr int kCommandFileExists = 1;
static constexpr int kCommandReadFile = 2;
static constexpr int kCommandCreateDirectory = 3;
static constexpr int kCommandWriteFile = 4;

static SystemHelperType system_helper;
int SetSystemHelper(int helper) {
  int old = reinterpret_cast<int>(system_helper);
  system_helper = reinterpret_cast<SystemHelperType>(helper);
  return old;
}

namespace google {
namespace protobuf {
namespace wasm {
bool FileExists(const std::string& name) {
  if (system_helper == nullptr) {
    return false;
  }
  int p1 = kCommandFileExists;
  int p2 = reinterpret_cast<int>(name.c_str());
  int p3 = 0;
  int ret = system_helper(p1, p2, p3);
  return ret != 0;
}
bool ReadFile(const std::string& name, std::string* content) {
  if (system_helper == nullptr) {
    return false;
  }
  int p1 = kCommandReadFile;
  int p2 = reinterpret_cast<int>(name.c_str());
  int p3 = 0;
  auto ret = reinterpret_cast<char*>(system_helper(p1, p2, p3));
  if (ret == nullptr) {
    return false;
  }
  content->assign(ret);
  free(ret);
  return true;
}
bool CreateDirectory(const std::string& name) {
  if (system_helper == nullptr) {
    return false;
  }
  int p1 = kCommandCreateDirectory;
  int p2 = reinterpret_cast<int>(name.c_str());
  int p3 = 0;
  int ret = system_helper(p1, p2, p3);
  return ret != 0;
}
bool WriteFile(const std::string& name, const std::string& content) {
  if (system_helper == nullptr) {
    return false;
  }
  int p1 = kCommandWriteFile;
  int p2 = reinterpret_cast<int>(name.c_str());
  int p3 = reinterpret_cast<int>(content.c_str());
  int ret = system_helper(p1, p2, p3);
  return ret != 0;
}
}  // namespace wasm
}  // namespace protobuf
}  // namespace google


#endif  // __EMSCRIPTEN__
