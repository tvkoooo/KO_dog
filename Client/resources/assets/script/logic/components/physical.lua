require("class")
-----------------------------------------------
physical = class(function(self,unit)
	self.unit = unit
end)
-----------------------------------------------
function physical:__tostring()
    return string.format("%s","physical")
end
-----------------------------------------------
function physical:on_unit_add(unit)
	print("physical.on_unit_add")
end
function physical:on_unit_rmv(unit)
	print("physical.on_unit_rmv")
end
-----------------------------------------------
function physical:set_position(x,y,z)
	print("physical.set_position ["..x..","..y..","..z.."]")
end
function physical:set_orientation(x,y,z,w)
	print("physical.set_orientation ["..x..","..y..","..z..","..w.."]")
end
-----------------------------------------------
return physical
