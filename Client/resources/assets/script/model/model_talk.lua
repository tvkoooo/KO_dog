local logger = require('logger')
local math = require('math')
local pairs = pairs
local print = print
local tostring = tostring
local string = string
----------------------------------------
local modname="model_talk"
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
mem_msg_colour =
{
	[0] = {r=1.0,g=0.8,b=0.0,a=1.0,},
	[1] = {r=1.0,g=1.0,b=1.0,a=1.0,},
}
----------------------------------------------
--function
function l_talk_msg_colour(flag)
	local u = mem_msg_colour[flag]
	if u then
		return u.r,u.g,u.b,u.a
	else
		logger.logW(modname..".l_talk_msg_colour flag:"..flag.." is invalid.")
	end
	return 1,1,1,1
end
----------------------------------------------
--test
----------------------------------------------
return M
