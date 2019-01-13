#include "mm_business_sql_process.h"

#include "core/mm_value_transform.h"

#include "shuttle_common/mm_error_code_mysql.h"
#include "shuttle_common/mm_error_code_common.h"



//////////////////////////////////////////////////////////////////////////
bool mm_business_sql_process_uid_find_userinfo(struct mm_db_mysql_section* db_mysql_section , struct mm_error_desc* error_desc ,mm_uint64_t user_id, mm::t_user_basic& user_info)
{
	bool ret = false;
	struct mm_db_mysql* db_mysql = mm_db_mysql_section_thread_instance(db_mysql_section);
	{
		struct mm_logger* g_logger = mm_logger_instance();
		mm::p_userinfo_search query;
		query.limit = 1;
		query.limit = 1;
		char val[32] = { 0 };
		mm_value_uint64_to_string(user_id, val);
		query.search = std::string(val);
		do
		{
			if (db_mysql_state_success != query.query(db_mysql, MM_LOG_INFO))
			{
				mm_logger_log_W(g_logger, "%s %d %d %s", __FUNCTION__, __LINE__, err_common_exec_procedure_failure, mm_error_desc_string(error_desc, err_common_exec_procedure_failure));
				break;
			}
			if (0 != query.code)
			{
				mm_logger_log_W(g_logger, "%s %d %d %s", __FUNCTION__, __LINE__, query.code, mm_error_desc_string(error_desc, query.code));
				break;
			}
			//拼装回包内容
			//typedef 做一个短名称
			typedef mm::p_userinfo_search::user_basic_vec user_basic_vec;
			user_basic_vec& vec = query.user_info_s;
			//遍历容器
			for (user_basic_vec::iterator it = vec.begin();
				it != vec.end(); it++)
			{
				//获取具体迭代器包含的元素引用
				user_info = *it;
			}
			mm_logger_log_I(g_logger, "%s %d user_id:%" PRIu64 "", __FUNCTION__, __LINE__, user_info.id);
			ret = true;
		} while (0);
	}
	return ret;
}
//////////////////////////////////////////////////////////////////////////
