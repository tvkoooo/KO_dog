#include "network_entry.h"
#include "KO_dog_network.h"
#include "core/mm_logger.h"
#include "application/KO_dog.h"
#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"

#include "protodef/cxx/protodef/c_shuttle_entry.pb.h"

#include "model_data/KO_dog_data_log_view.h"
#include "network_handle.h"


void network_entry_callback_function_registration(struct KO_dog_network* p)
{
	mm_client_udp_assign_n_callback(&p->udp, c_shuttle_entry::knock_rs_msg_id, &hd_n_c_basic_frame_entry_knock_rs);
}

//udp/////////////////////////////////////////////////////////////////////////////////
void mm_client_udp_flush_send_knock_rq_msg_id(struct mm_client_udp* p)
{
	c_shuttle_entry::knock_rq knock_rq;
	b_math::coord* coord_info = knock_rq.mutable_coord_info();
	coord_info->set_j(0);
	coord_info->set_w(0);
	knock_rq.set_native_client_version("");
	knock_rq.set_native_source_version("");
	mm_client_udp_flush_send_message(p,0 , c_shuttle_entry::knock_rq_msg_id, &knock_rq, &p->ss_remote);

}

void hd_n_c_basic_frame_entry_knock_rs(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	c_shuttle_entry::knock_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_udp* udp = (struct mm_udp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);
	
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		// 回包逻辑错误
		const b_network::address& g = rs_msg.addr();
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());	
			
			//发布到界面输出错误日志    发布内容  evt_ags
			mm::KO_dog_data_log_view* data_log_view = &impl->data.data_log_view;
			mm::mm_event_data_log_view evt_ags;
			evt_ags.code = error_info->code();
			evt_ags.desc = error_info->desc();
			evt_ags.view = data_log_view->code_map.get(evt_ags.code);
			data_log_view->d_event_set.fire_event(mm::KO_dog_data_log_view::event_log_view, evt_ags);
		}
		else
		{			
			//数据更新
			mm::KO_dog_data_net* data_net = &impl->data.data_net;
			data_net->lobby_ip = g.host();
			data_net->lobby_port = g.port();
			//
			//数据更新以后的事件发布    发布内容  evt_ags
			mm_event_args evt_ags;
			data_net->d_event_set.fire_event(mm::KO_dog_data_net::event_lobby_update, evt_ags);
			//////////////////////////////////////////////////////////////////////////
			//设置大厅 IP 和 端口
			KO_dog_network_client_tcp_assign_remote_target(&impl->network, g.host().c_str(), g.port());
		}

		//发布到界面视图log

	} while (0);
}

