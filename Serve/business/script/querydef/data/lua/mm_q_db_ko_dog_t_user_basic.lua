---------------------------------------------
local modname="mm_q_db_ko_dog_t_user_basic"
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
	"\"querydef/mm_m_db_ko_dog_t_user_basic.h\"",
	"<vector>",	
}
event =
{
	{
		define = "struct", name="p_userinfo_add", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			
			{type="string", name="name",default="\"\"",desc="",},
			{type="string", name="password",default="\"\"",desc="",},
			{type="string", name="nick", default = "\"\"",desc="",},
			
			{type="uint64", name="id",default="0",desc="",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_userinfo_add",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="name",},
						{kind="i",var="password",},
						{kind="i",var="nick",},
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
						"id",
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
		define = "struct", name="p_userinfo_check", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			
			{type="string", name="name",default="\"\"",desc="",},
			{type="string", name="password",default="\"\"",desc="",},
			
			{type="uint64", name="id",default="0",desc="",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_userinfo_check",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="name",},
						{kind="i",var="password",},
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
						"id",
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
		define = "struct", name="p_userinfo_search", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		typedef = 
		{
			{type="std::vector<t_user_basic>", name="user_basic_vec",},
		},
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			
			{type="uint32", name="limit",default="5",desc="",},
			{type="string", name="search",default="\"\"",desc="",},			

			{type="user_basic_vec", name="user_info_s",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_userinfo_search",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="limit",},
						{kind="i",var="search",},
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
					container_kind = "list",
					container_type = "user_basic_vec",
					container_name = "user_info_s",
					elem_type = "t_user_basic",
					elem_name = "v",
					key = "v.id",
					variable =
					{
						"v.id",
						"v.name",
						"v.nick",
						"v.create_time",
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
