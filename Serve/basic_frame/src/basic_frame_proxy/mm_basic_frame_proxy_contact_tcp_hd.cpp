#include "mm_basic_frame_proxy_contact_tcp_hd.h"
#include "core/mm_logger.h"
#include "core/mm_byte.h"
#include "net/mm_packet.h"
#include "net/mm_streambuf_packet.h"
#include "net/mm_tcp.h"
#include "mm_basic_frame_proxy.h"
#include "net/mm_default_handle.h"
#include "protobuf/mm_protobuff_cxx.h"
#include "mm_basic_frame_proxy_cback.h"
//////////////////////////////////////////////////////////////////////////
void hd_basic_frame_proxy_contact_handle( void* obj, void* u, struct mm_packet* rs_pack )
{
	////////////////////////////////
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	struct mm_basic_frame_proxy* impl = (struct mm_basic_frame_proxy*)(u);
	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_packet_head* phead = &rs_pack->phead;
	mm_logger_log_V(g_logger,"%s %d rs mid:0x%08X pid:%u sid:%" PRIu64 " uid:%" PRIu64,__FUNCTION__,__LINE__,phead->mid,phead->pid,phead->sid,phead->uid);
	//
	hd_basic_frame_proxy_cback(impl,tcp,rs_pack);
}
void hd_basic_frame_proxy_contact_broken( void* obj )
{
	mm_contact_broken_default(obj);
}
void hd_basic_frame_proxy_contact_nready( void* obj )
{
	mm_contact_nready_default(obj);
}
void hd_basic_frame_proxy_contact_finish( void* obj )
{
	mm_contact_finish_default(obj);
}
//////////////////////////////////////////////////////////////////////////