#ifndef __mm_basic_frame_cback_logic_h__
#define __mm_basic_frame_cback_logic_h__

#include "core/mm_prefix.h"

#include "core/mm_core.h"

#include "net/mm_packet.h"

#define MM_CBACK_HMGET_PATTERN_PAGE 128

struct mm_basic_frame_cback;
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_cback_logic_handle(struct mm_basic_frame_cback* impl,struct mm_packet* nt_pack);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_basic_frame_cback_logic_h__