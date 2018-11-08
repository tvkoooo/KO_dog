local math = require('math')
local pairs = pairs
local print = print
local tostring = tostring
local string = string
----------------------------------------
local modname="byte"
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
--all is int32
--true in use false not use
function get_in_use(in_use,car_num)
	local p1 = 2^car_num
	local a1 = math.floor(in_use/p1)
	return math.floor(a1%2)==1
end
function set_in_use(in_use,car_num)
	local p1 = 2^car_num
	local a1 = math.floor(in_use/p1)
	if math.floor(a1%2)==1 then
		return in_use
	else
		return in_use + p1
	end
end
function set_unused(in_use,car_num)
	local p1 = 2^car_num
	local a1 = math.floor(in_use/p1)
	if math.floor(a1%2)==1 then
		return in_use - p1
	else
		return in_use
	end
end
function flip_use_state(in_use,car_num)
	local p1 = 2^car_num
	local a1 = math.floor(in_use/p1)
	if math.floor(a1%2)==1 then
		return in_use - p1
	else
		return in_use + p1
	end
end
function get_high_half(_id)
	return math.floor(_id/65536)
end
function get_low_half(_id)
	return _id%65536
end
function gen_id(_high,_low)
	return _high*65536+_low
end
----------------------------------------------
--test
--local in_use = 0
--print(get_in_use(in_use,0))
--print(get_in_use(in_use,1))
--print(set_in_use(in_use,0))
--print(set_in_use(in_use,1))
--print(set_unused(in_use,0))
--print(set_unused(in_use,1))
--print(flip_use_state(in_use,0))
--print(flip_use_state(in_use,1))
--local _id = gen_id(1,65530)
--print(_id)
--print(get_high_half(_id))
--print(get_low_half(_id))
----------------------------------------------
return m
