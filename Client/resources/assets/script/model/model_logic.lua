local logger = require('logger')
local math = require('math')
local pairs = pairs
local print = print
local tostring = tostring
local string = string
require("../logic.script_unit_manager")
----------------------------------------
local modname="model_logic"
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
script_unit_managers = {}
----------------------------------------------
--function
function add_script_unit_manager(name)
	local m = _G.script_unit_manager()
	m.name = name
	script_unit_managers[name] = m
	return m
end
function get_script_unit_manager(name)
	local m = script_unit_managers[name]
	if m == nil then
		logger.logW(modname..".get_script_unit_manager name:"..name.." is invalid.")
	end
	return m
end
function rmv_script_unit_manager(name)
	script_unit_managers[name] = nil
end
function clear_script_unit_manager()
	script_unit_managers = {}
end
----------------------------------------------
--test
----------------------------------------------
return M
