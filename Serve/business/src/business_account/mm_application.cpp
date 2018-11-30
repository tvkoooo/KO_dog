#include "mm_application.h"
#include "core/mm_alloc.h"
#include "core/mm_time_cache.h"
#include "core/mm_context.h"
#include "core/mm_logger_manager.h"
#include "core/mm_atoi.h"
#include "zookeeper/mm_zookeeper_logger.h"
/////////////////////////////////////////////////////////////////
static const char* g_arg_impl[] = 
{
	"./mm_business_account",
	"./log",
	"7",
	"1",
	"::1-10010[2]",
	"::1-20010[2]",
	"127.0.0.1:10300,",
	"100",
	"0",
	"0",
	"123456",
};
const struct mm_argument g_argument = { MM_ARRAY_SIZE(g_arg_impl),(const char**)g_arg_impl, };
/////////////////////////////////////////////////////////////////
static void __static_print_help()
{
	mm_printf("%s\n", "help:");
	mm_printf("%s\n", "程序名             日志目录 日志等级 实例编号  内地址启动参数   外地址启动参数   写入监控集群号   模块号   分片行 分片列 令牌种子");
	mm_printf("%s\n", "program_name       log_dir  log_lvl  unique_id internal_mailbox external_headset zookeeper_export Module.n shard  depth  JWT     ");
	mm_printf("%s\n", "./mm_business_account ./log    7        1      ::1-10010[2]     ::1-20010[2]     127.0.0.1:10300, 100      0      0      123456  ");
}
/////////////////////////////////////////////////////////////////
static struct mm_application g_application;
struct mm_application* mm_application_instance()
{
	return &g_application;
}
/////////////////////////////////////////////////////////////////
void mm_application_init(struct mm_application* p)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_context* g_context = mm_context_instance();
	struct mm_time_cache* g_time_cache = mm_time_cache_instance();

	mm_context_init(g_context);
	mm_time_cache_init(g_time_cache);
	mm_zookeeper_logger_init();

	mm_argument_init(&p->argument);
	p->state = 0;
	mm_business_account_init(&p->impl);
	//
	mm_logger_log_I(g_logger,"%s %d.",__FUNCTION__,__LINE__);
}
void mm_application_destroy(struct mm_application* p)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_context* g_context = mm_context_instance();
	struct mm_time_cache* g_time_cache = mm_time_cache_instance();
	mm_argument_destroy(&p->argument);
	mm_business_account_destroy(&p->impl);
	mm_logger_log_I(g_logger,"%s %d.",__FUNCTION__,__LINE__);
	mm_zookeeper_logger_destroy();
	mm_time_cache_destroy(g_time_cache);
	mm_context_destroy(g_context);
}
void mm_application_initialize(struct mm_application* p,int argc,const char **argv)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_string argument_string;
	//
	p->argument.argc = argc;
	p->argument.argv = argv;
	//
	mm_string_init(&argument_string);
	mm_argument_to_string(&p->argument, &argument_string);
	mm_printf("%s\n",argument_string.s);
	//
	if (p->argument.argc == g_argument.argc)
	{
		struct mm_logger_manager* g_logger_manager = mm_logger_manager_instance();
		mm_string_assigns(&g_logger_manager->file_name,"mm_business_account");
		mm_string_assigns(&g_logger_manager->logger_path,p->argument.argv[1]);
		g_logger_manager->file_size = 300 * 1024 * 1024;
		g_logger_manager->logger_level = mm_atoi32(p->argument.argv[2]);
		g_logger_manager->check_file_size_time = 5000;
		g_logger_manager->rolling_index = 100;
		g_logger_manager->is_console = 0;
		g_logger_manager->is_immediately = 1;
		mm_logger_manager_open(g_logger_manager);
		////////////////////////////////////////////////////////
		mm_logger_log_I(g_logger,"%s %d %s.",__FUNCTION__,__LINE__,argument_string.s);
		////////////////////////////////////////////////////////
		mm_business_account_assign_unique_id(&p->impl,mm_atoi32(p->argument.argv[3]));
		mm_business_account_assign_internal_mailbox_parameters(&p->impl,p->argument.argv[4]);
		mm_business_account_assign_external_mailbox_parameters(&p->impl,p->argument.argv[5]);
		mm_business_account_assign_zookeeper_export_parameters(&p->impl, p->argument.argv[6]);
		mm_business_account_assign_module_number(&p->impl, mm_atoi32(p->argument.argv[7]));
		mm_business_account_assign_area_shard(&p->impl, mm_atoi32(p->argument.argv[8]));
		mm_business_account_assign_area_depth(&p->impl, mm_atoi32(p->argument.argv[9]));
		mm_business_account_assign_JWT_token_parameters(&p->impl, p->argument.argv[10]);
		////////////////////////////////////////////////////////
		p->state = 1;
	}
	else
	{
		__static_print_help();
	}
	//
	mm_logger_log_I(g_logger,"%s %d.",__FUNCTION__,__LINE__);
}
void mm_application_start(struct mm_application* p)
{
	struct mm_logger* g_logger = mm_logger_instance();
	if ( 1 == p->state )
	{
		struct mm_context* g_context = mm_context_instance();
		struct mm_time_cache* g_time_cache = mm_time_cache_instance();
		mm_logger_log_I(g_logger,"%s begin %d.",__FUNCTION__,__LINE__);
		//
		mm_context_start(g_context);
		mm_time_cache_start(g_time_cache);
		//
		mm_business_account_start(&p->impl);
		//
		mm_logger_log_I(g_logger,"%s end %d.",__FUNCTION__,__LINE__);
	}
	mm_logger_log_I(g_logger,"%s %d.",__FUNCTION__,__LINE__);
}
void mm_application_interrupt(struct mm_application* p)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_context* g_context = mm_context_instance();
	struct mm_time_cache* g_time_cache = mm_time_cache_instance();
	mm_business_account_interrupt(&p->impl);
	mm_time_cache_interrupt(g_time_cache);
	mm_context_interrupt(g_context);
	mm_logger_log_I(g_logger,"%s %d.",__FUNCTION__,__LINE__);
}
void mm_application_shutdown(struct mm_application* p)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_context* g_context = mm_context_instance();
	struct mm_time_cache* g_time_cache = mm_time_cache_instance();
	mm_business_account_shutdown(&p->impl);
	mm_time_cache_shutdown(g_time_cache);
	mm_context_shutdown(g_context);
	mm_logger_log_I(g_logger,"%s %d.",__FUNCTION__,__LINE__);
}
void mm_application_join(struct mm_application* p)
{
	struct mm_logger* g_logger = mm_logger_instance();
	if ( 1 == p->state )
	{
		struct mm_context* g_context = mm_context_instance();
		struct mm_time_cache* g_time_cache = mm_time_cache_instance();
		mm_business_account_join(&p->impl);
		mm_time_cache_join(g_time_cache);
		mm_context_join(g_context);
	}
	mm_logger_log_I(g_logger,"%s %d.",__FUNCTION__,__LINE__);
}