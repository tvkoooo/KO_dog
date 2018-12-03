#include "KO_dog.h"

#include "core/mm_logger.h"

#include "dish/mm_file_context.h"

#include "lua/mm_lua.h"

#include "CEGUI/System.h"
#include "CEGUI/GUIContext.h"
#include "CEGUI/SchemeManager.h"
#include "CEGUI/WindowManager.h"
#include "CEGUI/widgets/DefaultWindow.h"

#include "CEGUI/XMLParserModules/TinyXML/XMLParserModule.h"

#include "CEGUIOgreRenderer/ImageCodec.h"
#include "CEGUIOgreRenderer/ResourceProvider.h"

#include "OgreCamera.h"
#include "OgreSceneNode.h"
#include "OgreEntity.h"
#include "OgreViewport.h"
#include "OgreMaterialManager.h"

#include "flake/mm_flake_context.h"
#include "flake/mm_flake_surface.h"

#include "tinyxml.h"

#include "dish/mm_file_path.h"

#include "core/mm_file_system.h"

#include "lj_KO_dog_test_setup.h"
#include "network/network_entry.h"

//////////////////////////////////////////////////////////////////////////
static void __static_flake_context_adaptive_timer_unit_update_synchronize(void* obj, double interval);

namespace mm
{

	//////////////////////////////////////////////////////////////////////////
	mm_flake_activity* mm_flake_activity_native_alloc()
	{
		return new KO_dog;
	}
	void mm_flake_activity_native_dealloc(mm_flake_activity* v)
	{
		delete v;
	}
	//////////////////////////////////////////////////////////////////////////
	KO_dog::KO_dog()
	{
		mm_lua_context_init(&this->lua_context);
		KO_dog_network_init(&this->network);
		KO_dog_network_assign_context(&this->network, this);
	}

	KO_dog::~KO_dog()
	{
		KO_dog_network_destroy(&this->network);
		mm_lua_context_destroy(&this->lua_context);
	}

	void KO_dog::on_acquire_feature() 
	{
		mm_flake_context* flake_context = this->get_context();
		flake_context->acquire_plugin_feature("Plugin_ParticleFX");
		flake_context->acquire_plugin_feature("Plugin_ParticleUniverse");
		flake_context->acquire_plugin_feature("Plugin_OctreeSceneManager");
	}

	void KO_dog::on_release_feature()
	{
		mm_flake_context* flake_context = this->get_context();

		flake_context->release_plugin_feature("Plugin_OctreeSceneManager");
		flake_context->release_plugin_feature("Plugin_ParticleUniverse");
		flake_context->release_plugin_feature("Plugin_ParticleFX");
	}

	void KO_dog::on_finish_launching()
	{		
		struct mm_logger* g_logger = mm_logger_instance();
		mm_logger_log_I(g_logger,"%s %d 1.",__FUNCTION__,__LINE__);
		//////////////////////////////////////////////////////////////////////////
		//lj_bomer_test_a();
		//////////////////////////////////////////////////////////////////////////
		mm_flake_context* flake_context = this->get_context();
		mm_flake_surface* flake_surface = flake_context->get_main_flake_surface();
		//ogre::renderwindow* render_window = flake_surface->get_render_window();
		////启动  入口//////////////////////////////////////////////////////
		this->test_s_launching(flake_surface);
		//////////////////////////////////////////////////////////////////////////
		//添加一个网络模块数据线程队列的弹出模块处理过程
		mm_adaptive_timer_schedule(&flake_context->d_adaptive_timer, "network", 5, 1, &__static_flake_context_adaptive_timer_unit_update_synchronize, this);
		mm_adaptive_timer_assign_active(&flake_context->d_adaptive_timer, "network", 1);
		//////////////////////////////////////////////////////////////////////////
		//设置udp入口地址和端口
		KO_dog_network_client_udp_assign_remote_target(&this->network, "::1", 20001);

		//lua 脚本初始化
		struct lua_State* L = this->lua_context.state;
		mm_lua_state_set_global_file_context(L, &flake_context->d_file_context);
		mm_lua_state_load_file_and_pcall(L, "script/main.lua");


	}

	void KO_dog::on_before_terminate()
	{
		//////////////////////////////////////////////////////////////////////
		mm_flake_context* flake_context = this->get_context();
		mm_flake_surface* flake_surface = flake_context->get_main_flake_surface();
		//////////////////////////////////////////////////////////////////////
		mm_adaptive_timer_assign_active(&flake_context->d_adaptive_timer, "network", 0);
		/////结束  出口//////////////////////////////////////////////////////////////
		this->test_s_terminate(flake_surface);

	}

	void KO_dog::on_start()
	{
		//mm_flake_context* flake_context = this->get_context();
		//flake_context->d_cegui_system.set_rendering_enabled(false);
		//this->lj_timer_test.start();
		KO_dog_network_start(&this->network);
	}
	void KO_dog::on_interrupt()
	{
		//this->lj_timer_test.interrupt();
		KO_dog_network_interrupt(&this->network);
	}
	void KO_dog::on_shutdown()
	{
		//this->lj_timer_test.shutdown();
		KO_dog_network_shutdown(&this->network);
	}
	void KO_dog::on_join()
	{
		//this->lj_timer_test.join();
		KO_dog_network_join(&this->network);
	}

	void KO_dog::test_s_launching( mm_flake_surface* surface )
	{
		float d = 0;

		struct mm_logger* g_logger = mm_logger_instance();
		//////////////////////////////////////////////////////////////////////////
		mm_flake_context* flake_context = this->get_context();
		//////////////////////////////////////////////////////////////////////////
		this->jiemian.assign_flake_context(flake_context);
		//this->d_test_animation.assign_flake_context(flake_context);
		//////////////////////////////////////////////////////////////////////////
		this->jiemian.on_finish_launching(surface);
		//this->d_test_animation.on_finish_launching(surface);

		//////////////////////////////////////////////////////////////////////////
	}
	void KO_dog::test_s_terminate( mm_flake_surface* surface )
	{
		struct mm_logger* g_logger = mm_logger_instance();
		mm_flake_context* flake_context = this->get_context();

		//////////////////////////////////////////////////////////////////////////
		this->jiemian.on_before_terminate(surface);
		//this->d_test_animation.on_before_terminate(surface);

		//////////////////////////////////////////////////////////////////////////
	}

}

static void __static_flake_context_adaptive_timer_unit_update_synchronize(void* obj, double interval)
{
	struct mm_adaptive_timer_unit* unit = (struct mm_adaptive_timer_unit*)(obj);
	mm::KO_dog* p = (mm::KO_dog*)(unit->callback.obj);
	KO_dog_network_thread_handle_recv( &p->network);
}