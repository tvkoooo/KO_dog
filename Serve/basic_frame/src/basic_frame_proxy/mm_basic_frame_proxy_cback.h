#ifndef __mm_basic_frame_proxy_cback_h__
#define __mm_basic_frame_proxy_cback_h__

#include "core/mm_prefix.h"

#include "core/mm_core.h"
#include "net/mm_packet.h"

struct mm_mailbox;
struct mm_tcp;
//////////////////////////////////////////////////////////////////////////
extern void hd_basic_frame_proxy_cback_target(struct mm_mailbox* mailbox,struct mm_tcp* s_tcp,struct mm_tcp* t_tcp,struct mm_packet* nt_pack,struct mm_packet* pr_pack);
extern void hd_basic_frame_proxy_cback(struct mm_basic_frame_proxy* impl,struct mm_tcp* s_tcp,struct mm_packet* nt_pack);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_basic_frame_proxy_cback_h__