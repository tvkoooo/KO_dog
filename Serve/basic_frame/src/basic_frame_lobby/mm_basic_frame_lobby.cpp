#include "mm_basic_frame_lobby.h"
#include "core/mm_logger.h"
#include "core/mm_time_cache.h"
#include "core/mm_runtime_stat.h"
#include "core/mm_byte.h"
#include "net/mm_streambuf_packet.h"
#include "net/mm_default_handle.h"

#include "protobuf/mm_protobuff_cxx.h"

#include "shuttle_common/mm_error_code_common.h"
#include "shuttle_common/mm_error_code_mysql.h"
#include "shuttle_common/mm_control_tcp_hd.h"
#include "shuttle_common/mm_runtime_calculate.h"

#include "zookeeper/mm_zkwm_path.h"
#include "cxx/protodef/s_control.pb.h"

#include "mm_basic_frame_lobby_external_mailbox_tcp_hd.h"
#include "mm_basic_frame_lobby_internal_mailbox_tcp_hd.h"
#include "mm_basic_frame_lobby_contact_tcp_hd.h"
//////////////////////////////////////////////////////////////////////////
static void __static_mm_basic_frame_lobby_msec_update_dt_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_basic_frame_lobby_msec_launch_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_basic_frame_lobby_msec_commit_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_basic_frame_lobby_msec_commit_zk_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);

static void __static_basic_frame_lobby_event_mt_tcp_alloc( void* p, struct mm_mt_tcp* mt_tcp );
static void __static_basic_frame_lobby_event_mt_tcp_relax( void* p, struct mm_mt_tcp* mt_tcp );
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_lobby_init(struct mm_basic_frame_lobby* p)
{
	struct mm_accepter_callback accepter_callback;
	struct mm_mailbox_callback external_mailbox_callback;
	struct mm_mailbox_callback internal_mailbox_callback;
	struct mm_mt_contact_event_mt_tcp_alloc contact_callback;

	mm_mailbox_init(&p->external_mailbox);
	mm_mailbox_init(&p->internal_mailbox);
	mm_timer_init(&p->timer);
	mm_basic_frame_lobby_launch_init(&p->launch_info);
	mm_basic_frame_lobby_runtime_init(&p->runtime_info);
	mm_sharder_holder_init(&p->sharder_holder);
	mm_basic_frame_lobby_cache_init(&p->db_redis_cache_lobby);
	mm_mt_contact_init(&p->contact);
	mm_streambuf_array_init(&p->streambuf_array);
	mm_error_desc_init(&p->error_desc);

	// the max thread mm_streambuf thread instance is 1;
	mm_streambuf_array_set_length(&p->streambuf_array, 1);

	p->msec_update_dt = MM_SHUTTLE_LOBBY_MSEC_UPDATE_DT;
	p->msec_launch_db = MM_SHUTTLE_LOBBY_MSEC_LAUNCH_DB;
	p->msec_commit_db = MM_SHUTTLE_LOBBY_MSEC_COMMIT_DB;
	p->msec_commit_zk = MM_SHUTTLE_LOBBY_MSEC_COMMIT_ZK;

	accepter_callback.accept = &hd_basic_frame_lobby_external_mailbox_accept;
	accepter_callback.obj = &p->external_mailbox;
	mm_accepter_assign_callback(&p->external_mailbox.accepter,&accepter_callback);

	external_mailbox_callback.handle = &hd_basic_frame_lobby_external_mailbox_handle;
	external_mailbox_callback.broken = &hd_basic_frame_lobby_external_mailbox_broken;
	external_mailbox_callback.nready = &hd_basic_frame_lobby_external_mailbox_nready;
	external_mailbox_callback.finish = &hd_basic_frame_lobby_external_mailbox_finish;
	external_mailbox_callback.obj = p;
	mm_mailbox_assign_mailbox_callback(&p->external_mailbox,&external_mailbox_callback);

	internal_mailbox_callback.handle = &hd_basic_frame_lobby_internal_mailbox_handle;
	internal_mailbox_callback.broken = &hd_basic_frame_lobby_internal_mailbox_broken;
	internal_mailbox_callback.nready = &hd_basic_frame_lobby_internal_mailbox_nready;
	internal_mailbox_callback.finish = &hd_basic_frame_lobby_internal_mailbox_finish;
	internal_mailbox_callback.obj = p;
	mm_mailbox_assign_mailbox_callback(&p->internal_mailbox,&internal_mailbox_callback);

	contact_callback.event_mt_tcp_alloc = &__static_basic_frame_lobby_event_mt_tcp_alloc;
	contact_callback.event_mt_tcp_relax = &__static_basic_frame_lobby_event_mt_tcp_relax;
	contact_callback.obj = p;
	mm_mt_contact_assign_event_mt_tcp_alloc(&p->contact,&contact_callback);

	mm_mailbox_assign_callback(&p->internal_mailbox, s_control::set_logger_rq_msg_id, &hd_s_control_set_logger_rq);
	mm_mailbox_assign_callback(&p->internal_mailbox, s_control::get_logger_rq_msg_id, &hd_s_control_get_logger_rq);

	mm_mailbox_assign_context(&p->internal_mailbox,p);
	mm_mailbox_assign_context(&p->external_mailbox,p);
	mm_mt_contact_assign_context(&p->contact,p);

	mm_error_desc_assign_core(&p->error_desc);
	mm_error_desc_assign_common(&p->error_desc);
	mm_error_desc_assign_mysql(&p->error_desc);
	//
	mm_basic_frame_lobby_runtime_assign_launch_info(&p->runtime_info,&p->launch_info);
	mm_basic_frame_lobby_runtime_assign_internal_mailbox(&p->runtime_info,&p->internal_mailbox);
	mm_basic_frame_lobby_runtime_assign_external_mailbox(&p->runtime_info,&p->external_mailbox);
	//
	mm_timer_schedule(&p->timer, 10, p->msec_update_dt, &__static_mm_basic_frame_lobby_msec_update_dt_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_launch_db, &__static_mm_basic_frame_lobby_msec_launch_db_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_commit_db, &__static_mm_basic_frame_lobby_msec_commit_db_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_commit_zk, &__static_mm_basic_frame_lobby_msec_commit_zk_handle, p);
	//
	mm_protobuf_cxx_init();
}
void mm_basic_frame_lobby_destroy(struct mm_basic_frame_lobby* p)
{
	google::protobuf::ShutdownProtobufLibrary();
	mm_protobuf_cxx_destroy();
	//
	mm_mailbox_destroy(&p->external_mailbox);
	mm_mailbox_destroy(&p->internal_mailbox);
	mm_timer_destroy(&p->timer);
	mm_basic_frame_lobby_launch_destroy(&p->launch_info);
	mm_basic_frame_lobby_runtime_destroy(&p->runtime_info);
	mm_sharder_holder_destroy(&p->sharder_holder);
	mm_basic_frame_lobby_cache_destroy(&p->db_redis_cache_lobby);
	mm_mt_contact_destroy(&p->contact);
	mm_streambuf_array_destroy(&p->streambuf_array);
	mm_error_desc_destroy(&p->error_desc);

	p->msec_update_dt = MM_SHUTTLE_LOBBY_MSEC_UPDATE_DT;
	p->msec_launch_db = MM_SHUTTLE_LOBBY_MSEC_LAUNCH_DB;
	p->msec_commit_db = MM_SHUTTLE_LOBBY_MSEC_COMMIT_DB;
	p->msec_commit_zk = MM_SHUTTLE_LOBBY_MSEC_COMMIT_ZK;
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_lobby_assign_unique_id(struct mm_basic_frame_lobby* p,mm_uint32_t unique_id)
{
	struct mm_basic_frame_lobby_launch* launch_info = &p->launch_info;
	launch_info->unique_id = unique_id;
}
void mm_basic_frame_lobby_assign_internal_mailbox_parameters(struct mm_basic_frame_lobby* p,const char* parameters)
{
	struct mm_basic_frame_lobby_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->internal_mailbox_parameters, parameters);
}
void mm_basic_frame_lobby_assign_external_mailbox_parameters(struct mm_basic_frame_lobby* p,const char* parameters)
{
	struct mm_basic_frame_lobby_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->external_mailbox_parameters, parameters);
}
void mm_basic_frame_lobby_assign_zookeeper_import_parameters(struct mm_basic_frame_lobby* p,const char* parameters)
{
	struct mm_basic_frame_lobby_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->zookeeper_import_parameters, parameters);
}
void mm_basic_frame_lobby_assign_zookeeper_export_parameters(struct mm_basic_frame_lobby* p,const char* parameters)
{
	struct mm_basic_frame_lobby_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->zookeeper_export_parameters, parameters);
}
void mm_basic_frame_lobby_assign_rdb_account_cache_parameters(struct mm_basic_frame_lobby* p,const char* parameters)
{
	struct mm_basic_frame_lobby_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->rdb_account_cache_parameters, parameters);
}
void mm_basic_frame_lobby_assign_rdb_gateway_cache_parameters(struct mm_basic_frame_lobby* p,const char* parameters)
{
	struct mm_basic_frame_lobby_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->rdb_gateway_cache_parameters, parameters);
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_lobby_start(struct mm_basic_frame_lobby* p)
{
	struct mm_basic_frame_lobby_launch* launch_info = &p->launch_info;
	// pull launcher config.
	mm_basic_frame_lobby_launch_printf_information(&p->launch_info);
	//////////////////////////////////////////////////////////////////////////
	mm_basic_frame_lobby_runtime_assign_unique_id(&p->runtime_info,launch_info->unique_id);
	mm_basic_frame_lobby_cache_assign_rdb_gateway_cache_unique_id(&p->db_redis_cache_lobby,launch_info->unique_id);
	mm_mailbox_assign_parameters(&p->internal_mailbox, launch_info->internal_mailbox_parameters.s);
	mm_mailbox_assign_parameters(&p->external_mailbox, launch_info->external_mailbox_parameters.s);
	mm_basic_frame_lobby_runtime_assign_zkwb_host(&p->runtime_info,launch_info->zookeeper_export_parameters.s);
	mm_sharder_holder_assign_zkrm_host(&p->sharder_holder,launch_info->zookeeper_import_parameters.s);
	mm_basic_frame_lobby_cache_assign_rdb_gateway_cache_parameters(&p->db_redis_cache_lobby, launch_info->rdb_gateway_cache_parameters.s);
	//////////////////////////////////////////////////////////////////////////
	// assign callback
	mm_mailbox_assign_callback(&p->internal_mailbox,s_control::set_logger_rq_msg_id   ,&hd_s_control_set_logger_rq);
	mm_mailbox_assign_callback(&p->internal_mailbox,s_control::get_logger_rq_msg_id   ,&hd_s_control_get_logger_rq);
	//////////////////////////////////////////////////////////////////////////
	mm_basic_frame_lobby_runtime_assign_zkwb_path(&p->runtime_info,MM_SHUTTLE_LOBBY_ZK_EXPORT);

	mm_sharder_holder_assign_zkrm_path(&p->sharder_holder,MM_SHUTTLE_LOBBY_ZK_IMPORT);
	//////////////////////////////////////////////////////////////////////////
	// start mailbox.
	mm_mailbox_fopen_socket(&p->external_mailbox);
	mm_mailbox_bind(&p->external_mailbox);
	mm_mailbox_listen(&p->external_mailbox);
	mm_mailbox_start(&p->external_mailbox);

	mm_mailbox_fopen_socket(&p->internal_mailbox);
	mm_mailbox_bind(&p->internal_mailbox);
	mm_mailbox_listen(&p->internal_mailbox);
	mm_mailbox_start(&p->internal_mailbox);

	mm_timer_start(&p->timer);

	mm_mt_contact_start(&p->contact);

	mm_basic_frame_lobby_cache_start(&p->db_redis_cache_lobby);
	//////////////////////////////////////////////////////////////////////////
	mm_basic_frame_lobby_runtime_start(&p->runtime_info);
	mm_sharder_holder_start(&p->sharder_holder);
	//////////////////////////////////////////////////////////////////////////
	hd_basic_frame_lobby_external_mailbox_motion(p);
}
void mm_basic_frame_lobby_interrupt(struct mm_basic_frame_lobby* p)
{
	mm_mailbox_interrupt(&p->external_mailbox);
	mm_mailbox_interrupt(&p->internal_mailbox);
	mm_timer_interrupt(&p->timer);
	mm_mt_contact_interrupt(&p->contact);
	mm_basic_frame_lobby_cache_interrupt(&p->db_redis_cache_lobby);
	mm_basic_frame_lobby_runtime_interrupt(&p->runtime_info);
	mm_sharder_holder_interrupt(&p->sharder_holder);
}
void mm_basic_frame_lobby_shutdown(struct mm_basic_frame_lobby* p)
{
	mm_mailbox_shutdown(&p->external_mailbox);
	mm_mailbox_shutdown(&p->internal_mailbox);
	mm_timer_shutdown(&p->timer);
	mm_mt_contact_shutdown(&p->contact);
	mm_basic_frame_lobby_cache_shutdown(&p->db_redis_cache_lobby);
	mm_basic_frame_lobby_runtime_shutdown(&p->runtime_info);
	mm_sharder_holder_shutdown(&p->sharder_holder);
}
void mm_basic_frame_lobby_join(struct mm_basic_frame_lobby* p)
{
	mm_mailbox_join(&p->external_mailbox);
	mm_mailbox_join(&p->internal_mailbox);
	mm_timer_join(&p->timer);
	mm_mt_contact_join(&p->contact);
	mm_basic_frame_lobby_cache_join(&p->db_redis_cache_lobby);
	mm_basic_frame_lobby_runtime_join(&p->runtime_info);
	mm_sharder_holder_join(&p->sharder_holder);
	//////////////////////////////////////////////////////////////////////////
	hd_basic_frame_lobby_external_mailbox_closed(p);
}
//////////////////////////////////////////////////////////////////////////
static void __static_mm_basic_frame_lobby_msec_update_dt_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_basic_frame_lobby* basic_frame_lobby = (struct mm_basic_frame_lobby*)(entry->callback.obj);
	mm_basic_frame_lobby_runtime_update_runtime(&basic_frame_lobby->runtime_info);
	mm_sharder_holder_update_watcher(&basic_frame_lobby->sharder_holder);
	mm_sharder_holder_update(&basic_frame_lobby->sharder_holder);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_basic_frame_lobby_msec_launch_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_basic_frame_lobby_msec_commit_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_basic_frame_lobby* basic_frame_lobby = (struct mm_basic_frame_lobby*)(entry->callback.obj);
	mm_basic_frame_lobby_runtime_commit_db(&basic_frame_lobby->runtime_info);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_basic_frame_lobby_msec_commit_zk_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_basic_frame_lobby* basic_frame_lobby = (struct mm_basic_frame_lobby*)(entry->callback.obj);
	mm_basic_frame_lobby_runtime_commit_zk(&basic_frame_lobby->runtime_info);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
//////////////////////////////////////////////////////////////////////////
static void __static_basic_frame_lobby_event_mt_tcp_alloc( void* p, struct mm_mt_tcp* mt_tcp )
{
	struct mm_mt_tcp_callback mt_tcp_callback;
	mt_tcp_callback.handle = &hd_basic_frame_lobby_contact_handle;
	mt_tcp_callback.broken = &hd_basic_frame_lobby_contact_broken;
	mt_tcp_callback.nready = &hd_basic_frame_lobby_contact_nready;
	mt_tcp_callback.finish = &hd_basic_frame_lobby_contact_finish;
	mt_tcp_callback.obj = p;
	mm_mt_tcp_assign_default_callback(mt_tcp,&mt_tcp_callback);
}
static void __static_basic_frame_lobby_event_mt_tcp_relax( void* p, struct mm_mt_tcp* mt_tcp )
{
	// nothing todo.
}
//////////////////////////////////////////////////////////////////////////
