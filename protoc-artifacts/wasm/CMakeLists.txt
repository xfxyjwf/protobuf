cmake_minimum_required(VERSION 3.1.3)

project(protoc-wasm C CXX)

add_subdirectory(../../cmake protobuf)

set(CMAKE_CXX_STANDARD 11)
# In case we are building static libraries, link also the runtime library statically
# so that MSVCR*.DLL is not required at runtime.
# https://msdn.microsoft.com/en-us/library/2kzt1wy3.aspx
# This is achieved by replacing msvc option /MD with /MT and /MDd with /MTd
# http://www.cmake.org/Wiki/CMake_FAQ#How_can_I_build_my_MSVC_application_with_a_static_runtime.3F
if (MSVC)
  foreach(flag_var
      CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
      CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
    if(${flag_var} MATCHES "/MD")
      string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
    endif(${flag_var} MATCHES "/MD")
  endforeach(flag_var)
endif (MSVC)

add_library(protoc-wasm-lib src/wasm.cc)
target_link_libraries(protoc-wasm-lib libprotoc libprotobuf)

add_executable(protoc-wasm src/wasm.cc)
target_link_libraries(protoc-wasm libprotoc libprotobuf)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/src/util.pb.cc
         ${CMAKE_CURRENT_BINARY_DIR}/src/util.pb.h
  DEPENDS protoc src/util.proto
  COMMAND protoc -I ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/src/util.proto --cpp_out=${CMAKE_CURRENT_BINARY_DIR}/src)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/src)
add_executable(util-wasm src/util.cc ${CMAKE_CURRENT_BINARY_DIR}/src/util.pb.cc)
target_link_libraries(util-wasm libprotoc libprotobuf)
