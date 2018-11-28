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
---------------------------------------------
local modname="xlsx_export"
local M={}
_G[modname]=M
package.loaded[modname]=M
if setfenv then
	setfenv(1, M) -- for 5.1
else
	_ENV = M -- for 5.2
end
--linux windows
--platform = "linux"
platform = "windows"
----------------------------------------------------------------------------------
cscript_path_windows = ".\\"
function export_csv_windows(file_path, sheet_cnt)
	local cwd = ""

	os.execute("mkdir tmp")
	os.execute("cd > tmp\\_cwd.txt")
	local fcwd = io.open("tmp\\_cwd.txt")
	if fcwd then
		cwd = fcwd:read("*l")
		fcwd:close()
	end
	file_path = cwd .. "\\" .. file_path .. " "
	cwd = cwd .. "\\tmp\\ "
	os.execute("cscript "..cscript_path.."export.vbs " .. file_path .. cwd ..  sheet_cnt)
end

function clear_csv_windows()
	os.execute("rmdir /S /Q tmp")
end
----------------------------------------------------------------------------------
cscript_path_linux = "./"
function export_csv_linux(file_path, sheet_cnt)
	local cwd = ""

	-- if [ ! -d "tmp" ]; then mkdir "tmp" fi
	os.execute("if [ ! -d \"tmp\" ]; \nthen mkdir \"tmp\" \nfi")
	-- os.execute("mkdir tmp")
	os.execute("pwd > tmp/_cwd.txt")
	local fcwd = io.open("tmp/_cwd.txt")
	if fcwd then
		cwd = fcwd:read("*l")
		fcwd:close()
	end
	file_path = cwd .. "/" .. file_path .. " "
	cwd = cwd .. "/tmp/ "
	-- python xlsx2csv.py -a file_path cwd
	-- print("python xlsx2csv.py -a "..file_path.." "..cwd)
	os.execute("python "..cscript_path.."xlsx2csv.py -a "..file_path.." "..cwd)
end

function clear_csv_linux()
	os.execute("rm -rf tmp")
end

export_csv_fun = 
{
	["windows"] = export_csv_windows,
	["linux"] = export_csv_linux,
}
export_csv = export_csv_fun[platform]

clear_csv_fun = 
{
	["windows"] = clear_csv_windows,
	["linux"] = clear_csv_linux,
}
clear_csv = clear_csv_fun[platform]
----------------------------------------------------------------------------------
--
-- a customized compare function for sorting table that to be ouputed
--
function compare_func(a, b, w_tbl)
	w_tbl = w_tbl or {}
	w_tbl.id = w_tbl.id or -999
	w_tbl.name = w_tbl.name or -998

	local va = a
	local vb = b
	if type(a) ~= "number" then
		va = w_tbl[a] or 0
	end
	if type(b) ~= "number" then
		vb = w_tbl[b] or 0
	end

	if va == vb then
		return a<b
	else
		return va<vb
	end
end

--
--	output a table to file in a cutomized format
--	talbe:t
--	file:f
--
function output_table(t, f, tabs, comma, w_tbl)
	if not (type(t)=="table") then
		print("Invalid table to output!")
		return
	end

	tabs = tabs or ""
	local connector = ""
	local k_tbl = {}
	local has_tbl = false
	for k, v in pairs(t) do
		table.insert(k_tbl, k)
		if type(v)=="table" then
			has_tbl = true
		end
	end

	table.sort(k_tbl, function (a,b) return compare_func(a, b, w_tbl) end )

	--
	--	Note that:	getn is only for table with numberic index
	--			not available for table with string index
	--	so we use getn(k_tbl) instead of getn(t), as we know that
	--	k_tbl and t has the same number of k-v pairs
	-- lua 5.0 above has not table.getn
	-- if table.getn(k_tbl)<12 and not has_tbl then
	if #k_tbl<12 and not has_tbl then
		connector = ""
		tabs = ""
		f:write("{")
	else
		connector = "\n"
		f:write("\n"..tabs.."{")
		tabs = tabs .. "	"
		f:write("\n")
	end
	-- f:write("{" .. connector)
	for _, k in ipairs(k_tbl) do
		local v = t[k]

		if type(k)=="number" then
			k = "[" .. k .. "]"
		end
		local tv = type(v)
		if tv=="table" then
			f:write(tabs, k, "= ")
			output_table(v, f, tabs .. "", true)
		elseif tv=="string" then
			if v:sub(1,1)=="\"" and v:sub(-1)=="" then
				f:write(tabs, k, "=", v, ","..connector)
			elseif v:sub(-1) == "\\" then
				f:write(tabs, k, "=", "[["..v.."]],"..connector)
			else
				f:write(tabs, k, "=", "\""..v.."\","..connector)
			end
		elseif tv=="boolean" then
			f:write(tabs, k, "=", tostring(v), ","..connector)
		else
			f:write(tabs, k, "=", v or 0, ","..connector)
		end
	end
	if not (tabs=="")then
		tabs = tabs:sub(1,-2)
	end
	if comma then
		f:write(tabs .. "},\n")
	else
		f:write(tabs .. "}\n")
	end
end

function output_java_table(t, f, comma, tabs, w_tbl)
	if not (type(t)=="table") then
		print("Invalid table to output!")
		return
	end

	tabs = tabs or ""
--	local connector = ""
	local k_tbl = {}
	local has_tbl = false
	for k, v in pairs(t) do
		table.insert(k_tbl, k)
		if type(v)=="table" then
			has_tbl = true
		end
	end

	table.sort(k_tbl, function (a,b) return compare_func(a, b, w_tbl) end )

	--
	--	Note that:	getn is only for table with numberic index
	--			not available for table with string index
	--	so we use getn(k_tbl) instead of getn(t), as we know that
	--	k_tbl and t has the same number of k-v pairs
--	if table.getn(k_tbl)<12 and not has_tbl then
--		connector = ""
--		tabs = ""
--	else
--		connector = "\n"
--		tabs = tabs .. "	"
--	end

--	f:write("{" .. connector)

	local count = 0
	for _, k in ipairs(k_tbl) do
		local v = t[k]

		if type(k)=="number" then
			k = "[" .. k .. "]"
		end
		local tv = type(v)
		if tv=="table" then
--			f:write(tabs, k, "= ")
--			output_table(v, f, tabs .. "	", true)
		else
			if count ~= 0 then
				f:write(", ")
			end

			if tv=="string" then
				if v:sub(1,1)=="\"" and v:sub(-1)=="" then
					f:write(v)
				else
					f:write("\""..v.."\"")
				end
			elseif tv=="boolean" then
				f:write(tostring(v))
			else
				f:write(v or 0)
			end

			count = count + 1
		end
	end
--	if not (tabs=="")then
--		tabs = tabs:sub(1,-2)
--	end
	if comma then
		if comma == 0 then
			f:write(tabs .. ", ")
		elseif comma == 1 then
			f:write(tabs .. "), ")
		elseif comma == 2 then
			f:write(tabs .. "));\n")
		end
	else
		f:write(tabs .. ");\n")
	end
end


function handle_line(obj, line, x)
	obj[x] = {}
	local y = 1
	local pos_prev = 1
	local mode = 0
	for pos = 1, line:len() do
		local c = line:sub(pos,pos)
		if mode==1 then
			if c=="\"" then
				mode = 0
			end
		else
			if c=="\"" then
				mode = 1
			elseif c=="," then
				local val = line:sub(pos_prev, pos-1)
				if val:sub(1,1)=="\"" and val:sub(-1)=="\"" then
					obj[x][y] = val:sub(2,-2)
				elseif val=="" then
					obj[x][y] = 0
				else
					obj[x][y] = val
				end
				y = y+1
				pos_prev = pos+1
			end
		end
	end
	obj[x][y] = line:sub(pos_prev)
end

function handle_file(fileName, _start, _step, do_func)
	local f = io.open(fileName)
	if not f then
		print("Failed to open file:", fileName)
		return
	end

	if not do_func then
		print("Failed to handle file:", fileName, " invalid call back function")
		return
	end

	local cnt = 0
	local obj = {}
	local _end = _start + _step
	local pre_line
	for line in f:lines() do
		-- print("["..line.."]")
		if pre_line then
			line = pre_line .. line
		end
		local flag = 0
		for _ in line:gmatch("\"") do
			if flag == 0 then
				flag = 1
			else
				flag = 0
			end
		end
		if flag==1 then
			pre_line = line
		else
			pre_line = nil

			cnt = cnt + 1
			if cnt>=_end then
				do_func(obj)
				obj = {}
				_start = _start + _step
				_end = _end + _step

				handle_line(obj, line, cnt-_start+1)
			elseif cnt>=_start then
				handle_line(obj, line, cnt-_start+1)
			end
		end
	end
	if type(obj)=="table" then
		do_func(obj)
		obj = nil
	end
	f:close()
end

function get_frame_table(filename)
	local file = io.open(filename, "r")
	if not file then
		print("Failed to load frame table, invalid sprite file: ", filename)
		return
	end
	local source = file:read("*all")
	if not source then
		print("Failed to load sprite, not data: ", filename)
		return
	end
	file:close()
	local tab = {}
	local index = 0
	for n in source:gfind([[FRAME%s+"(.-)"]]) do
		tab[n] = index
		index = index+1
	end
	return tab
end
----------------------------------------------------------------------------------
return M
