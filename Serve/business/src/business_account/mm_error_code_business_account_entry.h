#ifndef __mm_error_code_basic_frame_entry_h__
#define __mm_error_code_basic_frame_entry_h__

#include "core/mm_core.h"

#include "shuttle_common/mm_error_desc.h"

#include "core/mm_prefix.h"
//////////////////////////////////////////////////////////////////////////
enum mm_err_basic_frame_entry
{
	err_basic_frame_entry_lobby_entry_failure = 400000001,//(001)获取大厅入口数据失败
};
//////////////////////////////////////////////////////////////////////////
extern void mm_error_desc_assign_basic_frame_entry(struct mm_error_desc* p);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_error_code_basic_frame_entry_h__