---------------------------------------------
local modname="mm_m_db_ko_dog_t_nt_message"
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
		define = "struct", name="t_nt_message", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{		
			{type="uint64", name="note_id",default="0",desc="note_id.",},
			{type="int8", name="read_state",default="0",desc="read_state.",},
			{type="uint64", name="to_user_id",default="0",desc="to_user_id.",},
			{type="uint64", name="user_id",default="0",desc="user_id.",},
			{type="uint32", name="message_mid",default="0",desc="message_mid.",},
			{type="uint32", name="create_time",default="0",desc="create_time.",},
			{type="string", name="nt_message",default="\"\"",desc="nt_message",},
		},
	},
}
----------------------------------------------------------------------------------
return M
