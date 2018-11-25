#include "mm_basic_frame_entry_launch.h"
#include "mm_application.h"
#include "core/mm_logger_manager.h"
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_entry_launch_init(struct mm_basic_frame_entry_launch* p)
{
	p->unique_id = 0;
	mm_string_init(&p->internal_mailbox_parameters);
	mm_string_init(&p->external_headset_parameters);
	mm_string_init(&p->zookeeper_import_parameters);
	mm_string_init(&p->zookeeper_export_parameters);
}
void mm_basic_frame_entry_launch_destroy(struct mm_basic_frame_entry_launch* p)
{
	p->unique_id = 0;
	mm_string_destroy(&p->internal_mailbox_parameters);
	mm_string_destroy(&p->external_headset_parameters);
	mm_string_destroy(&p->zookeeper_import_parameters);
	mm_string_destroy(&p->zookeeper_export_parameters);
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_entry_launch_printf_information(struct mm_basic_frame_entry_launch* p)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_logger_manager* g_logger_manager = mm_logger_manager_instance();

	// 服务实例编名称    mm_basic_frame_entry_0
	// 程序名            mm_basic_frame_entry
	// 日志文件夹路径    ../log
	// 日志等级          7
	// 实例编号          0
	// 内地址启动参数    192.168.111.123-65535(2)
	// 外地址启动参数    192.168.111.123-65535(2)
	// 读取监控集群号    127.0.0.1:10300,127.0.0.1:10301,127.0.0.1:10302,
	// 写入监控集群号    127.0.0.1:10300,127.0.0.1:10301,127.0.0.1:10302,

	mm_logger_log_I(g_logger,"##############################################################################################");
	mm_logger_log_I(g_logger,"%s %d launch information:",__FUNCTION__,__LINE__);
	mm_logger_log_I(g_logger,"服务实例编名称     mm_basic_frame_entry_%d",p->unique_id);
	mm_logger_log_I(g_logger,"程序名             %s","mm_basic_frame_entry");
	mm_logger_log_I(g_logger,"日志文件夹路径     %s",g_logger_manager->logger_path.s);
	mm_logger_log_I(g_logger,"日志等级           %u",g_logger_manager->logger_level);
	mm_logger_log_I(g_logger,"实例编号           %u",p->unique_id);
	mm_logger_log_I(g_logger,"内地址启动参数     %s",p->internal_mailbox_parameters.s);
	mm_logger_log_I(g_logger,"外地址启动参数     %s",p->external_headset_parameters.s);
	mm_logger_log_I(g_logger,"读取监控集群号     %s",p->zookeeper_import_parameters.s);
	mm_logger_log_I(g_logger,"写入监控集群号     %s",p->zookeeper_export_parameters.s);
	mm_logger_log_I(g_logger,"##############################################################################################");
}
