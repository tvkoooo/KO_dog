#include "mm_basic_frame_control_s_control_rq.h"
#include "mm_application.h"
#include "core/mm_logger.h"
#include "cxx/protodef/s_control.pb.h"
#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"
//////////////////////////////////////////////////////////////////////////
void hd_s_control_get_logger_rq(struct mm_net_tcp* net_tcp)
{
	struct mm_logger* g_logger = mm_logger_instance();
	char link_name[MM_LINK_NAME_LENGTH] = { 0 };
	mm_socket_string(&net_tcp->tcp.socket, link_name);
	mm_net_tcp_check(net_tcp);
	if (0 == mm_net_tcp_finally_state(net_tcp))
	{
		struct mm_string proto_desc;
		struct mm_packet rq_pack;
		s_control::get_logger_rq rq;

		mm_string_init(&proto_desc);

		mm_protobuf_cxx_q_tcp_append_rq( net_tcp,0, s_control::get_logger_rq_msg_id, &rq, MM_MSG_COMM_HEAD_SIZE, &rq_pack );
		mm_protobuf_cxx_n_tcp_flush_send( &net_tcp->tcp );

		mm_protobuf_cxx_logger_append_packet_message( &proto_desc, &rq_pack, &rq );
		mm_logger_log_I(g_logger,"%s %d nt rq:%s",__FUNCTION__,__LINE__,proto_desc.s);

		mm_string_destroy(&proto_desc);
	}
	else
	{
		mm_logger_log_E(g_logger,"%s %d net %s connect failure.",__FUNCTION__,__LINE__,link_name);
	}
}
void hd_s_control_set_logger_rq(struct mm_net_tcp* net_tcp,mm_uint32_t level)
{
	struct mm_logger* g_logger = mm_logger_instance();
	char link_name[MM_LINK_NAME_LENGTH] = { 0 };
	mm_socket_string(&net_tcp->tcp.socket, link_name);
	mm_net_tcp_check(net_tcp);
	if (0 == mm_net_tcp_finally_state(net_tcp))
	{
		struct mm_string proto_desc;
		struct mm_packet rq_pack;
		s_control::set_logger_rq rq;

		mm_string_init(&proto_desc);

		rq.set_level(level);

		mm_protobuf_cxx_q_tcp_append_rq( net_tcp,0, s_control::set_logger_rq_msg_id, &rq, MM_MSG_COMM_HEAD_SIZE, &rq_pack );
		mm_protobuf_cxx_n_tcp_flush_send( &net_tcp->tcp );

		mm_protobuf_cxx_logger_append_packet_message( &proto_desc, &rq_pack, &rq );
		mm_logger_log_I(g_logger,"%s %d nt rq:%s",__FUNCTION__,__LINE__,proto_desc.s);

		mm_string_destroy(&proto_desc);
	}
	else
	{
		mm_logger_log_E(g_logger,"%s %d net %s connect failure.",__FUNCTION__,__LINE__,link_name);
	}
}
//////////////////////////////////////////////////////////////////////////
