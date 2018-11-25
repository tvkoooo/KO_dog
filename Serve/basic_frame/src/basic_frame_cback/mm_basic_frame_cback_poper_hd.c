#include "mm_basic_frame_cback_poper_hd.h"
#include "core/mm_logger.h"
#include "core/mm_string.h"
#include "net/mm_buffer_packet.h"
#include "mm_basic_frame_cback_logic.h"
//////////////////////////////////////////////////////////////////////////
static void __static_basic_frame_cback_packet_handle_poper(void* obj, struct mm_packet* pack);
//////////////////////////////////////////////////////////////////////////
void mm_basic_frame_cback_redis_poper_hd(struct mm_redis_poper* p, void* u, struct mm_string* data)
{
	mm_buffer_packet_handle_tcp((mm_uint8_t*)(data->s), 0, (mm_uint32_t)data->l, &__static_basic_frame_cback_packet_handle_poper, u);
}
//////////////////////////////////////////////////////////////////////////
static void __static_basic_frame_cback_packet_handle_poper(void* obj, struct mm_packet* pack)
{
	struct mm_basic_frame_cback* impl = (struct mm_basic_frame_cback*)(obj);
	mm_basic_frame_cback_logic_handle(impl, pack);
}
//////////////////////////////////////////////////////////////////////////
