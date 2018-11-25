---------------------------------------------
local modname="mm_m_cobweb_mq_redis"
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
		define = "struct", name="m_config_mq_redis_queue", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id.",},
			{type="uint32", name="address_id",default="0",desc="address_id for server.",},
			{type="string", name="queue_name",default="\"\"",desc="vhost name.",},
		},
	},
}
----------------------------------------------------------------------------------
return M
