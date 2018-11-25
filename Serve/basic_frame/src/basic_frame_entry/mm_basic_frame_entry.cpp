#include "mm_basic_frame_entry.h"
#include "core/mm_logger.h"
#include "core/mm_time_cache.h"
#include "core/mm_timer.h"

#include "net/mm_streambuf_packet.h"
#include "net/mm_default_handle.h"

#include "shuttle_common/mm_error_code_mysql.h"
#include "shuttle_common/mm_error_code_common.h"
#include "shuttle_common/mm_error_code_core.h"
#include "shuttle_common/mm_runtime_calculate.h"

#include "protobuf/mm_protobuff_cxx.h"
#include "protodef/cxx/protodef/s_control.pb.h"
#include "protodef/cxx/protodef/c_basic_frame_entry.pb.h"

#include "mm_basic_frame_entry_udp_hd.h"
#include "mm_basic_frame_entry_error_code.h"

//////////////////////////////////////////////////////////////////////////
static void __static_mm_basic_frame_entry_msec_update_dt_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_basic_frame_entry_msec_launch_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_basic_frame_entry_msec_commit_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
static void __static_mm_basic_frame_entry_msec_commit_zk_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_entry_init(struct mm_basic_frame_entry* p)
{
	struct mm_headset_callback headset_callback;
	struct mm_mailbox_callback internal_mailbox_callback;

	mm_headset_init(&p->external_headset);
	mm_mailbox_init(&p->internal_mailbox);
	mm_timer_init(&p->timer);
	mm_basic_frame_entry_launch_init(&p->launch_info);
	mm_basic_frame_entry_runtime_init(&p->runtime_info);
	mm_loavger_holder_init(&p->loavger_holder);
	mm_error_desc_init(&p->error_desc);

	p->msec_update_dt = MM_BASIC_FRAME_ENTRY_MSEC_UPDATE_DT;
	p->msec_launch_db = MM_BASIC_FRAME_ENTRY_MSEC_LAUNCH_DB;
	p->msec_commit_db = MM_BASIC_FRAME_ENTRY_MSEC_COMMIT_DB;
	p->msec_commit_zk = MM_BASIC_FRAME_ENTRY_MSEC_COMMIT_ZK;

	headset_callback.handle = &mm_headset_handle_default;
	headset_callback.broken = &mm_headset_broken_default;
	headset_callback.nready = &mm_headset_nready_default;
	headset_callback.finish = &mm_headset_finish_default;
	headset_callback.obj = p;
	mm_headset_assign_headset_callback(&p->external_headset,&headset_callback);

	internal_mailbox_callback.handle = &mm_mailbox_handle_default;
	internal_mailbox_callback.broken = &mm_mailbox_broken_default;
	internal_mailbox_callback.nready = &mm_mailbox_nready_default;
	internal_mailbox_callback.finish = &mm_mailbox_finish_default;
	internal_mailbox_callback.obj = p;
	mm_mailbox_assign_mailbox_callback(&p->internal_mailbox,&internal_mailbox_callback);

	mm_mailbox_assign_context(&p->internal_mailbox,p);
	mm_headset_assign_context(&p->external_headset,p);

	mm_error_desc_assign_core(&p->error_desc);
	mm_error_desc_assign_common(&p->error_desc);
	mm_error_desc_assign_mysql(&p->error_desc);
	mm_error_desc_assign_basic_frame_entry(&p->error_desc);
	//
	mm_basic_frame_entry_runtime_assign_launch_info(&p->runtime_info,&p->launch_info);
	mm_basic_frame_entry_runtime_assign_internal_mailbox(&p->runtime_info,&p->internal_mailbox);
	mm_basic_frame_entry_runtime_assign_external_headset(&p->runtime_info,&p->external_headset);
	//
	mm_timer_schedule(&p->timer, 10, p->msec_update_dt, &__static_mm_basic_frame_entry_msec_update_dt_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_launch_db, &__static_mm_basic_frame_entry_msec_launch_db_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_commit_db, &__static_mm_basic_frame_entry_msec_commit_db_handle, p);
	mm_timer_schedule(&p->timer, 10, p->msec_commit_zk, &__static_mm_basic_frame_entry_msec_commit_zk_handle, p);
	//
	mm_protobuf_cxx_init();
}
void mm_basic_frame_entry_destroy(struct mm_basic_frame_entry* p)
{
	google::protobuf::ShutdownProtobufLibrary();
	mm_protobuf_cxx_destroy();
	//
	mm_headset_destroy(&p->external_headset);
	mm_mailbox_destroy(&p->internal_mailbox);
	mm_timer_destroy(&p->timer);
	mm_basic_frame_entry_launch_destroy(&p->launch_info);
	mm_basic_frame_entry_runtime_destroy(&p->runtime_info);
	mm_loavger_holder_destroy(&p->loavger_holder);
	mm_error_desc_destroy(&p->error_desc);

	p->msec_update_dt = MM_BASIC_FRAME_ENTRY_MSEC_UPDATE_DT;
	p->msec_launch_db = MM_BASIC_FRAME_ENTRY_MSEC_LAUNCH_DB;
	p->msec_commit_db = MM_BASIC_FRAME_ENTRY_MSEC_COMMIT_DB;
	p->msec_commit_zk = MM_BASIC_FRAME_ENTRY_MSEC_COMMIT_ZK;
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_entry_assign_unique_id(struct mm_basic_frame_entry* p,mm_uint32_t unique_id)
{
	struct mm_basic_frame_entry_launch* launch_info = &p->launch_info;
	launch_info->unique_id = unique_id;
}
void mm_basic_frame_entry_assign_internal_mailbox_parameters(struct mm_basic_frame_entry* p,const char* parameters)
{
	struct mm_basic_frame_entry_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->internal_mailbox_parameters, parameters);
}
void mm_basic_frame_entry_assign_external_headset_parameters(struct mm_basic_frame_entry* p,const char* parameters)
{
	struct mm_basic_frame_entry_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->external_headset_parameters, parameters);
}
void mm_basic_frame_entry_assign_zookeeper_import_parameters(struct mm_basic_frame_entry* p,const char* parameters)
{
	struct mm_basic_frame_entry_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->zookeeper_import_parameters, parameters);
}
void mm_basic_frame_entry_assign_zookeeper_export_parameters(struct mm_basic_frame_entry* p,const char* parameters)
{
	struct mm_basic_frame_entry_launch* launch_info = &p->launch_info;
	mm_string_assigns(&launch_info->zookeeper_export_parameters, parameters);
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_entry_start(struct mm_basic_frame_entry* p)
{
	struct mm_basic_frame_entry_launch* launch_info = &p->launch_info;
	// pull launcher config.
	//////////////////////////////////////////////////////////////////////////
	mm_basic_frame_entry_launch_printf_information(&p->launch_info);
	//////////////////////////////////////////////////////////////////////////
	mm_basic_frame_entry_runtime_assign_unique_id(&p->runtime_info,launch_info->unique_id);
	mm_mailbox_assign_parameters(&p->internal_mailbox, launch_info->internal_mailbox_parameters.s);
	mm_headset_assign_parameters(&p->external_headset, launch_info->external_headset_parameters.s);
	mm_loavger_holder_assign_zkrb_host(&p->loavger_holder, launch_info->zookeeper_import_parameters.s);
	mm_basic_frame_entry_runtime_assign_zkwb_host(&p->runtime_info, launch_info->zookeeper_export_parameters.s);
	//////////////////////////////////////////////////////////////////////////
	// assign callback
	mm_mailbox_assign_callback(&p->internal_mailbox,s_control::set_logger_rq_msg_id   ,&hd_s_control_set_logger_rq);
	mm_mailbox_assign_callback(&p->internal_mailbox,s_control::get_logger_rq_msg_id   ,&hd_s_control_get_logger_rq);

	mm_headset_assign_callback(&p->external_headset,c_basic_frame_entry::knock_rq_msg_id  ,&c_basic_frame_entry_knock_rq);
	//////////////////////////////////////////////////////////////////////////
	mm_basic_frame_entry_runtime_assign_zkwb_path(&p->runtime_info,MM_BASIC_FRAME_ENTRY_ZK_EXPORT);
	//
	mm_loavger_holder_assign_zkrb_path(&p->loavger_holder,MM_BASIC_FRAME_ENTRY_ZK_IMPORT);
	//////////////////////////////////////////////////////////////////////////
	// start headset.
	mm_headset_fopen_socket(&p->external_headset);
	mm_headset_bind(&p->external_headset);
	mm_headset_start(&p->external_headset);
	// start mailbox.
	mm_mailbox_fopen_socket(&p->internal_mailbox);
	mm_mailbox_bind(&p->internal_mailbox);
	mm_mailbox_listen(&p->internal_mailbox);
	mm_mailbox_start(&p->internal_mailbox);
	// start
	mm_timer_start(&p->timer);
	//
	mm_basic_frame_entry_runtime_start(&p->runtime_info);
	mm_loavger_holder_start(&p->loavger_holder);
}
void mm_basic_frame_entry_interrupt(struct mm_basic_frame_entry* p)
{
	mm_headset_interrupt(&p->external_headset);
	mm_mailbox_interrupt(&p->internal_mailbox);
	mm_timer_interrupt(&p->timer);
	mm_basic_frame_entry_runtime_interrupt(&p->runtime_info);
	mm_loavger_holder_interrupt(&p->loavger_holder);
}
void mm_basic_frame_entry_shutdown(struct mm_basic_frame_entry* p)
{
	mm_headset_shutdown(&p->external_headset);
	mm_mailbox_shutdown(&p->internal_mailbox);
	mm_timer_shutdown(&p->timer);
	mm_basic_frame_entry_runtime_shutdown(&p->runtime_info);
	mm_loavger_holder_shutdown(&p->loavger_holder);
}
void mm_basic_frame_entry_join(struct mm_basic_frame_entry* p)
{
	mm_headset_join(&p->external_headset);
	mm_mailbox_join(&p->internal_mailbox);
	mm_timer_join(&p->timer);
	mm_basic_frame_entry_runtime_join(&p->runtime_info);
	mm_loavger_holder_join(&p->loavger_holder);
}
//////////////////////////////////////////////////////////////////////////
static void __static_mm_basic_frame_entry_msec_update_dt_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_basic_frame_entry* basic_frame_entry = (struct mm_basic_frame_entry*)(entry->callback.obj);
	mm_basic_frame_entry_runtime_update_runtime(&basic_frame_entry->runtime_info);
	// update loavger holder cycle weights.
	mm_loavger_holder_update_watcher(&basic_frame_entry->loavger_holder);
	mm_loavger_holder_cycle_update(&basic_frame_entry->loavger_holder);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_basic_frame_entry_msec_launch_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_basic_frame_entry_msec_commit_db_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_basic_frame_entry* basic_frame_entry = (struct mm_basic_frame_entry*)(entry->callback.obj);
	mm_basic_frame_entry_runtime_commit_db(&basic_frame_entry->runtime_info);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
static void __static_mm_basic_frame_entry_msec_commit_zk_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_basic_frame_entry* basic_frame_entry = (struct mm_basic_frame_entry*)(entry->callback.obj);
	mm_basic_frame_entry_runtime_commit_zk(&basic_frame_entry->runtime_info);
	mm_logger_log_T(g_logger,"%s %d",__FUNCTION__,__LINE__);
}
//////////////////////////////////////////////////////////////////////////