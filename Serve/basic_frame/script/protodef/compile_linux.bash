#!/bin/sh

platform=linux

protoc_p=../../tools/protoc-$platform
protoc_n_exe=../../tools/protoc-$platform/protoc
protoc_c_exe=../../tools/protoc-$platform/protoc-c
proto_path=../../proto
src_proto_path=../../src/protodef
src_c_p=$src_proto_path/c
src_c_f=$src_proto_path/c/protodef
src_cxx_p=$src_proto_path/cxx
src_cxx_f=$src_proto_path/cxx/protodef
src_java_p=$src_proto_path/java
src_java_f=$src_proto_path/java
src_javanano_p=$src_proto_path/javanano
src_javanano_f=$src_proto_path/javanano
src_objc_p=$src_proto_path/objc
src_objc_f=$src_proto_path/objc/protodef
src_python_p=$src_proto_path/python
src_python_f=$src_proto_path/python/protodef

# mkdir function.
build_mkdir(){
	if [ ! -d "$1" ]; then 
	mkdir "$1" 
	fi
}

# build proto function.
build_proto(){
	"$protoc_n_exe" --proto_path="$proto_path" --python_out="$src_python_f" "$proto_path/$1.proto"
	"$protoc_n_exe" --proto_path="$proto_path" --cpp_out="$src_cxx_f" "$proto_path/$1.proto"
	"$protoc_n_exe" --proto_path="$proto_path" --objc_out="$src_objc_f" "$proto_path/$1.proto"
	"$protoc_n_exe" --proto_path="$proto_path" --java_out="$src_java_f" "$proto_path/$1.proto"
	"$protoc_n_exe" --proto_path="$proto_path" --javanano_out="$src_javanano_f" "$proto_path/$1.proto"
	"$protoc_c_exe" --proto_path="$proto_path" --c_out="$src_c_f" "$proto_path/$1.proto"
}
# build all mkdir function.
build_mkdir_all(){
	build_mkdir $protoc_p
	build_mkdir $src_c_p
	build_mkdir $src_c_f
	build_mkdir $src_cxx_p
	build_mkdir $src_cxx_f
	build_mkdir $src_java_p
	build_mkdir $src_java_f
	build_mkdir $src_javanano_p
	build_mkdir $src_javanano_f
	build_mkdir $src_objc_p
	build_mkdir $src_objc_f
	build_mkdir $src_python_p
	build_mkdir $src_python_f
}

# build all proto function.
build_proto_all(){
	build_proto b_enum
	build_proto b_error
	build_proto b_math
	build_proto b_network

	build_proto s_control
	build_proto s_basis

	build_proto c_entry
}

build_mkdir_all

build_proto_all



