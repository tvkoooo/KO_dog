set script_common_root=../../../../script

lua do_archive.lua %script_common_root% m_account

lua do_query.lua %script_common_root% q_account

pause