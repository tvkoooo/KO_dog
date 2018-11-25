---------------------------------------------
local modname="mm_m_cobweb_amqp"
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
		define = "struct", name="m_config_amqp", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id for server.",},
			{type="string", name="amqp_exchange",default="\"\"",desc="exchange key.",},
			{type="string", name="amqp_exchange_type",default="\"\"",desc="exchange type.",},
			{type="string", name="amqp_vhost",default="0",desc="amqp vhost.",},
			{type="string", name="amqp_routekey_preffix", default = "\"\"",desc="amqp route key preffix.",},
			{type="string", name="amqp_queue_name", default = "\"\"",desc="amqp queue name.",},
			{type="uint32", name="amqp_frame_max", default = "0",desc="frame max.",},
			{type="uint32", name="amqp_channel_max", default = "0",desc="channel max.",},
			{type="uint32", name="amqp_heartbeat", default = "0",desc="heartbeat.",},
			{type="uint32", name="amqp_channel", default = "0",desc="amqp channel.",},
		},
	},
}
----------------------------------------------------------------------------------
return M
