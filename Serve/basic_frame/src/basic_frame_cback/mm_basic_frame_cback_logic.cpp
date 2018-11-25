#include "mm_basic_frame_cback_logic.h"

#include "core/mm_logger.h"
#include "core/mm_byte.h"

#include "net/mm_streambuf_packet.h"

#include "redis/mm_redis_sync_array.h"
#include "redis/mm_redis_hash.h"

#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"

#include "shuttle_common/mm_loavger_holder.h"
#include "shuttle_common/mm_mulcast_c.h"
#include "shuttle_common/mm_rdb_gateway.h"

#include "mm_basic_frame_cback.h"

//////////////////////////////////////////////////////////////////////////
static void* __static_arrays_rbtree_u32_rbtset_u64_strong_alloc(struct mm_rbtree_u32_vpt* p,mm_uint32_t k);
static void* __static_arrays_rbtree_u32_rbtset_u64_strong_relax(struct mm_rbtree_u32_vpt* p,mm_uint32_t k,void* v);
//////////////////////////////////////////////////////////////////////////
struct __cback_loavger_holder_traver_context
{
	struct mm_mt_contact* contact;
	struct mm_packet* nt_pack;
	struct mm_packet* pr_pack;
};
static void __static_basic_frame_cback_loavger_holder_traver( struct mm_loavger_holder* p, struct mm_loavger_holder_elem* e, void* u );
//////////////////////////////////////////////////////////////////////////
void hd_basic_frame_cback_cback_target(struct mm_mt_contact* contact,mm::mm_m_runtime_state* runtime_state,struct mm_packet* nt_pack,struct mm_packet* pr_pack)
{
	struct mm_packet_head* phead = &nt_pack->phead;
	struct mm_logger* g_logger = mm_logger_instance();
	mm_uint32_t pid = phead->pid;
	mm_uint64_t sid = phead->sid;
	do 
	{
		struct mm_mt_tcp* mt_tcp = NULL;
		struct mm_net_tcp* net_tcp = NULL;
		struct mm_tcp* t_tcp = NULL;
		if ( 0 == runtime_state->unique_id )
		{
			// can not find valid lobby.
			mm_logger_log_W(g_logger,"%s %d mid:0x%08X uid:%" PRIu64 " can not find valid lobby:%u",__FUNCTION__,__LINE__,phead->mid,phead->uid,runtime_state->unique_id);
			break;
		}
		if (MM_ADDR_DEFAULT_NODE == runtime_state->node_internal && 0 == runtime_state->port_internal)
		{
			// invalid internal node:port empty lobby.
			mm_logger_log_W(g_logger,"%s %d mid:0x%08X uid:%" PRIu64 " internal node:port empty invalid lobby:%u",__FUNCTION__,__LINE__,phead->mid,phead->uid,runtime_state->unique_id);
			break;
		}
		mt_tcp = mm_mt_contact_get_instance(contact,runtime_state->unique_id,MM_ADDR_DEFAULT_NODE,runtime_state->node_internal.c_str(),runtime_state->port_internal);
		if ( NULL == mt_tcp )
		{
			// system not enough memory.
			mm_logger_log_E(g_logger,"%s %d mid:0x%08X uid:%" PRIu64 " system not enough memory.",__FUNCTION__,__LINE__,phead->mid,phead->uid);
			break;
		}
		net_tcp = mm_mt_tcp_thread_instance(mt_tcp);
		if ( NULL == net_tcp )
		{
			// system not enough memory.
			mm_logger_log_E(g_logger,"%s %d mid:0x%08X uid:%" PRIu64 " system not enough memory.",__FUNCTION__,__LINE__,phead->mid,phead->uid);
			break;
		}
		mm_net_tcp_check(net_tcp);
		if ( 0 != mm_net_tcp_finally_state(net_tcp) )
		{
			// net connect failure.
			mm_logger_log_E(g_logger,"%s %d mid:0x%08X uid:%" PRIu64 " net_tcp %s:%d connect failure.",__FUNCTION__,__LINE__,phead->mid,phead->uid,runtime_state->node_internal.c_str(),runtime_state->port_internal);
			break;
		}
		//
		t_tcp = &net_tcp->tcp;
		// send message to sharder target.
		mm_mt_tcp_lock(mt_tcp);
		mm_net_tcp_lock(net_tcp);
		mm_protobuf_cxx_p_tcp_append_rq( net_tcp, t_tcp, pid, sid, nt_pack, pr_pack );
		mm_protobuf_cxx_n_net_tcp_flush_send( net_tcp );
		mm_net_tcp_unlock(net_tcp);
		mm_mt_tcp_unlock(mt_tcp);
	} while (0);
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_cback_logic_handle(struct mm_basic_frame_cback* impl,struct mm_packet* nt_pack)
{
	struct mm_packet_head* phead = &nt_pack->phead;
	// if sid is valid,cback will ignore hget the login maping.
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_redis_sync* ctx_cache = mm_redis_sync_array_thread_instance(&impl->db_redis_cache_cback);
	do 
	{
		mm::mm_m_runtime_state runtime_state;
		struct mm_packet pr_pack;
		if ( NULL == ctx_cache )
		{
			mm_logger_log_E(g_logger,"%s %d %s:%d net failure ",__FUNCTION__,__LINE__,impl->db_redis_cache_cback.node.s,impl->db_redis_cache_cback.port);
			break;
		}
		if ( mm_mulcast_rbtset_msg_id == phead->pid )
		{
			struct mm_streambuf_unit* streambuf_unit = mm_streambuf_array_thread_instance(&impl->streambuf_array);
			if (NULL == streambuf_unit)
			{
				mm_logger_log_E(g_logger,"%s %d system memory not enough.",__FUNCTION__,__LINE__);
				break;
			}
			{
				struct mm_mulcast_rbtset mulcast_rbtset;
				struct mm_rbtree_u64_u64 rbtree_u64_u64;
				struct mm_streambuf* streambuf_0 = NULL;
				struct mm_streambuf* streambuf_1 = NULL;
				struct mm_streambuf* streambuf_2 = NULL;

				mm_mulcast_rbtset_init(&mulcast_rbtset);
				mm_rbtree_u64_u64_init(&rbtree_u64_u64);
				mm_streambuf_unit_lock(streambuf_unit);

				streambuf_0 = streambuf_unit->arrays[0];
				streambuf_1 = streambuf_unit->arrays[1];
				streambuf_2 = streambuf_unit->arrays[2];
				mm_streambuf_reset(streambuf_0);
				mm_streambuf_aligned_memory(streambuf_0, nt_pack->bbuff.length);
				mm_streambuf_sputn(streambuf_0, nt_pack->bbuff.buffer, nt_pack->bbuff.offset, nt_pack->bbuff.length);
				mm_mulcast_rbtset_decode(&mulcast_rbtset, streambuf_0);
				// hmget pattern page uid -> sid rbtree.
				mm_redis_hash_u64_u64_hmget_pattern_page(ctx_cache, g_rdb_gateway_uid2sid_pattern,MM_UID2SID_MOD_NUMBER,MM_CBACK_HMGET_PATTERN_PAGE,&mulcast_rbtset.arrays,&rbtree_u64_u64);
				if ( 0 != rbtree_u64_u64.size )
				{
					struct mm_rbtset_u64* u_rbtset = NULL;
					struct mm_rbtree_u32_vpt rbtree_u32_vpt;
					mm_rbtree_u32_vpt_init(&rbtree_u32_vpt);
					//
					struct mm_rbtree_u32_vpt_alloc rbtree_u32_vpt_alloc;
					rbtree_u32_vpt_alloc.alloc = &__static_arrays_rbtree_u32_rbtset_u64_strong_alloc;
					rbtree_u32_vpt_alloc.relax = &__static_arrays_rbtree_u32_rbtset_u64_strong_relax;
					rbtree_u32_vpt_alloc.obj = NULL;
					mm_rbtree_u32_vpt_assign_alloc(&rbtree_u32_vpt, &rbtree_u32_vpt_alloc);
					{
						// unique_id -> uid rbtree
						mm_uint32_t unique_id = 0;
						struct mm_rb_node* n = NULL;
						struct mm_rbtree_u64_u64_iterator* it = NULL;
						//
						n = mm_rb_last(&rbtree_u64_u64.rbt);
						while(NULL != n)
						{
							it = (struct mm_rbtree_u64_u64_iterator*)mm_rb_entry(n, struct mm_rbtree_u64_u64_iterator, n);
							n = mm_rb_prev(n);
							// sid l part.
							unique_id = mm_byte_uint64_l(it->v);
							u_rbtset = (struct mm_rbtset_u64*)mm_rbtree_u32_vpt_get_instance(&rbtree_u32_vpt, unique_id);
							// add uid to rbtset.
							mm_rbtset_u64_add(u_rbtset, it->k);
						}
					}
					{
						// unique pack to target node address.
						struct mm_byte_buffer unique_byte_buffer;
						struct mm_packet unique_pack;

						struct mm_rb_node* n = NULL;
						struct mm_rbtree_u32_vpt_iterator* it = NULL;

						mm_byte_buffer_init(&unique_byte_buffer);

						n = mm_rb_last(&rbtree_u32_vpt.rbt);
						while(NULL != n)
						{
							it = (struct mm_rbtree_u32_vpt_iterator*)mm_rb_entry(n, struct mm_rbtree_u32_vpt_iterator, n);
							n = mm_rb_prev(n);
							u_rbtset = (struct mm_rbtset_u64*)(it->v);
							//
							runtime_state.unique_id = it->k;
							//
							mm_byte_buffer_reset(&unique_byte_buffer);
							mm_streambuf_reset(streambuf_1);
							mm_streambuf_reset(streambuf_2);
							//
							unique_byte_buffer.length = mulcast_rbtset.buffer.length;
							mm_mulcast_rbtset_encode_buffer_arrays(streambuf_1, &unique_byte_buffer, u_rbtset);
							mm_memcpy((void*)(unique_byte_buffer.buffer + unique_byte_buffer.offset),(void*)(mulcast_rbtset.buffer.buffer + mulcast_rbtset.buffer.offset),unique_byte_buffer.length);
							//
							mm_message_coder_encode_message_streambuf(streambuf_2, streambuf_1, &nt_pack->phead, MM_MSG_COMM_HEAD_SIZE, &unique_pack);
							//
							mm_loavger_holder_get_state(&impl->loavger_holder,runtime_state.unique_id,&runtime_state);
							hd_basic_frame_cback_cback_target(&impl->contact, &runtime_state, &unique_pack, &pr_pack);
						}
						mm_byte_buffer_destroy(&unique_byte_buffer);
					}
					mm_rbtree_u32_vpt_destroy(&rbtree_u32_vpt);
				}
				mm_streambuf_unit_unlock(streambuf_unit);
				mm_mulcast_rbtset_destroy(&mulcast_rbtset);
				mm_rbtree_u64_u64_destroy(&rbtree_u64_u64);
			}
		} 
		else
		{
			if ( 0 == phead->sid )
			{
				// assign current sid.pack is weak ref,and only use at handler once.
				// it's safe.
				char key[32] = {0};
				mm_rdb_gateway_uid2sid_key_by_uid(key, phead->uid);
				mm_redis_sync_lock(ctx_cache);
				mm_redis_hash_u64_u64_hget(ctx_cache,key,phead->uid,&phead->sid);
				mm_redis_sync_unlock(ctx_cache);
			}
			if ( 0 == phead->sid )
			{
				// can not find target tcp.
				// this logger will case normality.here i flag the level is MM_LOG_TRACE.
				mm_logger_log_T(g_logger,"%s %d missing pack := mid:0x%08X pid:%u sid:%" PRIu64 " uid:%" PRIu64 " hsize:%u bsize:%u hbuff:%p bbuff:%p",
					__FUNCTION__,__LINE__,phead->mid,phead->pid,phead->sid,phead->uid,nt_pack->hbuff.length,nt_pack->bbuff.length,nt_pack->hbuff.buffer,nt_pack->bbuff.buffer);
				break;
			}
			runtime_state.unique_id = mm_byte_uint64_l(phead->sid);
			if ( 0xFFFFFFFF == runtime_state.unique_id )
			{
				struct __cback_loavger_holder_traver_context traver_context;
				traver_context.contact = &impl->contact;
				traver_context.pr_pack = &pr_pack;
				traver_context.nt_pack = nt_pack;
				mm_loavger_holder_traver(&impl->loavger_holder, &__static_basic_frame_cback_loavger_holder_traver, &traver_context);
			}
			else
			{
				mm_loavger_holder_get_state(&impl->loavger_holder,runtime_state.unique_id,&runtime_state);
				hd_basic_frame_cback_cback_target(&impl->contact, &runtime_state, nt_pack, &pr_pack);
			}
		}
	} while (0);
}
//////////////////////////////////////////////////////////////////////////
static void __static_basic_frame_cback_loavger_holder_traver( struct mm_loavger_holder* p, struct mm_loavger_holder_elem* e, void* u )
{
	struct __cback_loavger_holder_traver_context* traver_context = (struct __cback_loavger_holder_traver_context*)u;
	hd_basic_frame_cback_cback_target(traver_context->contact, &e->runtime_state, traver_context->nt_pack, traver_context->pr_pack);
}
static void* __static_arrays_rbtree_u32_rbtset_u64_strong_alloc(struct mm_rbtree_u32_vpt* p,mm_uint32_t k)
{
	struct mm_rbtset_u64* e = (struct mm_rbtset_u64*)mm_malloc(sizeof(struct mm_rbtset_u64));
	mm_rbtset_u64_init(e);
	return e;
}
static void* __static_arrays_rbtree_u32_rbtset_u64_strong_relax(struct mm_rbtree_u32_vpt* p,mm_uint32_t k,void* v)
{
	struct mm_rbtset_u64* e = (struct mm_rbtset_u64*)(v);
	mm_rbtset_u64_destroy(e);
	mm_free(e);
	return NULL;
}
