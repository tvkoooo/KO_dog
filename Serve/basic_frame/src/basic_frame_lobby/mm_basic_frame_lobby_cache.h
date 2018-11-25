#ifndef __mm_basic_frame_lobby_cache_h__
#define __mm_basic_frame_lobby_cache_h__


#include "core/mm_core.h"

#include "net/mm_sockaddr.h"

#include "redis/mm_redis_sync_array.h"

#define MM_LOBBY_CACHE_KEY_LENGTH 64
//////////////////////////////////////////////////////////////////////////
struct mm_basic_frame_lobby_cache
{
	struct mm_redis_sync_array rdb_gateway_cache;
	mm_uint32_t unique_id;
	char lobby_key[MM_LOBBY_CACHE_KEY_LENGTH];
};
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_lobby_cache_init(struct mm_basic_frame_lobby_cache* p);
extern void mm_basic_frame_lobby_cache_destroy(struct mm_basic_frame_lobby_cache* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_lobby_cache_assign_rdb_gateway_cache_unique_id(struct mm_basic_frame_lobby_cache* p,mm_uint32_t unique_id);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_lobby_cache_assign_rdb_gateway_cache_parameters(struct mm_basic_frame_lobby_cache* p,const char* parameters);
extern void mm_basic_frame_lobby_cache_assign_rdb_gateway_cache_auth(struct mm_basic_frame_lobby_cache* p,const char* auth);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_lobby_cache_rdb_gateway_cache_sid2add_hset(struct mm_basic_frame_lobby_cache* p,mm_uint64_t sid,char addr_name[MM_ADDR_NAME_LENGTH]);
extern void mm_basic_frame_lobby_cache_rdb_gateway_cache_sid2add_hdel(struct mm_basic_frame_lobby_cache* p,mm_uint64_t sid);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_lobby_cache_rdb_gateway_cache_sid2add_del(struct mm_basic_frame_lobby_cache* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_lobby_cache_rdb_gateway_cache_uid2sid_hdel_by_uid(struct mm_basic_frame_lobby_cache* p,mm_uint64_t uid);
extern void mm_basic_frame_lobby_cache_rdb_gateway_cache_uid2sid_hdel_by_sid(struct mm_basic_frame_lobby_cache* p,mm_uint64_t sid);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_lobby_cache_rdb_gateway_cache_uid2sid_hset(struct mm_basic_frame_lobby_cache* p,mm_uint64_t uid,mm_uint64_t sid);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_lobby_cache_rdb_gateway_cache_sid2uid_hset(struct mm_basic_frame_lobby_cache* p,mm_uint64_t sid,mm_uint64_t uid);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_lobby_cache_start(struct mm_basic_frame_lobby_cache* p);
extern void mm_basic_frame_lobby_cache_interrupt(struct mm_basic_frame_lobby_cache* p);
extern void mm_basic_frame_lobby_cache_shutdown(struct mm_basic_frame_lobby_cache* p);
extern void mm_basic_frame_lobby_cache_join(struct mm_basic_frame_lobby_cache* p);
//////////////////////////////////////////////////////////////////////////

#endif//__mm_basic_frame_lobby_cache_h__