//#ifndef __mm_business_nt_message_sql_h__
//#define __mm_business_nt_message_sql_h__
//
//#include <string>
//
//#include "mysql/mm_db_mysql.h"
//#include "protobuf/mm_protobuff_cxx.h"
//#include "protobuf/mm_protobuff_cxx_net.h"
//
//struct mm_business_nt_message_sql
//{
//	struct mm_db_mysql_config db_sql_config;
//	struct mm_db_mysql_section db_sql_section;
//	struct mm_message_lpusher* message_lpusher;
//	struct mm_error_desc* error_desc;               //´íÎóÂë¹ÜÀíÆ÷
//
//};
////////////////////////////////////////////////////////////////////////////
//extern void mm_business_nt_message_sql_init(struct mm_business_nt_message_sql* p);
//extern void mm_business_nt_message_sql_destroy(struct mm_business_nt_message_sql* p);
////////////////////////////////////////////////////////////////////////////
//extern void mm_business_nt_message_sql_assign(struct mm_business_nt_message_sql* p, struct mm_message_lpusher* message_lpusher, struct mm_error_desc* error_desc);
////////////////////////////////////////////////////////////////////////////
//extern mm_uint64_t mm_business_nt_message_sql_stored_procedure(struct mm_business_nt_message_sql* p,
//	mm_uint64_t user_id, mm_uint64_t to_user_id, mm_uint32_t message_mid, ::google::protobuf::Message* message,
//	struct mm_packet* nt_pack);
//
////////////////////////////////////////////////////////////////////////////
//
//#endif//__mm_business_nt_message_sql_h__
