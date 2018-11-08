require("class")
-----------------------------------------------
audio = class(function(self,unit)
	self.unit = unit
end)
-----------------------------------------------
function audio:__tostring()
    return string.format("%s","audio")
end
-----------------------------------------------
function audio:on_unit_add(unit)
	print("audio.on_unit_add")
end
function audio:on_unit_rmv(unit)
	print("audio.on_unit_rmv")
end
-----------------------------------------------
function audio:play(_soundName,_loop,_volume)
	print("audio.play:".._soundName)
end
function audio:stop(_soundName)
	print("audio.stop:".._soundName)
end
function audio:stopAll()
	print("audio.stopAll")
end
return audio
