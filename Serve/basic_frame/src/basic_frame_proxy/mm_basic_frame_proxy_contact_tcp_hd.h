#ifndef __mm_basic_frame_proxy_contact_tcp_hd_h__
#define __mm_basic_frame_proxy_contact_tcp_hd_h__

#include "core/mm_prefix.h"

#include "core/mm_core.h"
#include "net/mm_packet.h"
//////////////////////////////////////////////////////////////////////////
extern void hd_basic_frame_proxy_contact_handle( void* obj, void* u, struct mm_packet* rs_pack );
extern void hd_basic_frame_proxy_contact_broken( void* obj );
extern void hd_basic_frame_proxy_contact_nready( void* obj );
extern void hd_basic_frame_proxy_contact_finish( void* obj );
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_basic_frame_proxy_contact_tcp_hd_h__