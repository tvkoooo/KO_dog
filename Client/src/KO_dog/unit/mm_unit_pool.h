#ifndef __mm_unit_pool_h__
#define __mm_unit_pool_h__

#include "core/mm_config.h"
#include "core/mm_time.h"

#include "container/mm_list_vpt.h"
#include "container/mm_rbtset_vpt.h"

#include "dish/mm_id_generater.h"

#include "unit/mm_unit.h"

#include "core/mm_prefix.h"

#define MM_UNIT_PAGE_SIZE_DEFAULT 10
#define MM_UNIT_FOLD_SIZE_DEFAULT 2
#define MM_UNIT_POOL_SIZE_DEFAULT 4

struct mm_unit_pool
{
	struct mm_uint32_id_generater id_generater;
	struct mm_list_vpt pool;
	struct mm_rbtset_vpt used;
	mm_atomic_t locker_pool;
	size_t page_size;// default is MM_UNIT_PAGE_SIZE_DEFAULT.
	size_t fold_size;// default is MM_UNIT_FOLD_SIZE_DEFAULT.
	size_t pool_size;// default is MM_UNIT_POOL_SIZE_DEFAULT.
};
//////////////////////////////////////////////////////////////////////////
extern void mm_unit_pool_init(struct mm_unit_pool* p);
extern void mm_unit_pool_destroy(struct mm_unit_pool* p);
//////////////////////////////////////////////////////////////////////////
extern struct mm_unit* mm_unit_pool_produce(struct mm_unit_pool* p);
extern void mm_unit_pool_recycle(struct mm_unit_pool* p, struct mm_unit* unit);
//////////////////////////////////////////////////////////////////////////
extern void mm_unit_pool_clear(struct mm_unit_pool* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_unit_pool_try_decrease(struct mm_unit_pool* p);
extern void mm_unit_pool_try_increase(struct mm_unit_pool* p);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"
//////////////////////////////////////////////////////////////////////////
#endif//__mm_unit_pool_h__