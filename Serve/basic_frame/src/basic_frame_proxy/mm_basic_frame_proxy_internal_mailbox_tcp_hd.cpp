#include "mm_basic_frame_proxy_internal_mailbox_tcp_hd.h"
#include "core/mm_logger.h"
#include "core/mm_byte.h"
#include "net/mm_packet.h"
#include "net/mm_streambuf_packet.h"
#include "mm_basic_frame_proxy.h"
#include "redis/mm_redis_common.h"
#include "redis/mm_redis_hash.h"
#include "net/mm_default_handle.h"
#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"
//////////////////////////////////////////////////////////////////////////
void hd_basic_frame_proxy_internal_mailbox_handle(void* obj, void* u, struct mm_packet* rq_pack)
{
	////////////////////////////////
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* s_tcp = (struct mm_tcp*)(obj);
	struct mm_basic_frame_proxy* impl = (struct mm_basic_frame_proxy*)(u);
	struct mm_packet_head* phead = &rq_pack->phead;
	//
	mm_logger_log_V(g_logger,"%s %d mid:0x%08X sid:%" PRIu64 " uid:%" PRIu64,__FUNCTION__,__LINE__,phead->mid, phead->sid, phead->uid);
	mm_uint64_t sid = phead->sid;// copy rq_pack sid for sid.
	mm_uint32_t pid = (mm_uint32_t)(s_tcp->socket.socket);// proxy s_tcp socket is pid.
	do 
	{
		int cycle_code = 0;
		int finally_state = -1;
		char cycle_message[128] = {0};
		mm::mm_m_runtime_state runtime_state;
		mm_uint32_t slot_unique_id = 0;
		mm_uint64_t node_unique_id = 0;
		struct mm_mt_tcp* mt_tcp = NULL;
		struct mm_net_tcp* net_tcp = NULL;
		struct mm_tcp* t_tcp = NULL;
		struct mm_packet pr_pack;
		//////////////////////////////////////////////////////////////////////////
		// if uid or shard is zero, we use loavger cycle message routing strategy.
		if (0 == phead->uid || 0 == impl->launch_info.shard)
		{
			// cycle loavger ref.return the unique_id for live node.
			cycle_code = mm_primacy_holder_loavger_cycle(&impl->primacy_holder,&slot_unique_id,&runtime_state);
		} 
		else
		{
			mm_uint32_t slot = phead->uid % impl->launch_info.shard;
			cycle_code = mm_primacy_holder_cycle_min(&impl->primacy_holder,slot,&runtime_state);
		}
		if (0 == runtime_state.unique_id)
		{
			// can not find valid sharder.
			mm_sprintf(cycle_message, "(%d)%s", cycle_code, mm_primacy_holder_cycle_error_message(cycle_code));
			mm_logger_log_W(g_logger,"%s %d mid:0x%08X uid:%" PRIu64 " can not find primacy %s.",__FUNCTION__,__LINE__,phead->mid,phead->uid,cycle_message);
			break;
		}
		if (MM_ADDR_DEFAULT_NODE == runtime_state.node_internal && 0 == runtime_state.port_internal)
		{
			// invalid internal node:port empty lobby.
			mm_logger_log_W(g_logger,"%s %d mid:0x%08X uid:%" PRIu64 " internal node:port empty invalid lobby:%u",__FUNCTION__,__LINE__,phead->mid,phead->uid,runtime_state.unique_id);
			break;
		}
		node_unique_id = mm_byte_uint64_a(slot_unique_id, runtime_state.unique_id);
		mt_tcp = mm_mt_contact_get_instance(&impl->contact, node_unique_id,MM_ADDR_DEFAULT_NODE,runtime_state.node_internal.c_str(),runtime_state.port_internal);
		if (NULL == mt_tcp)
		{
			// system not enough memory.
			mm_logger_log_E(g_logger,"%s %d mid:0x%08X uid:%" PRIu64 " system not enough memory.",__FUNCTION__,__LINE__,phead->mid,phead->uid);
			break;
		}
		net_tcp = mm_mt_tcp_thread_instance(mt_tcp);
		if (NULL == net_tcp)
		{
			// system not enough memory.
			mm_logger_log_E(g_logger,"%s %d mid:0x%08X uid:%" PRIu64 " system not enough memory.",__FUNCTION__,__LINE__,phead->mid,phead->uid);
			break;
		}
		mm_net_tcp_lock(net_tcp);
		mm_net_tcp_check(net_tcp);
		finally_state = mm_net_tcp_finally_state(net_tcp);
		mm_net_tcp_unlock(net_tcp);
		if (0 != finally_state)
		{
			// net connect failure.
			mm_logger_log_E(g_logger,"%s %d mid:0x%08X uid:%" PRIu64 " net_tcp %s:%d connect failure.",__FUNCTION__,__LINE__,phead->mid,phead->uid,runtime_state.node_internal.c_str(),runtime_state.port_internal);
			break;
		}
		//
		t_tcp = &net_tcp->tcp;
		// send message to sharder target.
		mm_mt_tcp_lock(mt_tcp);
		mm_net_tcp_lock(net_tcp);
		mm_protobuf_cxx_p_tcp_append_rq( net_tcp, t_tcp, pid, sid, rq_pack, &pr_pack );
		mm_protobuf_cxx_n_net_tcp_flush_send( net_tcp );
		mm_net_tcp_unlock(net_tcp);
		mm_mt_tcp_unlock(mt_tcp);
	} while (0);
}
void hd_basic_frame_proxy_internal_mailbox_broken(void* obj)
{
	mm_mailbox_broken_default(obj);
}
void hd_basic_frame_proxy_internal_mailbox_nready( void* obj )
{
	mm_mailbox_nready_default(obj);
}
void hd_basic_frame_proxy_internal_mailbox_finish( void* obj )
{
	mm_mailbox_finish_default(obj);
}
//////////////////////////////////////////////////////////////////////////