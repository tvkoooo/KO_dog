#ifndef __mm_basic_frame_lobby_h__
#define __mm_basic_frame_lobby_h__

#include "core/mm_core.h"
#include "core/mm_timer.h"

#include "net/mm_mailbox.h"

#include "shuttle_common/mm_sharder_holder.h"
#include "shuttle_common/mm_streambuf_array.h"
#include "shuttle_common/mm_error_desc.h"

#include "mm_basic_frame_lobby_launch.h"
#include "mm_basic_frame_lobby_cache.h"
#include "mm_basic_frame_lobby_runtime.h"

#include "core/mm_prefix.h"

// update milliseconds.default is  5 second( 5000 ms).
#define MM_SHUTTLE_LOBBY_MSEC_UPDATE_DT  5000
// launch milliseconds.default is 60 second(60000 ms).
#define MM_SHUTTLE_LOBBY_MSEC_LAUNCH_DB 60000
// commit milliseconds.default is 10 second(10000 ms).
#define MM_SHUTTLE_LOBBY_MSEC_COMMIT_DB 10000
// commit milliseconds.default is 60 second(60000 ms).
#define MM_SHUTTLE_LOBBY_MSEC_COMMIT_ZK 60000

#define MM_SHUTTLE_LOBBY_ZK_IMPORT "/mm_proxy"
#define MM_SHUTTLE_LOBBY_ZK_EXPORT "/mm_lobby"

struct mm_basic_frame_lobby
{
	struct mm_mailbox external_mailbox;
	struct mm_mailbox internal_mailbox;
	struct mm_timer timer;
	struct mm_basic_frame_lobby_launch launch_info;
	struct mm_basic_frame_lobby_runtime runtime_info;
	struct mm_sharder_holder sharder_holder;
	struct mm_basic_frame_lobby_cache db_redis_cache_lobby;
	struct mm_mt_contact contact;
	struct mm_streambuf_array streambuf_array;
	struct mm_error_desc error_desc;
	mm_msec_t msec_update_dt;// launch milliseconds.default is MM_SHUTTLE_LOBBY_MSEC_UPDATE_DT.
	mm_msec_t msec_launch_db;// launch milliseconds.default is MM_SHUTTLE_LOBBY_MSEC_LAUNCH_DB.
	mm_msec_t msec_commit_db;// commit milliseconds.default is MM_SHUTTLE_LOBBY_MSEC_COMMIT_DB.
	mm_msec_t msec_commit_zk;// commit milliseconds.default is MM_SHUTTLE_LOBBY_MSEC_COMMIT_ZK.
};
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_lobby_init(struct mm_basic_frame_lobby* p);
extern void mm_basic_frame_lobby_destroy(struct mm_basic_frame_lobby* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_lobby_assign_unique_id(struct mm_basic_frame_lobby* p,mm_uint32_t unique_id);
extern void mm_basic_frame_lobby_assign_internal_mailbox_parameters(struct mm_basic_frame_lobby* p,const char* parameters);
extern void mm_basic_frame_lobby_assign_external_mailbox_parameters(struct mm_basic_frame_lobby* p,const char* parameters);
extern void mm_basic_frame_lobby_assign_zookeeper_import_parameters(struct mm_basic_frame_lobby* p,const char* parameters);
extern void mm_basic_frame_lobby_assign_zookeeper_export_parameters(struct mm_basic_frame_lobby* p,const char* parameters);
extern void mm_basic_frame_lobby_assign_rdb_account_cache_parameters(struct mm_basic_frame_lobby* p,const char* parameters);
extern void mm_basic_frame_lobby_assign_rdb_gateway_cache_parameters(struct mm_basic_frame_lobby* p,const char* parameters);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_lobby_start(struct mm_basic_frame_lobby* p);
extern void mm_basic_frame_lobby_interrupt(struct mm_basic_frame_lobby* p);
extern void mm_basic_frame_lobby_shutdown(struct mm_basic_frame_lobby* p);
extern void mm_basic_frame_lobby_join(struct mm_basic_frame_lobby* p);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_basic_frame_lobby_h__