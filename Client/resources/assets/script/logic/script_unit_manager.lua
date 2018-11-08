require("class")
require("script_unit")
-----------------------------------------------
-----------------------------------------------
-----------------------------------------------
script_unit_manager = class(function(self)
	self.name = nil
	self.unit_manager = nil
	self.entitys = {}
	self.awake_entitys = {}
	self.updating_entitys = {}
	self.new_updating_entitys = {}
	self.num_updating_entitys = 0
	self.num_entitys = 0
end)
-----------------------------------------------
function script_unit_manager:__tostring()
    return string.format("%s","script_unit_manager")
end
-----------------------------------------------
function script_unit_manager:set_unit_manager(unit_manager)
	self.unit_manager = unit_manager
end
function script_unit_manager:create_unit()
    local _unit = self.unit_manager:create()
    local uid = unit:get_uid()
    local _script_unit = script_unit(_unit)
	_script_unit:init()
    self.entitys[uid] = _script_unit
    self.awake_entitys[uid] = _script_unit
    self.num_entitys = self.num_entitys + 1
    return _script_unit
end
function script_unit_manager:destroy_entity(uid)
    local _script_unit = self.entitys[uid]
    if _script_unit then		
		_script_unit:destroy()
        self.num_entitys = self.num_entitys - 1
        self.entitys[uid] = nil        
        if self.updating_entitys[uid] then
            self.updating_entitys[uid] = nil
            self.num_updating_entitys = self.num_updating_entitys - 1
        end
        self.awake_entitys[uid] = nil
    end
end
function script_unit_manager:push_event(uid,event,data)
    local _script_unit = self.entitys[uid]
    if _script_unit then
        _script_unit:push_event(event,data)
    end
end
-----------------------------------------------
return script_unit_manager
