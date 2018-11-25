#include "mm_basic_frame_entry_udp_hd.h"
#include "core/mm_logger.h"
#include "net/mm_packet.h"
#include "net/mm_streambuf_packet.h"
#include "shuttle_common/mm_error_code_common.h"
#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"
#include "cxx/protodef/c_basic_frame_entry.pb.h"
#include "mm_basic_frame_entry.h"
#include "mm_basic_frame_entry_error_code.h"
//////////////////////////////////////////////////////////////////////////
void c_basic_frame_entry_knock_rq( void* obj, void* u, struct mm_packet* rq_pack, struct mm_sockaddr* remote )
{
	c_basic_frame_entry::knock_rq rq_msg;
	c_basic_frame_entry::knock_rs rs_msg;
	struct mm_packet rs_pack;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();
	b_network::address* addr_info = rs_msg.mutable_addr();
	//
	mm::mm_m_runtime_state runtime_state;
	char addr_name[MM_ADDR_NAME_LENGTH] = {0};
	char node[MM_NODE_NAME_LENGTH] = {0};
	mm_ushort_t port = 0;
	int cycle_code = 0;
	char cycle_message[128] = {0};
	//
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_udp* udp = (struct mm_udp*)(obj);
	struct mm_headset* headset = (struct mm_headset*)(udp->callback.obj);
	struct mm_basic_frame_entry* basic_frame_entry = (struct mm_basic_frame_entry*)(u);
	struct mm_error_desc* error_desc = &basic_frame_entry->error_desc;
	////////////////////////////////
	error_info->set_code(0);
	error_info->set_desc("");
	addr_info->set_host("0.0.0.0");
	addr_info->set_port(0);
	rs_msg.set_remote_client_version("0.0.0");
	rs_msg.set_remote_source_version("0.0.0");
	rs_msg.set_remote_server_version("0.0.0");
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
		rs_msg.set_remote_client_version(rq_msg.native_client_version());
		rs_msg.set_remote_source_version(rq_msg.native_source_version());
		rs_msg.set_remote_server_version(rq_msg.native_client_version());
		//////////////////////////////////////////////////////////////////////////
		cycle_code = mm_loavger_holder_cycle(&basic_frame_entry->loavger_holder,&runtime_state);
		if (0 == runtime_state.unique_id)
		{
			error_info->set_code(err_basic_frame_entry_lobby_entry_failure);
			error_info->set_desc(mm_error_desc_string(error_desc, error_info->code()));
			mm_sprintf(cycle_message, "(%d)%s", cycle_code, mm_loavger_holder_cycle_error_message(cycle_code));
			mm_logger_log_W(g_logger,"%s %d %s:%d => %s:%d %s",__FUNCTION__,__LINE__,node,port,addr_info->host().c_str(),addr_info->port(),cycle_message);
			break;
		}
		addr_info->set_host(runtime_state.node_external);
		addr_info->set_port(runtime_state.port_external);
		// logger.
		mm_sockaddr_string( remote, addr_name );
		mm_sockaddr_format_decode_string( addr_name, node, &port);
		mm_logger_log_T(g_logger,"%s %d %s:%d => %s:%d",__FUNCTION__,__LINE__,node,port,addr_info->host().c_str(),addr_info->port());
		//////////////////////////////////////////////////////////////////////////
	} while (0);
	// rs
	mm_udp_lock(udp);
	mm_protobuf_cxx_n_udp_buffer_send_reset(udp);
	mm_protobuf_cxx_n_udp_append_rs( headset, udp, c_basic_frame_entry::knock_rs_msg_id, &rs_msg, rq_pack, &rs_pack );
	mm_protobuf_cxx_n_udp_buffer_send_flush(udp,remote);
	mm_udp_unlock(udp);
	// logger rs.
	mm_string_clear(&proto_desc);
	mm_protobuf_cxx_logger_append_packet_message( &proto_desc, &rs_pack, &rs_msg );
	mm_logger_log_I(g_logger,"%s %d %s",__FUNCTION__,__LINE__,proto_desc.s);
	mm_string_destroy(&proto_desc);
}
//////////////////////////////////////////////////////////////////////////
