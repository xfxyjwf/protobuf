#!/bin/bash

pushd $(dirname $0)
DIR=`pwd`
popd
POSTJS="${DIR}/src/post.js"
emconfigure cmake \
  -Dprotobuf_BUILD_TESTS=OFF \
  -DCMAKE_CXX_LINK_FLAGS="-s EXTRA_EXPORTED_RUNTIME_METHODS='[\"cwrap\",\"UTF8ToString\"]' -s RESERVED_FUNCTION_POINTERS=1 --post-js '${POSTJS}' -s ALLOW_MEMORY_GROWTH=1" \
  $@ "${DIR}"
