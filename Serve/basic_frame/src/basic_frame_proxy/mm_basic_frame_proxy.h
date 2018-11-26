#ifndef __mm_basic_frame_proxy_h__
#define __mm_basic_frame_proxy_h__

#include "core/mm_core.h"
#include "core/mm_timer.h"

#include "net/mm_net_udp.h"
#include "net/mm_mailbox.h"
#include "net/mm_mt_contact.h"

#include "zookeeper/mm_zkrb_path.h"

#include "shuttle_common/mm_primacy_holder.h"
#include "shuttle_common/mm_control_tcp_hd.h"
#include "shuttle_common/mm_error_desc.h"

#include "mm_basic_frame_proxy_launch.h"
#include "mm_basic_frame_proxy_runtime.h"

#include "core/mm_prefix.h"

// update milliseconds.default is  5 second( 5000 ms).
#define MM_SHUTTLE_PROXY_MSEC_UPDATE_DT  5000
// launch milliseconds.default is 60 second(60000 ms).
#define MM_SHUTTLE_PROXY_MSEC_LAUNCH_DB 60000
// commit milliseconds.default is 10 second(10000 ms).
#define MM_SHUTTLE_PROXY_MSEC_COMMIT_DB 10000
// commit milliseconds.default is 60 second(60000 ms).
#define MM_SHUTTLE_PROXY_MSEC_COMMIT_ZK 60000

#define MM_SHUTTLE_PROXY_ZK_EXPORT "/mm_proxy"

struct mm_basic_frame_proxy
{
	struct mm_mailbox internal_mailbox;// tcp
	struct mm_timer timer;
	struct mm_basic_frame_proxy_launch launch_info;
	struct mm_basic_frame_proxy_runtime runtime_info;
	struct mm_primacy_holder primacy_holder;
	struct mm_mt_contact contact;
	struct mm_error_desc error_desc;
	mm_msec_t msec_update_dt;// launch milliseconds.default is MM_SHUTTLE_PROXY_MSEC_UPDATE_DT.
	mm_msec_t msec_launch_db;// launch milliseconds.default is MM_SHUTTLE_PROXY_MSEC_LAUNCH_DB.
	mm_msec_t msec_commit_db;// commit milliseconds.default is MM_SHUTTLE_PROXY_MSEC_COMMIT_DB.
	mm_msec_t msec_commit_zk;// commit milliseconds.default is MM_SHUTTLE_PROXY_MSEC_COMMIT_ZK.
};
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_proxy_init(struct mm_basic_frame_proxy* p);
extern void mm_basic_frame_proxy_destroy(struct mm_basic_frame_proxy* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_proxy_assign_unique_id(struct mm_basic_frame_proxy* p,mm_uint32_t unique_id);
//extern void mm_basic_frame_proxy_assign_server_id(struct mm_basic_frame_proxy* p,mm_uint32_t server_id);
extern void mm_basic_frame_proxy_assign_internal_mailbox_parameters(struct mm_basic_frame_proxy* p,const char* parameters);
extern void mm_basic_frame_proxy_assign_zookeeper_import_parameters(struct mm_basic_frame_proxy* p,const char* parameters);
extern void mm_basic_frame_proxy_assign_zookeeper_export_parameters(struct mm_basic_frame_proxy* p,const char* parameters);
extern void mm_basic_frame_proxy_assign_module(struct mm_basic_frame_proxy* p,mm_uint32_t module);
extern void mm_basic_frame_proxy_assign_message_interval(struct mm_basic_frame_proxy* p,const char* mid_l_string,const char* mid_r_string);
extern void mm_basic_frame_proxy_assign_shard(struct mm_basic_frame_proxy* p,mm_uint32_t shard);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_proxy_start(struct mm_basic_frame_proxy* p);
extern void mm_basic_frame_proxy_interrupt(struct mm_basic_frame_proxy* p);
extern void mm_basic_frame_proxy_shutdown(struct mm_basic_frame_proxy* p);
extern void mm_basic_frame_proxy_join(struct mm_basic_frame_proxy* p);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_basic_frame_proxy_h__