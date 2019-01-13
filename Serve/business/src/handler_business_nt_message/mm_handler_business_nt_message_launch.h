#ifndef __mm_handler_business_nt_message_launch_h__
#define __mm_handler_business_nt_message_launch_h__

#include "core/mm_core.h"
#include "core/mm_string.h"

//////////////////////////////////////////////////////////////////////////
// 服务实例编名称    mm_handler_business_nt_message_0
// 程序名            mm_handler_business_nt_message
// 日志文件夹路径    ../log
// 日志等级          7
// 实例编号          1
// 网关回推地址号    101.200.169.28-10200
// 事件队列地址号    101.200.169.28-5672[2]
// 事件队列密码种子  456789
// 弹出队列管道名    mm:relation:lobby:cback:000
struct mm_handler_business_nt_message_launch
{
	mm_uint32_t unique_id;
	struct mm_string rdb_gateway_queue_parameters;
	struct mm_string event_queue_rabbitmq_parameters;

	struct mm_string queue_name;
	struct mm_string rdb_gateway_queue_auth;

	mm_uint32_t rabbitmq_password_seed;
};
//////////////////////////////////////////////////////////////////////////
extern void mm_handler_business_nt_message_launch_init(struct mm_handler_business_nt_message_launch* p);
extern void mm_handler_business_nt_message_launch_destroy(struct mm_handler_business_nt_message_launch* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_handler_business_nt_message_launch_printf_information(struct mm_handler_business_nt_message_launch* p);
//////////////////////////////////////////////////////////////////////////

#endif//__mm_handler_business_nt_message_launch_h__
