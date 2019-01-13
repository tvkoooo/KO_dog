#include "mm_business_relation_tcp_hd.h"
#include "core/mm_logger.h"
#include "core/mm_time_cache.h"
#include "core/mm_value_transform.h"

#include "net/mm_packet.h"
#include "net/mm_streambuf_packet.h"
#include "shuttle_common/mm_error_code_common.h"
#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"
#include "cxx/protodef/c_business_relation.pb.h"

#include "mm_business_relation.h"
#include "mm_error_code_business_relation.h"

#include "querydef/mm_q_db_ko_dog_t_user_relation.h"
#include "querydef/mm_m_db_ko_dog_t_user_relation.h"

//#include "mm_business_nt_message_sql.h"
//////////////////////////////////////////////////////////////////////////
void mm_business_relation_tcp_hd_c_business_relation_query_friends_rq(void* obj, void* u, struct mm_packet* rq_pack)
{
	c_business_relation::query_friends_rq rq_msg;
	c_business_relation::query_friends_rs rs_msg;

	struct mm_packet rs_pack;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	struct mm_mailbox* mailbox = (struct mm_mailbox*)(tcp->callback.obj);
	struct mm_business_relation* impl = (struct mm_business_relation*)(u);
	//struct mm_business_nt_message_sql* nt_message_sql= &impl->nt_message_sql;
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
		mm_protobuf_cxx_logger_append_packet_message( &proto_desc, rq_pack, &rq_msg );
		mm_logger_log_I(g_logger,"%s %d %s",__FUNCTION__,__LINE__,proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		//rq��Я������
		mm_uint64_t user_myself_id = rq_msg.user_myself_id();
		//////////////////////////////////////////////////////////////////////////
		//�������ݿ⣨��ѯ����--���ذ������б�ͺ����б�
		struct mm_db_mysql* db_mysql = mm_db_mysql_section_thread_instance(&impl->db_sql_section);
		{

			mm::p_user_relation_query_friends query;
			query.myself_id = user_myself_id;
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
			//ƴװ���б�
			{
				//ƴװrs����relation_s �������ݣ�typedef ��һ��������
				typedef ::google::protobuf::RepeatedPtrField< ::b_business_relation::user_relation_group > b_user_relation_group_v;
				b_user_relation_group_v* user_relation_group_s = rs_msg.mutable_group_s();

				//ƴװsql����select�������ݣ�typedef ��һ��������
				typedef mm::p_user_relation_query_friends::user_relation_assist_vec user_relation_assist_vec;
				user_relation_assist_vec& vec = query.user_relation_assist_s;
				//��������
				for (user_relation_assist_vec::iterator it = vec.begin();
					it != vec.end(); it++)
				{
					//protobuf repeated �ֶ�Ԫ����Ӻ�������ȡ��������Ԫ������
					b_business_relation::user_relation_group* u = user_relation_group_s->Add();
					//��ȡ���������������Ԫ������
					mm::t_user_relation_assist& e = *it;
					//�Կ�������
					u->set_id(e.id);
					u->set_user_id(e.user_id);
					u->set_friend_group(e.friend_group);
				}
			}
			//ƴװ�����б�
			{
				//ƴװrs����relation_s �������ݣ�typedef ��һ��������
				typedef ::google::protobuf::RepeatedPtrField< ::b_business_relation::user_relation > b_user_relation_v;
				b_user_relation_v* user_relation_s = rs_msg.mutable_relation_s();

				//ƴװsql����select�������ݣ�typedef ��һ��������
				typedef mm::p_user_relation_query_friends::user_relation_vec user_relation_vec;
				user_relation_vec& vec = query.user_relation_s;
				//��������
				for (user_relation_vec::iterator it = vec.begin();
					it != vec.end(); it++)
				{
					//protobuf repeated �ֶ�Ԫ����Ӻ�������ȡ��������Ԫ������
					b_business_relation::user_relation* u = user_relation_s->Add();
					//��ȡ���������������Ԫ������
					mm::t_user_relation& e = *it;
					//�Կ�������
					u->set_user_id(e.user_id);
					u->set_friend_group_id(e.friend_group_id);
					u->set_friend_id(e.friend_id);
					u->set_friend_remark(e.friend_remark);
					u->set_build_friend_time(e.build_friend_time);
				}
			}
		}
	} while (0);
	//���break������˵�����д���������Ҫ��������ӡ������Ϣ
	if (0 != error_info->code())
	{
		mm_logger_log_W(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
	}

	// rs
	mm_tcp_o_lock(tcp);
	mm_protobuf_cxx_n_tcp_append_rs(mailbox, tcp, c_business_relation::query_friends_rs_msg_id, &rs_msg, rq_pack, &rs_pack);
	mm_protobuf_cxx_n_tcp_flush_send(tcp);
	mm_tcp_o_unlock(tcp);
	// logger rs.
	mm_string_clear(&proto_desc);
	mm_protobuf_cxx_logger_append_packet_message( &proto_desc, &rs_pack, &rs_msg );
	mm_logger_log_I(g_logger,"%s %d %s",__FUNCTION__,__LINE__,proto_desc.s);
	mm_string_destroy(&proto_desc);
}
//////////////////////////////////////////////////////////////////////////
