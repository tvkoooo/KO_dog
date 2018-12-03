#include "network/network_handle.h"
#include "core/mm_logger.h"

#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"

void mm_client_tcp_flush_send_message(struct mm_client_tcp* p, mm_uint64_t uid, mm_uint32_t mid, ::google::protobuf::Message *message)
{
	struct mm_logger* g_logger = mm_logger_instance();
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

void mm_client_udp_flush_send_message(struct mm_client_udp* p, mm_uint64_t uid, mm_uint32_t mid, ::google::protobuf::Message *message, struct mm_sockaddr* remote)
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