#include "mm_handler_business_nt_message_launch.h"
#include "core/mm_logger_manager.h"
//////////////////////////////////////////////////////////////////////////
void mm_handler_business_nt_message_launch_init(struct mm_handler_business_nt_message_launch* p)
{
	p->unique_id = 0;
	mm_string_init(&p->rdb_gateway_queue_parameters);
	mm_string_init(&p->event_queue_rabbitmq_parameters);
	mm_string_init(&p->queue_name);
	mm_string_init(&p->rdb_gateway_queue_auth);
	p->rabbitmq_password_seed = 0;
}
void mm_handler_business_nt_message_launch_destroy(struct mm_handler_business_nt_message_launch* p)
{
	p->unique_id = 0;
	mm_string_destroy(&p->rdb_gateway_queue_parameters);
	mm_string_destroy(&p->event_queue_rabbitmq_parameters);
	mm_string_destroy(&p->queue_name);
	mm_string_destroy(&p->rdb_gateway_queue_auth);
	p->rabbitmq_password_seed = 0;
}
//////////////////////////////////////////////////////////////////////////
void mm_handler_business_nt_message_launch_printf_information(struct mm_handler_business_nt_message_launch* p)
{
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_logger_manager* g_logger_manager = mm_logger_manager_instance();

	// 服务实例编名称    mm_handler_business_nt_message_0
	// 程序名            mm_handler_business_nt_message
	// 日志文件夹路径    ../log
	// 日志等级          7
	// 实例编号          1
	// 网关回推地址号    101.200.169.28-10200
	// 事件队列地址号    101.200.169.28-5672[2]
	// 事件队列密码种子  456789
	// 弹出队列管道名    mm:relation:lobby:cback:000

	mm_logger_log_I(g_logger,"##############################################################################################");
	mm_logger_log_I(g_logger,"%s %d launch information:",__FUNCTION__,__LINE__);
	mm_logger_log_I(g_logger,"服务实例编名称     mm_handler_business_nt_message_%d",p->unique_id);
	mm_logger_log_I(g_logger,"程序名             %s","mm_handler_business_nt_message");
	mm_logger_log_I(g_logger,"日志文件夹路径     %s",g_logger_manager->logger_path.s);
	mm_logger_log_I(g_logger,"日志等级           %u",g_logger_manager->logger_level);
	mm_logger_log_I(g_logger,"实例编号           %u",p->unique_id);
	mm_logger_log_I(g_logger,"网关回推地址号     %s", p->rdb_gateway_queue_parameters.s);
	mm_logger_log_I(g_logger,"事件队列地址号     %s", p->event_queue_rabbitmq_parameters.s);
	mm_logger_log_I(g_logger,"事件队列密码种子   %u", p->rabbitmq_password_seed);
	mm_logger_log_I(g_logger,"弹出队列管道名     %s", p->queue_name.s);
	mm_logger_log_I(g_logger,"##############################################################################################");
}
