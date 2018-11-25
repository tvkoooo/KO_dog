---------------------------------------------
local modname="mm_q_cobweb_runtime"
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
	"\"dish/mm_m_runtime_state.h\"",
	"\"core/mm_logger.h\"",
}
event =
{
	{
		define = "struct", name="p_get_runtime_state", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="mm_m_runtime_state", name="info",default="",desc="server runtime info.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_get_runtime_state",fl="(",fr=")",
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
						"info.pid",
						"info.node_internal",
						"info.port_internal",
						"info.workers_internal",
						"info.node_external",
						"info.port_external",
						"info.workers_external",
						"info.lavg_01",
						"info.lavg_05",
						"info.lavg_15",
						"info.cpu_pro",
						"info.mem_pro",
						"info.weights",
						"info.logger_lvl",
						"info.logger_dir",
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
		define = "struct", name="p_set_runtime_state", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="mm_m_runtime_state", name="info",default="",desc="server runtime info.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_set_runtime_state",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="info.unique_id",},
						{kind="i",var="info.pid",},
						{kind="i",var="info.node_internal",},
						{kind="i",var="info.port_internal",},
						{kind="i",var="info.workers_internal",},
						{kind="i",var="info.node_external",},
						{kind="i",var="info.port_external",},
						{kind="i",var="info.workers_external",},
						{kind="i",var="info.lavg_01",},
						{kind="i",var="info.lavg_05",},
						{kind="i",var="info.lavg_15",},
						{kind="i",var="info.cpu_pro",},
						{kind="i",var="info.mem_pro",},
						{kind="i",var="info.weights",},
						{kind="i",var="info.logger_lvl",},
						{kind="i",var="info.logger_dir",},
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
