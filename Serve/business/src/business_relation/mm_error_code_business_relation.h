#ifndef __mm_error_code_business_relation_h__
#define __mm_error_code_business_relation_h__

#include "core/mm_core.h"

#include "dish/mm_error_desc.h"

#include "core/mm_prefix.h"
//////////////////////////////////////////////////////////////////////////
enum mm_err_business_relation
{
	err_business_relation_signed_in_relation_does_not_exist = 400100011,            //(400100011)登陆账号不存在
	err_business_relation_signed_in_relation_does_not_match_password = 400100012,   //(400100012)账号与密码不匹配
	err_business_relation_register_relation_already_exists = 400100013,             //(400100013)注册账号已经存在
	err_business_relation_register_illegal_relation_or_password = 400100014,        //(400100014)注册账号或者密码非法
};
//////////////////////////////////////////////////////////////////////////
extern void mm_error_desc_assign_business_relation(struct mm_error_desc* p);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_error_code_business_relation_h__
