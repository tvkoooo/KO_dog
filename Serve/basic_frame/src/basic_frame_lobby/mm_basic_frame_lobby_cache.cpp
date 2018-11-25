#include "mm_basic_frame_lobby_cache.h"

#include "core/mm_logger_manager.h"

#include "redis/mm_redis_common.h"
#include "redis/mm_redis_hash.h"

#include "shuttle_common/mm_rdb_gateway.h"

void mm_basic_frame_lobby_cache_init(struct mm_basic_frame_lobby_cache* p)
{
	mm_redis_sync_array_init(&p->rdb_gateway_cache);
	p->unique_id = 0;
	mm_memset(p->lobby_key,0,sizeof(char) * MM_LOBBY_CACHE_KEY_LENGTH);
}
void mm_basic_frame_lobby_cache_destroy(struct mm_basic_frame_lobby_cache* p)
{
	mm_redis_sync_array_destroy(&p->rdb_gateway_cache);
	p->unique_id = 0;
	mm_memset(p->lobby_key,0,sizeof(char) * MM_LOBBY_CACHE_KEY_LENGTH);
}
void mm_basic_frame_lobby_cache_assign_rdb_gateway_cache_unique_id(struct mm_basic_frame_lobby_cache* p,mm_uint32_t unique_id)
{
	p->unique_id = unique_id;
	mm_rdb_gateway_sid2add_key(p->lobby_key,p->unique_id);
}

void mm_basic_frame_lobby_cache_assign_rdb_gateway_cache_parameters(struct mm_basic_frame_lobby_cache* p,const char* parameters)
{
	mm_redis_sync_array_assign_parameters(&p->rdb_gateway_cache,parameters);
	mm_redis_sync_array_apply_broken(&p->rdb_gateway_cache);
}
void mm_basic_frame_lobby_cache_assign_rdb_gateway_cache_auth(struct mm_basic_frame_lobby_cache* p,const char* auth)
{
	mm_redis_sync_array_assign_auth(&p->rdb_gateway_cache,auth);
}

void mm_basic_frame_lobby_cache_rdb_gateway_cache_sid2add_hset(struct mm_basic_frame_lobby_cache* p,mm_uint64_t sid,char addr_name[MM_ADDR_NAME_LENGTH])
{
	do 
	{
		struct mm_redis_sync* redis = mm_redis_sync_array_thread_instance(&p->rdb_gateway_cache);
		if ( NULL == redis )
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger,"%s %d dbredis %s:%d connect failure.",__FUNCTION__,__LINE__,p->rdb_gateway_cache.node.s,p->rdb_gateway_cache.port);
		}
		if ( 0 == sid )
		{
			// need do nothing.
			break;
		}
		{
			mm_redis_sync_lock(redis);
			mm_redis_hash_u64_bin_hset(redis,p->lobby_key,sid,addr_name,MM_ADDR_NAME_LENGTH);
			mm_redis_sync_unlock(redis);
		}
	} while (0);
}
void mm_basic_frame_lobby_cache_rdb_gateway_cache_sid2add_hdel(struct mm_basic_frame_lobby_cache* p,mm_uint64_t sid)
{
	do 
	{
		struct mm_redis_sync* redis = mm_redis_sync_array_thread_instance(&p->rdb_gateway_cache);
		if ( NULL == redis )
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger,"%s %d dbredis %s:%d connect failure.",__FUNCTION__,__LINE__,p->rdb_gateway_cache.node.s,p->rdb_gateway_cache.port);
		}
		if ( 0 == sid )
		{
			// need do nothing.
			break;
		}
		{
			mm_redis_sync_lock(redis);
			mm_redis_hash_u64_hdel(redis,p->lobby_key,sid);
			mm_redis_sync_unlock(redis);
		}
	} while (0);
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_lobby_cache_rdb_gateway_cache_sid2add_del(struct mm_basic_frame_lobby_cache* p)
{
	do 
	{
		struct mm_redis_sync* redis = mm_redis_sync_array_thread_instance(&p->rdb_gateway_cache);
		if ( NULL == redis )
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger,"%s %d dbredis %s:%d connect failure.",__FUNCTION__,__LINE__,p->rdb_gateway_cache.node.s,p->rdb_gateway_cache.port);
		}
		{
			mm_redis_sync_lock(redis);
			mm_redis_str_del(redis,p->lobby_key);
			mm_redis_sync_unlock(redis);
		}
	} while (0);
}
void mm_basic_frame_lobby_cache_rdb_gateway_cache_uid2sid_hdel_by_uid(struct mm_basic_frame_lobby_cache* p,mm_uint64_t uid)
{
	do 
	{
		struct mm_redis_sync* redis = mm_redis_sync_array_thread_instance(&p->rdb_gateway_cache);
		if ( NULL == redis )
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger,"%s %d dbredis %s:%d connect failure.",__FUNCTION__,__LINE__,p->rdb_gateway_cache.node.s,p->rdb_gateway_cache.port);
		}
		if ( 0 == uid )
		{
			// need do nothing.
			break;
		}
		{
			char key[32] = {0};
			mm_rdb_gateway_uid2sid_key_by_uid(key, uid);
			mm_redis_sync_lock(redis);
			mm_redis_hash_u64_hdel(redis,key,uid);
			mm_redis_sync_unlock(redis);
		}
	} while (0);
}
void mm_basic_frame_lobby_cache_rdb_gateway_cache_uid2sid_hdel_by_sid(struct mm_basic_frame_lobby_cache* p,mm_uint64_t sid)
{
	do 
	{
		mm_uint64_t uid = 0;
		char key[32] = {0};
		struct mm_redis_sync* redis = mm_redis_sync_array_thread_instance(&p->rdb_gateway_cache);
		if ( NULL == redis )
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger,"%s %d dbredis %s:%d connect failure.",__FUNCTION__,__LINE__,p->rdb_gateway_cache.node.s,p->rdb_gateway_cache.port);
		}
		if ( 0 == sid )
		{
			// need do nothing.
			break;
		}
		{
			mm_rdb_gateway_sid2uid_key_by_sid(key, sid);
			mm_redis_sync_lock(redis);
			mm_redis_hash_u64_u64_hget(redis,key,sid,&uid);
			mm_redis_sync_unlock(redis);
		}
		if ( 0 == uid )
		{
			// need do nothing.
			break;
		}
		{
			mm_rdb_gateway_uid2sid_key_by_uid(key, uid);
			mm_redis_sync_lock(redis);
			mm_redis_hash_u64_hdel(redis,key,uid);
			mm_redis_sync_unlock(redis);
		}
	} while (0);
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_lobby_cache_rdb_gateway_cache_uid2sid_hset(struct mm_basic_frame_lobby_cache* p,mm_uint64_t uid,mm_uint64_t sid)
{
	do 
	{
		struct mm_redis_sync* redis = mm_redis_sync_array_thread_instance(&p->rdb_gateway_cache);
		if ( NULL == redis )
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger,"%s %d dbredis %s:%d connect failure.",__FUNCTION__,__LINE__,p->rdb_gateway_cache.node.s,p->rdb_gateway_cache.port);
		}
		if ( 0 == uid || 0 == sid )
		{
			// need do nothing.
			break;
		}
		{
			char key[32] = {0};
			mm_rdb_gateway_uid2sid_key_by_uid(key, uid);
			mm_redis_sync_lock(redis);
			mm_redis_hash_u64_u64_hset(redis,key,uid,sid);
			mm_redis_sync_unlock(redis);
		}
	} while (0);
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_lobby_cache_rdb_gateway_cache_sid2uid_hset(struct mm_basic_frame_lobby_cache* p,mm_uint64_t sid,mm_uint64_t uid)
{
	do 
	{
		struct mm_redis_sync* redis = mm_redis_sync_array_thread_instance(&p->rdb_gateway_cache);
		if ( NULL == redis )
		{
			struct mm_logger* g_logger = mm_logger_instance();
			mm_logger_log_E(g_logger,"%s %d dbredis %s:%d connect failure.",__FUNCTION__,__LINE__,p->rdb_gateway_cache.node.s,p->rdb_gateway_cache.port);
		}
		if ( 0 == uid || 0 == sid )
		{
			// need do nothing.
			break;
		}
		{
			char key[32] = {0};
			mm_rdb_gateway_sid2uid_key_by_sid(key, sid);
			mm_redis_sync_lock(redis);
			mm_redis_hash_u64_u64_hset(redis,key,sid,uid);
			mm_redis_sync_unlock(redis);
		}
	} while (0);
}
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_lobby_cache_start(struct mm_basic_frame_lobby_cache* p)
{
	mm_redis_sync_array_start(&p->rdb_gateway_cache);
}
void mm_basic_frame_lobby_cache_interrupt(struct mm_basic_frame_lobby_cache* p)
{
	mm_redis_sync_array_interrupt(&p->rdb_gateway_cache);
}
void mm_basic_frame_lobby_cache_shutdown(struct mm_basic_frame_lobby_cache* p)
{
	mm_redis_sync_array_shutdown(&p->rdb_gateway_cache);
}
void mm_basic_frame_lobby_cache_join(struct mm_basic_frame_lobby_cache* p)
{
	mm_redis_sync_array_join(&p->rdb_gateway_cache);
}