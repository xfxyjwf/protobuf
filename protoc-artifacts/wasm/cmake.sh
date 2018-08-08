#!/bin/bash

DIR=$(realpath $(dirname $0))
POSTJS="${DIR}/src/post.js"
emconfigure cmake \
  -Dprotobuf_BUILD_TESTS=OFF \
  -DCMAKE_CXX_LINK_FLAGS="-s RESERVED_FUNCTION_POINTERS=1 --post-js '${POSTJS}' -s ALLOW_MEMORY_GROWTH=1" \
  $@ "${DIR}"
