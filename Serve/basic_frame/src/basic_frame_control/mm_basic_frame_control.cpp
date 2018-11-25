#include "mm_basic_frame_control.h"
#include "core/mm_logger.h"
#include "core/mm_time_cache.h"
#include "core/mm_timer.h"
#include "net/mm_streambuf_packet.h"
#include "net/mm_default_handle.h"

#include "dish/mm_json.h"

#include "protobuf/mm_protobuff_cxx.h"

#include "shuttle_common/mm_error_code_mysql.h"
#include "shuttle_common/mm_error_code_common.h"
#include "shuttle_common/mm_error_code_core.h"

#include "cxx/protodef/s_control.pb.h"
#include "mm_basic_frame_control_s_control_rs.h"
#include "mm_basic_frame_control_s_control_rq.h"
#include "mm_application.h"

//////////////////////////////////////////////////////////////////////////
void __static_server_control_cmd_stdin_handle(void* obj,const char* buff,size_t size);
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_control_init(struct mm_basic_frame_control* p)
{
	struct mm_cmd_stdin_callback stdin_callback;
	struct mm_net_tcp_callback net_tcp_callback;

	mm_net_tcp_init(&p->net_tcp);
	mm_cmd_stdin_init(&p->commond);
	//
	stdin_callback.handle = &__static_server_control_cmd_stdin_handle;
	stdin_callback.obj = p;
	mm_cmd_stdin_assign_callback(&p->commond,&stdin_callback);

	net_tcp_callback.handle = &mm_net_tcp_handle_default;
	net_tcp_callback.broken = &mm_net_tcp_broken_default;
	net_tcp_callback.nready = &mm_net_tcp_nready_default;
	net_tcp_callback.finish = &mm_net_tcp_finish_default;
	net_tcp_callback.obj = p;
	mm_net_tcp_assign_net_tcp_callback(&p->net_tcp,&net_tcp_callback);
	//
	mm_protobuf_cxx_init();
}
void mm_basic_frame_control_destroy(struct mm_basic_frame_control* p)
{
	google::protobuf::ShutdownProtobufLibrary();
	mm_protobuf_cxx_destroy();
	//
	mm_net_tcp_init(&p->net_tcp);
	mm_cmd_stdin_init(&p->commond);
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_control_assign_addr_target(struct mm_basic_frame_control* p,const char* info)
{
	char addr_name[MM_ADDR_NAME_LENGTH] = {0};
	char node_name[MM_NODE_NAME_LENGTH] = {0};
	mm_ushort_t port = 0;
	mm_strcpy(addr_name,info);
	mm_sockaddr_format_decode_string(addr_name,node_name,&port);

	char prompt[MM_NODE_NAME_LENGTH] = {0};
	mm_sprintf(prompt,"%s>",info);
	mm_cmd_stdin_assign_prompt(&p->commond,prompt);
	//
	mm_net_tcp_detach_socket(&p->net_tcp);
	mm_net_tcp_assign_remote(&p->net_tcp,node_name,port);
}
void mm_basic_frame_control_command_set_logger(struct mm_basic_frame_control* p, mm_uint32_t level)
{
	hd_s_control_set_logger_rq(&p->net_tcp, level);
}
void mm_basic_frame_control_command_get_logger(struct mm_basic_frame_control* p)
{
	hd_s_control_get_logger_rq(&p->net_tcp);
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_control_start(struct mm_basic_frame_control* p)
{
	mm_net_tcp_assign_callback(&p->net_tcp,s_control::get_logger_rs_msg_id,&hd_s_control_get_logger_rs);
	mm_net_tcp_assign_callback(&p->net_tcp,s_control::set_logger_rs_msg_id,&hd_s_control_set_logger_rs);
	//
	mm_net_tcp_assign_context(&p->net_tcp,p);
	//
	mm_net_tcp_start(&p->net_tcp);
	mm_cmd_stdin_start(&p->commond);
}
void mm_basic_frame_control_interrupt(struct mm_basic_frame_control* p)
{
	mm_net_tcp_interrupt(&p->net_tcp);
	mm_cmd_stdin_interrupt(&p->commond);
}
void mm_basic_frame_control_shutdown(struct mm_basic_frame_control* p)
{
	mm_net_tcp_shutdown(&p->net_tcp);
	mm_cmd_stdin_shutdown(&p->commond);
}
void mm_basic_frame_control_join(struct mm_basic_frame_control* p)
{
	mm_net_tcp_join(&p->net_tcp);
	mm_cmd_stdin_join(&p->commond);
}
//////////////////////////////////////////////////////////////////////////
void __static_server_control_cmd_stdin_handle(void* obj,const char* buff,size_t size)
{
	char cmd[MM_COMMOND_MAX_LINE];
	//////////////////////////////////////////////////////////////////////////////
	struct mm_cmd_stdin* commond = (struct mm_cmd_stdin*)(obj);
	struct mm_basic_frame_control* server_control = (struct mm_basic_frame_control*)(commond->callback.obj);
	//////////////////////////////////////////////////////////////////////////////
	mm_sscanf(buff,"%s ",cmd);
	//////////////////////////////////////////////////////////////////////////////
	if(!mm_strcmp(cmd, "q"))
	{
		struct mm_application* g_application = mm_application_instance();
		mm_application_interrupt(g_application);
	}
	else if(!mm_strcmp(cmd, "set_logger"))
	{
		int level = 0;
		mm_sscanf(buff,"%s %d",cmd,&level);
		hd_s_control_set_logger_rq(&server_control->net_tcp,level);
	}
	else if(!mm_strcmp(cmd, "get_logger"))
	{
		hd_s_control_get_logger_rq(&server_control->net_tcp);
	}
	else if(!mm_strcmp(cmd, "connect"))
	{
		char addr_name[MM_ADDR_NAME_LENGTH] = {0};
		mm_sscanf(buff,"%s %s",cmd,addr_name);
		mm_basic_frame_control_assign_addr_target(server_control,addr_name);
	}
	else
	{
		mm_printf("unreconized command: %s\n", cmd);
	}
}