#include "mm_business_account_launch.h"
#include "mm_application.h"
#include "core/mm_logger_manager.h"
//////////////////////////////////////////////////////////////////////////
void mm_business_account_launch_init(struct mm_business_account_launch* p)
{
	p->unique_id = 0;
	mm_string_init(&p->internal_mailbox_parameters);
	mm_string_init(&p->external_mailbox_parameters);
	mm_string_init(&p->zookeeper_export_parameters);
	p->module_number = 0;
	p->area_shard = 0;
	p->area_depth = 0;
	p->token_seed = 0;

}
void mm_business_account_launch_destroy(struct mm_business_account_launch* p)
{
	p->unique_id = 0;
	mm_string_destroy(&p->internal_mailbox_parameters);
	mm_string_destroy(&p->external_mailbox_parameters);
	mm_string_destroy(&p->zookeeper_export_parameters);
	p->module_number = 0;
	p->area_shard = 0;
	p->area_depth = 0;
	p->token_seed = 0;
}
//////////////////////////////////////////////////////////////////////////
void mm_business_account_launch_printf_information(struct mm_business_account_launch* p)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_logger_manager* g_logger_manager = mm_logger_manager_instance();
	// 服务实例编名称    mm_business_account_0
	// 程序名            mm_business_account
	// 日志文件夹路径    ../log
	// 日志等级          7
	// 实例编号          1
	// 内地址启动参数    192.168.111.123-65535(2)   //内部接口：业务接口tcp（proxy传过来的）  
	// 外地址启动参数    192.168.111.123-65535(2)   //外表接口：控制服务器接口tcp（ctrl 传过来的，更改日志等级）
	// 写入监控集群号    127.0.0.1:10300,127.0.0.1:10301,127.0.0.1:10302,
	// 模块号            100
	// 分片行(shard)     0        //备注：分片规模，2的n次方，行数[0,2^n)
	// 分片列(depth)     0        //备注：分片深度，主备规模（备用机器规模）
	// JWT令牌种子       123456   //hs256 密码生成种子
	mm_logger_log_I(g_logger,"##############################################################################################");
	mm_logger_log_I(g_logger,"%s %d launch information:",__FUNCTION__,__LINE__);
	mm_logger_log_I(g_logger,"服务实例编名称     mm_business_account_%d",p->unique_id);
	mm_logger_log_I(g_logger,"程序名             %s","mm_business_account");
	mm_logger_log_I(g_logger,"日志文件夹路径     %s",g_logger_manager->logger_path.s);
	mm_logger_log_I(g_logger,"日志等级           %u",g_logger_manager->logger_level);
	mm_logger_log_I(g_logger,"实例编号           %u",p->unique_id);
	mm_logger_log_I(g_logger,"内地址启动参数     %s",p->internal_mailbox_parameters.s);
	mm_logger_log_I(g_logger,"外地址启动参数     %s",p->external_mailbox_parameters.s);
	mm_logger_log_I(g_logger,"写入监控集群号     %s",p->zookeeper_export_parameters.s);
	mm_logger_log_I(g_logger,"模块号             %u",p->module_number);
	mm_logger_log_I(g_logger,"分片行(shard)      %u",p->area_shard);
	mm_logger_log_I(g_logger,"分片列(depth)      %u",p->area_depth);
	mm_logger_log_I(g_logger,"JWT令牌种子        %u",p->token_seed);
	mm_logger_log_I(g_logger,"##############################################################################################");
}
