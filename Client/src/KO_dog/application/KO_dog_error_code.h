#ifndef __KO_dog_error_code_h__
#define __KO_dog_error_code_h__

#include "core/mm_core.h"

#include "toolkit/mm_error_desc.h"

#include "core/mm_prefix.h"
//////////////////////////////////////////////////////////////////////////
enum KO_dog_error_code
{
	KO_dog_error_code_does_remote_login = 600001001,            //(600001001)异地登录

};
//////////////////////////////////////////////////////////////////////////
extern void KO_dog_error_code(struct mm_error_desc* p);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__KO_dog_error_code_h__