#include "KO_dog.h"

#include "core/mm_logger.h"

#include "dish/mm_file_context.h"


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

//////////////////////////////////////////////////////////////////////////

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

	}

	KO_dog::~KO_dog()
	{

	}

	void KO_dog::on_acquire_feature() 
	{
		//mm_flake_context* flake_context = this->get_context();
		//flake_context->acquire_plugin_feature("Plugin_ParticleFX");
		//flake_context->acquire_plugin_feature("Plugin_ParticleUniverse");
		//flake_context->acquire_plugin_feature("Plugin_OctreeSceneManager");
	}

	void KO_dog::on_release_feature()
	{
		//mm_flake_context* flake_context = this->get_context();

		//flake_context->release_plugin_feature("Plugin_OctreeSceneManager");
		//flake_context->release_plugin_feature("Plugin_ParticleUniverse");
		//flake_context->release_plugin_feature("Plugin_ParticleFX");
	}

	void KO_dog::test_s_fuzhi( mm_flake_surface* surface )
	{

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

	}

	void KO_dog::on_before_terminate()
	{
		//////////////////////////////////////////////////////////////////////
		mm_flake_context* flake_context = this->get_context();
		mm_flake_surface* flake_surface = flake_context->get_main_flake_surface();
		/////结束  出口//////////////////////////////////////////////////////////////
		this->test_s_terminate(flake_surface);

	}

	void KO_dog::on_start()
	{
		//mm_flake_context* flake_context = this->get_context();
		//flake_context->d_cegui_system.set_rendering_enabled(false);
		this->lj_timer_test.start();
	}
	void KO_dog::on_interrupt()
	{
		this->lj_timer_test.interrupt();
	}
	void KO_dog::on_shutdown()
	{
		this->lj_timer_test.shutdown();
	}
	void KO_dog::on_join()
	{
		this->lj_timer_test.join();
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
