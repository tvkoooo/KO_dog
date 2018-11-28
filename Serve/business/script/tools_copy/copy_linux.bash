#!/bin/sh

platform=linux

protoc_p=../../tools/protoc-$platform
protoc_n_exe=../../tools/protoc-$platform/protoc
protoc_c_exe=../../tools/protoc-$platform/protoc-c

cp -u ../../../../mm_lib/build/protobuf/proj_$platform/bin/protoc $protoc_p/protoc
cp -u ../../../../mm_lib/build/protobuf-c/proj_$platform/bin/protoc-c $protoc_p/protoc-c

chmod 777 $protoc_n_exe
chmod 777 $protoc_c_exe



