#ifndef __mm_business_account_launch_h__
#define __mm_business_account_launch_h__

#include "core/mm_core.h"
#include "core/mm_string.h"

//////////////////////////////////////////////////////////////////////////
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
struct mm_business_account_launch
{
	mm_uint32_t unique_id;
	struct mm_string internal_mailbox_parameters;
	struct mm_string external_mailbox_parameters;
	struct mm_string zookeeper_export_parameters;
	mm_uint32_t module_number;
	mm_uint32_t area_shard;
	mm_uint32_t area_depth;
	struct mm_string JWT_token_parameters;
};
//////////////////////////////////////////////////////////////////////////
extern void mm_business_account_launch_init(struct mm_business_account_launch* p);
extern void mm_business_account_launch_destroy(struct mm_business_account_launch* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_business_account_launch_printf_information(struct mm_business_account_launch* p);
//////////////////////////////////////////////////////////////////////////

#endif//__mm_business_account_launch_h__