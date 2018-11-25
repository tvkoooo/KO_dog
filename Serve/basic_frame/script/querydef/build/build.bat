@echo off

set script_common_root=../..

lua do_archive.lua %script_common_root% m_cobweb_common
lua do_archive.lua %script_common_root% m_cobweb_amqp
lua do_archive.lua %script_common_root% m_cobweb_common_mq_amqp
lua do_archive.lua %script_common_root% m_cobweb_common_mq_redis

lua do_query.lua %script_common_root% q_cobweb_common_address
lua do_query.lua %script_common_root% q_cobweb_amqp
lua do_query.lua %script_common_root% q_cobweb_common_mq_amqp
lua do_query.lua %script_common_root% q_cobweb_common_mq_redis
lua do_query.lua %script_common_root% q_cobweb_common_module
lua do_query.lua %script_common_root% q_cobweb_common_runtime
lua do_query.lua %script_common_root% q_cobweb_common_zookeeper
lua do_query.lua %script_common_root% q_cobweb_common_entry
lua do_query.lua %script_common_root% q_cobweb_common_lobby
lua do_query.lua %script_common_root% q_cobweb_common_proxy
lua do_query.lua %script_common_root% q_cobweb_common_cback

xcopy ..\data\cpp\*.*   ..\\..\\..\\src\\querydef\ /s /h /d /y

pause