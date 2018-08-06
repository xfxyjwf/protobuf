cmake_minimum_required(VERSION 3.1.3)

project(protoc-wasm C CXX)

add_subdirectory(../../cmake protobuf)

set(CMAKE_CXX_STANDARD 11)

add_executable(protoc-wasm src/wasm.cc)
target_link_libraries(protoc-wasm libprotoc libprotobuf)
