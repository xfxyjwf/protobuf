#!/bin/bash

mkdir -p build
cd build
../cmake.sh -DCMAKE_BUILD_TYPE=RELEASE
emmake make -j8 protoc-wasm
