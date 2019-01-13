#ifndef __mm_handler_business_nt_message_hd_h__
#define __mm_handler_business_nt_message_hd_h__

#include "core/mm_core.h"

struct mm_handler_business_nt_message;
struct mm_packet;
//////////////////////////////////////////////////////////////////////////
extern void mm_handler_lobby_hd_register(struct mm_handler_business_nt_message* consume_array);
//////////////////////////////////////////////////////////////////////////
extern void hd_s_shuttle_lobby_token_verify_ev(void* obj, void* u, struct mm_packet* pack);
//////////////////////////////////////////////////////////////////////////
#endif//__mm_handler_business_nt_message_hd_h__
