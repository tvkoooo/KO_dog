#ifndef __mm_basic_frame_control_h__
#define __mm_basic_frame_control_h__

#include "core/mm_prefix.h"

#include "core/mm_core.h"
#include "core/mm_timer.h"

#include "net/mm_net_udp.h"
#include "net/mm_mailbox.h"
#include "net/mm_mt_contact.h"
#include "dish/mm_cmd_stdin.h"

#define MM_COMMOND_MAX_LINE 128

struct mm_basic_frame_control
{
	struct mm_net_tcp net_tcp;
	struct mm_cmd_stdin commond;
};
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_control_init(struct mm_basic_frame_control* p);
extern void mm_basic_frame_control_destroy(struct mm_basic_frame_control* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_control_assign_addr_target(struct mm_basic_frame_control* p,const char* info);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_control_command_set_logger(struct mm_basic_frame_control* p, mm_uint32_t level);
extern void mm_basic_frame_control_command_get_logger(struct mm_basic_frame_control* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_control_start(struct mm_basic_frame_control* p);
extern void mm_basic_frame_control_interrupt(struct mm_basic_frame_control* p);
extern void mm_basic_frame_control_shutdown(struct mm_basic_frame_control* p);
extern void mm_basic_frame_control_join(struct mm_basic_frame_control* p);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_basic_frame_control_h__