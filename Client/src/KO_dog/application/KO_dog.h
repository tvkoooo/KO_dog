#ifndef __KO_dog_h__
#define __KO_dog_h__

#include "core/mm_core.h"

#include "flake/mm_flake_activity.h"
#include "flake/mm_flake_surface.h"

#include "dish/mm_event.h"

//#include "KO_dog_test_animation.h"
#include "KO_dog_interface_manager.h"
#include "KO_dog_test.h"
#include "model_data/KO_dog_data.h"
#include "network/KO_dog_network.h"

#include "lua/mm_lua_context.h"
#include "toolkit/mm_error_desc.h"

namespace mm
{
	extern mm_flake_activity* mm_flake_activity_native_alloc();
	extern void mm_flake_activity_native_dealloc(mm_flake_activity* v);

	class KO_dog : public mm_flake_activity
	{
	//test
	public:
		struct mm_lua_context lua_context;

	public:
		//struct_timer_test lj_timer_test;
		KO_dog_data data;
		struct KO_dog_network network;

	public:
		KO_dog_interface_manager jiemian;
		//KO_dog_test_animation d_test_animation;

	public:
		struct mm_error_desc error_desc;

	public:
		void test_s_terminate( mm_flake_surface* surface );
		void test_s_launching( mm_flake_surface* surface );

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