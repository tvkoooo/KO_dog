#include "mm_business_nt_message_tcp_hd.h"
#include "core/mm_logger.h"
#include "core/mm_time_cache.h"
#include "net/mm_packet.h"
#include "net/mm_streambuf_packet.h"
#include "shuttle_common/mm_error_code_common.h"
#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"
#include "cxx/protodef/c_business_nt_message.pb.h"
#include "mm_business_nt_message.h"
#include "mm_error_code_business_nt_message.h"

#include "querydef/mm_q_db_ko_dog_t_user_basic.h"
#include "querydef/mm_q_db_ko_dog_t_nt_message.h"
#include "querydef/mm_m_db_ko_dog_t_user_basic.h"
//////////////////////////////////////////////////////////////////////////
void mm_business_nt_message_tcp_hd_c_business_nt_message_all_unread_rq(void* obj, void* u, struct mm_packet* rq_pack)
{
	c_business_nt_message::nt_message_all_unread_rq rq_msg;
	c_business_nt_message::nt_message_all_unread_rs rs_msg;
	struct mm_packet rs_pack;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	struct mm_mailbox* mailbox = (struct mm_mailbox*)(tcp->callback.obj);
	struct mm_business_nt_message* impl = (struct mm_business_nt_message*)(u);
	struct mm_error_desc* error_desc = &impl->error_desc;
	////////////////////////////////
	error_info->set_code(0);
	error_info->set_desc("");
	rs_msg.set_user_id(0);
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
		mm_protobuf_cxx_logger_append_packet_message( &proto_desc, rq_pack, &rq_msg );
		mm_logger_log_I(g_logger,"%s %d %s",__FUNCTION__,__LINE__,proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		mm_uint64_t user_id = rq_msg.user_id();
		//////////////////////////////////////////////////////////////////////////
		struct mm_db_mysql* db_mysql = mm_db_mysql_section_thread_instance(&impl->db_sql_section);
		{
			mm::p_nt_message_read_by_to_user_id query;
			query.to_user_id = user_id;
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
			//
			//拼装回包内容
			//typedef 做一个短名称
			typedef mm::p_nt_message_read_by_to_user_id::nt_message_vec message_vec;
			message_vec& vec = query.nt_message_s;
			//遍历容器
			for (message_vec::iterator it = vec.begin();
				it != vec.end(); it++)
			{
				//获取具体迭代器包含的元素引用
				mm::t_nt_message& e = *it;
				//根据获取的元素，拼装信息发到回退队列
				mm_message_lpusher_lpush_buffer(&impl->message_lpusher, (mm_uint8_t*)e.nt_message.data(), 0, e.nt_message.size());
			}
		}
		//////////////////////////////////////////////////////////////////////////
	} while (0);
	// rs
	mm_tcp_lock(tcp);
	mm_protobuf_cxx_n_tcp_append_rs(mailbox, tcp, c_business_nt_message::nt_message_all_unread_rs_msg_id, &rs_msg, rq_pack, &rs_pack);
	mm_protobuf_cxx_n_tcp_flush_send(tcp);
	mm_tcp_unlock(tcp);
	// logger rs.
	mm_string_clear(&proto_desc);
	mm_protobuf_cxx_logger_append_packet_message( &proto_desc, &rs_pack, &rs_msg );
	mm_logger_log_I(g_logger,"%s %d %s",__FUNCTION__,__LINE__,proto_desc.s);
	mm_string_destroy(&proto_desc);
}
//////////////////////////////////////////////////////////////////////////
