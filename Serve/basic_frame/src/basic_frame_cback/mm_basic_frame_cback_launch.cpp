#include "mm_basic_frame_cback_launch.h"
#include "core/mm_logger_manager.h"

#include "cpp/INIReader.h"
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_cback_launch_init( struct mm_basic_frame_cback_launch* p )
{
	p->unique_id = 0;
	p->server_id = 0;
	mm_string_init(&p->zookeeper_import_parameters);
	mm_string_init(&p->rdb_account_cache_parameters);
	mm_string_init(&p->rdb_message_queue_parameters);
	mm_string_init(&p->queue_name);
	mm_string_init(&p->queue_pop_mode);

	mm_string_init(&p->rdb_message_queue_auth);
	mm_string_init(&p->rdb_gateway_cache_auth);
}
void mm_basic_frame_cback_launch_destroy( struct mm_basic_frame_cback_launch* p )
{
	p->unique_id = 0;
	p->server_id = 0;
	mm_string_destroy(&p->zookeeper_import_parameters);
	mm_string_destroy(&p->rdb_account_cache_parameters);
	mm_string_destroy(&p->rdb_message_queue_parameters);
	mm_string_destroy(&p->queue_name);
	mm_string_destroy(&p->queue_pop_mode);

	mm_string_destroy(&p->rdb_message_queue_auth);
	mm_string_destroy(&p->rdb_gateway_cache_auth);
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_cback_launch_load_config( struct mm_basic_frame_cback_launch* p, const char* config_file )
{
	assert(NULL != config_file && "config_file is a null.");
	INIReader reader(config_file);

	std::string rdb_message_queue_auth = reader.Get("common", "rdb_message_queue_auth", "");
	std::string rdb_gateway_cache_auth = reader.Get("common", "rdb_gateway_cache_auth", "");

	mm_string_assigns(&p->rdb_message_queue_auth, rdb_message_queue_auth.c_str());
	mm_string_assigns(&p->rdb_gateway_cache_auth, rdb_gateway_cache_auth.c_str());

	std::string zookeeper_import = reader.Get("common", "zookeeper_import", "");
	mm_string_assigns(&p->zookeeper_import_parameters, zookeeper_import.c_str());
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_cback_launch_printf_information(struct mm_basic_frame_cback_launch* p)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_logger_manager* g_logger_manager = mm_logger_manager_instance();

	// ; ===================== 启动参数 ======================
	// ; static void __static_print_help()
	// ; {
	// ; 	mm_printf("%s\n", "help:");
	// ; 	mm_printf("%s\n", "程序名             日志目录 日志等级 实例编号  服        读取缓存地址号        弹队列启动参数           弹出队列管道名 弹出方式");
	// ; 	mm_printf("%s\n", "program_name       log_dir  log_lvl  unique_id server_id rdb_account_cache     rdb_message_queue        queue_name     pop_mode");
	// ; 	mm_printf("%s\n", "./mm_basic_frame_cback ./log    7        1         1         192.168.111.123-65535 192.168.111.123-65535[2] mm:cback:001   brpop   ");
	// ; }

	// [common]
	// zookeeper_import  = 10.26.50.101:2181,              ; 读取监控集群号 (这个集群是网关的写入集群号,是不变的)

	// rdb_message_queue_auth = xcRed.,0505                ; redis 消息队列 密码
	// rdb_gateway_cache_auth = xcRed.,0505                ; redis 网关缓存 密码

	mm_logger_log_I(g_logger,"##############################################################################################");
	mm_logger_log_I(g_logger,"%s %d launch information:",__FUNCTION__,__LINE__);
	mm_logger_log_I(g_logger,"服务实例编名称     mm_basic_frame_cback_%d",p->unique_id);
	mm_logger_log_I(g_logger,"程序名             %s","mm_basic_frame_cback");
	mm_logger_log_I(g_logger,"日志文件夹路径     %s",g_logger_manager->logger_path.s);
	mm_logger_log_I(g_logger,"日志等级           %u",g_logger_manager->logger_level);
	mm_logger_log_I(g_logger,"实例编号           %u",p->unique_id);
	mm_logger_log_I(g_logger,"服                 %u",p->server_id);
	mm_logger_log_I(g_logger,"读取监控集群号     %s",p->zookeeper_import_parameters.s);
	mm_logger_log_I(g_logger,"账号缓存地址号     %s",p->rdb_account_cache_parameters.s);
	mm_logger_log_I(g_logger,"消息队列地址号     %s",p->rdb_message_queue_parameters.s);
	mm_logger_log_I(g_logger,"弹出队列管道名     %s",p->queue_name.s);
	mm_logger_log_I(g_logger,"弹出方式           %s",p->queue_pop_mode.s);
	mm_logger_log_I(g_logger,"##############################################################################################");
}