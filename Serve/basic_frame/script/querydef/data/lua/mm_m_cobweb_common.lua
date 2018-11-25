---------------------------------------------
local modname="mm_m_cobweb"
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
		define = "struct", name="m_config_address", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id for server.",},
			{type="string", name="node",default="\"\"",desc="node ip.",},
			{type="string", name="bind",default="\"\"",desc="bind ip.",},
			{type="uint32", name="port",default="0",desc="port.",},
			{type="string", name="username", default = "\"\"",desc="username.",},
			{type="string", name="password", default = "\"\"",desc="password.",},
			{type="string", name="desc", default = "\"\"",desc="description.",},
		},
	},
	{
		define = "struct", name="m_config_launch_module", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id for zookeeper.",},
			{type="uint32", name="mid_l",default="0",desc="message id l.",},
			{type="uint32", name="mid_r",default="0",desc="message id r.",},
			{type="uint32", name="shard_size",default="0",desc="shard size.",},
			{type="uint32", name="depth_size",default="0",desc="depth size.",},
			{type="string", name="desc", default = "\"\"",desc="description.",},
		},
	},
	{
		define = "struct", name="m_config_launch_entry", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id for server.",},
			{type="uint32", name="zkimport_address",default="0",desc="zookeeper import address.",},
			{type="uint32", name="zkexport_address",default="0",desc="zookeeper export address.",},
			{type="uint32", name="external_address",default="0",desc="external listen address.",},
			{type="uint32", name="external_workers",default="0",desc="external listen workers.",},
			{type="uint32", name="internal_address",default="0",desc="internal listen address.",},
			{type="uint32", name="internal_workers",default="0",desc="internal listen workers.",},
		},
	},
	{
		define = "struct", name="m_config_launch_lobby", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id for zookeeper.",},
			{type="uint32", name="zkimport_address",default="0",desc="zookeeper import address.",},
			{type="uint32", name="zkexport_address",default="0",desc="zookeeper export address.",},
			{type="uint32", name="external_address",default="0",desc="external listen address.",},
			{type="uint32", name="external_workers",default="0",desc="external listen workers.",},
			{type="uint32", name="internal_address",default="0",desc="internal listen address.",},
			{type="uint32", name="internal_workers",default="0",desc="internal listen workers.",},
			{type="uint32", name="dbcredis_address",default="0",desc="dbcredis redis address.",},
		},
	},
	{
		define = "struct", name="m_config_launch_proxy", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id for zookeeper.",},
			{type="uint32", name="zkimport_address",default="0",desc="zookeeper import address.",},
			{type="uint32", name="zkexport_address",default="0",desc="zookeeper export address.",},
			{type="uint32", name="internal_address",default="0",desc="internal listen address.",},
			{type="uint32", name="internal_workers",default="0",desc="internal listen workers.",},
			{type="uint32", name="module",default="0",desc="module type.",},
		},
	},
	{
		define = "struct", name="m_config_launch_module_proxy", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id for zookeeper.",},
			{type="uint32", name="zkimport_address",default="0",desc="zookeeper import address.",},
			{type="uint32", name="zkexport_address",default="0",desc="zookeeper export address.",},
			{type="uint32", name="internal_address",default="0",desc="internal listen address.",},
			{type="uint32", name="internal_workers",default="0",desc="internal listen workers.",},
			{type="uint32", name="module",default="0",desc="module type.",},
			{type="uint32", name="mid_l",default="0",desc="message id l.",},
			{type="uint32", name="mid_r",default="0",desc="message id r.",},
			{type="uint32", name="shard_size",default="0",desc="shard size.",},
			{type="uint32", name="depth_size",default="0",desc="depth size.",},
		},
	},
	{
		define = "struct", name="m_config_launch_cback", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id for zookeeper.",},
			{type="uint32", name="zkimport_address",default="0",desc="zookeeper import address.",},
			{type="uint32", name="internal_address",default="0",desc="internal listen address.",},
			{type="uint32", name="internal_workers",default="0",desc="internal listen workers.",},
			{type="uint32", name="dbcredis_address",default="0",desc="cache redis address.",},
			{type="uint32", name="dbplobby_lpusher",default="0",desc="poper redis lpusher.",},
			{type="uint32", name="dbplobby_workers",default="0",desc="poper redis workers.",},
		},
	},
	{
		define = "struct", name="m_runtime_lobby", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="unique_id",default="0",desc="unique_id for zookeeper.",},
			{type="uint32", name="poll_size",default="0",desc="zookeeper import address.",},
			{type="float", name="qpm_rq",default="0",desc="rq minute pkg number.",},
			{type="float", name="qpm_rs",default="0",desc="rs minute pkg number.",},
			{type="float", name="qpm_nt",default="0",desc="nt minute pkg number.",},
			{type="uint32", name="lastuptime",default="0",desc="last updatetime unix time.",},
			{type="uint32", name="updatetime",default="0",desc="updatetime unix time.",},
		},
	},
	{
		define = "struct", name="m_zk_cluster", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32", name="cluster_id",default="0",desc="unique_id for cluster.",},
			{type="uint32", name="cluster_state",default="0",desc="cluster state.",},
			{type="uint32", name="node_number",default="0",desc="cluster node number.",},
			{type="string", name="desc",default="\"\"",desc="description.",},
		},
	},
	{
		define = "struct", name="m_zk_cluster_node", KeyH = "1", KeyL = "1",base = "mm_package",virtual_base = true,
		attributes =
		{
			{type="uint32"	, name="unique_id"		, default = 0,desc="node unique id",},
			{type="uint32"	, name="cluster_id"		, default = 0,desc="node cluster id",},
			{type="string"	, name="node"		, default = "\"\"",desc="server node ip.",},
			{type="uint32"	, name="port"		, default = 0,desc="server port",},
		},
	},
}
----------------------------------------------------------------------------------
return M
