require("class")
require("tablecopy")
-----------------------------------------------
stategraph = class(function(self)
	self.name = args.name
	self.onenter = args.onenter
	self.onexit = args.onexit
	self.onupdate = args.onupdate
	self.ontimeout = args.ontimeout
end)
-----------------------------------------------
function stategraph:__tostring()
    return string.format("%s","stategraph")
end
-----------------------------------------------
-----------------------------------------------
-----------------------------------------------
return unit
