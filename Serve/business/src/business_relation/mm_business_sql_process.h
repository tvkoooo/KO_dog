#ifndef __mm_business_sql_process_h__
#define __mm_business_sql_process_h__

#include "core/mm_core.h"

#include "dish/mm_error_desc.h"

#include "querydef/mm_q_db_ko_dog_t_user_basic.h"
#include "querydef/mm_m_db_ko_dog_t_user_basic.h"
//////////////////////////////////////////////////////////////////////////
extern bool mm_business_sql_process_uid_find_userinfo(struct mm_db_mysql_section* db_mysql_section, struct mm_error_desc* error_desc, mm_uint64_t user_id, mm::t_user_basic& user_info);
//////////////////////////////////////////////////////////////////////////

#endif//__mm_business_sql_process_h__