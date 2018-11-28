﻿#ifndef __mm_business_account_launch_h__
#define __mm_business_account_launch_h__

#include "core/mm_core.h"
#include "core/mm_string.h"

//////////////////////////////////////////////////////////////////////////
// 服务实例编名称    mm_business_account_0
// 程序名            mm_business_account
// 日志文件夹路径    ../log
// 日志等级          7
// 实例编号          0
// 内地址启动参数    192.168.111.123-65535(2)
// 外地址启动参数    192.168.111.123-65535(2)
// 写入监控集群号    127.0.0.1:10300,127.0.0.1:10301,127.0.0.1:10302,
struct mm_business_account_launch
{
	mm_uint32_t unique_id;
	struct mm_string internal_mailbox_parameters;
	struct mm_string external_mailbox_parameters;
	struct mm_string zookeeper_export_parameters;
};
//////////////////////////////////////////////////////////////////////////
extern void mm_business_account_launch_init(struct mm_business_account_launch* p);
extern void mm_business_account_launch_destroy(struct mm_business_account_launch* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_business_account_launch_printf_information(struct mm_business_account_launch* p);
//////////////////////////////////////////////////////////////////////////

#endif//__mm_business_account_launch_h__