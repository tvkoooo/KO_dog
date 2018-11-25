#ifndef __mm_basic_frame_cback_h__
#define __mm_basic_frame_cback_h__

#include "core/mm_core.h"
#include "core/mm_timer.h"

#include "net/mm_net_udp.h"
#include "net/mm_mailbox.h"
#include "net/mm_mt_contact.h"

#include "mm_basic_frame_cback_launch.h"
#include "mm_basic_frame_cback_runtime.h"

#include "shuttle_common/mm_loavger_holder.h"
#include "shuttle_common/mm_control_tcp_hd.h"
#include "shuttle_common/mm_streambuf_array.h"
#include "shuttle_common/mm_error_desc.h"

#include "zookeeper/mm_zkrb_path.h"

#include "redis/mm_redis_sync_array.h"
#include "redis/mm_redis_poper_array.h"

#include "core/mm_prefix.h"

// update milliseconds.default is  5 second( 5000 ms).
#define MM_SHUTTLE_CBACK_MSEC_UPDATE_DT  5000
// launch milliseconds.default is 60 second(60000 ms).
#define MM_SHUTTLE_CBACK_MSEC_LAUNCH_DB 60000
// commit milliseconds.default is 10 second(10000 ms).
#define MM_SHUTTLE_CBACK_MSEC_COMMIT_DB 10000
// commit milliseconds.default is 60 second(60000 ms).
#define MM_SHUTTLE_CBACK_MSEC_COMMIT_ZK 60000

#define MM_SHUTTLE_CBACK_ZK_IMPORT "/mm_lobby"

struct mm_basic_frame_cback
{
	struct mm_timer timer;
	struct mm_basic_frame_cback_launch launch_info;
	struct mm_basic_frame_cback_runtime runtime_info;
	struct mm_loavger_holder loavger_holder;
	struct mm_redis_sync_array db_redis_cache_cback;
	struct mm_redis_poper_array db_redis_poper_cback;
	struct mm_mt_contact contact;
	struct mm_streambuf_array streambuf_array;
	struct mm_error_desc error_desc;
	mm_msec_t msec_update_dt;// update milliseconds.default is MM_SHUTTLE_CBACK_MSEC_UPDATE_DT.
	mm_msec_t msec_launch_db;// launch milliseconds.default is MM_SHUTTLE_CBACK_MSEC_LAUNCH_DB.
	mm_msec_t msec_commit_db;// commit milliseconds.default is MM_SHUTTLE_CBACK_MSEC_COMMIT_DB.
	mm_msec_t msec_commit_zk;// commit milliseconds.default is MM_SHUTTLE_CBACK_MSEC_COMMIT_ZK.
};
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_cback_init(struct mm_basic_frame_cback* p);
extern void mm_basic_frame_cback_destroy(struct mm_basic_frame_cback* p);
//////////////////////////////////////////////////////////////////////////
//"./mm_basic_frame_cback",
//"./log",
//"7",
//"1",
//"1",
//"192.168.111.123-65535",
//"192.168.111.123-65535[2]",
//"vnc:queue:link:cback:000",
//"rpop",
extern void mm_basic_frame_cback_assign_unique_id(struct mm_basic_frame_cback* p,mm_uint32_t unique_id);
extern void mm_basic_frame_cback_assign_server_id(struct mm_basic_frame_cback* p,mm_uint32_t server_id);
extern void mm_basic_frame_cback_assign_rdb_account_cache_parameters(struct mm_basic_frame_cback* p,const char* parameters);
extern void mm_basic_frame_cback_assign_rdb_message_queue_parameters(struct mm_basic_frame_cback* p,const char* parameters);
extern void mm_basic_frame_cback_assign_queue_name(struct mm_basic_frame_cback* p,const char* queue_name);
extern void mm_basic_frame_cback_assign_queue_pop_mode(struct mm_basic_frame_cback* p,const char* pop_mode);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_cback_start(struct mm_basic_frame_cback* p);
extern void mm_basic_frame_cback_interrupt(struct mm_basic_frame_cback* p);
extern void mm_basic_frame_cback_shutdown(struct mm_basic_frame_cback* p);
extern void mm_basic_frame_cback_join(struct mm_basic_frame_cback* p);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_basic_frame_cback_h__