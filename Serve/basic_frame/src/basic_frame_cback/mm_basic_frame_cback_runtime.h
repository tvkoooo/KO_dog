#ifndef __mm_basic_frame_cback_runtime_h__
#define __mm_basic_frame_cback_runtime_h__

#include "core/mm_core.h"
#include "core/mm_runtime_stat.h"

#include "net/mm_mailbox.h"

#include "dish/mm_m_runtime_state.h"

#include "zookeeper/mm_zkwb_path.h"

#include "redis/mm_redis_poper_array.h"

//////////////////////////////////////////////////////////////////////////
struct mm_basic_frame_cback_runtime
{
	struct mm_runtime_stat runtime;
	mm::mm_m_runtime_state runtime_state;

	struct mm_basic_frame_cback_launch* launch_info;// weak ref.
	struct mm_redis_poper_array* poper_array;// weak ref.
};
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_cback_runtime_init(struct mm_basic_frame_cback_runtime* p);
extern void mm_basic_frame_cback_runtime_destroy(struct mm_basic_frame_cback_runtime* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_cback_runtime_assign_unique_id(struct mm_basic_frame_cback_runtime* p,mm_uint32_t unique_id);
extern void mm_basic_frame_cback_runtime_assign_launch_info(struct mm_basic_frame_cback_runtime* p,struct mm_basic_frame_cback_launch* launch_info);
//////////////////////////////////////////////////////////////////////////
// update runtime value.
extern void mm_basic_frame_cback_runtime_update_runtime(struct mm_basic_frame_cback_runtime* p);
// commit db.
extern void mm_basic_frame_cback_runtime_commit_db(struct mm_basic_frame_cback_runtime* p);
// commit zk.
extern void mm_basic_frame_cback_runtime_commit_zk(struct mm_basic_frame_cback_runtime* p);
//////////////////////////////////////////////////////////////////////////

#endif//__mm_basic_frame_cback_runtime_h__