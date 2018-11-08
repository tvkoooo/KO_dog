local p = {}
----------------------------------------------
function logger_print( message ) print(message) end
----------------------------------------------
function p.log_U( message ) logger_print( message ) end
function p.log_F( message ) logger_print( message ) end
function p.log_C( message ) logger_print( message ) end
function p.log_E( message ) logger_print( message ) end
function p.log_A( message ) logger_print( message ) end
function p.log_W( message ) logger_print( message ) end
function p.log_N( message ) logger_print( message ) end
function p.log_I( message ) logger_print( message ) end
function p.log_T( message ) logger_print( message ) end
function p.log_D( message ) logger_print( message ) end
function p.log_V( message ) logger_print( message ) end
----------------------------------------------
return p
