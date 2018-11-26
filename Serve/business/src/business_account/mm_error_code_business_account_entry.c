#include "mm_error_code_basic_frame_entry.h"
#include "core/mm_string.h"

//////////////////////////////////////////////////////////////////////////
void mm_error_desc_assign_basic_frame_entry(struct mm_error_desc* p)
{
	mm_error_core_assign_code_desc(p,err_basic_frame_entry_lobby_entry_failure,"lobby entry failure.");
}
//////////////////////////////////////////////////////////////////////////
