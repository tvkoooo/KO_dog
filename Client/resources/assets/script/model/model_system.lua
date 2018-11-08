local logger = require('mm/logger')
local math = require('math')
local pairs = pairs
local print = print
local tostring = tostring
local string = string
local debug = debug
----------------------------------------
local modname="model_system"
local M={}
_G[modname]=M
package.loaded[modname]=M
if setfenv then
	setfenv(1, M) -- for 5.1
else
	_ENV = M -- for 5.2
end
----------------------------------------------
--member
----------------------------------------------
--function
function l_user_info_exit_ensure_title()
	return "确定退出?"
end
----------------------------------------------
--test
logger.log_I("222222222222")
----------------------------------------------
return M
