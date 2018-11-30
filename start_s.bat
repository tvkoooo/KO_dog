@echo off 

cd ./Serve/basic_frame/proj/windows/bin/Release

set log_dir=../../../../../../log

start /b basic_frame_lobby.exe %log_dir% 7 1 ::1-10000[2] ::1-20000[2] 127.0.0.1:10300, 127.0.0.1:10300, 101.200.169.28-10200 101.200.169.28-10200 > nul 2>&1 &
start /b basic_frame_entry.exe %log_dir% 7 1 ::1-10001[2] ::1-20001[2] 127.0.0.1:10300, 127.0.0.1:10300, > nul 2>&1 &
start /b basic_frame_proxy.exe %log_dir% 7 1 ::1-10002[2] ::1:10300, 127.0.0.1:10300, 100 0x02002000 0x020020FF 0 > nul 2>&1 &

cd ../../../../../..

cd ./Serve/business/proj/windows/bin/Release
start /b business_account.exe %log_dir% 7 1 ::1-10010[2] ::1-20010[2] 127.0.0.1:10300, > nul 2>&1 &

cd ../../../../../..

pause
