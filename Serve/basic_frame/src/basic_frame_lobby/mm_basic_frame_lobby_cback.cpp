#include "mm_basic_frame_lobby_cback.h"

#include "core/mm_logger.h"
#include "core/mm_byte.h"

#include "net/mm_packet.h"
#include "net/mm_streambuf_packet.h"
#include "net/mm_mailbox.h"

#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"

#include "shuttle_common/mm_mulcast_c.h"

#include "mm_basic_frame_lobby.h"
//////////////////////////////////////////////////////////////////////////
struct __cback_mailbox_traver_context
{
	struct mm_mailbox* external_mailbox;
	struct mm_packet* nt_pack;
	struct mm_packet* pr_pack;
};
//////////////////////////////////////////////////////////////////////////
static void __static_basic_frame_lobby_cback_mailbox_traver( void* obj, void* u, mm_uint32_t k, void* v );
//////////////////////////////////////////////////////////////////////////
void hd_basic_frame_lobby_cback_target(struct mm_mailbox* mailbox,struct mm_tcp* t_tcp,struct mm_packet* nt_pack,struct mm_packet* pr_pack)
{
	// send message to sharder target.
	mm_tcp_lock(t_tcp);
	mm_protobuf_cxx_p_tcp_append_rs( mailbox, t_tcp, nt_pack, pr_pack );
	mm_protobuf_cxx_n_tcp_flush_send( t_tcp );
	mm_tcp_unlock(t_tcp);
}
void hd_basic_frame_lobby_cback(struct mm_basic_frame_lobby* impl,struct mm_tcp* s_tcp,struct mm_packet* nt_pack)
{
	////////////////////////////////
	struct mm_mailbox* external_mailbox = &impl->external_mailbox;
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_packet_head* phead = &nt_pack->phead;
	struct mm_packet pr_pack;
	mm_uint32_t socket = mm_byte_uint64_r(phead->sid);
	do 
	{
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
				struct mm_streambuf* streambuf_0 = NULL;

				mm_mulcast_rbtset_init(&mulcast_rbtset);
				mm_streambuf_unit_lock(streambuf_unit);

				streambuf_0 = streambuf_unit->arrays[0];
				mm_streambuf_reset(streambuf_0);
				mm_streambuf_aligned_memory(streambuf_0, nt_pack->bbuff.length);
				mm_streambuf_sputn(streambuf_0, nt_pack->bbuff.buffer, nt_pack->bbuff.offset, nt_pack->bbuff.length);
				mm_mulcast_rbtset_decode(&mulcast_rbtset, streambuf_0);
				{
					// unique_id -> uid rbtree
					//mm_uint32_t unique_id = 0;
					//struct mm_rb_node* n = NULL;
					//struct mm_rbtset_u64_iterator* it = NULL;
					////
					//n = mm_rb_last(&mulcast_rbtset.arrays.rbt);
					//while(NULL != n)
					//{
					//	it = (struct mm_rbtset_u64_iterator*)mm_rb_entry(n, struct mm_rbtset_u64_iterator, n);
					//	n = mm_rb_prev(n);
					//	// uid -> sid.
					//	mm_logger_log_E(g_logger,"%s %d not suppot this api now.",__FUNCTION__,__LINE__);
					//}
				}
				mm_streambuf_unit_unlock(streambuf_unit);
				mm_mulcast_rbtset_destroy(&mulcast_rbtset);
			}
		}
		else
		{
			if ( 0xFFFFFFFF == socket )
			{
				// to all tcp.
				struct __cback_mailbox_traver_context traver_context;
				traver_context.external_mailbox = external_mailbox;
				traver_context.pr_pack = &pr_pack;
				traver_context.nt_pack = nt_pack;
				mm_mailbox_traver(external_mailbox,&__static_basic_frame_lobby_cback_mailbox_traver,&traver_context);
			} 
			else
			{
				// to one tcp.
				struct mm_tcp* t_tcp = mm_mailbox_get(external_mailbox,socket);
				if (NULL == t_tcp)
				{
					// can not find target tcp.
					// this logger will case normality.here i flag the level is MM_LOG_TRACE.
					mm_logger_log_T(g_logger,"%s %d missing pack := mid:0x%08X pid:%u sid:%" PRIu64 " uid:%" PRIu64 " hsize:%u bsize:%u hbuff:%p bbuff:%p",
						__FUNCTION__,__LINE__,phead->mid,phead->pid,phead->sid,phead->uid,nt_pack->hbuff.length,nt_pack->bbuff.length,nt_pack->hbuff.buffer,nt_pack->bbuff.buffer);
				}
				else
				{
					hd_basic_frame_lobby_cback_target(external_mailbox, t_tcp, nt_pack, &pr_pack);
				}
			}
		}
	} while (0);
}
//////////////////////////////////////////////////////////////////////////
static void __static_basic_frame_lobby_cback_mailbox_traver( void* obj, void* u, mm_uint32_t k, void* v )
{
	struct mm_tcp* t_tcp =( struct mm_tcp* ) v;
	struct __cback_mailbox_traver_context* traver_context = (struct __cback_mailbox_traver_context*)(u);
	hd_basic_frame_lobby_cback_target(traver_context->external_mailbox, t_tcp, traver_context->nt_pack, traver_context->pr_pack);
}
//////////////////////////////////////////////////////////////////////////