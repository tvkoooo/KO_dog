#ifndef __mm_basic_frame_lobby_internal_mailbox_tcp_hd_h__
#define __mm_basic_frame_lobby_internal_mailbox_tcp_hd_h__

#include "core/mm_prefix.h"

#include "core/mm_core.h"
#include "core/mm_os_socket.h"
#include "net/mm_packet.h"
#include "net/mm_sockaddr.h"

struct mm_basic_frame_lobby;
//////////////////////////////////////////////////////////////////////////
extern void hd_basic_frame_lobby_internal_mailbox_handle( void* obj, void* u, struct mm_packet* rq_pack );
extern void hd_basic_frame_lobby_internal_mailbox_broken( void* obj );
extern void hd_basic_frame_lobby_internal_mailbox_nready( void* obj );
extern void hd_basic_frame_lobby_internal_mailbox_finish( void* obj );
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_basic_frame_lobby_internal_mailbox_tcp_hd_h__