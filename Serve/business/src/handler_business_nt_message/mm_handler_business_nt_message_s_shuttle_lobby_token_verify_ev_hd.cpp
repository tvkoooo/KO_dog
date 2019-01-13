#include "mm_handler_business_nt_message_hd.h"

#include "core/mm_logger.h"
#include "core/mm_time_cache.h"

#include "net/mm_packet.h"

#include "redis/mm_redis_list.h"

#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"

#include "cxx/protodef/c_business_nt_message.pb.h"
#include "cxx/protodef/s_shuttle_lobby.pb.h"


#include "shuttle_common/mm_error_code_common.h"

#include "mm_handler_business_nt_message.h"

#include "querydef/mm_q_db_ko_dog_t_nt_message.h"
#include "querydef/mm_m_db_ko_dog_t_nt_message.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void hd_s_shuttle_lobby_token_verify_ev(void* obj, void* u, struct mm_packet* ev_pack)
{
	s_shuttle_lobby::token_verify_ev ev_msg;
	b_error::info error_info_impl;
	b_error::info* error_info = &error_info_impl;
	struct mm_string proto_desc;
	//
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_handler_business_nt_message* impl = (struct mm_handler_business_nt_message*)(u);
	struct mm_error_desc* error_desc = &impl->error_desc;
	////////////////////////////////
	error_info->set_code(0);
	error_info->set_desc("");
	////////////////////////////////
	mm_string_init(&proto_desc);
	do
	{
		if (0 != mm_protobuf_cxx_decode_message(ev_pack, &ev_msg))
		{
			error_info->set_code(err_common_package_decode_failure);
			error_info->set_desc(mm_error_desc_string(error_desc, error_info->code()));
			break;
		}
		// logger ev.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, ev_pack, &ev_msg);
		mm_logger_log_D(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		mm_uint64_t uid = ev_msg.uid();
		if (0 != uid)
		{
			struct mm_db_mysql* db_mysql = mm_db_mysql_section_thread_instance(&impl->db_sql_section);
			{
				mm::p_nt_message_read_by_to_user_id query;
				query.to_user_id = uid;
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
				//ƴװ�ذ�����
				//typedef ��һ��������
				typedef mm::p_nt_message_read_by_to_user_id::nt_message_vec message_vec;
				message_vec& vec = query.nt_message_s;
				//��������
				for (message_vec::iterator it = vec.begin();
					it != vec.end(); it++)
				{
					//��ȡ���������������Ԫ������
					mm::t_nt_message& e = *it;
					//���ݻ�ȡ��Ԫ�أ�ƴװ��Ϣ�������˶���
					mm_message_lpusher_lpush_buffer(&impl->message_lpusher,(mm_uint8_t*)e.nt_message.data(), 0, e.nt_message.size());
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		// logger.
		//////////////////////////////////////////////////////////////////////////
	} while (0);
	// logger error.
	if (0 != error_info->code())
	{
		mm_uint32_t code = error_info->code();
		const std::string& desc = error_info->desc();
		mm_logger_log_E(g_logger, "%s %d (%u)%s", __FUNCTION__, __LINE__, code, desc.c_str());
	}
}
