#include "network/network_handle.h"
#include "core/mm_logger.h"

#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"
#include "application/KO_dog.h"
#include "application/KO_dog_error_code.h"

#include "script/KO_dog_script_error_code.h"

void mm_client_tcp_flush_send_message(struct mm_client_tcp* p, mm_uint64_t uid, mm_uint32_t mid, ::google::protobuf::Message *message)
{
	struct mm_logger* g_logger = mm_logger_instance();
	// note: if state not at ts_motion, is interrupt of shutdown.
	if (ts_motion == p->state)
	{
		struct mm_string proto_desc;
		struct mm_packet rq_pack;
		mm_packet_init(&rq_pack);
		mm_string_init(&proto_desc);

		mm_protobuf_cxx_q_client_tcp_flush_message_append(p, uid, mid, message, MM_MSG_COMM_HEAD_SIZE, &rq_pack);
		mm_protobuf_cxx_q_client_tcp_flush_signal(p);

		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, &rq_pack, message);

		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		mm_packet_destroy(&rq_pack);
		mm_string_destroy(&proto_desc);
	}
	else
	{
		mm_logger_log_I(g_logger, "%s %d mm_client_tcp state not at ts_motion, need do nothing", __FUNCTION__, __LINE__);
		mm::KO_dog* impl = (mm::KO_dog*)p->u;
		//发布到界面输出错误日志    发布内容  evt_ags
		mm::KO_dog_data_log_view* data_log_view = &impl->data.data_log_view;
		mm::mm_event_data_log_view evt_ags;
		evt_ags.code = KO_dog_error_code_network_anomaly;
		evt_ags.desc = mm_error_desc_string(&impl->error_desc, evt_ags.code);
		KO_dog_script_error_code_get_view(impl->lua_context.state, evt_ags.code, evt_ags.view);		
		data_log_view->push(evt_ags);
	}
}
void mm_client_tcps_flush_send_message(struct mm_client_tcp* p, mm_uint64_t uid, mm_uint32_t mid, ::google::protobuf::Message *message)
{
	struct mm_logger* g_logger = mm_logger_instance();
	// note: if state not at ts_motion, is interrupt of shutdown.

	mm::KO_dog* impl = (mm::KO_dog*)p->u;
	struct KO_dog_network* network = &impl->network;

	if (tcps_connect::tcps_state_finish == network->tcps.state)
	{
		mm_client_tcp_flush_send_message(p, uid, mid, message);
	}
	else
	{
		mm_logger_log_I(g_logger, "%s %d mm_client_tcps state not at tcps_state_finish, need do nothing", __FUNCTION__, __LINE__);
		mm::KO_dog* impl = (mm::KO_dog*)p->u;
		//发布到界面输出错误日志    发布内容  evt_ags
		mm::KO_dog_data_log_view* data_log_view = &impl->data.data_log_view;
		mm::mm_event_data_log_view evt_ags;
		evt_ags.code = KO_dog_error_code_unencrypted_network;
		evt_ags.desc = mm_error_desc_string(&impl->error_desc, evt_ags.code);
		KO_dog_script_error_code_get_view(impl->lua_context.state, evt_ags.code, evt_ags.view);
		data_log_view->push(evt_ags);
	}
}
void mm_client_udp_flush_send_message(struct mm_client_udp* p, mm_uint64_t uid, mm_uint32_t mid, ::google::protobuf::Message *message, struct mm_sockaddr* remote)
{
	struct mm_logger* g_logger = mm_logger_instance();
	// note: if state not at ts_motion, is interrupt of shutdown.
	if (ts_motion == p->state)
	{
		struct mm_logger* g_logger = mm_logger_instance();
		struct mm_string proto_desc;
		struct mm_packet rq_pack;
		mm_packet_init(&rq_pack);
		mm_string_init(&proto_desc);

		mm_protobuf_cxx_q_client_udp_flush_message_append(p, uid, mid, message, MM_MSG_COMM_HEAD_SIZE, &rq_pack, remote);
		mm_protobuf_cxx_q_client_udp_flush_signal(p);

		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, &rq_pack, message);

		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		mm_packet_destroy(&rq_pack);
		mm_string_destroy(&proto_desc);
	}
	else
	{
		mm_logger_log_I(g_logger, "%s %d mm_client_udp state not at ts_motion, need do nothing", __FUNCTION__, __LINE__);
		mm::KO_dog* impl = (mm::KO_dog*)p->u;
		//发布到界面输出错误日志    发布内容  evt_ags
		mm::KO_dog_data_log_view* data_log_view = &impl->data.data_log_view;
		mm::mm_event_data_log_view evt_ags;
		evt_ags.code = KO_dog_error_code_network_anomaly;
		evt_ags.desc = mm_error_desc_string(&impl->error_desc, evt_ags.code);
		KO_dog_script_error_code_get_view(impl->lua_context.state, evt_ags.code, evt_ags.view);
		data_log_view->push(evt_ags);
	}
}