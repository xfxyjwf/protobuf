#!/bin/bash

set -ex

cp build/protoc-wasm.js build/protoc-wasm.bc
em++  build/protoc-wasm.bc -o build/protoc.js --post-js src/post.js -s RESERVED_FUNCTION_POINTERS=1 -s ALLOW_MEMORY_GROWTH=1
