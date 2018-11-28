---------------------------------------------
local modname="mm_m_db_ko_dog_t_user_basic"
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
		define = "struct", name="t_user_basic", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{		
			{type="uint64", name="id",default="0",desc="用户id.",},
			{type="string", name="name",default="\"\"",desc="用户名.",},
			{type="string", name="password",default="\"\"",desc="用户密码.",},
			{type="string", name="nick", default = "\"\"",desc="昵称.",},
			{type="uint32", name="create_time", default = "0",desc="创建时间.",},
		},
	},
}
----------------------------------------------------------------------------------
return M
