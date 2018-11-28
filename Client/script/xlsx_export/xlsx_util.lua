require "io"
local assert=assert
local table=table
local string=string
local loadfile=loadfile
local print=print
local io=io
local os=os
local type=type
local pairs=pairs
local require=require
local ipairs=ipairs
local tonumber=tonumber
---------------------------------------------
local modname="xlsx_util"
local M={}
_G[modname]=M
package.loaded[modname]=M
if setfenv then
	setfenv(1, M) -- for 5.1
else
	_ENV = M -- for 5.2
end
----------------------------------------------------------------------------------
--member variable
----------------------------------------------------------------------------------
--function
function parse_int_group(_value)
	local group={}

	if type(_value)=="string" then
		_value = _value..","
		for w in string.gmatch(_value,"%d*") do
			if w:len()~=0 then
				--print(w)
				group[#group+1] = tonumber(w)
			end
		end
	end

	return group
end
function parse_string_group(_value)
	local group={}

	if type(_value)=="string" then
		_value = _value..","
		for w in string.gmatch(_value,"(.-),") do
			if w:len()~=0 then
				--print(w)
				group[#group+1] = w
			end
		end
	end

	return group
end
function parse_number(_value)
	local n=tonumber(_value)
	if nil==n then
		return 0
	end
	return n
end
function copy_file(source,destination)
	-- print("source     :"..source)
	-- print("destination:"..destination)
	sourcefile = io.open(source,"rb")
	if sourcefile == nil then
		print("the source file:"..source.." is a invalid.")
		return
	end
	destinationfile = io.open(destination,"wb")
	if destinationfile == nil then
		print("the destinationfile file:"..destination.." is a invalid.")
		return
	end
	local code = sourcefile:read("*all")
	destinationfile:write(code)
	sourcefile:close()
	destinationfile:close()
end
----------------------------------------------------------------------------------
--test
--parse_int_group("1001,1002,1003,1005,")
--parse_int_group("1001,1002,1003,1005")
--print(parse_number(nil))
----------------------------------------------------------------------------------
return M
