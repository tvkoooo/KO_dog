#include "mm_basic_frame_lobby_internal_mailbox_tcp_hd.h"

#include "core/mm_logger.h"
#include "core/mm_byte.h"

#include "net/mm_packet.h"
#include "net/mm_streambuf_packet.h"
#include "net/mm_default_handle.h"

#include "redis/mm_redis_common.h"
#include "redis/mm_redis_hash.h"

#include "protobuf/mm_protobuff_cxx.h"

#include "mm_basic_frame_lobby.h"
#include "mm_basic_frame_lobby_cback.h"
//////////////////////////////////////////////////////////////////////////
void hd_basic_frame_lobby_internal_mailbox_handle(void* obj, void* u, struct mm_packet* nt_pack)
{
	////////////////////////////////
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	struct mm_basic_frame_lobby* impl = (struct mm_basic_frame_lobby*)(u);
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_packet_head* phead = &nt_pack->phead;
	//
	mm_logger_log_V(g_logger,"%s %d cback mid:0x%08X pid:%u sid:%" PRIu64 " uid:%" PRIu64,__FUNCTION__,__LINE__,phead->mid,phead->pid,phead->sid,phead->uid);
	//
	hd_basic_frame_lobby_cback(impl,tcp,nt_pack);
}
void hd_basic_frame_lobby_internal_mailbox_broken(void* obj)
{
	mm_mailbox_broken_default(obj);
}
void hd_basic_frame_lobby_internal_mailbox_nready( void* obj )
{
	mm_mailbox_nready_default(obj);
}
void hd_basic_frame_lobby_internal_mailbox_finish( void* obj )
{
	mm_mailbox_finish_default(obj);
}
//////////////////////////////////////////////////////////////////////////