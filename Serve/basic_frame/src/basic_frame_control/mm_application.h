#ifndef __mm_application_h__
#define __mm_application_h__

#include "mm_basic_frame_control.h"

#include "core/mm_prefix.h"

#include "core/mm_core.h"

#include "core/mm_argument.h"

//////////////////////////////////////////////////////////////////////////
extern const struct mm_argument g_argument;// default arg.
//////////////////////////////////////////////////////////////////////////
struct mm_application
{
	struct mm_argument argument;
	mm_sint8_t state;// run state.1 is run 0 is stop.
	struct mm_basic_frame_control impl;
};
//////////////////////////////////////////////////////////////////////////
extern struct mm_application* mm_application_instance();
//////////////////////////////////////////////////////////////////////////
extern void mm_application_init(struct mm_application* p);
extern void mm_application_destroy(struct mm_application* p);
//////////////////////////////////////////////////////////////////////////
extern void mm_application_initialize(struct mm_application* p, int argc, const char **argv);
extern void mm_application_start(struct mm_application* p);
extern void mm_application_interrupt(struct mm_application* p);
extern void mm_application_shutdown(struct mm_application* p);
extern void mm_application_join(struct mm_application* p);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_application_h__