#include "mm_business_account_tcp_hd.h"
#include "core/mm_logger.h"
#include "core/mm_time_cache.h"
#include "net/mm_packet.h"
#include "net/mm_streambuf_packet.h"
#include "shuttle_common/mm_error_code_common.h"
#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"
#include "cxx/protodef/c_business_account.pb.h"
#include "mm_business_account.h"
#include "mm_error_code_business_account.h"

#include "querydef/mm_q_db_ko_dog_t_user_basic.h"
#include "querydef/mm_m_db_ko_dog_t_user_basic.h"

#define SEARCH_ACCOUNT_RQ_LIMIT 5

//////////////////////////////////////////////////////////////////////////
void mm_business_account_tcp_hd_c_business_account_search_account_rq(void* obj, void* u, struct mm_packet* rq_pack)
{
	typedef ::google::protobuf::RepeatedPtrField< ::b_business_account::user_info > b_user_info_v;

	c_business_account::search_account_rq rq_msg;
	c_business_account::search_account_rs rs_msg;
	struct mm_packet rs_pack;
	struct mm_string proto_desc;

	b_error::info* error_info = rs_msg.mutable_error();
	b_user_info_v* user_info_s = rs_msg.mutable_user_info_s();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	struct mm_mailbox* mailbox = (struct mm_mailbox*)(tcp->callback.obj);
	struct mm_business_account* impl = (struct mm_business_account*)(u);
	struct mm_error_desc* error_desc = &impl->error_desc;
	////////////////////////////////
	error_info->set_code(0);
	error_info->set_desc("");
	////////////////////////////////
	mm_string_init(&proto_desc);
	do
	{
		if (0 != mm_protobuf_cxx_decode_message(rq_pack, &rq_msg))
		{
			error_info->set_code(err_common_package_decode_failure);
			error_info->set_desc(mm_error_desc_string(error_desc, error_info->code()));
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, rq_pack, &rq_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		const std::string& _condition = rq_msg.condition();
		mm_uint32_t  _limit = SEARCH_ACCOUNT_RQ_LIMIT;
		//////////////////////////////////////////////////////////////////////////
		struct mm_db_mysql* db_mysql = mm_db_mysql_section_thread_instance(&impl->db_sql_section);
		{
			mm::p_userinfo_search query;
			query.limit = _limit;
			query.search = _condition;
			if (db_mysql_state_success != query.query(db_mysql, MM_LOG_INFO))
			{
				error_info->set_code(err_common_exec_procedure_failure);
				error_info->set_desc(mm_error_desc_string(error_desc, error_info->code()));
				break;
			}
			if (0 != query.code)
			{
				error_info->set_code(query.code);
				error_info->set_desc(mm_error_desc_string(error_desc, error_info->code()));
				break;
			}
			//拼装sql返回select容器内容
			//typedef 做一个短名称
			typedef mm::p_userinfo_search::user_basic_vec user_basic_vec;
			user_basic_vec& vec = query.user_info_s;
			//遍历容器
			for (user_basic_vec::iterator it = vec.begin();
				it != vec.end(); it++)
			{
				//protobuf repeated 字段元素添加函数，获取的是容器元素类型
				b_business_account::user_info* u = user_info_s->Add();
				//获取具体迭代器包含的元素引用
				mm::t_user_basic& e = *it;
				//对拷贝数据
				u->set_user_id(e.id);
				u->set_user_name(e.name);
				u->set_user_nick(e.nick);
				u->set_create_time(e.create_time);
			}
		}
		//////////////////////////////////////////////////////////////////////////
	} while (0);
	// rs
	mm_tcp_o_lock(tcp);
	mm_protobuf_cxx_n_tcp_append_rs(mailbox, tcp, c_business_account::search_account_rs_msg_id, &rs_msg, rq_pack, &rs_pack);
	mm_protobuf_cxx_n_tcp_flush_send(tcp);
	mm_tcp_o_unlock(tcp);
	// logger rs.
	mm_string_clear(&proto_desc);
	mm_protobuf_cxx_logger_append_packet_message(&proto_desc, &rs_pack, &rs_msg);
	mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
	mm_string_destroy(&proto_desc);
}
//////////////////////////////////////////////////////////////////////////
