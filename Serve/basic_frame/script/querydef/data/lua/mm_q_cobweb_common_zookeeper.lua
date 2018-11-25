---------------------------------------------
local modname="mm_q_server_config"
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
		define = "struct", name="p_get_zookeeper_cluster", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="m_zk_cluster", name="info",default="",desc="cluster infomation.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_get_zookeeper_cluster",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="info.cluster_id",},
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
						"info.cluster_state",
						"info.node_number",
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
		define = "struct", name="p_set_zookeeper_cluster", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="m_zk_cluster", name="info",default="",desc="cluster infomation.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_set_zookeeper_cluster",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="info.cluster_id",},
						{kind="i",var="info.cluster_state",},
						{kind="i",var="info.node_number",},
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
	{
		define = "struct", name="p_get_zookeeper_node", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="uint32", name="unique_id",default="0",desc="unique_id for zookeeper.",},
			{type="uint32", name="cluster_id",default="0",desc="cluster_id for zookeeper.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_get_zookeeper_node",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="unique_id",},
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
						"cluster_id",
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
		define = "struct", name="p_set_zookeeper_node", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="uint32", name="unique_id",default="0",desc="unique_id for zookeeper.",},
			{type="uint32", name="cluster_id",default="0",desc="cluster_id for zookeeper.",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_set_zookeeper_node",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="unique_id",},
						{kind="i",var="cluster_id",},
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
		define = "struct", name="p_select_zookeeper_cluster_node_list", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		typedef = 
		{
			{type="std::vector< m_zk_cluster_node >"	    , name="m_zk_cluster_node_vec",},
		},
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="uint32", name="cluster_id",default="0",desc="cluster id",},
			{type="m_zk_cluster_node_vec", name="items",desc="item list for this cluster",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call xcbb_cobweb.p_select_zookeeper_cluster_node_list",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="cluster_id",},
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
					container_kind = "vector",
					container_type = "m_zk_cluster_node_vec",
					container_name = "items",
					elem_type = "m_zk_cluster_node",
					elem_name = "v",
					key = "v.sid",
					variable =
					{
						"v.unique_id",
						"v.cluster_id",
						"v.node",
						"v.port",
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
}
----------------------------------------------------------------------------------
return M
