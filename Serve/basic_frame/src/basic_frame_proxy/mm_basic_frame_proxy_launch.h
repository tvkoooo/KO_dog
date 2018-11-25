#ifndef __mm_basic_frame_proxy_launch_h__
#define __mm_basic_frame_proxy_launch_h__

#include "core/mm_core.h"
#include "core/mm_string.h"

//////////////////////////////////////////////////////////////////////////
struct mm_basic_frame_proxy_launch
{
	mm_uint32_t unique_id;
	mm_uint32_t server_id;
	struct mm_string internal_mailbox_parameters;
	struct mm_string zookeeper_import_parameters;
	struct mm_string zookeeper_export_parameters;
	mm_uint32_t module;
	mm_uint32_t mid_l;
	mm_uint32_t mid_r;
	mm_uint32_t shard;

	mm_uint64_t number_id;
};
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_proxy_launch_init(struct mm_basic_frame_proxy_launch* p);
extern void mm_basic_frame_proxy_launch_destroy(struct mm_basic_frame_proxy_launch* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_proxy_launch_load_config( struct mm_basic_frame_proxy_launch* p, const char* config_file );
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_proxy_launch_printf_information(struct mm_basic_frame_proxy_launch* p);
//////////////////////////////////////////////////////////////////////////

#endif//__mm_basic_frame_proxy_launch_h__