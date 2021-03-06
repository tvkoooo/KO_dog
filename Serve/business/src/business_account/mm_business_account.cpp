#include "mm_business_account.h"
#include "core/mm_logger.h"
#include "core/mm_time_cache.h"
#include "core/mm_timer.h"

#include "net/mm_streambuf_packet.h"
#include "net/mm_default_handle.h"

#include "shuttle_common/mm_error_code_mysql.h"
#include "shuttle_common/mm_error_code_common.h"
#include "shuttle_common/mm_error_code_core.h"
#include "shuttle_common/mm_runtime_calculate.h"
#include "shuttle_common/mm_modules_runtime.h"

#include "protobuf/mm_protobuff_cxx.h"
#include "protodef/cxx/protodef/s_control.pb.h"
#include "protodef/cxx/protodef/c_business_account.pb.h"

#include "mm_business_account_tcp_hd.h"
#include "mm_error_code_business_account.h"

//////////////////////////////////////////////////////////////////////////
static void __static_mm_business_account_msec_update_dt_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_business_account_msec_launch_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_business_account_msec_commit_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_business_account_msec_commit_zk_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
//////////////////////////////////////////////////////////////////////////
void mm_business_account_init(struct mm_business_account* p)
{
	struct mm_mailbox_callback external_mailbox_callback;
	struct mm_mailbox_callback internal_mailbox_callback;

	mm_mailbox_init(&p->external_mailbox);
	mm_mailbox_init(&p->internal_mailbox);
	mm_timer_init(&p->timer);
	mm_business_account_launch_init(&p->launch_info);
	mm_business_account_runtime_init(&p->runtime_info);
	mm_db_mysql_config_init(&p->db_sql_config);
	mm_db_mysql_section_init(&p->db_sql_section);
	mm_error_desc_init(&p->error_desc);
	mm_jwt_authority_array_init(&p->jwt_authority_array);

	p->msec_update_dt = MM_BUSINESS_ACCOUNT_MSEC_UPDATE_DT;
	p->msec_launch_db = MM_BUSINESS_ACCOUNT_MSEC_LAUNCH_DB;
	p->msec_commit_db = MM_BUSINESS_ACCOUNT_MSEC_COMMIT_DB;
	p->msec_commit_zk = MM_BUSINESS_ACCOUNT_MSEC_COMMIT_ZK;

	external_mailbox_callback.handle = &mm_mailbox_handle_default;
	external_mailbox_callback.broken = &mm_mailbox_broken_default;
	external_mailbox_callback.nready = &mm_mailbox_nready_default;
	external_mailbox_callback.finish = &mm_mailbox_finish_default;
	external_mailbox_callback.obj = p;
	mm_mailbox_assign_mailbox_callback(&p->external_mailbox,&external_mailbox_callback);

	internal_mailbox_callback.handle = &mm_mailbox_handle_default;
	internal_mailbox_callback.broken = &mm_mailbox_broken_default;
	internal_mailbox_callback.nready = &mm_mailbox_nready_default;
	internal_mailbox_callback.finish = &mm_mailbox_finish_default;
	internal_mailbox_callback.obj = p;
	mm_mailbox_assign_mailbox_callback(&p->internal_mailbox,&internal_mailbox_callback);

	mm_mailbox_assign_context(&p->internal_mailbox,p);
	mm_mailbox_assign_context(&p->external_mailbox,p);

	mm_error_desc_assign_core(&p->error_desc);
	mm_error_desc_assign_common(&p->error_desc);
	mm_error_desc_assign_mysql(&p->error_desc);
	mm_error_desc_assign_business_account(&p->error_desc);
	//
	mm_business_account_runtime_assign_launch_info(&p->runtime_info,&p->launch_info);
	mm_business_account_runtime_assign_internal_mailbox(&p->runtime_info,&p->internal_mailbox);
	mm_business_account_runtime_assign_external_mailbox(&p->runtime_info,&p->external_mailbox);
	//
	mm_string_assigns(&p->db_sql_config.node, "127.0.0.1");
	mm_string_assigns(&p->db_sql_config.username, "tvkoooo");
	mm_string_assigns(&p->db_sql_config.password, "fsf4e%$c34fdt43BR_BDfdhjs8eu");
	mm_string_assigns(&p->db_sql_config.basename, "db_ko_dog");
	p->db_sql_config.port = 3306;
	//
	mm_db_mysql_section_set_config(&p->db_sql_section, &p->db_sql_config);
	//
	mm_timer_schedule(&p->timer, 10, p->msec_update_dt, &__static_mm_business_account_msec_update_dt_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_launch_db, &__static_mm_business_account_msec_launch_db_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_commit_db, &__static_mm_business_account_msec_commit_db_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_commit_zk, &__static_mm_business_account_msec_commit_zk_handle, p);
	//
	mm_protobuf_cxx_init();
	//初始化随机数种子
	srand((int)time(NULL));
}
void mm_business_account_destroy(struct mm_business_account* p)
{
	google::protobuf::ShutdownProtobufLibrary();
	mm_protobuf_cxx_destroy();
	//
	mm_mailbox_destroy(&p->external_mailbox);
	mm_mailbox_destroy(&p->internal_mailbox);
	mm_timer_destroy(&p->timer);
	mm_business_account_launch_destroy(&p->launch_info);
	mm_business_account_runtime_destroy(&p->runtime_info);
	mm_db_mysql_config_destroy(&p->db_sql_config);
	mm_db_mysql_section_destroy(&p->db_sql_section);
	mm_error_desc_destroy(&p->error_desc);
	mm_jwt_authority_array_destroy(&p->jwt_authority_array);

	p->msec_update_dt = MM_BUSINESS_ACCOUNT_MSEC_UPDATE_DT;
	p->msec_launch_db = MM_BUSINESS_ACCOUNT_MSEC_LAUNCH_DB;
	p->msec_commit_db = MM_BUSINESS_ACCOUNT_MSEC_COMMIT_DB;
	p->msec_commit_zk = MM_BUSINESS_ACCOUNT_MSEC_COMMIT_ZK;
}
//////////////////////////////////////////////////////////////////////////
void mm_business_account_assign_unique_id(struct mm_business_account* p,mm_uint32_t unique_id)
{
	struct mm_business_account_launch* launch_info = &p->launch_info;
	launch_info->unique_id = unique_id;
}
void mm_business_account_assign_internal_mailbox_parameters(struct mm_business_account* p,const char* parameters)
{
	struct mm_business_account_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->internal_mailbox_parameters, parameters);
}
void mm_business_account_assign_external_mailbox_parameters(struct mm_business_account* p,const char* parameters)
{
	struct mm_business_account_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->external_mailbox_parameters, parameters);
}
void mm_business_account_assign_zookeeper_export_parameters(struct mm_business_account* p,const char* parameters)
{
	struct mm_business_account_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->zookeeper_export_parameters, parameters);
}
void mm_business_account_assign_module_number(struct mm_business_account* p, mm_uint32_t module_number)
{
	struct mm_business_account_launch* launch_info = &p->launch_info;
	launch_info->module_number = module_number;
}
void mm_business_account_assign_area_shard(struct mm_business_account* p, mm_uint32_t area_shard)
{
	struct mm_business_account_launch* launch_info = &p->launch_info;
	launch_info->area_shard = area_shard;
}
void mm_business_account_assign_area_depth(struct mm_business_account* p, mm_uint32_t area_depth)
{
	struct mm_business_account_launch* launch_info = &p->launch_info;
	launch_info->area_depth = area_depth;
}
void mm_business_account_assign_token_seed(struct mm_business_account* p, mm_uint32_t token_seed)
{
	struct mm_business_account_launch* launch_info = &p->launch_info;
	launch_info->token_seed = token_seed;
}
//////////////////////////////////////////////////////////////////////////
void mm_business_account_start(struct mm_business_account* p)
{
	char module_path[64] = { 0 };
	struct mm_business_account_launch* launch_info = &p->launch_info;
	// pull launcher config.
	//////////////////////////////////////////////////////////////////////////
	mm_business_account_launch_printf_information(&p->launch_info);
	//////////////////////////////////////////////////////////////////////////
	mm_modules_runtime_module_path(launch_info->module_number, module_path);
	mm_business_account_runtime_assign_parameters(&p->runtime_info,launch_info->unique_id, launch_info->area_shard, launch_info->area_depth);
	mm_mailbox_assign_parameters(&p->internal_mailbox, launch_info->internal_mailbox_parameters.s);
	mm_mailbox_assign_parameters(&p->external_mailbox, launch_info->external_mailbox_parameters.s);
	mm_business_account_runtime_assign_zkwb_host(&p->runtime_info, launch_info->zookeeper_export_parameters.s);
	//////////////////////////////////////////////////////////////////////////
	// assign callback
	mm_mailbox_assign_callback(&p->internal_mailbox,s_control::set_logger_rq_msg_id   ,&hd_s_control_set_logger_rq);
	mm_mailbox_assign_callback(&p->internal_mailbox,s_control::get_logger_rq_msg_id   ,&hd_s_control_get_logger_rq);

	mm_mailbox_assign_callback(&p->external_mailbox, c_business_account::signed_in_rq_msg_id, &mm_business_account_tcp_hd_c_business_account_signed_in_rq);
	mm_mailbox_assign_callback(&p->external_mailbox, c_business_account::register_rq_msg_id, &mm_business_account_tcp_hd_c_business_account_register_rq);
	//////////////////////////////////////////////////////////////////////////
	mm_business_account_runtime_assign_zkwb_path(&p->runtime_info, module_path);
	// random token buffer.
	mm_jwt_authority_array_assign_token_seed(&p->jwt_authority_array, p->launch_info.token_seed);
	mm_jwt_authority_array_assign_secret_length(&p->jwt_authority_array, MM_BUSINESS_ACCOUNT_JWT_SECRET_LENGTH);

	//////////////////////////////////////////////////////////////////////////
	// start headset.
	mm_mailbox_fopen_socket(&p->external_mailbox);
	mm_mailbox_bind(&p->external_mailbox);
	mm_mailbox_listen(&p->external_mailbox);
	mm_mailbox_start(&p->external_mailbox);
	// start mailbox.
	mm_mailbox_fopen_socket(&p->internal_mailbox);
	mm_mailbox_bind(&p->internal_mailbox);
	mm_mailbox_listen(&p->internal_mailbox);
	mm_mailbox_start(&p->internal_mailbox);
	// start
	mm_timer_start(&p->timer);
	//
	mm_business_account_runtime_start(&p->runtime_info);
}
void mm_business_account_interrupt(struct mm_business_account* p)
{
	mm_mailbox_interrupt(&p->external_mailbox);
	mm_mailbox_interrupt(&p->internal_mailbox);
	mm_timer_interrupt(&p->timer);
	mm_business_account_runtime_interrupt(&p->runtime_info);
}
void mm_business_account_shutdown(struct mm_business_account* p)
{
	mm_mailbox_shutdown(&p->external_mailbox);
	mm_mailbox_shutdown(&p->internal_mailbox);
	mm_timer_shutdown(&p->timer);
	mm_business_account_runtime_shutdown(&p->runtime_info);
}
void mm_business_account_join(struct mm_business_account* p)
{
	mm_mailbox_join(&p->external_mailbox);
	mm_mailbox_join(&p->internal_mailbox);
	mm_timer_join(&p->timer);
	mm_business_account_runtime_join(&p->runtime_info);
}
//////////////////////////////////////////////////////////////////////////
static void __static_mm_business_account_msec_update_dt_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_business_account* business_account = (struct mm_business_account*)(entry->callback.obj);
	mm_business_account_runtime_update_runtime(&business_account->runtime_info);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_business_account_msec_launch_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_business_account_msec_commit_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_business_account* business_account = (struct mm_business_account*)(entry->callback.obj);
	mm_business_account_runtime_commit_db(&business_account->runtime_info);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_business_account_msec_commit_zk_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_business_account* business_account = (struct mm_business_account*)(entry->callback.obj);
	mm_business_account_runtime_commit_zk(&business_account->runtime_info);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
//////////////////////////////////////////////////////////////////////////