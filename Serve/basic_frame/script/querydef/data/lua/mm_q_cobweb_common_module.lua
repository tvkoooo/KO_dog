---------------------------------------------
local modname="mm_q_cobweb_module"
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
		define = "struct", name="p_get_launch_module", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="m_config_launch_module", name="info",default="",desc="server runtime info.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_get_launch_module",fl="(",fr=")",
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
						"info.mid_l",
						"info.mid_r",
						"info.shard_size",
						"info.depth_size",
						"info.desc",
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
		define = "struct", name="p_set_launch_module", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="m_config_launch_module", name="info",default="",desc="server runtime info.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_set_launch_module",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="info.unique_id",},
						{kind="i",var="info.mid_l",},
						{kind="i",var="info.mid_r",},
						{kind="i",var="info.shard_size",},
						{kind="i",var="info.depth_size",},
						{kind="i",var="info.desc",},
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
