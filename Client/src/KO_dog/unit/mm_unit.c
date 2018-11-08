#include "unit/mm_unit.h"
#include "core/mm_spinlock.h"
//////////////////////////////////////////////////////////////////////////
extern void mm_unit_init(struct mm_unit* p)
{
	p->pool = NULL;
	mm_spinlock_init(&p->locker, NULL);
	p->id = MM_UNIT_INVALID_ID;
	p->u = NULL;
}
extern void mm_unit_destroy(struct mm_unit* p)
{
	p->pool = NULL;
	mm_spinlock_destroy(&p->locker);
	p->id = MM_UNIT_INVALID_ID;
	p->u = NULL;
}
extern void mm_unit_produce(struct mm_unit* p)
{

}

extern void mm_unit_recycle(struct mm_unit* p)
{

}

extern void mm_unit_lock(struct mm_unit* p)
{
	mm_spinlock_lock(&p->locker);
}
extern void mm_unit_unlock(struct mm_unit* p)
{
	mm_spinlock_unlock(&p->locker);
}
extern void mm_unit_assign_context(struct mm_unit* p, void* u)
{
	p->u = u;
}
