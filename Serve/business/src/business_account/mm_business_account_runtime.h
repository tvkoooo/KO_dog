#ifndef __mm_business_account_runtime_h__
#define __mm_business_account_runtime_h__

#include "core/mm_core.h"
#include "core/mm_runtime_stat.h"

#include "net/mm_mailbox.h"
#include "net/mm_headset.h"

#include "dish/mm_m_runtime_state.h"

#include "zookeeper/mm_zookeeper_zkwp_path.h"

//////////////////////////////////////////////////////////////////////////
struct mm_business_account_runtime
{
	struct mm_runtime_stat runtime;
	struct mm_zkwp_path zkwp_path;

	mm::mm_m_runtime_state runtime_state;

	struct mm_business_account_launch* launch_info;// weak ref.
	struct mm_mailbox* internal_mailbox;// weak ref.
	struct mm_mailbox* external_mailbox;// weak ref.
};
//////////////////////////////////////////////////////////////////////////
extern void mm_business_account_runtime_init(struct mm_business_account_runtime* p);
extern void mm_business_account_runtime_destroy(struct mm_business_account_runtime* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_business_account_runtime_start(struct mm_business_account_runtime* p);
extern void mm_business_account_runtime_interrupt(struct mm_business_account_runtime* p);
extern void mm_business_account_runtime_shutdown(struct mm_business_account_runtime* p);
extern void mm_business_account_runtime_join(struct mm_business_account_runtime* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_business_account_runtime_assign_parameters(struct mm_business_account_runtime* p,mm_uint32_t unique_id ,mm_uint32_t shard, mm_uint32_t depth);
extern void mm_business_account_runtime_assign_launch_info(struct mm_business_account_runtime* p,struct mm_business_account_launch* launch_info);
extern void mm_business_account_runtime_assign_internal_mailbox(struct mm_business_account_runtime* p,struct mm_mailbox* internal_mailbox);
extern void mm_business_account_runtime_assign_external_mailbox(struct mm_business_account_runtime* p,struct mm_mailbox* external_mailbox);
//////////////////////////////////////////////////////////////////////////
extern void mm_business_account_runtime_assign_zkwb_path(struct mm_business_account_runtime* p,const char* path);
extern void mm_business_account_runtime_assign_zkwb_host(struct mm_business_account_runtime* p,const char* host);
//////////////////////////////////////////////////////////////////////////
// update runtime value.
extern void mm_business_account_runtime_update_runtime(struct mm_business_account_runtime* p);
// commit db.
extern void mm_business_account_runtime_commit_db(struct mm_business_account_runtime* p);
// commit zk.
extern void mm_business_account_runtime_commit_zk(struct mm_business_account_runtime* p);
//////////////////////////////////////////////////////////////////////////

#endif//__mm_business_account_runtime_h__