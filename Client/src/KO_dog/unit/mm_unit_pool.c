#include "unit/mm_unit_pool.h"
#include "core/mm_thread.h"
#include "core/mm_logger.h"
#include "core/mm_spinlock.h"

//////////////////////////////////////////////////////////////////////////
extern void mm_unit_pool_init(struct mm_unit_pool* p)
{
	mm_uint32_id_generater_init(&p->id_generater);
	mm_list_vpt_init(&p->pool);
	mm_rbtset_vpt_init(&p->used);
	mm_spinlock_init(&p->locker_pool, NULL);
	p->page_size = MM_UNIT_PAGE_SIZE_DEFAULT;
	p->fold_size = MM_UNIT_FOLD_SIZE_DEFAULT;
	p->pool_size = MM_UNIT_POOL_SIZE_DEFAULT;
}
extern void mm_unit_pool_destroy(struct mm_unit_pool* p)
{
	mm_unit_pool_clear(p);
	//
	mm_uint32_id_generater_destroy(&p->id_generater);
	mm_list_vpt_destroy(&p->pool);
	mm_rbtset_vpt_destroy(&p->used);
	mm_spinlock_destroy(&p->locker_pool);
	p->page_size = MM_UNIT_PAGE_SIZE_DEFAULT;
	p->fold_size = MM_UNIT_FOLD_SIZE_DEFAULT;
	p->pool_size = MM_UNIT_POOL_SIZE_DEFAULT;
}
//////////////////////////////////////////////////////////////////////////
extern struct mm_unit* mm_unit_pool_produce(struct mm_unit_pool* p)
{
	struct mm_unit* unit = NULL;
	mm_unit_pool_try_increase(p);
	mm_spinlock_lock(&p->locker_pool);
	unit = (struct mm_unit*)mm_list_vpt_pop_font(&p->pool);
	mm_rbtset_vpt_add(&p->used, unit);
	mm_spinlock_unlock(&p->locker_pool);
	//
	mm_unit_lock(unit);
	mm_unit_produce(unit);
	mm_unit_unlock(unit);
	return unit;
}
extern void mm_unit_pool_recycle(struct mm_unit_pool* p, struct mm_unit* unit)
{
	mm_unit_lock(unit);
	mm_unit_recycle(unit);
	mm_unit_unlock(unit);
	//
	mm_spinlock_lock(&p->locker_pool);
	mm_rbtset_vpt_rmv(&p->used, unit);
	mm_list_vpt_add_tail(&p->pool, unit);
	mm_spinlock_unlock(&p->locker_pool);
	mm_unit_pool_try_decrease(p);
}
//////////////////////////////////////////////////////////////////////////
extern void mm_unit_pool_clear(struct mm_unit_pool* p)
{
	struct mm_unit* unit = NULL;
	//
	mm_spinlock_lock(&p->locker_pool);
	{
		struct mm_list_head* pos = NULL;
		struct mm_list_vpt_iterator* it = NULL;
		pos = p->pool.l.next;
		while(pos != &p->pool.l)
		{
			struct mm_list_head* curr = pos;
			pos = pos->next;
			it =(struct mm_list_vpt_iterator*)mm_list_entry(curr, struct mm_list_vpt_iterator, n);
			unit = (struct mm_unit*)(it->v);
			mm_unit_lock(unit);
			mm_unit_destroy(unit);
			mm_list_vpt_erase(&p->pool, it);
			mm_uint32_id_generater_recycle(&p->id_generater, unit->id);
			mm_unit_unlock(unit);
			mm_free(unit);
		}
	}
	//
	{
		struct mm_rb_node* n = NULL;
		struct mm_rbtset_vpt_iterator* it = NULL;
		//
		n = mm_rb_first(&p->used.rbt);
		while(NULL != n)
		{
			it = (struct mm_rbtset_vpt_iterator*)mm_rb_entry(n, struct mm_rbtset_vpt_iterator, n);
			n = mm_rb_next(n);
			unit = (struct mm_unit*)(it->k);
			mm_unit_lock(unit);
			mm_unit_destroy(unit);
			mm_rbtset_vpt_erase(&p->used,it);
			mm_uint32_id_generater_recycle(&p->id_generater, unit->id);
			mm_unit_unlock(unit);
			mm_free(unit);
		}
	}
	mm_spinlock_unlock(&p->locker_pool);
}
//////////////////////////////////////////////////////////////////////////
extern void mm_unit_pool_try_decrease(struct mm_unit_pool* p)
{
	if (p->pool.size > p->pool_size * p->page_size)
	{
		size_t i = 0;
		size_t sz = p->fold_size * p->page_size;
		struct mm_unit* unit = NULL;
		mm_spinlock_lock(&p->locker_pool);
		for (i = 0; i < sz ; ++i)
		{
			unit = (struct mm_unit*)mm_list_vpt_pop_font(&p->pool);
			mm_unit_lock(unit);
			mm_uint32_id_generater_recycle(&p->id_generater, unit->id);
			mm_unit_destroy(unit);
			mm_unit_unlock(unit);
			mm_free(unit);
		}
		mm_spinlock_unlock(&p->locker_pool);
	}
}
extern void mm_unit_pool_try_increase(struct mm_unit_pool* p)
{
	if (0 == p->pool.size)
	{
		size_t i = 0;
		struct mm_unit* unit = NULL;
		mm_spinlock_lock(&p->locker_pool);
		for (i = 0 ; i < p->page_size; ++i)
		{
			unit = (struct mm_unit*)mm_malloc(sizeof(struct mm_unit));
			mm_unit_init(unit);
			mm_unit_lock(unit);
			unit->pool = p;
			unit->id = mm_uint32_id_generater_produce(&p->id_generater);
			mm_list_vpt_add_tail(&p->pool, unit);
			mm_unit_unlock(unit);
		}
		mm_spinlock_unlock(&p->locker_pool);
	}
}