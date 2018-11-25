---copyright longer 2016---------------------------------
require "io"
local assert=assert
local table=table
local string=string
local loadfile=loadfile
local print=print
local io=io
local type=type
local pairs=pairs
local load= loadstring and loadstring or load
local loadfile=loadfile
local dofile=dofile

local _G=_G
---------------------------------------------
local modname="generator"
local M={}
_G[modname]=M
package.loaded[modname]=M
if setfenv then
	setfenv(1, M) -- for 5.1
else
	_ENV = M -- for 5.2
end
----------------------------------------------------------------------------------
function intepret_template(code)
	if (code) then
		--code = code:gsub("(%s+)(<#[^=]-#>)", function (a, b) if b:sub(-1)=="=" then return a..b else return b end end )
		--code = code:gsub("([ %t]+<#=?)", function (a) if a:sub(-1)=="=" then return a else return "<#" end end )
		--code = code:gsub("(#>%s+\n)", function (a) if a:sub(-1)=="\n" then return "#>" else return a end end )
		--code = code:gsub("(#>[\t ]*\n)", function (a) return "#>"end )
		code = code:gsub("(\n[\t ]+<#)(=?)",
		function (a, b)
			if b=="=" then
				return a..b
			else
				return "\n<#"
			end
		end )

		local lastpos=1
		local pos=0
		local spos

		local dstcode =
		"require \"io\"\n"..
		"function g_write_file(f,ctx)\n"

		while true do
			lastpos=pos+1
			spos,pos,eqs,cd = code:find("<#(=?)(.-)#>",pos)
			-- if nil ~= code and nil ~= spos then
			-- 	print("------spos,pos-------")
			-- 	print(spos,pos)
			-- 	print(code:sub(spos,pos))
			-- 	print("------eqs,cd-------")
			-- 	print(eqs,cd)
			-- end

			if not spos then
				dstcode=dstcode.."f:write([["..code:sub(lastpos).."]])\n"
				break
			elseif( lastpos<spos) then
				dstcode=dstcode.."f:write([["..code:sub(lastpos,spos-1).."]])\n"
			end

			if eqs=="=" then
				dstcode=dstcode.."f:write("..cd..")\n"
			else
				dstcode=dstcode..cd.."\n"
			end
		end
		dstcode =dstcode..
		"\n"..
		"	return f\n"..
		"end"
		return dstcode
	end
end
function load_template(filename)
	local tf = assert(io.open(filename,"rb"))
	local code = tf:read("*all")
	tf:close()
	code = intepret_template(code)
	return load(code)
end

function debug_template(filename)
	local tf = assert(io.open(filename,"rb"))
	local code = tf:read("*all")
	tf:close()
	code = intepret_template(code)
	local tpl = load(code)
	if tpl then tpl() end
	print("------------------------------------------")
	tf= assert(io.open("error.lua", "wb"))
	tf:write(code)
	tf:close()
	dofile("error.lua")
	print("------------------------------------------")
end

function show_template(filename)
	local tf = assert(io.open(filename,"rb"))
	local code = tf:read("*all")
	tf:close()
	code = intepret_template(code)
	print("______________________________________________________")
	print(code)
	print("======================================================")
end

function dump_template(filename, outputfile)
	local tf = assert(io.open(filename,"rb"))
	local code = tf:read("*all")
	tf:close()
	code = intepret_template(code)
	print("------------------------------------------")
	print("template [" .. filename .."] already been dumped into [" ..outputfile .."]")
	tf= io.open(outputfile, "w");
	tf:write(code)
	tf:close()
end
function bind_template(ctx,template_file, data_file, output_file )
	-- print("bind_template "..output_file.." begin.")
	if template_file and output_file then
		local tpl = load_template(template_file)
		if tpl then
			local data_ctx = nil
			if data_file and data_file~="" then
				local data_f = loadfile(data_file)
				if data_f then
					data_ctx = data_f()
					ctx["data"] = data_ctx
				else
					print("bind_template failed, invalid data file : " , data_file)
				end
			else
				print("bind_template data_file is a null.is common _template file.")
			end
			local theFile_w = assert(io.open("temp.bind", "wb"))
			--local theFile = assert(io.open(output_file, "wb"))
			print("bind_template ["..data_file.."] + ["..template_file.."] = ["..output_file.."]")
			tpl()
			theFile_w=_G.g_write_file(theFile_w,ctx)
			theFile_w:close()

			local theFile_r = assert(io.open("temp.bind", "rb"))
			local theFile_r_code = theFile_r:read("*all")
			local _tf_r = io.open(output_file,"rb")
			if nil == _tf_r then
				_tf_r = io.open(output_file,"wb")
				_tf_r:close()
				_tf_r = assert(io.open(output_file,"rb"))
			end
			if _tf_r then
				local _tf_r_code = _tf_r:read("*all")
				if _tf_r_code ~= theFile_r_code then
					local _tf_w = assert(io.open(output_file,"wb"))
					_tf_w:write(theFile_r_code)
					_tf_w:close()
					print("file change :["..output_file.."].")
				end
				_tf_r:close()
			else
				print("bind_template failed, invlaid output file : ", output_file)
				debug_template(template_file)
			end

			theFile_r:close()
		else
			print("bind_template failed, invalid _template :  ", template_file)
			debug_template(template_file)
		end
	else
		print("bind_template failed, missing parameter!!!")
	end
	-- print("bind_template "..output_file.." end.")
end
----------------------------------------------------------------------------------
return M
