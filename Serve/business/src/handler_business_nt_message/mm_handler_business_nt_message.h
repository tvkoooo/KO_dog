#ifndef __mm_handler_business_nt_message_h__
#define __mm_handler_business_nt_message_h__

#include "core/mm_core.h"
#include "core/mm_timer.h"
#include "dish/mm_error_desc.h"
#include "mysql/mm_db_mysql.h"

#include "random/mm_xoshiro.h"

#include "rabbitmq/mm_amqp_consume_array.h"

#include "shuttle_common/mm_message_lpusher.h"

#include "mm_handler_business_nt_message_launch.h"

#include "core/mm_prefix.h"

#define MM_HANDLER_LOBBY_RABBITMQ_SECRET_LENGTH 16

struct mm_handler_business_nt_message
{
	struct mm_handler_business_nt_message_launch launch_info;
	struct mm_amqp_consume_array consume_array;
	struct mm_message_lpusher message_lpusher;
	struct mm_xoshiro256starstar rabbitmq_password_random;
	struct mm_db_mysql_config db_sql_config;
	struct mm_db_mysql_section db_sql_section;
	struct mm_error_desc error_desc;
};
//////////////////////////////////////////////////////////////////////////
extern void mm_handler_business_nt_message_init(struct mm_handler_business_nt_message* p);
extern void mm_handler_business_nt_message_destroy(struct mm_handler_business_nt_message* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_handler_business_nt_message_assign_unique_id(struct mm_handler_business_nt_message* p, mm_uint32_t unique_id);
extern void mm_handler_business_nt_message_assign_rdb_gateway_queue_parameters(struct mm_handler_business_nt_message* p, const char* parameters);
extern void mm_handler_business_nt_message_assign_event_queue_rabbitmq_parameters(struct mm_handler_business_nt_message* p, const char* parameters);
extern void mm_handler_business_nt_message_assign_queue_name(struct mm_handler_business_nt_message* p, const char* queue_name);
extern void mm_handler_business_nt_message_assign_rabbitmq_password_seed(struct mm_handler_business_nt_message* p, mm_uint32_t rabbitmq_password_seed);
//////////////////////////////////////////////////////////////////////////
extern void mm_handler_business_nt_message_start(struct mm_handler_business_nt_message* p);
extern void mm_handler_business_nt_message_interrupt(struct mm_handler_business_nt_message* p);
extern void mm_handler_business_nt_message_shutdown(struct mm_handler_business_nt_message* p);
extern void mm_handler_business_nt_message_join(struct mm_handler_business_nt_message* p);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_handler_business_nt_message_h__
