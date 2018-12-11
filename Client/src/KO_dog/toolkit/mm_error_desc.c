#include "mm_error_desc.h"
#include "core/mm_string.h"

//////////////////////////////////////////////////////////////////////////
void mm_error_desc_init(struct mm_error_desc* p)
{
	struct mm_rbtree_u32_vpt_alloc rbtree_u32_vpt_alloc;

	mm_rbtree_u32_vpt_init(&p->rbtree);

	rbtree_u32_vpt_alloc.alloc = &mm_rbtree_u32_vpt_weak_alloc;
	rbtree_u32_vpt_alloc.relax = &mm_rbtree_u32_vpt_weak_relax;
	rbtree_u32_vpt_alloc.obj = p;
	mm_rbtree_u32_vpt_assign_alloc(&p->rbtree,&rbtree_u32_vpt_alloc);
}
void mm_error_desc_destroy(struct mm_error_desc* p)
{
	// clear first.
	mm_error_desc_clear(p);
	//
	mm_rbtree_u32_vpt_destroy(&p->rbtree);
}
//////////////////////////////////////////////////////////////////////////
void mm_error_desc_clear(struct mm_error_desc* p)
{
	struct mm_rb_node* n = NULL;
	struct mm_rbtree_u32_vpt_iterator* it = NULL;
	struct mm_string* e = NULL;
	n = mm_rb_first(&p->rbtree.rbt);
	while(n)
	{
		it = (struct mm_rbtree_u32_vpt_iterator*)mm_rb_entry(n, struct mm_rbtree_u32_vpt_iterator, n);
		n = mm_rb_next(n);
		e = (struct mm_string*)(it->v);
		mm_string_destroy(e);
		mm_free(e);
	}
}
//////////////////////////////////////////////////////////////////////////
const char* mm_error_desc_string(struct mm_error_desc* p, int code)
{
	struct mm_string* desc_string = (struct mm_string*)mm_rbtree_u32_vpt_get(&p->rbtree,code);
	if ( NULL == desc_string )
	{
		return mm_error_desc_unknown();
	}
	else
	{
		return desc_string->s;
	}
}
// use the code cache current code -> desc.
void mm_error_desc_cache_result(struct mm_error_desc* p, int code)
{
	p->code = code;
	mm_string_assigns(&p->desc, mm_error_desc_string(p, p->code));
}
void mm_error_core_assign_code_desc(struct mm_error_desc* p, int code, const char* desc)
{
	struct mm_string* desc_string = (struct mm_string*)mm_rbtree_u32_vpt_get(&p->rbtree,code);
	if ( NULL == desc_string )
	{
		desc_string = (struct mm_string*)mm_malloc(sizeof(struct mm_string));
		mm_string_init(desc_string);
		mm_string_assigns(desc_string,desc);
		mm_rbtree_u32_vpt_set(&p->rbtree,code,desc_string);
	}
	else
	{
		mm_string_assigns(desc_string,desc);
	}
}
//////////////////////////////////////////////////////////////////////////
const char* mm_error_desc_unknown()
{
	return "unknown error.";
}
//////////////////////////////////////////////////////////////////////////
