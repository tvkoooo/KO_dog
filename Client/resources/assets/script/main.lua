local p = {}
----------------------------------------------
package.path = "script/?.lua;" .. package.path
----------------------------------------------
local lua_context = require("mm/lua_context")
local logger = require("mm/logger")
----------------------------------------------
function loader_function(modulename)
	--print (modulename, package.path)
    local errmsg = ""
    local modulepath = string.gsub(modulename, "%.", "/")
    for path in string.gmatch(package.path, "([^;]+)") do
        local filename = string.gsub(path, "%?", modulepath)
        filename = string.gsub(filename, "\\", "/")
        local result = lua_context.require_loader(filename)
        if result then
            return result
        end
        errmsg = errmsg.."\n\tno file '"..filename.."' (checked with custom loader)"
    end
  return errmsg
end
function initialize()
	if nil ~= package.loaders then
		-- version <= 5.1
		table.insert(package.loaders, 1, loader_function)
	else
		-- version >= 5.2
		table.insert(package.searchers, 1, loader_function)
	end
	--
	require("model/model_error")
	--
	logger.log_I("lua main initialize success.")
end
----------------------------------------------
initialize()
----------------------------------------------
return p
