#ifndef __mm_business_nt_message_tcp_hd_h__
#define __mm_business_nt_message_tcp_hd_h__

#include "core/mm_prefix.h"

#include "core/mm_core.h"


//////////////////////////////////////////////////////////////////////////
extern void mm_business_nt_message_tcp_hd_c_business_nt_message_consume_by_id_rq(void* obj, void* u, struct mm_packet* rq_pack);
extern void mm_business_nt_message_tcp_hd_c_business_nt_message_consume_by_maxid_rq(void* obj, void* u, struct mm_packet* rq_pack);

extern void mm_business_nt_message_tcp_hd_c_business_nt_message_read_note_id_rq(void* obj, void* u, struct mm_packet* rq_pack);
extern void mm_business_nt_message_tcp_hd_c_business_nt_message_all_unread_rq(void* obj, void* u, struct mm_packet* rq_pack);

//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_business_nt_message_tcp_hd_h__
