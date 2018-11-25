---------------------------------------------
local modname="mm_q_cobweb_lobby"
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
		define = "struct", name="p_get_config_launch_lobby", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="m_config_launch_lobby", name="info",default="",desc="config for server address infomation.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_get_config_launch_lobby",fl="(",fr=")",
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
						"info.zkexport_address",
						"info.external_address",
						"info.external_workers",
						"info.internal_address",
						"info.internal_workers",
						"info.dbcredis_address",
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
		define = "struct", name="p_set_config_launch_lobby", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="m_config_launch_lobby", name="info",default="",desc="config for server address infomation.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_set_config_launch_lobby",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="info.unique_id",},
						{kind="i",var="info.zkimport_address",},
						{kind="i",var="info.zkexport_address",},
						{kind="i",var="info.external_address",},
						{kind="i",var="info.external_workers",},
						{kind="i",var="info.internal_address",},
						{kind="i",var="info.internal_workers",},
						{kind="i",var="info.dbcredis_address",},
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
	{
		define = "struct", name="p_get_runtime_lobby", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="m_runtime_lobby", name="info",default="",desc="lobby runtime infomation.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_get_runtime_lobby",fl="(",fr=")",
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
						"info.poll_size",
						"info.qpm_rq",
						"info.qpm_rs",
						"info.qpm_nt",
						"info.lastuptime",
						"info.updatetime",
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
		define = "struct", name="p_set_runtime_lobby", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="m_runtime_lobby", name="info",default="",desc="lobby runtime infomation.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_set_runtime_lobby",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="info.unique_id",},
						{kind="i",var="info.poll_size",},
						{kind="i",var="info.qpm_rq",},
						{kind="i",var="info.qpm_rs",},
						{kind="i",var="info.qpm_nt",},
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
