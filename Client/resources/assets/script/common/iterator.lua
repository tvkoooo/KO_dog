local math = require('math')
local table = table
local pairs = pairs
local sort = sort
local print = print
local tostring = tostring
local string = string
----------------------------------------
local modname="iterator"
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
function pairs_by_keys(t)
    local a = {}
    for _k,_v in pairs(t) do
        a[#a+1] = _k
    end
    table.sort(a)
    local i = 0
    return function()
        i = i + 1
        return a[i], t[a[i]]
    end
end
----------------------------------------------
--test
----------------------------------------------
return m
