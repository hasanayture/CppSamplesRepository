#!/bin/sh
rm -rf Debug
mkdir Debug
cd Debug
cmake -DPlatform=64 -DCMAKE_BUILD_TYPE=Debug ..
make -j8
