---------------------------------------------
local modname="mm_q_cobweb_cback"
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
	"\"querydef/mm_m_cobweb_common.h\"",
}
event =
{
	{
		define = "struct", name="p_get_config_launch_cback", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="m_config_launch_cback", name="info",default="",desc="config for server address infomation.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_get_config_launch_cback",fl="(",fr=")",
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
						"info.zkimport_address",
						"info.internal_address",
						"info.internal_workers",
						"info.dbcredis_address",
						"info.dbplobby_lpusher",
						"info.dbplobby_workers",
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
		define = "struct", name="p_set_config_launch_cback", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="m_config_launch_cback", name="info",default="",desc="config for server address infomation.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_set_config_launch_cback",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="info.unique_id",},
						{kind="i",var="info.zkimport_address",},
						{kind="i",var="info.internal_address",},
						{kind="i",var="info.internal_workers",},
						{kind="i",var="info.dbcredis_address",},
						{kind="i",var="info.dbplobby_lpusher",},
						{kind="i",var="info.dbplobby_workers",},
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
