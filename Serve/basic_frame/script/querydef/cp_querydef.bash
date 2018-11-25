#!/bin/sh

cd build
lua do_archive_account.lua MAccount
lua do_query_account.lua QAccount

lua do_archive_account.lua MRelation
lua do_query_account.lua QRelation
cd ..

source_dir=data/cpp
protodef_path=../../src/querydef

if [ ! -d "$protodef_path" ]; then 
mkdir "$protodef_path" 
fi

cp_file(){
	cp -rf $source_dir/$1.h   $protodef_path
	cp -rf $source_dir/$1.cpp $protodef_path
}
cp_file DishMAccount
cp_file DishQAccount

cp_file DishMRelation
cp_file DishQRelation