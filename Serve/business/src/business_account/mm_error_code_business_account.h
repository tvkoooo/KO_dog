#ifndef __mm_error_code_business_account_h__
#define __mm_error_code_business_account_h__

#include "core/mm_core.h"

#include "shuttle_common/mm_error_desc.h"

#include "core/mm_prefix.h"
//////////////////////////////////////////////////////////////////////////
enum mm_err_business_account
{
	err_business_account_signed_in_account_does_not_exist = 400002011,            //(2011)登陆账号不存在
	err_business_account_signed_in_account_does_not_match_password = 400002012,   //(2012)账号与密码不匹配
	err_business_account_register_account_already_exists = 400002013,             //(2013)注册账号已经存在
	err_business_account_register_illegal_account_or_password = 400002014,        //(2014)注册账号或者密码非法
};
//////////////////////////////////////////////////////////////////////////
extern void mm_error_desc_assign_business_account(struct mm_error_desc* p);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_error_code_business_account_h__