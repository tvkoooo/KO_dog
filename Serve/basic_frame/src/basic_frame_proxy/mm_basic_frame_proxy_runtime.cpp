﻿#include "mm_basic_frame_proxy_runtime.h"
#include "core/mm_logger_manager.h"
#include "core/mm_os_context.h"
#include "shuttle_common/mm_runtime_calculate.h"
#include "mm_basic_frame_proxy_launch.h"
#include "shuttle_common/mm_j_runtime_state.h"
void mm_basic_frame_proxy_runtime_init(struct mm_basic_frame_proxy_runtime* p)
{
	mm_runtime_stat_init(&p->runtime);
	mm_zkwm_path_init(&p->zkwm_path);
	p->internal_mailbox = NULL;
	p->external_mailbox = NULL;
	p->launch_info = NULL;
	// first update.
	mm_runtime_stat_update(&p->runtime);
}
void mm_basic_frame_proxy_runtime_destroy(struct mm_basic_frame_proxy_runtime* p)
{
	mm_runtime_stat_destroy(&p->runtime);
	mm_zkwm_path_destroy(&p->zkwm_path);
	p->internal_mailbox = NULL;
	p->external_mailbox = NULL;
	p->launch_info = NULL;
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_proxy_runtime_start(struct mm_basic_frame_proxy_runtime* p)
{
	mm_zkwm_path_start(&p->zkwm_path);
}
void mm_basic_frame_proxy_runtime_interrupt(struct mm_basic_frame_proxy_runtime* p)
{
	mm_zkwm_path_interrupt(&p->zkwm_path);
}
void mm_basic_frame_proxy_runtime_shutdown(struct mm_basic_frame_proxy_runtime* p)
{
	mm_zkwm_path_shutdown(&p->zkwm_path);
}
void mm_basic_frame_proxy_runtime_join(struct mm_basic_frame_proxy_runtime* p)
{
	mm_zkwm_path_join(&p->zkwm_path);
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_proxy_runtime_assign_unique_id(struct mm_basic_frame_proxy_runtime* p,mm_uint32_t unique_id)
{
	mm_zkwm_path_assign_unique_id(&p->zkwm_path,unique_id);
	p->runtime_state.unique_id = unique_id;
}
void mm_basic_frame_proxy_runtime_assign_internal_mailbox(struct mm_basic_frame_proxy_runtime* p,struct mm_mailbox* internal_mailbox)
{
	p->internal_mailbox = internal_mailbox;
}
void mm_basic_frame_proxy_runtime_assign_external_mailbox(struct mm_basic_frame_proxy_runtime* p,struct mm_mailbox* external_mailbox)
{
	p->external_mailbox = external_mailbox;
}
void mm_basic_frame_proxy_runtime_assign_launch_info(struct mm_basic_frame_proxy_runtime* p,struct mm_basic_frame_proxy_launch* launch_info)
{
	p->launch_info = launch_info;
}
void mm_basic_frame_proxy_runtime_assign_zkwm_path(struct mm_basic_frame_proxy_runtime* p,const char* path)
{
	mm_zkwm_path_assign_path(&p->zkwm_path,path);
}
void mm_basic_frame_proxy_runtime_assign_zkwm_host(struct mm_basic_frame_proxy_runtime* p,const char* host)
{
	mm_zkwm_path_assign_host(&p->zkwm_path,host);
}
void mm_basic_frame_proxy_runtime_assign_number_id(struct mm_basic_frame_proxy_runtime* p,mm_uint64_t number_id)
{
	mm_zkwm_path_assign_number_id(&p->zkwm_path,number_id);
}
// update runtime value.
void mm_basic_frame_proxy_runtime_update_runtime(struct mm_basic_frame_proxy_runtime* p)
{
	char node[MM_NODE_NAME_LENGTH] = {0};
	mm_ushort_t port = 0;
	if ( NULL != p->internal_mailbox )
	{
		mm_sockaddr_node_port( &p->internal_mailbox->accepter.socket.ss_native, node, &port );
		p->runtime_state.node_internal = node;
		p->runtime_state.port_internal = port;
		p->runtime_state.workers_internal = mm_mailbox_get_length(p->internal_mailbox);
	}
	else
	{
		p->runtime_state.node_internal = MM_ADDR_DEFAULT_NODE;
		p->runtime_state.port_internal = MM_ADDR_DEFAULT_PORT;
		p->runtime_state.workers_internal = 0;
	}
	if ( NULL != p->external_mailbox )
	{
		mm_sockaddr_node_port( &p->external_mailbox->accepter.socket.ss_native, node, &port );
		p->runtime_state.node_external = node;
		p->runtime_state.port_external = port;
		p->runtime_state.workers_external = mm_mailbox_get_length(p->external_mailbox);
	}
	else
	{
		p->runtime_state.node_external = MM_ADDR_DEFAULT_NODE;
		p->runtime_state.port_external = MM_ADDR_DEFAULT_PORT;
		p->runtime_state.workers_external = 0;
	}
	{
		// update the machine information.
		mm_runtime_stat_update(&p->runtime);
		mm_runtime_state_update(&p->runtime_state, &p->runtime);
	}
	{
		// update zookeeper.
		rapidjson::StringBuffer string_buffer;
		rapidjson::Document _jc(rapidjson::kObjectType);
		rapidjson::Writer<rapidjson::StringBuffer> _writer(string_buffer);
		mm::mm_j_runtime_state j_runtime_state(p->runtime_state);
		j_runtime_state.encode(_jc,_jc);
		string_buffer.Clear();
		_writer.Reset(string_buffer);
		_jc.Accept(_writer);
		mm_string_assigns(&p->zkwm_path.value_buffer,string_buffer.GetString());
	}
	{
		mm_zkwm_path_assign_number_id(&p->zkwm_path,p->launch_info->number_id);
		//
		p->launch_module.unique_id = p->launch_info->module;
		p->launch_module.mid_l = p->launch_info->mid_l;
		p->launch_module.mid_r = p->launch_info->mid_r;
		p->launch_module.shard_size = p->launch_info->shard;
		p->launch_module.depth_size = 0;
		//
		rapidjson::StringBuffer string_buffer;
		rapidjson::Document _jc(rapidjson::kObjectType);
		rapidjson::Writer<rapidjson::StringBuffer> _writer(string_buffer);
		mm::mm_j_config_module j_launch_module(p->launch_module);
		j_launch_module.encode(_jc,_jc);
		string_buffer.Clear();
		_writer.Reset(string_buffer);
		_jc.Accept(_writer);
		mm_string_assigns(&p->zkwm_path.shard_buffer,string_buffer.GetString());
	}
}
// commit db.
void mm_basic_frame_proxy_runtime_commit_db(struct mm_basic_frame_proxy_runtime* p)
{
	// common runtime.
}
// commit zk.
void mm_basic_frame_proxy_runtime_commit_zk(struct mm_basic_frame_proxy_runtime* p)
{
	mm_zkwm_path_commit(&p->zkwm_path);
}
