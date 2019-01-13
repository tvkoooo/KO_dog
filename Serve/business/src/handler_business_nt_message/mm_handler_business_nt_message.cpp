#include "mm_handler_business_nt_message.h"
#include "core/mm_logger.h"
#include "core/mm_time_cache.h"
#include "core/mm_timer.h"
#include "net/mm_streambuf_packet.h"
#include "net/mm_default_handle.h"

#include "protobuf/mm_protobuff_cxx.h"

#include "shuttle_common/mm_error_code_mysql.h"
#include "shuttle_common/mm_error_code_common.h"

#include "cxx/protodef/s_control.pb.h"

#include "mm_handler_business_nt_message_hd.h"
#include "mm_handler_business_nt_message_message_consume.h"

#include "mm_application.h"

static void __static_hd_consume_array_default_callback(void* obj, void* u, struct mm_packet* pack);

void mm_handler_business_nt_message_init(struct mm_handler_business_nt_message* p)
{
	struct mm_amqp_consume_array_callback default_callback;

	mm_handler_business_nt_message_launch_init(&p->launch_info);
	mm_amqp_consume_array_init(&p->consume_array);
	mm_message_lpusher_init(&p->message_lpusher);
	mm_xoshiro256starstar_init(&p->rabbitmq_password_random);
	mm_db_mysql_config_init(&p->db_sql_config);
	mm_db_mysql_section_init(&p->db_sql_section);
	mm_error_desc_init(&p->error_desc);
	//
	default_callback.handle = &__static_hd_consume_array_default_callback;
	default_callback.obj = p;
	mm_amqp_consume_array_assign_default_callback(&p->consume_array, &default_callback);
	//
	mm_error_desc_assign_core(&p->error_desc);
	mm_error_desc_assign_common(&p->error_desc);
	mm_error_desc_assign_mysql(&p->error_desc);

	mm_string_assigns(&p->db_sql_config.node, "127.0.0.1");
	mm_string_assigns(&p->db_sql_config.username, "tvkoooo");
	mm_string_assigns(&p->db_sql_config.password, "fsf4e%$c34fdt43BR_BDfdhjs8eu");
	mm_string_assigns(&p->db_sql_config.basename, "db_ko_dog");
	p->db_sql_config.port = 3306;
	//
	mm_db_mysql_section_set_config(&p->db_sql_section, &p->db_sql_config);
	//
	mm_protobuf_cxx_init();
}
void mm_handler_business_nt_message_destroy(struct mm_handler_business_nt_message* p)
{
	google::protobuf::ShutdownProtobufLibrary();
	mm_protobuf_cxx_destroy();
	//
	mm_handler_business_nt_message_launch_destroy(&p->launch_info);
	mm_amqp_consume_array_destroy(&p->consume_array);
	mm_message_lpusher_destroy(&p->message_lpusher);
	mm_xoshiro256starstar_destroy(&p->rabbitmq_password_random);
	mm_db_mysql_config_destroy(&p->db_sql_config);
	mm_db_mysql_section_destroy(&p->db_sql_section);
	mm_error_desc_destroy(&p->error_desc);
}
//////////////////////////////////////////////////////////////////////////
void mm_handler_business_nt_message_assign_unique_id(struct mm_handler_business_nt_message* p, mm_uint32_t unique_id)
{
	struct mm_handler_business_nt_message_launch* launch_info = &p->launch_info;
	launch_info->unique_id = unique_id;
}
void mm_handler_business_nt_message_assign_rdb_gateway_queue_parameters(struct mm_handler_business_nt_message* p, const char* parameters)
{
	struct mm_handler_business_nt_message_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->rdb_gateway_queue_parameters, parameters);
}
void mm_handler_business_nt_message_assign_event_queue_rabbitmq_parameters(struct mm_handler_business_nt_message* p, const char* parameters)
{
	struct mm_handler_business_nt_message_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->event_queue_rabbitmq_parameters, parameters);
}
void mm_handler_business_nt_message_assign_queue_name(struct mm_handler_business_nt_message* p, const char* queue_name)
{
	struct mm_handler_business_nt_message_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->queue_name, queue_name);
}
void mm_handler_business_nt_message_assign_rabbitmq_password_seed(struct mm_handler_business_nt_message* p, mm_uint32_t rabbitmq_password_seed)
{
	struct mm_handler_business_nt_message_launch* launch_info = &p->launch_info;
	launch_info->rabbitmq_password_seed = rabbitmq_password_seed;
}
//////////////////////////////////////////////////////////////////////////
void mm_handler_business_nt_message_start(struct mm_handler_business_nt_message* p)
{
	struct mm_handler_business_nt_message_launch* launch_info = &p->launch_info;

	mm_message_lpusher_assign_parameters(&p->message_lpusher, launch_info->rdb_gateway_queue_parameters.s);
	mm_message_lpusher_assign_queue_passwd(&p->message_lpusher, launch_info->rdb_gateway_queue_auth.s);
	mm_message_lpusher_assign_queue_nameky(&p->message_lpusher, launch_info->queue_name.s);

	mm_handler_business_nt_message_message_consume_config(p);

	mm_handler_lobby_hd_register(p);

	mm_amqp_consume_array_start(&p->consume_array);
	mm_message_lpusher_start(&p->message_lpusher);
}
void mm_handler_business_nt_message_interrupt(struct mm_handler_business_nt_message* p)
{
	mm_amqp_consume_array_interrupt(&p->consume_array);
	mm_message_lpusher_interrupt(&p->message_lpusher);
}
void mm_handler_business_nt_message_shutdown(struct mm_handler_business_nt_message* p)
{
	mm_amqp_consume_array_shutdown(&p->consume_array);
	mm_message_lpusher_shutdown(&p->message_lpusher);
}
void mm_handler_business_nt_message_join(struct mm_handler_business_nt_message* p)
{
	mm_amqp_consume_array_join(&p->consume_array);
	mm_message_lpusher_join(&p->message_lpusher);
}
//////////////////////////////////////////////////////////////////////////
static void __static_hd_consume_array_default_callback(void* obj, void* u, struct mm_packet* pack)
{
	struct mm_logger* g_logger = mm_logger_instance();
	mm_logger_log_W(g_logger, "%s %d mid:0x%08X not handle.", __FUNCTION__, __LINE__, pack->phead.mid);
}
