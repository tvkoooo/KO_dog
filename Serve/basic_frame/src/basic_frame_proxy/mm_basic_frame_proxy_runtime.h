#ifndef __mm_basic_frame_proxy_runtime_h__
#define __mm_basic_frame_proxy_runtime_h__

#include "querydef/mm_q_cobweb_common_runtime.h"

#include "core/mm_core.h"
#include "core/mm_runtime_stat.h"

#include "net/mm_mailbox.h"

#include "zookeeper/mm_zkwm_path.h"

//////////////////////////////////////////////////////////////////////////
struct mm_basic_frame_proxy_runtime
{
	struct mm_runtime_stat runtime;
	struct mm_zkwm_path zkwm_path;

	mm::mm_m_runtime_state runtime_state;
	mm::mm_m_config_module launch_module;

	struct mm_basic_frame_proxy_launch* launch_info;// weak ref.
	struct mm_mailbox* internal_mailbox;// weak ref.
	struct mm_mailbox* external_mailbox;// weak ref.
};
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_proxy_runtime_init(struct mm_basic_frame_proxy_runtime* p);
extern void mm_basic_frame_proxy_runtime_destroy(struct mm_basic_frame_proxy_runtime* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_proxy_runtime_start(struct mm_basic_frame_proxy_runtime* p);
extern void mm_basic_frame_proxy_runtime_interrupt(struct mm_basic_frame_proxy_runtime* p);
extern void mm_basic_frame_proxy_runtime_shutdown(struct mm_basic_frame_proxy_runtime* p);
extern void mm_basic_frame_proxy_runtime_join(struct mm_basic_frame_proxy_runtime* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_proxy_runtime_assign_unique_id(struct mm_basic_frame_proxy_runtime* p,mm_uint32_t unique_id);
extern void mm_basic_frame_proxy_runtime_assign_internal_mailbox(struct mm_basic_frame_proxy_runtime* p,struct mm_mailbox* internal_mailbox);
extern void mm_basic_frame_proxy_runtime_assign_external_mailbox(struct mm_basic_frame_proxy_runtime* p,struct mm_mailbox* external_mailbox);
extern void mm_basic_frame_proxy_runtime_assign_launch_info(struct mm_basic_frame_proxy_runtime* p,struct mm_basic_frame_proxy_launch* launch_info);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_proxy_runtime_assign_zkwm_path(struct mm_basic_frame_proxy_runtime* p,const char* path);
extern void mm_basic_frame_proxy_runtime_assign_zkwm_host(struct mm_basic_frame_proxy_runtime* p,const char* host);
extern void mm_basic_frame_proxy_runtime_assign_number_id(struct mm_basic_frame_proxy_runtime* p,mm_uint64_t number_id);
//////////////////////////////////////////////////////////////////////////
// update runtime value.
extern void mm_basic_frame_proxy_runtime_update_runtime(struct mm_basic_frame_proxy_runtime* p);
// commit db.
extern void mm_basic_frame_proxy_runtime_commit_db(struct mm_basic_frame_proxy_runtime* p);
// commit zk.
extern void mm_basic_frame_proxy_runtime_commit_zk(struct mm_basic_frame_proxy_runtime* p);
//////////////////////////////////////////////////////////////////////////

#endif//__mm_basic_frame_proxy_runtime_h__