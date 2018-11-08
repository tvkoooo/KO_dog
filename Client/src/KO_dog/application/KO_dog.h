#ifndef __KO_dog_h__
#define __KO_dog_h__

#include "core/mm_core.h"

#include "flake/mm_flake_activity.h"
#include "flake/mm_flake_surface.h"

#include "dish/mm_event.h"

//#include "KO_dog_test_animation.h"
#include "lj_KO_dog_jiemian.h"

namespace mm
{
	extern mm_flake_activity* mm_flake_activity_native_alloc();
	extern void mm_flake_activity_native_dealloc(mm_flake_activity* v);

	class KO_dog : public mm_flake_activity
	{

	public:
		lj_KO_dog_jiemian jiemian;
		//KO_dog_test_animation d_test_animation;

	public:
		void test_s_terminate( mm_flake_surface* surface );
		void test_s_launching( mm_flake_surface* surface );
		void test_s_fuzhi( mm_flake_surface* surface );
	public:
		KO_dog();
		virtual ~KO_dog();
	public:
		virtual void on_acquire_feature();
		virtual void on_release_feature();
	public:
		virtual void on_finish_launching();
		virtual void on_before_terminate();
	public:
		virtual void on_start();
		virtual void on_interrupt();
		virtual void on_shutdown();
		virtual void on_join();
	};
}

#endif//__KO_dog_h__