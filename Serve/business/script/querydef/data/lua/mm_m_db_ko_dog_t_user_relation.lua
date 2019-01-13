---------------------------------------------
local modname="mm_m_db_ko_dog_t_user_relation"
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
	"\"dish/mm_package.h\"",
	"<string>",
}
event =
{
	{
		define = "struct", name="t_user_relation", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{		
			{type="uint64", name="user_id",default="0",desc="user_id.",},
			{type="uint64", name="friend_group_id",default="0",desc="friend_group_id.",},
			{type="uint64", name="friend_id",default="0",desc="friend_id.",},
			{type="string", name="friend_remark",default="\"\"",desc="friend_remark.",},
			{type="uint32", name="build_friend_time", default = "0",desc="build_friend_time",},
		},
	},
	{
		define = "struct", name="t_user_relation_assist", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{		
			{type="uint64", name="id",default="0",desc="friend_group_id.",},
			{type="uint64", name="user_id",default="0",desc="user_id.",},
			{type="string", name="friend_group",default="\"\"",desc="friend_group.",},
		},
	},
	{
		define = "struct", name="t_user_relation_friend_apply", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{		
			{type="uint64", name="user_apply_id",default="0",desc="user_apply_id.",},
			{type="string", name="user_apply_name",default="\"\"",desc="user_apply_name.",},
			{type="string", name="user_apply_nick",default="\"\"",desc="user_apply_nick.",},
			{type="uint32", name="user_apply_create_time", default = "0",desc="user_apply_create_time",},
			{type="string", name="user_apply_description",default="\"\"",desc="friend_group.",},
		},
	},
}
----------------------------------------------------------------------------------
return M
