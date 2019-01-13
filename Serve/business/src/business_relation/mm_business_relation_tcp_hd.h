#ifndef __mm_business_relation_tcp_hd_h__
#define __mm_business_relation_tcp_hd_h__

#include "core/mm_prefix.h"

#include "core/mm_core.h"


//////////////////////////////////////////////////////////////////////////
extern void mm_business_relation_tcp_hd_c_business_relation_add_friend_rq(void* obj, void* u, struct mm_packet* rq_pack);
extern void mm_business_relation_tcp_hd_c_business_relation_delete_friend_rq(void* obj, void* u, struct mm_packet* rq_pack);
extern void mm_business_relation_tcp_hd_c_business_relation_allow_friend_rq(void* obj, void* u, struct mm_packet* rq_pack);
extern void mm_business_relation_tcp_hd_c_business_relation_query_friends_rq(void* obj, void* u, struct mm_packet* rq_pack);
extern void mm_business_relation_tcp_hd_c_business_relation_rename_friend_remark_rq(void* obj, void* u, struct mm_packet* rq_pack);
extern void mm_business_relation_tcp_hd_c_business_relation_add_friend_group_rq(void* obj, void* u, struct mm_packet* rq_pack);
extern void mm_business_relation_tcp_hd_c_business_relation_delete_friend_group_rq(void* obj, void* u, struct mm_packet* rq_pack);
extern void mm_business_relation_tcp_hd_c_business_relation_rename_friend_group_rq(void* obj, void* u, struct mm_packet* rq_pack);
extern void mm_business_relation_tcp_hd_c_business_relation_change_friend_group_rq(void* obj, void* u, struct mm_packet* rq_pack);
extern void mm_business_relation_tcp_hd_c_business_relation_talk_friend_rq(void* obj, void* u, struct mm_packet* rq_pack);
extern void mm_business_relation_tcp_hd_c_business_relation_query_friends_apply_rq(void* obj, void* u, struct mm_packet* rq_pack);

//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_business_relation_tcp_hd_h__
