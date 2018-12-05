#include "KO_dog_zhujiemian_rtt.h"

namespace mm
{
	KO_dog_zhujiemian_rtt::KO_dog_zhujiemian_rtt()
		: n_camera("")
		, c_flake_context(NULL)
		, c_surface(NULL)

		, d_scene_manager(NULL)
		, d_root_node(NULL)
		, d_node_camera(NULL)
		, d_camera(NULL)
		, d_viewport(NULL)
		, d_light_node(NULL)
		, d_dir_light(NULL)
	{
		mm_windows_target_init(&this->d_windows_target);
	}

	KO_dog_zhujiemian_rtt::~KO_dog_zhujiemian_rtt()
	{
		mm_windows_target_destroy(&this->d_windows_target);
	}

	//ÅäÖÃrtt
	void KO_dog_zhujiemian_rtt::set_flake_context(mm_flake_context* c_flake_context, mm_flake_surface* c_surface)
	{
		this->c_flake_context = c_flake_context;
		this->c_surface = c_surface;
	}
	void KO_dog_zhujiemian_rtt::on_finish_launching()
	{
		struct mm_logger* g_logger = mm_logger_instance();
		Ogre::RenderTarget* _render_target = this->d_windows_target.d_render_target;
		//////////////////////////////////////////////////////////////////////
		Ogre::Root* _ogre_root = this->c_flake_context->d_ogre_system.get_ogre_root();

		// Create the scene manager
		this->d_scene_manager = _ogre_root->createSceneManager();
		Ogre::RTShader::ShaderGenerator::getSingletonPtr()->addSceneManager(this->d_scene_manager);
		// Create and initialise the camera
		this->d_root_node = this->d_scene_manager->getRootSceneNode();
		/////////////////////////////////////////////////////////////////////
		this->d_camera = this->d_scene_manager->createCamera(this->n_camera);
		this->d_camera->setNearClipDistance(1.0f);
		this->d_camera->setFarClipDistance(100000.0f);
		this->d_camera->setAutoAspectRatio(true);

		this->d_node_camera = this->d_root_node->createChildSceneNode();
		this->d_node_camera->attachObject(this->d_camera);

		this->d_viewport = _render_target->addViewport(this->d_camera);
		this->d_camera->setAspectRatio(Ogre::Real(this->d_viewport->getActualWidth()) / Ogre::Real(this->d_viewport->getActualHeight()));

		Ogre::Vector3 lightdir(0.55f, -0.3f, -0.75f);
		lightdir.normalise();
		this->d_light_node = this->d_root_node->createChildSceneNode();
		this->d_dir_light = this->d_scene_manager->createLight();
		this->d_dir_light->setType(Ogre::Light::LT_DIRECTIONAL);
		this->d_dir_light->setDirection(lightdir);
		this->d_dir_light->setDiffuseColour(Ogre::ColourValue::White);
		this->d_dir_light->setSpecularColour(Ogre::ColourValue(0.4f, 0.4f, 0.4f));
		this->d_light_node->attachObject(this->d_dir_light);
		this->d_scene_manager->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));

	}

	void KO_dog_zhujiemian_rtt::on_before_terminate()
	{
		Ogre::Root* _ogre_root = this->c_flake_context->d_ogre_system.get_ogre_root();
		//
		Ogre::RenderTarget* _render_target = this->d_windows_target.d_render_target;
		//
		this->d_scene_manager->destroyLight(this->d_dir_light);
		this->d_scene_manager->destroySceneNode(this->d_light_node);
		_render_target->removeViewport(this->d_viewport->getZOrder());
		this->d_scene_manager->destroyCamera(this->d_camera);
		this->d_scene_manager->destroySceneNode(this->d_node_camera);
		//
		Ogre::RTShader::ShaderGenerator::getSingletonPtr()->removeSceneManager(this->d_scene_manager);
		_ogre_root->destroySceneManager(this->d_scene_manager);
		//
		mm_windows_target_terminate(&this->d_windows_target);
	}

}
