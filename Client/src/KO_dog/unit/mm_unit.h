#ifndef __mm_unit_h__
#define __mm_unit_h__

#include "core/mm_config.h"
#include "core/mm_atomic.h"

#include "core/mm_prefix.h"

#define MM_UNIT_INVALID_ID -1

struct mm_unit_pool;

struct mm_unit
{
	struct mm_unit_pool* pool;
	mm_atomic_t locker;
	mm_uint32_t id;
	void* u;
};
//////////////////////////////////////////////////////////////////////////
extern void mm_unit_init(struct mm_unit* p);
extern void mm_unit_destroy(struct mm_unit* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_unit_produce(struct mm_unit* p);
extern void mm_unit_recycle(struct mm_unit* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_unit_lock(struct mm_unit* p);
extern void mm_unit_unlock(struct mm_unit* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_unit_assign_context(struct mm_unit* p, void* u);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"
//////////////////////////////////////////////////////////////////////////
#endif//__mm_unit_h__