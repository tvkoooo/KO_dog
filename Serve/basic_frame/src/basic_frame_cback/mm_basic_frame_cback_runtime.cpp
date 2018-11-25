#include "mm_basic_frame_cback_runtime.h"
#include "core/mm_logger_manager.h"
#include "core/mm_os_context.h"

#include "shuttle_common/mm_runtime_calculate.h"

#include "mm_basic_frame_cback_launch.h"

void mm_basic_frame_cback_runtime_init(struct mm_basic_frame_cback_runtime* p)
{
	mm_runtime_stat_init(&p->runtime);
	p->launch_info = NULL;
	p->poper_array = NULL;
	// first update.
	mm_runtime_stat_update(&p->runtime);
}
void mm_basic_frame_cback_runtime_destroy(struct mm_basic_frame_cback_runtime* p)
{
	mm_runtime_stat_destroy(&p->runtime);
	p->launch_info = NULL;
	p->poper_array = NULL;
}
void mm_basic_frame_cback_runtime_assign_unique_id(struct mm_basic_frame_cback_runtime* p,mm_uint32_t unique_id)
{
	p->runtime_state.unique_id = unique_id;
}
void mm_basic_frame_cback_runtime_assign_launch_info(struct mm_basic_frame_cback_runtime* p,struct mm_basic_frame_cback_launch* launch_info)
{
	p->launch_info = launch_info;
}
// update runtime value.
void mm_basic_frame_cback_runtime_update_runtime(struct mm_basic_frame_cback_runtime* p)
{
	{
		// update the machine information.
		mm_runtime_stat_update(&p->runtime);
		mm_runtime_state_update(&p->runtime_state, &p->runtime);
	}
}
// commit db.
void mm_basic_frame_cback_runtime_commit_db(struct mm_basic_frame_cback_runtime* p)
{
	// common runtime db.
}
// commit zk.
void mm_basic_frame_cback_runtime_commit_zk(struct mm_basic_frame_cback_runtime* p)
{
	// common runtime zk.
}
