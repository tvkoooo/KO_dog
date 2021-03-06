local logger = require("mm/logger")
local math = require('math')
local pairs = pairs
local print = print
local tostring = tostring
local string = string
local pairs = pairs
----------------------------------------
local modname="model_error"
local M={}
_G[modname]=M
package.loaded[modname]=M
if setfenv then
	setfenv(1, M) -- for 5.1
else
	_ENV = M -- for 5.2
end
----------------------------------------------
--member
code_view =
{
	[-1] = "未知错误",
	[0] = "成功",

	[100000001] = "解包失败",
	[100000002] = "打包失败",
	[100000101] = "执行存储过程失败",
	[100000102] = "执行脚本失败",
	[100000103] = "执行命令失败",
	[100000201] = "不支持的模块",
	[100000202] = "不支持的功能",
	[100000203] = "不支持的接口",
	[100000204] = "不支持的操作码",
	[100000301] = "无效的参数",
	[100000302] = "无效的用户号",
	[100000701] = "网络数据库断开连接",
	[100000702] = "网络服务断开连接",
	[100000801] = "系统内存不足",
	[100000901] = "系统输入输出打开文件失败",

	[200000001] = "服务器异常",
	[200000002] = "服务器异常",
	[200000003] = "服务器异常",
	[200000004] = "服务器异常",
	[200000005] = "服务器异常",

	[400000001] = "获取大厅入口数据失败",
	
	[400001001] = "大厅令牌验证失败",
	[400001002] = "大厅服务端秘钥公钥无效",
	[400001003] = "大厅客户端秘钥公钥无效",

	[400100011] = "登陆账号不存在",
	[400100012] = "账号与密码不匹配",
	[400100013] = "注册账号已经存在",
	[400100014] = "你输入带有奇葩字符",
	
	[600001001] = "异地登录",
}
----------------------------------------------
--function
function err_code_view(code)
	local u = code_view[code]
	if u then
		return u
	else
		return "未知错误"
	end
end
----------------------------------------------
--test
function test_func()
	print("111")
	for i, v in pairs(code_view) do
		print("code: "..i.." desc: "..err_code_view(i))
	end

end
----------------------------------------------
return M
