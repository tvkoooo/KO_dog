#ifndef __mm_basic_frame_entry_h__
#define __mm_basic_frame_entry_h__

#include "core/mm_core.h"
#include "core/mm_timer.h"

#include "net/mm_headset.h"
#include "net/mm_mailbox.h"

#include "zookeeper/mm_zkrb_path.h"

#include "shuttle_common/mm_loavger_holder.h"
#include "shuttle_common/mm_control_tcp_hd.h"
#include "shuttle_common/mm_error_desc.h"

#include "mm_basic_frame_entry_launch.h"
#include "mm_basic_frame_entry_runtime.h"

#include "core/mm_prefix.h"

// update milliseconds.default is  5 second( 5000 ms).
#define MM_SHUTTLE_ENTRY_MSEC_UPDATE_DT  5000
// launch milliseconds.default is 60 second(60000 ms).
#define MM_SHUTTLE_ENTRY_MSEC_LAUNCH_DB 60000
// commit milliseconds.default is 10 second(10000 ms).
#define MM_SHUTTLE_ENTRY_MSEC_COMMIT_DB 10000
// commit milliseconds.default is 60 second(60000 ms).
#define MM_SHUTTLE_ENTRY_MSEC_COMMIT_ZK 60000

#define MM_SHUTTLE_ENTRY_ZK_IMPORT "/mm_lobby"
#define MM_SHUTTLE_ENTRY_ZK_EXPORT "/mm_entry"

struct mm_basic_frame_entry
{
	struct mm_headset external_headset;// udp
	struct mm_mailbox internal_mailbox;// tcp
	struct mm_timer timer;
	struct mm_basic_frame_entry_launch launch_info;
	struct mm_basic_frame_entry_runtime runtime_info;
	struct mm_loavger_holder loavger_holder;
	struct mm_error_desc error_desc;
	mm_msec_t msec_update_dt;// launch milliseconds.default is MM_SHUTTLE_ENTRY_MSEC_UPDATE_DT.
	mm_msec_t msec_launch_db;// launch milliseconds.default is MM_SHUTTLE_ENTRY_MSEC_LAUNCH_DB.
	mm_msec_t msec_commit_db;// commit milliseconds.default is MM_SHUTTLE_ENTRY_MSEC_COMMIT_DB.
	mm_msec_t msec_commit_zk;// commit milliseconds.default is MM_SHUTTLE_ENTRY_MSEC_COMMIT_ZK.
};
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_entry_init(struct mm_basic_frame_entry* p);
extern void mm_basic_frame_entry_destroy(struct mm_basic_frame_entry* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_entry_assign_unique_id(struct mm_basic_frame_entry* p,mm_uint32_t unique_id);
extern void mm_basic_frame_entry_assign_internal_mailbox_parameters(struct mm_basic_frame_entry* p,const char* parameters);
extern void mm_basic_frame_entry_assign_external_headset_parameters(struct mm_basic_frame_entry* p,const char* parameters);
extern void mm_basic_frame_entry_assign_zookeeper_import_parameters(struct mm_basic_frame_entry* p,const char* parameters);
extern void mm_basic_frame_entry_assign_zookeeper_export_parameters(struct mm_basic_frame_entry* p,const char* parameters);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_entry_start(struct mm_basic_frame_entry* p);
extern void mm_basic_frame_entry_interrupt(struct mm_basic_frame_entry* p);
extern void mm_basic_frame_entry_shutdown(struct mm_basic_frame_entry* p);
extern void mm_basic_frame_entry_join(struct mm_basic_frame_entry* p);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_basic_frame_entry_h__