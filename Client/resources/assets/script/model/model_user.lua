local logger = require('logger')
local math = require('math')
local pairs = pairs
local print = print
local tostring = tostring
local string = string
----------------------------------------
local modname="model_user"
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
mem_user_info_cfg =
{
	[0] = {title = "我的好友",add = {t="发起会话",v=1,},rmv = {t="移除好友",v=1,},},--current
	[1] = {title = "我的邀请",add = {t="再次邀请",v=1,},rmv = {t="取消邀请",v=1,},},--myinvite
	[2] = {title = "邀请我的",add = {t="同意好友",v=1,},rmv = {t="拒绝好友",v=1,},},--inviteme
	[3] = {title = "好友历史",add = {t="再次邀请",v=1,},rmv = {t="移除记录",v=1,},},--history
	[4] = {title = "自己信息",add = {t="取消操作",v=0,},rmv = {t="取消操作",v=1,},},--self
	[5] = {title = "陌生用户",add = {t="邀请好友",v=1,},rmv = {t="取消操作",v=1,},},--stranger
}
----------------------------------------------
--function
function l_user_info_all(idx)
	local u = mem_user_info_cfg[idx]
	if u then
		return u.title,u.add.t,u.add.v,u.rmv.t,u.rmv.v
	else
		logger.logW(modname..".l_user_info_all idx:"..idx.." is invalid.")
	end
	return "","",0,"",0
end
function l_user_info_config(idx,field)
	local u = mem_user_info_cfg[idx]
	if u then
		local v = u[field]
		if v then
			return v
		else
			logger.logW(modname..".l_user_info_config field:"..field.." is invalid.")
		end
	else
		logger.logW(modname..".l_user_info_config idx:"..idx.." is invalid.")
	end
	return ""
end
function l_user_info_delete_ensure_title()
	return "确定删除好友?"
end
----------------------------------------------
--test
----------------------------------------------
return M
