#ifndef __mm_business_nt_message_h__
#define __mm_business_nt_message_h__

#include "core/mm_core.h"
#include "core/mm_timer.h"
#include "dish/mm_error_desc.h"
#include "mysql/mm_db_mysql.h"
#include "net/mm_mailbox.h"

#include "zookeeper/mm_zookeeper_zkrb_path.h"

#include "shuttle_common/mm_loavger_holder.h"
#include "shuttle_common/mm_control_tcp_hd.h"
#include "shuttle_common/mm_message_lpusher.h"

#include "random/mm_xoshiro.h"

#include "jwt/mm_jwt_authority.h"


#include "mm_business_nt_message_launch.h"
#include "mm_business_nt_message_runtime.h"



#include "core/mm_prefix.h"

// update milliseconds.default is  5 second( 5000 ms).
#define MM_BUSINESS_MESSAGE_MSEC_UPDATE_DT  5000
// launch milliseconds.default is 60 second(60000 ms).
#define MM_BUSINESS_MESSAGE_MSEC_LAUNCH_DB 60000
// commit milliseconds.default is 10 second(10000 ms).
#define MM_BUSINESS_MESSAGE_MSEC_COMMIT_DB 10000
// commit milliseconds.default is 60 second(60000 ms).
#define MM_BUSINESS_MESSAGE_MSEC_COMMIT_ZK 60000


struct mm_business_nt_message
{
	struct mm_mailbox external_mailbox; // tcp Processing client account logic
	struct mm_mailbox internal_mailbox;// tcp Setting log parameters
	struct mm_timer timer;
	struct mm_business_nt_message_launch launch_info;
	struct mm_business_nt_message_runtime runtime_info;
	struct mm_message_lpusher message_lpusher;
	struct mm_db_mysql_config db_sql_config;
	struct mm_db_mysql_section db_sql_section;
	struct mm_error_desc error_desc;               //¥ÌŒÛ¬Îπ‹¿Ì∆˜

	mm_msec_t msec_update_dt;// launch milliseconds.default is MM_BUSINESS_MESSAGE_MSEC_UPDATE_DT.
	mm_msec_t msec_launch_db;// launch milliseconds.default is MM_BUSINESS_MESSAGE_MSEC_LAUNCH_DB.
	mm_msec_t msec_commit_db;// commit milliseconds.default is MM_BUSINESS_MESSAGE_MSEC_COMMIT_DB.
	mm_msec_t msec_commit_zk;// commit milliseconds.default is MM_BUSINESS_MESSAGE_MSEC_COMMIT_ZK.
};
//////////////////////////////////////////////////////////////////////////
extern void mm_business_nt_message_init(struct mm_business_nt_message* p);
extern void mm_business_nt_message_destroy(struct mm_business_nt_message* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_business_nt_message_assign_unique_id(struct mm_business_nt_message* p,mm_uint32_t unique_id);
extern void mm_business_nt_message_assign_internal_mailbox_parameters(struct mm_business_nt_message* p,const char* parameters);
extern void mm_business_nt_message_assign_external_mailbox_parameters(struct mm_business_nt_message* p,const char* parameters);
extern void mm_business_nt_message_assign_zookeeper_export_parameters(struct mm_business_nt_message* p, const char* parameters);
extern void mm_business_nt_message_assign_module_number(struct mm_business_nt_message* p, mm_uint32_t module_number);
extern void mm_business_nt_message_assign_area_shard(struct mm_business_nt_message* p, mm_uint32_t area_shard);
extern void mm_business_nt_message_assign_area_depth(struct mm_business_nt_message* p, mm_uint32_t area_depth);
//////////////////////////////////////////////////////////////////////////
extern void mm_business_nt_message_start(struct mm_business_nt_message* p);
extern void mm_business_nt_message_interrupt(struct mm_business_nt_message* p);
extern void mm_business_nt_message_shutdown(struct mm_business_nt_message* p);
extern void mm_business_nt_message_join(struct mm_business_nt_message* p);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_business_nt_message_h__
