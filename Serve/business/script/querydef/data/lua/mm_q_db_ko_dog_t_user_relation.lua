---------------------------------------------
local modname="mm_q_db_ko_dog_t_user_relation"
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
	"\"querydef/mm_m_db_ko_dog_t_user_relation.h\"",
	"<vector>",
}
event =
{
	{
		define = "struct", name="p_user_relation_add_friend", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		typedef =
		{
			{type="std::vector<t_user_relation>", name="user_relation_vec",},
		},

		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="myself_id",default="0",desc="myself_id",},
			{type="uint64", name="friend_id",default="0",desc="friend_id",},
			{type="uint64", name="friend_group_id",default="0",desc="friend_group_id",},
			{type="string", name="friend_remark",default="\"\"",desc="friend_remark",},

			{type="user_relation_vec", name="user_relation_s",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_user_relation_add_friend",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="myself_id",},
						{kind="i",var="friend_id",},
						{kind="i",var="friend_group_id",},
						{kind="i",var="friend_remark",},
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
					container_type = "user_relation_vec",
					container_name = "user_relation_s",
					elem_type = "t_user_relation",
					elem_name = "v",
					key = "v.user_id",
					variable =
					{
						"v.user_id",
						"v.friend_group_id",
						"v.friend_id",
						"v.friend_remark",
						"v.build_friend_time",
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
		define = "struct", name="p_user_relation_delete_friend", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="myself_id",default="0",desc="myself_id",},
			{type="uint64", name="friend_id",default="0",desc="friend_id",},

		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_user_relation_delete_friend",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="myself_id",},
						{kind="i",var="friend_id",},
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
		define = "struct", name="p_user_relation_query_friends", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		typedef =
		{
			{type="std::vector<t_user_relation_assist>", name="user_relation_assist_vec",},
			{type="std::vector<t_user_relation>", name="user_relation_vec",},
		},
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="myself_id",default="0",desc="myself_id",},

			{type="user_relation_assist_vec", name="user_relation_assist_s",},
			{type="user_relation_vec", name="user_relation_s",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_user_relation_query_friends",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="myself_id",},
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
					container_type = "user_relation_assist_vec",
					container_name = "user_relation_assist_s",
					elem_type = "t_user_relation_assist",
					elem_name = "v",
					key = "v.id",
					variable =
					{
						"v.id",
						"v.user_id",
						"v.friend_group",
					},
				},
				{
					container_kind = "list",
					container_type = "user_relation_vec",
					container_name = "user_relation_s",
					elem_type = "t_user_relation",
					elem_name = "v",
					key = "v.user_id",
					variable =
					{
						"v.user_id",
						"v.friend_group_id",
						"v.friend_id",
						"v.friend_remark",
						"v.build_friend_time",
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
		define = "struct", name="p_user_relation_add_group", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="myself_id",default="0",desc="myself_id",},
			{type="string", name="friend_group",default="\"\"",desc="friend_group",},

			{type="uint64", name="id",default="0",desc="",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_user_relation_add_group",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="myself_id",},
						{kind="i",var="friend_group",},
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
		define = "struct", name="p_user_relation_rename_group", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="user_id",default="0",desc="user_id",},
			{type="uint64", name="friend_group_id",default="0",desc="friend_group_id",},
			{type="string", name="friend_group",default="\"\"",desc="friend_group",},

		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_user_relation_rename_group",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="user_id",},
						{kind="i",var="friend_group_id",},
						{kind="i",var="friend_group",},
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
		define = "struct", name="p_user_relation_delete_group", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="myself_id",default="0",desc="myself_id",},
			{type="uint64", name="friend_id",default="0",desc="friend_id",},
			{type="uint64", name="friend_group_id",default="0",desc="friend_group_id",},

		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_user_relation_delete_group",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="myself_id",},
						{kind="i",var="friend_id",},
						{kind="i",var="friend_group_id",},
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
		define = "struct", name="p_user_relation_change_group", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="myself_id",default="0",desc="myself_id",},
			{type="uint64", name="friend_id",default="0",desc="friend_id",},
			{type="uint64", name="friend_group_id_old",default="0",desc="friend_group_id_old",},
			{type="uint64", name="friend_group_id_new",default="0",desc="friend_group_id_new",},

		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_user_relation_change_group",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="myself_id",},
						{kind="i",var="friend_id",},
						{kind="i",var="friend_group_id_old",},
						{kind="i",var="friend_group_id_new",},
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
		define = "struct", name="p_user_relation_change_remark", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="myself_id",default="0",desc="myself_id",},
			{type="uint64", name="friend_id",default="0",desc="friend_id",},
			{type="string", name="friend_remark",default="\"\"",desc="friend_remark",},

		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_user_relation_change_remark",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="myself_id",},
						{kind="i",var="friend_id",},
						{kind="i",var="friend_remark",},
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
		define = "struct", name="p_user_relation_add_apply", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="user_allow_id",default="0",desc="user_allow_id",},
			{type="uint64", name="user_apply_id",default="0",desc="user_apply_id",},
			{type="string", name="user_apply_description",default="\"\"",desc="user_apply_description",},

		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_user_relation_add_apply",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="user_allow_id",},
						{kind="i",var="user_apply_id",},
						{kind="i",var="user_apply_description",},
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
		define = "struct", name="p_user_relation_respond_apply", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="user_allow_id",default="0",desc="user_allow_id",},
			{type="uint64", name="user_apply_id",default="0",desc="user_apply_id",},

		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_user_relation_respond_apply",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="user_allow_id",},
						{kind="i",var="user_apply_id",},
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
		define = "struct", name="p_user_relation_query_friends_apply", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		typedef =
		{
			{type="std::vector<t_user_relation_friend_apply>", name="user_relation_friend_apply_vec",},
		},
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="myself_id",default="0",desc="myself_id",},

			{type="user_relation_friend_apply_vec", name="user_relation_friend_apply_s",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_user_relation_query_friends_apply",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="myself_id",},
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
					container_type = "user_relation_friend_apply_vec",
					container_name = "user_relation_friend_apply_s",
					elem_type = "t_user_relation_friend_apply",
					elem_name = "v",
					key = "v.id",
					variable =
					{
						"v.user_apply_id",
						"v.user_apply_name",
						"v.user_apply_nick",
						"v.user_apply_create_time",
						"v.user_apply_description",
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
