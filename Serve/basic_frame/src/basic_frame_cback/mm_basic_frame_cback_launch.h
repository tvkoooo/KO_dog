#ifndef __mm_basic_frame_cback_launch_h__
#define __mm_basic_frame_cback_launch_h__

#include "core/mm_core.h"
#include "core/mm_string.h"

//////////////////////////////////////////////////////////////////////////
struct mm_basic_frame_cback_launch
{
	mm_uint32_t unique_id;
	mm_uint32_t server_id;
	struct mm_string zookeeper_import_parameters;
	struct mm_string rdb_account_cache_parameters;
	struct mm_string rdb_message_queue_parameters;
	struct mm_string queue_name;
	struct mm_string queue_pop_mode;
	//
	struct mm_string rdb_message_queue_auth;
	struct mm_string rdb_gateway_cache_auth;
};
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_cback_launch_init( struct mm_basic_frame_cback_launch* p );
extern void mm_basic_frame_cback_launch_destroy( struct mm_basic_frame_cback_launch* p );
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_cback_launch_load_config( struct mm_basic_frame_cback_launch* p, const char* config_file );
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_cback_launch_printf_information(struct mm_basic_frame_cback_launch* p);
//////////////////////////////////////////////////////////////////////////

#endif//__mm_basic_frame_cback_launch_h__