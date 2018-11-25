---------------------------------------------
local modname="mm_m_cobweb_mq_amqp"
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
		define = "struct", name="m_config_mq_amqp_vhost", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id.",},
			{type="uint32", name="address_id",default="0",desc="address_id for server.",},
			{type="string", name="vhost_name",default="\"/\"",desc="vhost name.",},
			{type="uint32", name="channel_max",default="0",desc="channel max,default 0.",},
			{type="uint32", name="frame_max",default="131072",desc="frame max.default 131072",},
			{type="uint32", name="heartbeat", default = "0",desc="heartbeat for secones.default 0 is not heartbeat.",},
		},
	},
	{
		define = "struct", name="m_config_mq_amqp_exchange", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id.",},
			{type="string", name="exchange_name",default="\"\"",desc="exchange_name for amqp.",},
			{type="string", name="exchange_type",default="\"\"",desc="exchange_type for amqp.",},
			{type="uint32", name="exchange_passive",default="0",desc="passive.",},
			{type="uint32", name="exchange_durable",default="1",desc="durable",},
			{type="uint32", name="exchange_auto_delete", default = "0",desc="auto_delete.",},
			{type="uint32", name="exchange_internal", default = "0",desc="internal.",},
		},
	},
	{
		define = "struct", name="m_config_mq_amqp_queue", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id.",},
			{type="string", name="queue_name",default="\"\"",desc="exchange_name for amqp.",},
			{type="uint32", name="queue_passive",default="0",desc="passive.",},
			{type="uint32", name="queue_durable",default="1",desc="durable",},
			{type="uint32", name="queue_exclusive", default = "0",desc="auto_delete.",},
			{type="uint32", name="queue_auto_delete", default = "0",desc="internal.",},
		},
	},
	{
		define = "struct", name="m_config_mq_amqp_publish", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id.",},
			{type="uint32", name="vhost_id",default="0",desc="vhost_id.",},
			{type="uint32", name="exchange_id",default="0",desc="exchange_id",},
			{type="uint32", name="publish_mandatory",default="0",desc="publish_mandatory",},
			{type="uint32", name="publish_immediate",default="0",desc="publish_immediate",},
			{type="string", name="routingkey_prefix", default = "\"\"",desc="routingkey_prefix.",},
		},
	},
	{
		define = "struct", name="m_config_mq_amqp_consume", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id.",},
			{type="uint32", name="vhost_id",default="0",desc="vhost_id.",},
			{type="uint32", name="exchange_id",default="0",desc="exchange_id",},
			{type="uint32", name="queue_id",default="0",desc="queue_id",},
			{type="uint32", name="consume_no_local",default="0",desc="consume_no_local",},
			{type="uint32", name="consume_no_ack",default="0",desc="consume_no_ack",},
			{type="uint32", name="consume_exclusive",default="0",desc="consume_exclusive",},
			{type="string", name="routingkey", default = "\"\"",desc="routingkey.",},
		},
	},
}
----------------------------------------------------------------------------------
return M
