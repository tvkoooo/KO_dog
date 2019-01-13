@echo off

set platform=windows

set protoc_p=../../tools/protoc-%platform%
set protoc_n_exe=../../tools/protoc-%platform%/protoc
set protoc_c_exe=../../tools/protoc-%platform%/protoc-c
set proto_path=../../proto
set src_proto_path=../../src/protodef
set src_c_p=%src_proto_path%/c
set src_c_f=%src_proto_path%/c/protodef
set src_cxx_p=%src_proto_path%/cxx
set src_cxx_f=%src_proto_path%/cxx/protodef
set src_java_p=%src_proto_path%/java
set src_java_f=%src_proto_path%/java
set src_javanano_p=%src_proto_path%/javanano
set src_javanano_f=%src_proto_path%/javanano
set src_objc_p=%src_proto_path%/objc
set src_objc_f=%src_proto_path%/objc/protodef
set src_python_p=%src_proto_path%/python
set src_python_f=%src_proto_path%/python/protodef

call :build_mkdir_all

call :build_proto_all

GOTO :EOF

:: build all mkdir function.
:build_mkdir_all
SETLOCAL
REM.
call :build_mkdir "%src_proto_path%"
call :build_mkdir "%src_c_p%"
call :build_mkdir "%src_c_f%"
call :build_mkdir "%src_cxx_p%"
call :build_mkdir "%src_cxx_f%"
call :build_mkdir "%src_java_p%"
call :build_mkdir "%src_java_f%"
call :build_mkdir "%src_javanano_p%"
call :build_mkdir "%src_javanano_f%"
call :build_mkdir "%src_objc_p%"
call :build_mkdir "%src_objc_f%"
call :build_mkdir "%src_python_p%"
call :build_mkdir "%src_python_f%"
GOTO :EOF

:: build all proto function.
:build_proto_all
SETLOCAL
REM.
call :build_proto b_enum
call :build_proto b_error
call :build_proto b_math
call :build_proto b_network
call :build_proto b_business_account
call :build_proto b_business_relation
call :build_proto c_shuttle_entry
call :build_proto c_shuttle_lobby
call :build_proto c_business_account
call :build_proto c_business_relation
call :build_proto c_business_nt_message
GOTO :EOF

:: build proto function.
:build_proto
SETLOCAL
REM.
"%protoc_n_exe%" --proto_path="%proto_path%" --python_out="%src_python_f%" "%proto_path%/%~1.proto"
"%protoc_n_exe%" --proto_path="%proto_path%" --cpp_out="%src_cxx_f%" "%proto_path%/%~1.proto"
"%protoc_n_exe%" --proto_path="%proto_path%" --objc_out="%src_objc_f%" "%proto_path%/%~1.proto"
"%protoc_n_exe%" --proto_path="%proto_path%" --java_out="%src_java_f%" "%proto_path%/%~1.proto"
"%protoc_n_exe%" --proto_path="%proto_path%" --javanano_out="%src_javanano_f%" "%proto_path%/%~1.proto"
"%protoc_c_exe%" --proto_path="%proto_path%" --c_out="%src_c_f%" "%proto_path%/%~1.proto"
GOTO :EOF

:: mkdir function.
:build_mkdir
SETLOCAL
REM.
if not exist "%~1" (
	md "%~1"
)
GOTO :EOF

pause