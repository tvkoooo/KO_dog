#include "mm_basic_frame_control_s_control_rs.h"
#include "mm_application.h"
#include "core/mm_logger_manager.h"
#include "net/mm_net_tcp.h"
#include "cxx/protodef/s_control.pb.h"
#include "protobuf/mm_protobuff_cxx.h"
//////////////////////////////////////////////////////////////////////////
void hd_s_control_get_logger_rs(void* obj,void* u,struct mm_packet* rs_pack)
{
	char link_name[MM_LINK_NAME_LENGTH] = { 0 };
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	struct mm_basic_frame_control* impl = (struct mm_basic_frame_control*)(u);
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_string proto_desc;
	mm_socket_string(&tcp->socket,link_name);
	mm_string_init(&proto_desc);
	s_control::get_logger_rs rs;
	if (0 == mm_protobuf_cxx_decode_message(rs_pack, &rs))
	{
		mm_protobuf_cxx_logger_append_packet_message( &proto_desc, rs_pack, &rs );
		mm_logger_log_I(g_logger,"%s %d nt rq:%s",__FUNCTION__,__LINE__,proto_desc.s);

		mm_printf("%s logger level:%2d\n", link_name,rs.level());
		mm_cmd_stdin_flush_prompt(&impl->commond);
	}
	else
	{
		mm_protobuf_cxx_logger_append_packet( &proto_desc, rs_pack );
		mm_logger_log_W(g_logger,"%s %d nt rs:%s",__FUNCTION__,__LINE__,proto_desc.s);
	}
	mm_string_destroy(&proto_desc);
}
void hd_s_control_set_logger_rs(void* obj,void* u,struct mm_packet* rs_pack)
{
	char link_name[MM_LINK_NAME_LENGTH] = { 0 };
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	struct mm_basic_frame_control* impl = (struct mm_basic_frame_control*)(u);
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_string proto_desc;
	mm_socket_string(&tcp->socket, link_name);
	mm_string_init(&proto_desc);
	s_control::set_logger_rs rs;
	if (0 == mm_protobuf_cxx_decode_message(rs_pack, &rs))
	{
		mm_protobuf_cxx_logger_append_packet_message( &proto_desc, rs_pack, &rs );
		mm_logger_log_I(g_logger,"%s %d nt rq:%s",__FUNCTION__,__LINE__,proto_desc.s);

		mm_printf("%s logger level:%2d\n", link_name,rs.level());
		mm_cmd_stdin_flush_prompt(&impl->commond);
	}
	else
	{
		mm_protobuf_cxx_logger_append_packet( &proto_desc, rs_pack );
		mm_logger_log_W(g_logger,"%s %d nt rs:%s",__FUNCTION__,__LINE__,proto_desc.s);
	}
	mm_string_destroy(&proto_desc);
}
//////////////////////////////////////////////////////////////////////////
