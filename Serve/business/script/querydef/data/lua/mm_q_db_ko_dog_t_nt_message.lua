---------------------------------------------
local modname="mm_q_db_ko_dog_t_nt_message"
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
	"\"querydef/mm_m_db_ko_dog_t_nt_message.h\"",
	"<vector>",
}
event =
{
	{
		define = "struct", name="p_nt_message_add", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="user_id",default="0",desc="user_id",},
			{type="uint64", name="to_user_id",default="0",desc="to_user_id",},
			{type="uint32", name="message_mid",default="0",desc="message_mid",},
			{type="string", name="nt_message",default="\"\"",desc="nt_message",},

			{type="uint64", name="note_id",default="0",desc="note_id",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_nt_message_add",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="user_id",},
						{kind="i",var="to_user_id",},
						{kind="i",var="message_mid",},
						{kind="i",var="nt_message",},
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
						"note_id",
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
		define = "struct", name="p_nt_message_delete_by_id", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="note_id",default="0",desc="note_id",},

		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_nt_message_delete_by_id",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="note_id",},
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
		define = "struct", name="p_nt_message_read_by_note_id", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		typedef =
		{
			{type="std::vector<t_nt_message>", name="nt_message_vec",},
		},
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="note_id",default="0",desc="note_id",},

			{type="nt_message_vec", name="nt_message_s",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_nt_message_read_by_note_id",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="note_id",},
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
					container_type = "nt_message_vec",
					container_name = "nt_message_s",
					elem_type = "t_nt_message",
					elem_name = "v",
					key = "v.note_id",
					variable =
					{
						"v.note_id",
						"v.read_state",
						"v.to_user_id",
						"v.user_id",
						"v.message_mid",
						"v.create_time",
						"v.nt_message",
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
		define = "struct", name="p_nt_message_read_by_to_user_id", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		typedef =
		{
			{type="std::vector<t_nt_message>", name="nt_message_vec",},
		},
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="to_user_id",default="0",desc="to_user_id",},

			{type="nt_message_vec", name="nt_message_s",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_nt_message_read_by_to_user_id",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="to_user_id",},
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
					container_type = "nt_message_vec",
					container_name = "nt_message_s",
					elem_type = "t_nt_message",
					elem_name = "v",
					key = "v.note_id",
					variable =
					{
						"v.note_id",
						"v.read_state",
						"v.to_user_id",
						"v.user_id",
						"v.message_mid",
						"v.create_time",
						"v.nt_message",
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
		define = "struct", name="p_nt_message_consume_by_note_id", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="to_user_id",default="0",desc="to_user_id",},
			{type="uint64", name="note_id",default="0",desc="note_id",},

		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_nt_message_consume_by_note_id",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="to_user_id",},
						{kind="i",var="note_id",},
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
		define = "struct", name="p_nt_message_consume_by_max_note_id", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},

			{type="uint64", name="to_user_id",default="0",desc="to_user_id",},
			{type="uint64", name="note_id",default="0",desc="note_id",},

		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_nt_message_consume_by_max_note_id",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="to_user_id",},
						{kind="i",var="note_id",},
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
		define = "struct", name="p_nt_message_regular_clean", KeyH = "2", KeyL = "1",base = "mm_queryer",virtual_base = true,
		attributes =
		{

			{type="uint32", name="unread_day",default="0",desc="unread_day",},
			{type="uint32", name="read_day",default="0",desc="read_day",},

		},
		handler =
		{
			sql =
			{
				{
					function_name = "call db_ko_dog.p_nt_message_regular_clean",fl="(",fr=")",
					variable =
					{
						{kind="i",var="unread_day",},
						{kind="i",var="read_day",},
					},
				},
			},
			output =
			{

			},
		},
	},
}
----------------------------------------------------------------------------------
return M
