---------------------------------------------
local modname="mm_q_cobweb_amqp"
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
	"\"mysql/mm_db_mysql_query.h\"",
	"\"dish/mm_package.h\"",
	"\"core/mm_logger.h\"",
	"\"querydef/mm_m_cobweb_amqp.h\"",
}			
event =
{
	{
		define = "struct", name="p_get_config_amqp", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="m_config_amqp", name="info",default="",desc="info address for server.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_get_config_amqp",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="info.unique_id",},
					},
				},
				{
					function_name = "select",fl=" ",fr=" ",
					variable =
					{
						{kind="o",var="code",},
					},
				},
			},
			output =
			{
				{
					variable =
					{
						"info.amqp_exchange",
						"info.amqp_exchange_type",
						"info.amqp_vhost",
						"info.amqp_routekey_preffix",
						"info.amqp_queue_name",
						"info.amqp_frame_max",
						"info.amqp_channel_max",
						"info.amqp_heartbeat",
						"info.amqp_channel"
					},
				},
				{
					variable =
					{
						"code",
					},
				},
			},
		},
	},
	{
		define = "struct", name="p_set_config_amqp", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="m_config_amqp", name="info",default="",desc="info address for server.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb0.p_set_config_amqp",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="info.unique_id",},
						{kind="i",var="info.amqp_exchange",},
						{kind="i",var="info.amqp_exchange_type",},
						{kind="i",var="info.amqp_vhost",},
						{kind="i",var="info.amqp_routekey_preffix",},
						{kind="i",var="info.amqp_queue_name",},
						{kind="i",var="info.amqp_frame_max",},
						{kind="i",var="info.amqp_channel_max",},
						{kind="i",var="info.amqp_heartbeat",},
						{kind="i",var="info.amqp_channel",},
					},
				},
				{
					function_name = "select",fl=" ",fr=" ",
					variable =
					{
						{kind="o",var="code",},
					},
				},
			},
			output =
			{
				{
					variable =
					{
						"code",
					},
				},
			},
		},
	},
}
----------------------------------------------------------------------------------
return M
