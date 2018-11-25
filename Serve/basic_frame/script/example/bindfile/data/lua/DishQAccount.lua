---------------------------------------------
local modname="DishQAccount"
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
	"\"Database/DishDBMySQLQueryer.h\"",
	"\"Dish/Logger/DishLogger.h\"",
	"\"struct/DishMAccount.h\"",
}
event =
{
	{
		define = "struct", name="AccountGet", KeyH = "2", KeyL = "1",base = "DBMySQLQueryer",virtual_base = true,
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="uint32", name="uid",default="0",desc="id for test",},
			{type="string", name="timecode",       desc="time for test",},
			{type="Account", name="account",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call routine_account_get",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="account.id",},
					},
				},
				{
					function_name = "select",fl=" ",fr=" ",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="account.id",},
					},
				},
				{
					function_name = "now",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="account.id",},
					},
				},
			},
			output =
			{
				{
					variable =
					{
						"account.type",
						"account.username",
						"account.password",
						"account.email",
						"account.sex",
						"account.birthday",
						"account.lasttime",
						"account.createtime",
					},
				},
				{
					variable =
					{
						"code",
					},
				},
				{
					variable =
					{
						"timecode",
					},
				},
			},
		},
	},
	{
		define = "struct", name="AccountVector", KeyH = "2", KeyL = "2",base = "DBMySQLQueryer",virtual_base = true,
		typedef = 
		{
			{type="std::vector<int>", name="IntVec",},
		},
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="uint32", name="uid",default="0",desc="id for test",},
			{type="uint64", name="user_id",},
			{type="IntVec", name="iv",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call routine_account_get",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="user_id",},
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
					container_type = "IntVec",
					container_name = "iv",
					elem_type = "MAccount",
					elem_name = "v",
					key = "v.id",
					variable =
					{
						"v.account.type",
						"v.account.username",
						"v.account.password",
						"v.account.email",
						"v.account.sex",
						"v.account.birthday",
						"v.account.lasttime",
						"v.account.createtime",
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
		define = "struct", name="AccountMap", KeyH = "2", KeyL = "2",base = "DBMySQLQueryer",virtual_base = true,
		typedef = 
		{
			{type="std::map<MAccount>", name="AMap",},
		},
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="uint32", name="uid",default="0",desc="id for test",},
			{type="uint64", name="user_id",},
			{type="AMap", name="am",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call routine_account_get",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="user_id",},
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
					container_kind = "map",
					container_type = "AMap",
					container_name = "am",
					elem_type = "MAccount",
					elem_name = "v",
					key = "v.id",
					variable =
					{
						"v.account.type",
						"v.account.username",
						"v.account.password",
						"v.account.email",
						"v.account.sex",
						"v.account.birthday",
						"v.account.lasttime",
						"v.account.createtime",
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
		define = "struct", name="AccountIntMap", KeyH = "2", KeyL = "2",base = "DBMySQLQueryer",virtual_base = true,
		typedef = 
		{
			{type="std::map<int>", name="IntMap",},
		},
		attributes =
		{
			{type="uint32", name="code",default="0",desc="error code for sql.",},
			{type="uint32", name="uid",default="0",desc="id for test",},
			{type="uint64", name="user_id",},
			{type="IntMap", name="im",},
		},
		handler =
		{
			sql =
			{
				{
					function_name = "call routine_account_get",fl="(",fr=")",
					variable =
					{
						{kind="o",var="code",},
						{kind="i",var="user_id",},
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
					container_kind = "map",
					container_type = "IntMap",
					container_name = "im",
					elem_type = "int",
					elem_name = "v",
					key = "v",
					variable =
					{
						"v",
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
