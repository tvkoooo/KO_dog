require 'os'
local script_common_root=_G.arg[1]
local script_use_root=".."
local import_file_path=script_use_root.."/data/lua"
local export_file_path=script_use_root.."/data/cpp"
local print = print
-----------------------------------------------------------
local old_path = package.path
package.path =
";"..script_common_root.."/generator/?.lua"..
";"..script_common_root.."/generator/?.?"..
package.path

require 'os'
local loadfile = loadfile
local math = require 'math'
local generator = require "generator"
local typedef = require "typedef"
package.path = old_path
-----------------------------------------------------------
local template_file_path=script_common_root.."/template"
function bind_model( name )
	local ctx = 
	{
		file_tag = name,
		vname = typedef.vname,
		types = typedef.types,
	}
	local data = import_file_path.."/mm_"..name..".lua"
	local cxxt = template_file_path.."/queryer_cxx.template"
	local cxxe = export_file_path.."/mm_"..name..".cpp"
	generator.bind_template(ctx,cxxt,data,cxxe)
	local hxxt = template_file_path.."/queryer_hxx.template"
	local hxxe = export_file_path.."/mm_"..name..".h"
	generator.bind_template(ctx,hxxt,data,hxxe)
	-- local hppt = template_file_path.."/queryer_hpp.template"
	-- local hppe = export_file_path.."/mm_"..name..".hpp"
	-- generator.bind_template(ctx,hppt,data,hppe)
end
if _G.arg[2] then
	-- bind_model("QAccount")
	print("bind_model(".._G.arg[2]..")")
	bind_model(_G.arg[2])
else
	print("lua do_query.lua script_home mode_name")
end