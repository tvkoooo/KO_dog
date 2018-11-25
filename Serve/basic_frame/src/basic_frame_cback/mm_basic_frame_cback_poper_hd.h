#ifndef __mm_basic_frame_cback_poper_hd_h__
#define __mm_basic_frame_cback_poper_hd_h__

#include "core/mm_prefix.h"

#include "core/mm_core.h"

#include "net/mm_packet.h"

struct mm_string;
struct mm_redis_poper;
//////////////////////////////////////////////////////////////////////////
extern void mm_basic_frame_cback_redis_poper_hd(struct mm_redis_poper* p,void* u,struct mm_string* data);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_basic_frame_cback_poper_hd_h__