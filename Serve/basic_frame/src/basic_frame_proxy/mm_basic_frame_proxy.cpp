#include "mm_basic_frame_proxy.h"
#include "core/mm_logger.h"
#include "core/mm_time_cache.h"
#include "core/mm_timer.h"
#include "core/mm_byte.h"

#include "net/mm_streambuf_packet.h"
#include "net/mm_default_handle.h"

#include "dish/mm_json.h"

#include "shuttle_common/mm_error_code_mysql.h"
#include "shuttle_common/mm_error_code_common.h"
#include "shuttle_common/mm_error_code_core.h"
#include "shuttle_common/mm_modules_runtime.h"
#include "shuttle_common/mm_runtime_calculate.h"

#include "protobuf/mm_protobuff_cxx.h"
#include "protodef/cxx/protodef/s_control.pb.h"
#include "protodef/cxx/protodef/c_basic_frame_entry.pb.h"

#include "mm_basic_frame_proxy_internal_mailbox_tcp_hd.h"
#include "mm_basic_frame_proxy_contact_tcp_hd.h"

//////////////////////////////////////////////////////////////////////////
static void __static_mm_basic_frame_proxy_msec_update_dt_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_basic_frame_proxy_msec_launch_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_basic_frame_proxy_msec_commit_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_basic_frame_proxy_msec_commit_zk_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);

static void __static_basic_frame_proxy_event_mt_tcp_alloc( void* p, struct mm_mt_tcp* mt_tcp );
static void __static_basic_frame_proxy_event_mt_tcp_relax( void* p, struct mm_mt_tcp* mt_tcp );
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_proxy_init(struct mm_basic_frame_proxy* p)
{
	struct mm_mailbox_callback internal_mailbox_callback;
	struct mm_mt_contact_event_mt_tcp_alloc contact_callback;
	//
	mm_mailbox_init(&p->internal_mailbox);
	mm_timer_init(&p->timer);
	mm_basic_frame_proxy_launch_init(&p->launch_info);
	mm_basic_frame_proxy_runtime_init(&p->runtime_info);
	mm_primacy_holder_init(&p->primacy_holder);
	mm_mt_contact_init(&p->contact);
	mm_error_desc_init(&p->error_desc);

	p->msec_update_dt = MM_SHUTTLE_PROXY_MSEC_UPDATE_DT;
	p->msec_launch_db = MM_SHUTTLE_PROXY_MSEC_LAUNCH_DB;
	p->msec_commit_db = MM_SHUTTLE_PROXY_MSEC_COMMIT_DB;
	p->msec_commit_zk = MM_SHUTTLE_PROXY_MSEC_COMMIT_ZK;

	internal_mailbox_callback.handle = &hd_basic_frame_proxy_internal_mailbox_handle;
	internal_mailbox_callback.broken = &hd_basic_frame_proxy_internal_mailbox_broken;
	internal_mailbox_callback.nready = &hd_basic_frame_proxy_internal_mailbox_nready;
	internal_mailbox_callback.finish = &hd_basic_frame_proxy_internal_mailbox_finish;
	internal_mailbox_callback.obj = p;
	mm_mailbox_assign_mailbox_callback(&p->internal_mailbox,&internal_mailbox_callback);

	contact_callback.event_mt_tcp_alloc = &__static_basic_frame_proxy_event_mt_tcp_alloc;
	contact_callback.event_mt_tcp_relax = &__static_basic_frame_proxy_event_mt_tcp_relax;
	contact_callback.obj = p;
	mm_mt_contact_assign_event_mt_tcp_alloc(&p->contact,&contact_callback);

	mm_mailbox_assign_context(&p->internal_mailbox,p);
	mm_mt_contact_assign_context(&p->contact,p);

	mm_error_desc_assign_core(&p->error_desc);
	mm_error_desc_assign_common(&p->error_desc);
	mm_error_desc_assign_mysql(&p->error_desc);
	//
	mm_basic_frame_proxy_runtime_assign_internal_mailbox(&p->runtime_info,&p->internal_mailbox);
	mm_basic_frame_proxy_runtime_assign_external_mailbox(&p->runtime_info,&p->internal_mailbox);
	mm_basic_frame_proxy_runtime_assign_launch_info(&p->runtime_info,&p->launch_info);
	//
	mm_timer_schedule(&p->timer, 10, p->msec_update_dt, &__static_mm_basic_frame_proxy_msec_update_dt_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_launch_db, &__static_mm_basic_frame_proxy_msec_launch_db_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_commit_db, &__static_mm_basic_frame_proxy_msec_commit_db_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_commit_zk, &__static_mm_basic_frame_proxy_msec_commit_zk_handle, p);
	//
	mm_protobuf_cxx_init();
}
void mm_basic_frame_proxy_destroy(struct mm_basic_frame_proxy* p)
{
	google::protobuf::ShutdownProtobufLibrary();
	mm_protobuf_cxx_destroy();
	//
	mm_mailbox_destroy(&p->internal_mailbox);
	mm_timer_destroy(&p->timer);
	mm_basic_frame_proxy_launch_destroy(&p->launch_info);
	mm_basic_frame_proxy_runtime_destroy(&p->runtime_info);
	mm_primacy_holder_destroy(&p->primacy_holder);
	mm_mt_contact_destroy(&p->contact);
	mm_error_desc_destroy(&p->error_desc);

	p->msec_update_dt = MM_SHUTTLE_PROXY_MSEC_UPDATE_DT;
	p->msec_launch_db = MM_SHUTTLE_PROXY_MSEC_LAUNCH_DB;
	p->msec_commit_db = MM_SHUTTLE_PROXY_MSEC_COMMIT_DB;
	p->msec_commit_zk = MM_SHUTTLE_PROXY_MSEC_COMMIT_ZK;
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_proxy_assign_unique_id(struct mm_basic_frame_proxy* p,mm_uint32_t unique_id)
{
	struct mm_basic_frame_proxy_launch* launch_info = &p->launch_info;
	launch_info->unique_id = unique_id;
}
void mm_basic_frame_proxy_assign_server_id(struct mm_basic_frame_proxy* p,mm_uint32_t server_id)
{
	struct mm_basic_frame_proxy_launch* launch_info = &p->launch_info;
	launch_info->server_id = server_id;
}
void mm_basic_frame_proxy_assign_internal_mailbox_parameters(struct mm_basic_frame_proxy* p,const char* parameters)
{
	struct mm_basic_frame_proxy_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->internal_mailbox_parameters, parameters);
}
void mm_basic_frame_proxy_assign_zookeeper_import_parameters(struct mm_basic_frame_proxy* p,const char* parameters)
{
	struct mm_basic_frame_proxy_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->zookeeper_import_parameters, parameters);
}
void mm_basic_frame_proxy_assign_module(struct mm_basic_frame_proxy* p,mm_uint32_t module)
{
	struct mm_basic_frame_proxy_launch* launch_info = &p->launch_info;
	launch_info->module = module;
}
void mm_basic_frame_proxy_assign_zookeeper_export_parameters(struct mm_basic_frame_proxy* p,const char* parameters)
{
	struct mm_basic_frame_proxy_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->zookeeper_export_parameters, parameters);
}
void mm_basic_frame_proxy_assign_message_interval(struct mm_basic_frame_proxy* p,const char* mid_l_string,const char* mid_r_string)
{
	struct mm_basic_frame_proxy_launch* launch_info = &p->launch_info;
	mm_sscanf(mid_l_string,"%" PRIX32 "", &launch_info->mid_l);
	mm_sscanf(mid_r_string,"%" PRIX32 "", &launch_info->mid_r);
}
void mm_basic_frame_proxy_assign_shard(struct mm_basic_frame_proxy* p,mm_uint32_t shard)
{
	struct mm_basic_frame_proxy_launch* launch_info = &p->launch_info;
	launch_info->shard = shard;
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_proxy_start(struct mm_basic_frame_proxy* p)
{
	char config_path[128] = {0};
	char module_path[64] = {0};
	struct mm_basic_frame_proxy_launch* launch_info = &p->launch_info;
	// pull launcher config.
	mm_sprintf(config_path, "../../config/vnc/%d/vnc_proxy", launch_info->server_id);
	mm_basic_frame_proxy_launch_load_config(&p->launch_info, config_path);
	//////////////////////////////////////////////////////////////////////////
	mm_basic_frame_proxy_launch_printf_information(&p->launch_info);
	//////////////////////////////////////////////////////////////////////////
	mm_basic_frame_proxy_runtime_assign_unique_id(&p->runtime_info,launch_info->unique_id);
	mm_mailbox_assign_parameters(&p->internal_mailbox, launch_info->internal_mailbox_parameters.s);
	mm_primacy_holder_assign_zkrp_host(&p->primacy_holder,launch_info->zookeeper_import_parameters.s);
	mm_basic_frame_proxy_runtime_assign_zkwm_host(&p->runtime_info,launch_info->zookeeper_export_parameters.s);
	mm_modules_runtime_module_path(launch_info->module,module_path);
	mm_basic_frame_proxy_runtime_assign_number_id(&p->runtime_info,p->launch_info.number_id);
	//////////////////////////////////////////////////////////////////////////
	// assign callback
	mm_mailbox_assign_callback(&p->internal_mailbox,s_control::set_logger_rq_msg_id   ,&hd_s_control_set_logger_rq);
	mm_mailbox_assign_callback(&p->internal_mailbox,s_control::get_logger_rq_msg_id   ,&hd_s_control_get_logger_rq);
	//////////////////////////////////////////////////////////////////////////
	mm_basic_frame_proxy_runtime_assign_zkwm_path(&p->runtime_info,MM_SHUTTLE_PROXY_ZK_EXPORT);
	//
	mm_primacy_holder_assign_zkrp_path(&p->primacy_holder,module_path);
	//////////////////////////////////////////////////////////////////////////
	// start mailbox.
	mm_mailbox_fopen_socket(&p->internal_mailbox);
	mm_mailbox_bind(&p->internal_mailbox);
	mm_mailbox_listen(&p->internal_mailbox);
	mm_mailbox_start(&p->internal_mailbox);
	// start
	mm_timer_start(&p->timer);
	//
	mm_mt_contact_start(&p->contact);
	//
	mm_basic_frame_proxy_runtime_start(&p->runtime_info);
	mm_primacy_holder_start(&p->primacy_holder);
}
void mm_basic_frame_proxy_interrupt(struct mm_basic_frame_proxy* p)
{
	mm_mailbox_interrupt(&p->internal_mailbox);
	mm_timer_interrupt(&p->timer);
	mm_mt_contact_interrupt(&p->contact);
	mm_basic_frame_proxy_runtime_interrupt(&p->runtime_info);
	mm_primacy_holder_interrupt(&p->primacy_holder);
}
void mm_basic_frame_proxy_shutdown(struct mm_basic_frame_proxy* p)
{
	mm_mailbox_shutdown(&p->internal_mailbox);
	mm_timer_shutdown(&p->timer);
	mm_mt_contact_shutdown(&p->contact);
	mm_basic_frame_proxy_runtime_shutdown(&p->runtime_info);
	mm_primacy_holder_shutdown(&p->primacy_holder);
}
void mm_basic_frame_proxy_join(struct mm_basic_frame_proxy* p)
{
	mm_mailbox_join(&p->internal_mailbox);
	mm_timer_join(&p->timer);
	mm_mt_contact_join(&p->contact);
	mm_basic_frame_proxy_runtime_join(&p->runtime_info);
	mm_primacy_holder_join(&p->primacy_holder);
}
//////////////////////////////////////////////////////////////////////////
static void __static_mm_basic_frame_proxy_msec_update_dt_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_basic_frame_proxy* basic_frame_proxy = (struct mm_basic_frame_proxy*)(entry->callback.obj);
	mm_basic_frame_proxy_runtime_update_runtime(&basic_frame_proxy->runtime_info);
	mm_primacy_holder_update_watcher(&basic_frame_proxy->primacy_holder);
	mm_primacy_holder_update(&basic_frame_proxy->primacy_holder);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_basic_frame_proxy_msec_launch_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_basic_frame_proxy_msec_commit_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_basic_frame_proxy* basic_frame_proxy = (struct mm_basic_frame_proxy*)(entry->callback.obj);
	mm_basic_frame_proxy_runtime_commit_db(&basic_frame_proxy->runtime_info);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_basic_frame_proxy_msec_commit_zk_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_basic_frame_proxy* basic_frame_proxy = (struct mm_basic_frame_proxy*)(entry->callback.obj);
	mm_basic_frame_proxy_runtime_commit_zk(&basic_frame_proxy->runtime_info);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
//////////////////////////////////////////////////////////////////////////
static void __static_basic_frame_proxy_event_mt_tcp_alloc( void* p, struct mm_mt_tcp* mt_tcp )
{
	struct mm_mt_tcp_callback mt_tcp_callback;
	mt_tcp_callback.handle = &hd_basic_frame_proxy_contact_handle;
	mt_tcp_callback.broken = &hd_basic_frame_proxy_contact_broken;
	mt_tcp_callback.nready = &hd_basic_frame_proxy_contact_nready;
	mt_tcp_callback.finish = &hd_basic_frame_proxy_contact_finish;
	mt_tcp_callback.obj = p;
	mm_mt_tcp_assign_default_callback(mt_tcp,&mt_tcp_callback);
}
static void __static_basic_frame_proxy_event_mt_tcp_relax( void* p, struct mm_mt_tcp* mt_tcp )
{
	// nothing todo.
}
//////////////////////////////////////////////////////////////////////////
