#!/bin/env bash

pushd /usr/lib/emsdk
source emsdk_env.sh
popd
#source /usr/lib/emsdk/emsdk_env.sh


mkdir build-em &>/dev/null
cd build-em

       	#-DCMAKE_INSTALL_PREFIX=/usr/lib/emscripten/system 
cmake .. -G Ninja \
       	-DCMAKE_INSTALL_PREFIX=dist \
       	-DCMAKE_BUILD_TYPE=Debug \
	-DCMAKE_TOOLCHAIN_FILE="third_party/repos/toolchains/generic/Emscripten-wasm.cmake" \
       	-DEMSCRIPTEN_PREFIX="/usr/lib/emscripten"

cmake --build .  --target install #cmake --target install .
