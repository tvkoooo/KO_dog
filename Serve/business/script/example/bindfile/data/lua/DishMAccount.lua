---------------------------------------------
local modname="DishMAccount"
local M={}
_G[modname]=M
package.loaded[modname]=M
if setfenv then
	setfenv(1, M) -- for 5.1
else
	_ENV = M -- for 5.2
end
----------------------------------------------------------------------------------
include_file=
{
	"\"Dish/Archive/DishPackage.h\"",
	"<string>",
}
event =
{
	{
		define = "struct", name="MAccount", KeyH = "1", KeyL = "1",base = "Package",virtual_base = true,
		attributes =
		{
			{type="int32"	, name="id"			, default =  0,desc="static id",},
			{type="int32"	, name="type"		, default = -1,desc="type for account",},
			{type="string"	, name="username"	, },
			{type="string"	, name="password"	, },
			{type="string"	, name="email"		, },
			{type="int16"	, name="sex"		, },
			{type="int32"	, name="lasttime"	, default = 0,},
			{type="int32"	, name="createtime"	, default = 0,},
			{type="int32"	, name="birthday"	, default = 0,},
		},
	},
	{
		define = "msg", name="MAccountGroup", KeyH = "1", KeyL = "1",base = "Msg",virtual_base = true,
		typedef = 
		{
			{type="std::map<MAccount>", name="MAccountMap",},
		},
		attributes =
		{
			{type="MAccountMap"	, name="map"	, },
		},
	},
}
----------------------------------------------------------------------------------
return M
