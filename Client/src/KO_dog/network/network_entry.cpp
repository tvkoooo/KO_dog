#include "network_entry.h"
#include "KO_dog_network.h"
#include "core/mm_logger.h"
#include "application/KO_dog.h"
#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"

void network_entry_callback_function_registration(struct KO_dog_network* p)
{
	mm_client_udp_assign_n_callback(&p->udp, c_basic_frame_entry::knock_rs_msg_id, &hd_n_c_basic_frame_entry_knock_rs);
}


void mm_client_udp_send_message(struct mm_client_udp* p, struct mm_packet_head* packet_head, mm_uint32_t hlength, ::google::protobuf::Message* message, struct mm_sockaddr* remote)
{

}
void mm_client_udp_flush_send_knock_rq_msg_id(struct mm_client_udp* p)
{
	c_basic_frame_entry::knock_rq knock_rq;
	struct mm_packet_head packet_head;
	mm_packet_head_init(&packet_head);

	packet_head.mid = c_basic_frame_entry::knock_rq_msg_id;
	packet_head.pid = 0;
	packet_head.sid = 0;
	packet_head.uid = 0;

	mm_client_udp_send_message(p, &packet_head, MM_MSG_COMM_HEAD_SIZE, &knock_rq, &p->ss_remote);
	mm_client_udp_flush_signal(p);

	mm_packet_head_destroy(&packet_head);
}

void hd_n_c_basic_frame_entry_knock_rs(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	c_basic_frame_entry::knock_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_udp* udp = (struct mm_udp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);
	do
	{
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		//
		const b_network::address& g = rs_msg.addr();
		mm::KO_dog_data_net* data_net = &impl->data.data_net;

		//数据更新
		data_net->lobby_ip = g.host();
		data_net->lobby_port = g.port();

		//数据更新以后的事件发布    发布内容  evt_ags
		mm_event_args evt_ags;
		data_net->d_event_set.fire_event(mm::KO_dog_data_net::event_lobby_update, evt_ags);
		//////////////////////////////////////////////////////////////////////////
		KO_dog_network_client_tcp_assign_remote_target(&impl->network, g.host().c_str(), g.port());
	} while (0);
}