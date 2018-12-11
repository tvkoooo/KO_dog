#ifndef __mm_error_desc_h__
#define __mm_error_desc_h__

#include "core/mm_core.h"

#include "container/mm_rbtree_u32.h"

#include "core/mm_prefix.h"
//////////////////////////////////////////////////////////////////////////
struct mm_error_desc
{
	struct mm_rbtree_u32_vpt rbtree;
	struct mm_string desc;// cache for error desc.
	mm_uint32_t code;// cache for error code.
};
//////////////////////////////////////////////////////////////////////////
extern void mm_error_desc_init(struct mm_error_desc* p);
extern void mm_error_desc_destroy(struct mm_error_desc* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_error_desc_clear(struct mm_error_desc* p);
//////////////////////////////////////////////////////////////////////////
extern const char* mm_error_desc_string(struct mm_error_desc* p, int code);
// use the code cache current code -> desc.
extern void mm_error_desc_cache_result(struct mm_error_desc* p, int code);
//////////////////////////////////////////////////////////////////////////
extern void mm_error_core_assign_code_desc(struct mm_error_desc* p, int code, const char* desc);
//////////////////////////////////////////////////////////////////////////
extern const char* mm_error_desc_unknown();
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_error_desc_h__