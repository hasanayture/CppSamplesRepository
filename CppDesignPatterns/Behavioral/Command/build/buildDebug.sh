#!/bin/sh
rm -rf Debug
mkdir Debug
cd Debug
#cmake -DPlatform=64 -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" ..
#cmake -DPlatform=64 -DCMAKE_BUILD_TYPE=Debug -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_ECLIPSE_VERSION=4.15.0 ..

#cmake -DPlatform=64 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_ECLIPSE_VERSION=4.15.0 ..
#cmake -DPlatform=64 -DCMAKE_BUILD_TYPE=Debug -G "Xcode" ..
#xcodebuild -project ./cppProjectTemplete.xcodeproj/
#open -a Xcode ./cppProjectTemplete.xcodeproj/

cmake -DPlatform=64 -DCMAKE_BUILD_TYPE=Debug ..
make -j8
