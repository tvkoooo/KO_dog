@echo off

set script_common_root=../..

lua do_archive.lua %script_common_root% m_db_ko_dog_t_user_basic

lua do_query.lua %script_common_root% q_db_ko_dog_t_user_basic

lua do_archive.lua %script_common_root% m_db_ko_dog_t_nt_message

lua do_query.lua %script_common_root% q_db_ko_dog_t_nt_message

lua do_archive.lua %script_common_root% m_db_ko_dog_t_user_relation

lua do_query.lua %script_common_root% q_db_ko_dog_t_user_relation





xcopy ..\data\cpp\*.*   ..\\..\\..\\src\\querydef\ /s /h /d /y

pause