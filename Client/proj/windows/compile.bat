@echo off 

set VSVARS="%VS141COMNTOOLS%vcvars64.bat"
set VC_VER=141

call %VSVARS%

devenv %~dp0/KO_dog.sln /build debug
devenv %~dp0/KO_dog.sln /build release
pause