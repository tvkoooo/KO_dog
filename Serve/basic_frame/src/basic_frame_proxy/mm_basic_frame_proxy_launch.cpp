#include "mm_basic_frame_proxy_launch.h"
#include "core/mm_logger_manager.h"
#include "core/mm_byte.h"

#include "cpp/INIReader.h"

//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_proxy_launch_init(struct mm_basic_frame_proxy_launch* p)
{
	p->unique_id = 0;
	p->server_id = 0;
	mm_string_init(&p->internal_mailbox_parameters);
	mm_string_init(&p->zookeeper_import_parameters);
	mm_string_init(&p->zookeeper_export_parameters);
	p->module = 0;
	p->mid_l = 0;
	p->mid_r = 0;
	p->shard = 0;
	p->number_id = 0;
}
void mm_basic_frame_proxy_launch_destroy(struct mm_basic_frame_proxy_launch* p)
{
	p->unique_id = 0;
	p->server_id = 0;
	mm_string_destroy(&p->internal_mailbox_parameters);
	mm_string_destroy(&p->zookeeper_import_parameters);
	mm_string_destroy(&p->zookeeper_export_parameters);
	p->module = 0;
	p->mid_l = 0;
	p->mid_r = 0;
	p->shard = 0;
	p->number_id = 0;
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_proxy_launch_load_config( struct mm_basic_frame_proxy_launch* p, const char* config_file )
{
	assert(NULL != config_file && "config_file is a null.");
	INIReader reader(config_file);

	std::string zookeeper_import = reader.Get("common", "zookeeper_import", "");
	std::string zookeeper_export = reader.Get("common", "zookeeper_export", "");

	mm_string_assigns(&p->zookeeper_import_parameters, zookeeper_import.c_str());
	mm_string_assigns(&p->zookeeper_export_parameters, zookeeper_export.c_str());
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_proxy_launch_printf_information(struct mm_basic_frame_proxy_launch* p)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_logger_manager* g_logger_manager = mm_logger_manager_instance();

	p->number_id = mm_byte_uint64_a(p->mid_l,p->mid_r);

	// ; ===================== 启动参数 ======================
	// ; static void __static_print_help()
	// ; {
	// ; 	mm_printf("%s\n", "help:");
	// ; 	mm_printf("%s\n", "程序名             日志目录 日志等级 实例编号  服        内地址启动参数   模块号 包号区间左 包号区间右 分片规模(0用负载)");
	// ; 	mm_printf("%s\n", "program_name       log_dir  log_lvl  unique_id server_id internal_mailbox module mid_l      mid_r      shard_size       ");
	// ; 	mm_printf("%s\n", "./mm_basic_frame_proxy ./log    7        1         1         ::-65535[2]      100    0x01000100 0x010001FF 2                ");
	// ; }

	// [common]
	// zookeeper_import  = 10.26.50.101:2181,              ; 读取监控集群号
	// zookeeper_export  = 10.26.50.101:2181,              ; 写入监控集群号

	mm_logger_log_I(g_logger,"##############################################################################################");
	mm_logger_log_I(g_logger,"%s %d launch information:",__FUNCTION__,__LINE__);
	mm_logger_log_I(g_logger,"服务实例编名称     mm_basic_frame_proxy_%d",p->unique_id);
	mm_logger_log_I(g_logger,"程序名             %s","mm_basic_frame_proxy");
	mm_logger_log_I(g_logger,"日志文件夹路径     %s",g_logger_manager->logger_path.s);
	mm_logger_log_I(g_logger,"日志等级           %u",g_logger_manager->logger_level);
	mm_logger_log_I(g_logger,"实例编号           %u",p->unique_id);
	mm_logger_log_I(g_logger,"服                 %u",p->server_id);
	mm_logger_log_I(g_logger,"内地址启动参数     %s",p->internal_mailbox_parameters.s);
	mm_logger_log_I(g_logger,"读取监控集群号     %s",p->zookeeper_import_parameters.s);
	mm_logger_log_I(g_logger,"写入监控集群号     %s",p->zookeeper_export_parameters.s);
	mm_logger_log_I(g_logger,"模块号             %u",p->module);
	mm_logger_log_I(g_logger,"包号区间左         %08" PRIX32 "",p->mid_l);
	mm_logger_log_I(g_logger,"包号区间右         %08" PRIX32 "",p->mid_r);
	mm_logger_log_I(g_logger,"分片规模(0用负载)  %u",p->shard);
	mm_logger_log_I(g_logger,"号段区间编号       %016" PRIX64 "",p->number_id);
	mm_logger_log_I(g_logger,"##############################################################################################");
}