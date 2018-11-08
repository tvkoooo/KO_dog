require("class")
-----------------------------------------------
anmiation = class(function(self,unit)
	self.unit = unit
end)
-----------------------------------------------
function anmiation:__tostring()
    return string.format("%s","anmiation")
end
-----------------------------------------------
function anmiation:on_unit_add(unit)
	print("anmiation.on_unit_add")
end
function anmiation:on_unit_rmv(unit)
	print("anmiation.on_unit_rmv")
end
-----------------------------------------------
function anmiation:play(_animName,_loop,_speed)
	print("anmiation.play:".._animName)
end
function anmiation:stop(_animName)
	print("anmiation.stop:".._animName)
end
function anmiation:stopAll()
	print("anmiation.stopAll")
end
return anmiation
