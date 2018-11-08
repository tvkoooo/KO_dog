require 'class'
local logger = require 'logger'
-----------------------------------------------
local components = {}
-----------------------------------------------
local function load_component(name)
    if components[name] == nil then
        components[name] = require("components/"..name)
    end
    return components[name]
end
-----------------------------------------------
script_unit = class(function(self,unit)
    self.unit = unit
	self.components = {}
end)
-----------------------------------------------
function script_unit:__tostring()
    return string.format("%s:%u","script_unit",self.unit:get_uid())
end
-----------------------------------------------
function script_unit:init()
	self.unit:init()
end
function script_unit:destroy()
	self.unit:destroy()
end
function script_unit:add_component(name)
    if self.components[name] then
        logger.logW("component "..name.." already exists!")
    end
    local cmp = load_component(name)
    assert(cmp, "component ".. name .. " does not exist!")

    local component = cmp(self)
    self.components[name] = component

	if cmp.on_unit_add then
		cmp:on_unit_add(self)
	end
	logger.logV("entity.add_component "..name)
	return component
end
function script_unit:rmv_component(name)
    local cmp = self.components[name]
    if cmp then
        self.components[name] = nil
        if cmp.on_unit_rmv then
            cmp:on_unit_rmv(self)
        end
    end
	logger.logV("entity.rmv_component "..name)
end
function script_unit:push_event(event,data)

end
-----------------------------------------------
return script_unit
