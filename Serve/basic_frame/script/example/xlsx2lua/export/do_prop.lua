local script_common_root="../../.."
local script_use_root=".."
local import_file_path=script_use_root.."/data/xlsx"
local export_file_path=script_use_root.."/data/lua"
-----------------------------------------------------------
local old_path = package.path
package.path =
";"..script_common_root.."/generator/?.lua"..
";"..script_common_root.."/generator/?.?"..
";"..script_common_root.."/xlsx_export/?.lua"..
";"..script_common_root.."/xlsx_export/?.?"..
package.path

require 'os'
local xlsx_export = require 'xlsx_export'
local xlsx_util = require 'xlsx_util'
local math = require 'math'
package.path = old_path
-----------------------------------------------------------
xlsx_export.cscript_path = script_common_root.."/xlsx_export/"
-----------------------------------------------------------------
xlsx_export.export_csv(import_file_path.."/role.xlsx", 0)
-----------------------------------------------------------------
local of_file = io.open(export_file_path.."/prop_data.lua", "w")
if not of_file then
	print("Failed to open output file: prop_data.lua")
else
----------------------------------------
	of_file:write([[
local type = type
----------------------------------------
local modname="prop_data"
local M={}
_G[modname]=M
package.loaded[modname]=M
if setfenv then
	setfenv(1, M) -- for 5.1
else
	_ENV = M -- for 5.2
end
----------------------------------------
]])
----------------------------------------
	of_file:write([[
if not (type(data_prop)=="table") then
	data_prop = {}
end

data_prop =]])
-- id	task_sub_type	task_desc	note
local data_prop_s = {}
function handle_data_prop(o)
	local lvl 			= tonumber(o[1][1])
	-- if id and id>0 then
	if lvl and lvl >= 0 then --
		local cell = {}
		------------------------------
		-- 进阶次数	体力值	血量	进阶需要战斗力	暴击几率	闪避几率	进阶后剩余战斗力
		cell.id 				= lvl + 1			--sid
		cell.lvl 				= lvl				--进阶次数
		cell.tl 				= tonumber(o[1][2]) --体力值
		cell.xl 				= tonumber(o[1][3]) --血量
		cell.nz 				= tonumber(o[1][4]) --进阶需要战斗力
		cell.bj 				= tonumber(o[1][5]) --暴击几率
		cell.sb 				= tonumber(o[1][6]) --闪避几率
		cell.zs 				= tonumber(o[1][7]) --进阶后剩余战斗力
		------------------------------
		data_prop_s[cell.id] = cell
	end
end

xlsx_export.handle_file("tmp/sheet1.csv", 2, 1, handle_data_prop)
xlsx_export.output_table(data_prop_s, of_file)
-----------------------------------------------------------------
	of_file:write([[
----------------------------------------------
return M
]])
end
-----------------------------------------------------------------
-- xlsx_export.clear_csv()
of_file:close()
-- xlsx_util.copyfile("../data/lua/arch_data.lua",data_root.."/../../resources/client/media/script/data/arch_data.lua")
