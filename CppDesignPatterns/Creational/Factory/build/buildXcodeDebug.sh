#!/bin/sh
rm -rf Debug
mkdir Debug
cd Debug

cmake -DPlatform=64 -DCMAKE_BUILD_TYPE=Debug .. -DCMAKE_CXX_FLAGS_DEBUG="-g -O0" -G Xcode
cmake --build . --config Debug
