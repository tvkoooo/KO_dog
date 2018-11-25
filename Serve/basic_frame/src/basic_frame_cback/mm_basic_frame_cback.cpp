#include "mm_basic_frame_cback.h"

#include "core/mm_logger.h"
#include "core/mm_time_cache.h"
#include "core/mm_timer.h"
#include "core/mm_logger_manager.h"

#include "net/mm_streambuf_packet.h"
#include "net/mm_default_handle.h"

#include "dish/mm_json.h"

#include "protobuf/mm_protobuff_cxx.h"

#include "shuttle_common/mm_error_code_mysql.h"
#include "shuttle_common/mm_error_code_common.h"
#include "shuttle_common/mm_error_code_core.h"
#include "shuttle_common/mm_runtime_calculate.h"

#include "protodef/cxx/protodef/s_control.pb.h"

#include "mm_basic_frame_cback_poper_hd.h"

//////////////////////////////////////////////////////////////////////////
static void __static_mm_basic_frame_cback_msec_update_dt_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_basic_frame_cback_msec_launch_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_basic_frame_cback_msec_commit_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_basic_frame_cback_msec_commit_zk_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);

static void __static_basic_frame_cback_event_mt_tcp_alloc( void* p, struct mm_mt_tcp* mt_tcp );
static void __static_basic_frame_cback_event_mt_tcp_relax( void* p, struct mm_mt_tcp* mt_tcp );
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_cback_init(struct mm_basic_frame_cback* p)
{
	struct mm_redis_poper_callback poper_callback;
	struct mm_mt_contact_event_mt_tcp_alloc contact_callback;

	mm_timer_init(&p->timer);
	mm_basic_frame_cback_launch_init(&p->launch_info);
	mm_basic_frame_cback_runtime_init(&p->runtime_info);
	mm_loavger_holder_init(&p->loavger_holder);
	mm_redis_sync_array_init(&p->db_redis_cache_cback);
	mm_redis_poper_array_init(&p->db_redis_poper_cback);
	mm_mt_contact_init(&p->contact);
	mm_streambuf_array_init(&p->streambuf_array);
	mm_error_desc_init(&p->error_desc);

	// the max thread mm_streambuf thread instance is 3;
	mm_streambuf_array_set_length(&p->streambuf_array, 3);

	p->msec_update_dt = MM_SHUTTLE_CBACK_MSEC_UPDATE_DT;
	p->msec_launch_db = MM_SHUTTLE_CBACK_MSEC_LAUNCH_DB;
	p->msec_commit_db = MM_SHUTTLE_CBACK_MSEC_COMMIT_DB;
	p->msec_commit_zk = MM_SHUTTLE_CBACK_MSEC_COMMIT_ZK;

	poper_callback.poper = &mm_basic_frame_cback_redis_poper_hd;
	poper_callback.obj = p;
	mm_redis_poper_array_assign_callback(&p->db_redis_poper_cback,&poper_callback);

	contact_callback.event_mt_tcp_alloc = &__static_basic_frame_cback_event_mt_tcp_alloc;
	contact_callback.event_mt_tcp_relax = &__static_basic_frame_cback_event_mt_tcp_relax;
	contact_callback.obj = p;
	mm_mt_contact_assign_event_mt_tcp_alloc(&p->contact,&contact_callback);

	mm_redis_poper_array_assign_context(&p->db_redis_poper_cback,p);
	mm_mt_contact_assign_context(&p->contact,p);

	mm_error_desc_assign_core(&p->error_desc);
	mm_error_desc_assign_common(&p->error_desc);
	//
	mm_basic_frame_cback_runtime_assign_launch_info(&p->runtime_info,&p->launch_info);
	//
	mm_redis_poper_array_assign_cmd(&p->db_redis_poper_cback,"brpop");
	//
	mm_timer_schedule(&p->timer, 10, p->msec_update_dt, &__static_mm_basic_frame_cback_msec_update_dt_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_launch_db, &__static_mm_basic_frame_cback_msec_launch_db_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_commit_db, &__static_mm_basic_frame_cback_msec_commit_db_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_commit_zk, &__static_mm_basic_frame_cback_msec_commit_zk_handle, p);
	//
	mm_protobuf_cxx_init();
}
void mm_basic_frame_cback_destroy(struct mm_basic_frame_cback* p)
{
	google::protobuf::ShutdownProtobufLibrary();
	mm_protobuf_cxx_destroy();
	//
	mm_timer_destroy(&p->timer);
	mm_basic_frame_cback_launch_destroy(&p->launch_info);
	mm_basic_frame_cback_runtime_destroy(&p->runtime_info);
	mm_loavger_holder_destroy(&p->loavger_holder);
	mm_redis_sync_array_destroy(&p->db_redis_cache_cback);
	mm_redis_poper_array_destroy(&p->db_redis_poper_cback);
	mm_mt_contact_destroy(&p->contact);
	mm_streambuf_array_destroy(&p->streambuf_array);
	mm_error_desc_destroy(&p->error_desc);

	p->msec_update_dt = MM_SHUTTLE_CBACK_MSEC_UPDATE_DT;
	p->msec_launch_db = MM_SHUTTLE_CBACK_MSEC_LAUNCH_DB;
	p->msec_commit_db = MM_SHUTTLE_CBACK_MSEC_COMMIT_DB;
	p->msec_commit_zk = MM_SHUTTLE_CBACK_MSEC_COMMIT_ZK;
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_cback_assign_unique_id(struct mm_basic_frame_cback* p,mm_uint32_t unique_id)
{
	struct mm_basic_frame_cback_launch* launch_info = &p->launch_info;
	launch_info->unique_id = unique_id;
}
void mm_basic_frame_cback_assign_server_id(struct mm_basic_frame_cback* p,mm_uint32_t server_id)
{
	struct mm_basic_frame_cback_launch* launch_info = &p->launch_info;
	launch_info->server_id = server_id;
}
void mm_basic_frame_cback_assign_rdb_account_cache_parameters(struct mm_basic_frame_cback* p,const char* parameters)
{
	struct mm_basic_frame_cback_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->rdb_account_cache_parameters, parameters);
}
void mm_basic_frame_cback_assign_rdb_message_queue_parameters(struct mm_basic_frame_cback* p,const char* parameters)
{
	struct mm_basic_frame_cback_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->rdb_message_queue_parameters, parameters);
}
void mm_basic_frame_cback_assign_queue_name(struct mm_basic_frame_cback* p,const char* queue_name)
{
	struct mm_basic_frame_cback_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->queue_name, queue_name);
}
void mm_basic_frame_cback_assign_queue_pop_mode(struct mm_basic_frame_cback* p,const char* pop_mode)
{
	struct mm_basic_frame_cback_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->queue_pop_mode, pop_mode);
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_cback_start(struct mm_basic_frame_cback* p)
{
	char config_path[128] = {0};
	struct mm_basic_frame_cback_launch* launch_info = &p->launch_info;
	// pull launcher config.
	mm_sprintf(config_path, "../../config/vnc/%d/vnc_cback_link", launch_info->server_id);
	mm_basic_frame_cback_launch_load_config(&p->launch_info, config_path);
	//////////////////////////////////////////////////////////////////////////
	mm_basic_frame_cback_launch_printf_information(&p->launch_info);
	//////////////////////////////////////////////////////////////////////////
	mm_basic_frame_cback_runtime_assign_unique_id(&p->runtime_info,launch_info->unique_id);
	mm_loavger_holder_assign_zkrb_host(&p->loavger_holder,launch_info->zookeeper_import_parameters.s);
	mm_redis_sync_array_assign_parameters(&p->db_redis_cache_cback,launch_info->rdb_account_cache_parameters.s);
	mm_redis_poper_array_assign_parameters(&p->db_redis_poper_cback,launch_info->rdb_message_queue_parameters.s);
	mm_redis_poper_array_assign_key(&p->db_redis_poper_cback,launch_info->queue_name.s);
	mm_redis_poper_array_assign_cmd(&p->db_redis_poper_cback,launch_info->queue_pop_mode.s);
	//
	mm_redis_sync_array_assign_auth(&p->db_redis_cache_cback, launch_info->rdb_gateway_cache_auth.s);
	mm_redis_poper_array_assign_auth(&p->db_redis_poper_cback,launch_info->rdb_message_queue_auth.s);
	//////////////////////////////////////////////////////////////////////////
	mm_loavger_holder_assign_zkrb_path(&p->loavger_holder,MM_SHUTTLE_CBACK_ZK_IMPORT);
	//////////////////////////////////////////////////////////////////////////
	// start
	mm_timer_start(&p->timer);
	mm_redis_sync_array_start(&p->db_redis_cache_cback);
	mm_redis_poper_array_start(&p->db_redis_poper_cback);
	mm_mt_contact_start(&p->contact);
	mm_loavger_holder_start(&p->loavger_holder);
}
void mm_basic_frame_cback_interrupt(struct mm_basic_frame_cback* p)
{
	mm_timer_interrupt(&p->timer);
	mm_redis_sync_array_interrupt(&p->db_redis_cache_cback);
	mm_redis_poper_array_interrupt(&p->db_redis_poper_cback);
	mm_mt_contact_interrupt(&p->contact);
	mm_loavger_holder_interrupt(&p->loavger_holder);
}
void mm_basic_frame_cback_shutdown(struct mm_basic_frame_cback* p)
{
	mm_timer_shutdown(&p->timer);
	mm_redis_sync_array_shutdown(&p->db_redis_cache_cback);
	mm_redis_poper_array_shutdown(&p->db_redis_poper_cback);
	mm_mt_contact_shutdown(&p->contact);
	mm_loavger_holder_shutdown(&p->loavger_holder);
}
void mm_basic_frame_cback_join(struct mm_basic_frame_cback* p)
{
	mm_timer_join(&p->timer);
	mm_redis_sync_array_join(&p->db_redis_cache_cback);
	mm_redis_poper_array_join(&p->db_redis_poper_cback);
	mm_mt_contact_join(&p->contact);
	mm_loavger_holder_join(&p->loavger_holder);
}
//////////////////////////////////////////////////////////////////////////
static void __static_mm_basic_frame_cback_msec_update_dt_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_basic_frame_cback* basic_frame_cback = (struct mm_basic_frame_cback*)(entry->callback.obj);
	mm_basic_frame_cback_runtime_update_runtime(&basic_frame_cback->runtime_info);
	mm_loavger_holder_update_watcher(&basic_frame_cback->loavger_holder);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_basic_frame_cback_msec_launch_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_basic_frame_cback_msec_commit_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_basic_frame_cback* basic_frame_cback = (struct mm_basic_frame_cback*)(entry->callback.obj);
	mm_basic_frame_cback_runtime_commit_db(&basic_frame_cback->runtime_info);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_basic_frame_cback_msec_commit_zk_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_basic_frame_cback* basic_frame_cback = (struct mm_basic_frame_cback*)(entry->callback.obj);
	mm_basic_frame_cback_runtime_commit_zk(&basic_frame_cback->runtime_info);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
//////////////////////////////////////////////////////////////////////////
static void __static_basic_frame_cback_event_mt_tcp_alloc( void* p, struct mm_mt_tcp* mt_tcp )
{
	struct mm_mt_tcp_callback mt_tcp_callback;
	mt_tcp_callback.handle = &mm_contact_handle_default;
	mt_tcp_callback.broken = &mm_contact_broken_default;
	mt_tcp_callback.nready = &mm_contact_nready_default;
	mt_tcp_callback.finish = &mm_contact_finish_default;
	mt_tcp_callback.obj = p;
	mm_mt_tcp_assign_default_callback(mt_tcp,&mt_tcp_callback);
}
static void __static_basic_frame_cback_event_mt_tcp_relax( void* p, struct mm_mt_tcp* mt_tcp )
{
	// nothing todo.
}
//////////////////////////////////////////////////////////////////////////