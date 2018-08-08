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
#ifndef GOOGLE_PROTOBUF_STUBS_WASM_H_
#define GOOGLE_PROTOBUF_STUBS_WASM_H_

// Helper functions for running as a web assembly binary. When running
// as a web assembly binary, regular C/C++ APIs will be accessing a
// virtual environment (e.g., a virtual file system). In order to access
// physical file system, a JS bridge is needed to translate file access
// to access actually physical files. Helper functions in this header
// is used for this purpose. To make it work, provide an implementation
// of SystemHelper in JS and hook it up using SetSystemHelper. Then use
// helper functions in this header instead of regular C/C++ APIs for
// file access.

#ifdef __EMSCRIPTEN__

#include <string>
#include <emscripten/emscripten.h>

extern "C" {
// Called in JS to set the SystemHelper.
EMSCRIPTEN_KEEPALIVE int SetSystemHelper(int helper);
}

namespace google {
namespace protobuf {
namespace wasm {
bool FileExists(const std::string& name);
bool ReadFile(const std::string& name, std::string* content);
bool CreateDirectory(const std::string& name);
bool WriteFile(const std::string& name, const std::string& content);
}  // namespace wasm
}  // namespace protobuf
}  // namespace google

#endif  // __EMSCRIPTEN__

#endif  // GOOGLE_PROTOBUF_STUBS_WASM_H_
