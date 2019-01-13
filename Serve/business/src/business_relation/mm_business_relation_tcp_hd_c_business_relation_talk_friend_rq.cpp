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


//#include "mm_business_nt_message_sql.h"
//////////////////////////////////////////////////////////////////////////
void mm_business_relation_tcp_hd_c_business_relation_talk_friend_rq(void* obj, void* u, struct mm_packet* rq_pack)
{
	c_business_relation::talk_friend_rq rq_msg;
	c_business_relation::talk_friend_rs rs_msg;
	c_business_relation::talk_friend_nt nt_msg;

	struct mm_packet rs_pack;
	struct mm_packet nt_pack;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	struct mm_mailbox* mailbox = (struct mm_mailbox*)(tcp->callback.obj);
	struct mm_business_relation* impl = (struct mm_business_relation*)(u);
//	struct mm_business_nt_message_sql* nt_message_sql= &impl->nt_message_sql;
	struct mm_error_desc* error_desc = &impl->error_desc;
	////////////////////////////////
	error_info->set_code(0);
	error_info->set_desc("");
	rs_msg.set_user_talk_id(0);
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
		mm_uint64_t user_myself_id = rq_msg.user_myself_id();
		mm_uint64_t user_talk_id = rq_msg.user_talk_id();
		const std::string& talking = rq_msg.talking();
		rs_msg.set_user_talk_id(user_talk_id);
		//////////////////////////////////////////////////////////////////////////
		//拼装nt包
		nt_msg.set_apply_talk_id(user_myself_id);
		nt_msg.set_talking(talking);
		//////////////////////////////////////////////////////////////////////////
		////对nt包放入回退队并列做流处理,存储sql后发送回推队列
		//mm_business_nt_message_sql_stored_procedure(nt_message_sql,
		//	user_myself_id, user_talk_id, c_business_relation::talk_friend_nt_msg_id, &nt_msg,
		//	&nt_pack);
		//////////////////////////////////////////////////////////////////////////
		//对nt包进行 cback 回推发送
		struct mm_packet_head packet_head;

		packet_head.mid = c_business_relation::talk_friend_nt_msg_id;
		packet_head.pid = 0;
		packet_head.sid = 0;
		packet_head.uid = user_talk_id;

		mm_message_lpusher_lpush_buffer_protobuf(&impl->message_lpusher, &nt_msg, &packet_head, &nt_pack);

		// logger nt.
		mm_string_clear(&proto_desc);
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, &nt_pack, &nt_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);

	} while (0);
	//如果break出来，说明是有错误发生，需要服务器打印错误信息
	if (0 != error_info->code())
	{
		mm_logger_log_W(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
	}

	// rs
	mm_tcp_o_lock(tcp);
	mm_protobuf_cxx_n_tcp_append_rs(mailbox, tcp, c_business_relation::talk_friend_rs_msg_id, &rs_msg, rq_pack, &rs_pack);
	mm_protobuf_cxx_n_tcp_flush_send(tcp);
	mm_tcp_o_unlock(tcp);
	// logger rs.
	mm_string_clear(&proto_desc);
	mm_protobuf_cxx_logger_append_packet_message( &proto_desc, &rs_pack, &rs_msg );
	mm_logger_log_I(g_logger,"%s %d %s",__FUNCTION__,__LINE__,proto_desc.s);
	mm_string_destroy(&proto_desc);
}
//////////////////////////////////////////////////////////////////////////
