@echo off

set platform=windows

set protoc_p=../../tools/protoc-%platform%
set protoc_n_exe=../../tools/protoc-%platform%/protoc
set protoc_c_exe=../../tools/protoc-%platform%/protoc-c

xcopy "%MM_LIB%\\build\\protobuf\\proj_%platform%\\bin\\Release\protoc.exe" "..\\..\\tools\\protoc-%platform%\*" /s /e /h /d /y 
xcopy "%MM_LIB%\\build\\protobuf-c\\proj_%platform%\\bin\\Release\protoc-c.exe" "..\\..\\tools\\protoc-%platform%\*" /s /e /h /d /y 

pause