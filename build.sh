#!/bin/env bash
mkdir build &>/dev/null
set -e
cd build

cmake .. -G Ninja \
       	-DCMAKE_BUILD_TYPE=Debug

cmake --build .
#tests/test_runner
apps/My_Application_main
