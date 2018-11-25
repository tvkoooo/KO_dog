#include "mm_basic_frame_proxy_cback.h"
#include "core/mm_logger.h"
#include "core/mm_byte.h"
#include "net/mm_packet.h"
#include "net/mm_streambuf_packet.h"
#include "net/mm_mailbox.h"
#include "mm_basic_frame_proxy.h"
#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"
//////////////////////////////////////////////////////////////////////////
struct __cback_mailbox_traver_context
{
	struct mm_mailbox* internal_mailbox;
	struct mm_tcp* s_tcp;
	struct mm_packet* nt_pack;
	struct mm_packet* pr_pack;
};
//////////////////////////////////////////////////////////////////////////
static void __static_basic_frame_proxy_cback_mailbox_traver( void* obj, void* u, mm_uint32_t k, void* v );
//////////////////////////////////////////////////////////////////////////
void hd_basic_frame_proxy_cback_target(struct mm_mailbox* mailbox,struct mm_tcp* s_tcp,struct mm_tcp* t_tcp,struct mm_packet* nt_pack,struct mm_packet* pr_pack)
{
	// send message to sharder target.
	mm_tcp_lock(t_tcp);
	mm_protobuf_cxx_p_tcp_append_rs( mailbox, t_tcp, nt_pack, pr_pack );
	mm_protobuf_cxx_n_tcp_flush_send( t_tcp );
	mm_tcp_unlock(t_tcp);
}
void hd_basic_frame_proxy_cback(struct mm_basic_frame_proxy* impl,struct mm_tcp* s_tcp,struct mm_packet* nt_pack)
{
	////////////////////////////////
	struct mm_mailbox* internal_mailbox = &impl->internal_mailbox;
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_packet_head* phead = &nt_pack->phead;
	struct mm_packet pr_pack;
	mm_uint32_t socket = phead->pid;
	do 
	{
		if ( 0xFFFFFFFF == socket )
		{
			// to all tcp.
			struct __cback_mailbox_traver_context traver_context;
			traver_context.internal_mailbox = internal_mailbox;
			traver_context.s_tcp = s_tcp;
			traver_context.pr_pack = &pr_pack;
			traver_context.nt_pack = nt_pack;
			mm_mailbox_traver(internal_mailbox,&__static_basic_frame_proxy_cback_mailbox_traver,&traver_context);
		} 
		else
		{
			// to one tcp.
			struct mm_tcp* t_tcp = mm_mailbox_get(internal_mailbox,socket);
			if (NULL == t_tcp)
			{
				// can not find target tcp.
				// this logger will case normality.here i flag the level is MM_LOG_TRACE.
				mm_logger_log_T(g_logger,"%s %d missing pack := mid:0x%08X pid:%u sid:%" PRIu64 " uid:%" PRIu64 " hsize:%u bsize:%u hbuff:%p bbuff:%p",
					__FUNCTION__,__LINE__,phead->mid,phead->pid,phead->sid,phead->uid,nt_pack->hbuff.length,nt_pack->bbuff.length,nt_pack->hbuff.buffer,nt_pack->bbuff.buffer);
			}
			else
			{
				hd_basic_frame_proxy_cback_target(internal_mailbox, s_tcp, t_tcp, nt_pack, &pr_pack);
			}
		}
	} while (0);
}
//////////////////////////////////////////////////////////////////////////
//typedef void (*rbtree_visible_handle)( void* obj, void* u, mm_uint32_t k, void* v );
//static void __static_basic_frame_proxy_cback_mailbox_traver( struct mm_mailbox* mailbox, struct mm_tcp* t_tcp, void* u )
static void __static_basic_frame_proxy_cback_mailbox_traver( void* obj, void* u, mm_uint32_t k, void* v )
{
	struct mm_tcp* t_tcp =( struct mm_tcp* ) v;
	struct __cback_mailbox_traver_context* traver_context = (struct __cback_mailbox_traver_context*)(u);
	hd_basic_frame_proxy_cback_target(traver_context->internal_mailbox, traver_context->s_tcp, t_tcp, traver_context->nt_pack, traver_context->pr_pack);
}
//////////////////////////////////////////////////////////////////////////