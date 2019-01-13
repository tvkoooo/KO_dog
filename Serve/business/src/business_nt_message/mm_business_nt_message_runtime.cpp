#include "mm_business_nt_message_runtime.h"
#include "core/mm_logger_manager.h"
#include "core/mm_os_context.h"
#include "shuttle_common/mm_runtime_calculate.h"
#include "shuttle_common/mm_j_runtime_state.h"
#include "mm_business_nt_message_launch.h"
mm_uint32_t unique_id;
mm_uint32_t shard;// slot for shard.
mm_uint32_t depth;// slot for depth.

void mm_business_nt_message_runtime_init(struct mm_business_nt_message_runtime* p)
{
	mm_runtime_stat_init(&p->runtime);
	mm_zkwp_path_init(&p->zkwp_path);
	p->launch_info = NULL;
	p->internal_mailbox = NULL;
	p->external_mailbox = NULL;
	// first update.
	mm_runtime_stat_update(&p->runtime);
}
void mm_business_nt_message_runtime_destroy(struct mm_business_nt_message_runtime* p)
{
	mm_runtime_stat_destroy(&p->runtime);
	mm_zkwp_path_destroy(&p->zkwp_path);
	p->launch_info = NULL;
	p->internal_mailbox = NULL;
	p->external_mailbox = NULL;
}
//////////////////////////////////////////////////////////////////////////
void mm_business_nt_message_runtime_start(struct mm_business_nt_message_runtime* p)
{
	mm_zkwp_path_start(&p->zkwp_path);
}
void mm_business_nt_message_runtime_interrupt(struct mm_business_nt_message_runtime* p)
{
	mm_zkwp_path_interrupt(&p->zkwp_path);
}
void mm_business_nt_message_runtime_shutdown(struct mm_business_nt_message_runtime* p)
{
	mm_zkwp_path_shutdown(&p->zkwp_path);
}
void mm_business_nt_message_runtime_join(struct mm_business_nt_message_runtime* p)
{
	mm_zkwp_path_join(&p->zkwp_path);
}
//////////////////////////////////////////////////////////////////////////
void mm_business_nt_message_runtime_assign_parameters(struct mm_business_nt_message_runtime* p,mm_uint32_t unique_id, mm_uint32_t shard, mm_uint32_t depth)
{
	mm_zkwp_path_assign_unique_id(&p->zkwp_path,unique_id);
	mm_zkwp_path_assign_slot(&p->zkwp_path, shard, depth);
	p->runtime_state.unique_id = unique_id;
}
void mm_business_nt_message_runtime_assign_launch_info(struct mm_business_nt_message_runtime* p,struct mm_business_nt_message_launch* launch_info)
{
	p->launch_info = launch_info;
}
void mm_business_nt_message_runtime_assign_internal_mailbox(struct mm_business_nt_message_runtime* p,struct mm_mailbox* internal_mailbox)
{
	p->internal_mailbox = internal_mailbox;
}
void mm_business_nt_message_runtime_assign_external_mailbox(struct mm_business_nt_message_runtime* p,struct mm_mailbox* external_mailbox)
{
	p->external_mailbox = external_mailbox;
}
void mm_business_nt_message_runtime_assign_zkwb_path(struct mm_business_nt_message_runtime* p,const char* path)
{
	mm_zkwp_path_assign_path(&p->zkwp_path,path);
}
void mm_business_nt_message_runtime_assign_zkwb_host(struct mm_business_nt_message_runtime* p,const char* host)
{
	mm_zkwp_path_assign_host(&p->zkwp_path,host);
}
// update runtime value.
void mm_business_nt_message_runtime_update_runtime(struct mm_business_nt_message_runtime* p)
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
	if ( NULL != p->external_mailbox)
	{
		mm_sockaddr_node_port( &p->external_mailbox->accepter.socket.ss_native, node, &port);
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
		mm_string_assigns(&p->zkwp_path.value_buffer,string_buffer.GetString());
	}
}
// commit db.
void mm_business_nt_message_runtime_commit_db(struct mm_business_nt_message_runtime* p)
{
	// common runtime.
}
// commit zk.
void mm_business_nt_message_runtime_commit_zk(struct mm_business_nt_message_runtime* p)
{
	mm_zkwp_path_commit(&p->zkwp_path);
}
