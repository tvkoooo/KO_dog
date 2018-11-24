#include "KO_dog_test_animation.h"

#include "OgreSkeletonManager.h"
#include "OgreMesh.h"
#include "OgreMaterial.h"
#include "OgreTechnique.h"
#include "OgrePass.h"

#include "CEGUI/System.h"
#include "CEGUI/GUIContext.h"
#include "CEGUI/SchemeManager.h"
#include "CEGUI/WindowManager.h"
#include "CEGUI/RenderingWindow.h"


#include "toolkit/mm_util_mesh.h"

#include "flake/mm_system_event_surface.h"
#include "math/mm_math_const.h"


namespace mm
{
	static void __static_flake_context_adaptive_timer_unit_update_synchronize(void* obj, double interval);
	static void __static_logic_data_to_view(struct zhen_dog_luoji_data *d, Ogre::SceneNode* n);

	const std::string KO_dog_test_animation::event_close("event_close");

	KO_dog_test_animation::KO_dog_test_animation()
		: d_flake_context(NULL)
		, d_surface(NULL)

		, d_scene_manager(NULL)
		, d_root_node(NULL)

		, d_node_camera(NULL)
		, d_camera(NULL)
		, d_viewport(NULL)

		, d_light_node(NULL)
		, d_dir_light(NULL)

		, d_ogrehead_node_0(NULL)
		, d_ogrehead_node_1(NULL)
		, d_ogrehead_mesh_0(NULL)

		, d_skeleton_resource_ptr()
		, d_cube_skeleton(NULL)

		, d_floor_node(NULL)
		, d_floor_mash(NULL)

		, d_dog_resource_ptr()
		, d_floor_resource_ptr()

		, d_is_touch_began(false)

		, dog_running(0)
		, now_camra_node(NULL)

		, d_window(NULL)
		, l_layer_dog_a1(NULL)
		, Label_jiaodu(NULL)
		, Label_zongchang(NULL)
		, Label_sudu_v(NULL)
		, Label_quyu(NULL)
		, l_s_button_out(NULL)
		, StaticImage(NULL)
		//, dog_m_x(0)
		//, d_fix_v3()
		//, d_fix_s3()
		, dog_v_4(0)
		, dog_hudu_4_Dhudu(0)
		, dog_ds_all(0)
		, dog_ago()
		, dog_tag()
		, dog_now()
		, dog_mid()
		, d_sync_frequency(0)
		, d_sync_interval(0)
		, d_is_anchor_touch_began(false)
		, d_rotation(0)
	{
		mm_bitset_init(&this->keyb_s);
		mm_vector2_init(&this->d_anchor_center);
		mm_bitset_resize(&this->keyb_s, mm::mm_key::MediaSelect + 1);
	}
	KO_dog_test_animation::~KO_dog_test_animation()
	{
		mm_bitset_destroy(&this->keyb_s);
		mm_vector2_destroy(&this->d_anchor_center);
	}
	void KO_dog_test_animation::assign_flake_context(mm_flake_context* flake_context)
	{
		this->d_flake_context = flake_context;
	}

	void KO_dog_test_animation::on_finish_launching(mm_flake_surface* surface)
	{
		this->d_surface = surface;
		/////////////////////////////////////////////////////////////////////
		this->d_event_updated_conn = surface->d_event_set.subscribe_event(mm_flake_surface::event_updated, &KO_dog_test_animation::on_event_updated, this);

		this->d_event_mouse_moved_conn = surface->d_event_set.subscribe_event(mm_flake_surface::event_mouse_moved, &KO_dog_test_animation::on_event_mouse_moved, this);
		this->d_event_mouse_began_conn = surface->d_event_set.subscribe_event(mm_flake_surface::event_mouse_began, &KO_dog_test_animation::on_event_mouse_began, this);
		this->d_event_mouse_ended_conn = surface->d_event_set.subscribe_event(mm_flake_surface::event_mouse_ended, &KO_dog_test_animation::on_event_mouse_ended, this);
		this->d_event_key_pressed_conn = surface->d_event_set.subscribe_event(mm_flake_surface::event_key_pressed, &KO_dog_test_animation::on_event_key_pressed, this);
		this->d_event_key_release_conn = surface->d_event_set.subscribe_event(mm_flake_surface::event_key_release, &KO_dog_test_animation::on_event_key_release, this);
		/////////////////////////////////////////////////////////////////////
		Ogre::Root* _ogre_root = this->d_flake_context->d_ogre_system.get_ogre_root();

		// Create the scene manager
		this->d_scene_manager = _ogre_root->createSceneManager();
		Ogre::RTShader::ShaderGenerator::getSingletonPtr()->addSceneManager(this->d_scene_manager);
		// Create and initialise the camera
		this->d_root_node = this->d_scene_manager->getRootSceneNode();
		/////////////////////////////////////////////////////////////////////
		this->d_camera = d_scene_manager->createCamera("main_camera");
		//this->d_camera->setPosition(Ogre::Vector3(0, 0, 0));
		//this->d_camera->lookAt(Ogre::Vector3(0, 0, 0));
		this->d_camera->setNearClipDistance(1.0f);
		this->d_camera->setFarClipDistance(100000.0f);
		this->d_camera->setAutoAspectRatio(true);

		this->d_node_camera = this->d_root_node->createChildSceneNode();
		this->d_node_camera->attachObject(this->d_camera);
		this->now_camra_node = this->d_node_camera;

		this->d_viewport = surface->d_render_window->addViewport(this->d_camera);
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
		/////////////////////////////////////////////////////////////////////
		this->on_scene_launching();
		this->on_scene_layer_launching();
		this->on_synchronize_launching();
	}
	void KO_dog_test_animation::on_before_terminate(mm_flake_surface* surface)
	{
		struct mm_logger* g_logger = mm_logger_instance();
		mm_flake_context* flake_context = this->d_flake_context;
		Ogre::Root* _ogre_root = flake_context->d_ogre_system.get_ogre_root();
		//////////////////////////////////////////////////////////////////////////
		surface->d_render_window->removeViewport(this->d_viewport->getZOrder());
		//////////////////////////////////////////////////////////////////////////
		this->on_synchronize_terminate();
		this->on_scene_layer_terminate();
		this->on_scene_terminate();
		//////////////////////////////////////////////////////////////////////////
		this->d_scene_manager->destroyLight(this->d_dir_light);
		this->d_scene_manager->destroySceneNode(this->d_light_node);
		this->d_scene_manager->destroyCamera(this->d_camera);
		this->d_scene_manager->destroySceneNode(this->d_node_camera);
		//////////////////////////////////////////////////////////////////////////
		Ogre::RTShader::ShaderGenerator::getSingletonPtr()->removeSceneManager(this->d_scene_manager);
		_ogre_root->destroySceneManager(this->d_scene_manager);
		mm_logger_log_I(g_logger, "KO_dog::%s %d success.", __FUNCTION__, __LINE__);
		//////////////////////////////////////////////////////////////////////////
		surface->d_event_set.unsubscribe_event(mm_flake_surface::event_updated, this->d_event_updated_conn);

		surface->d_event_set.unsubscribe_event(mm_flake_surface::event_mouse_moved, this->d_event_mouse_moved_conn);
		surface->d_event_set.unsubscribe_event(mm_flake_surface::event_mouse_began, this->d_event_mouse_began_conn);
		surface->d_event_set.unsubscribe_event(mm_flake_surface::event_mouse_ended, this->d_event_mouse_ended_conn);
		surface->d_event_set.unsubscribe_event(mm_flake_surface::event_key_pressed, this->d_event_key_pressed_conn);
		surface->d_event_set.unsubscribe_event(mm_flake_surface::event_key_release, this->d_event_key_release_conn);
	}
	void KO_dog_test_animation::on_scene_launching()
	{
		Ogre::ResourceGroupManager* _resource_group_manager = Ogre::ResourceGroupManager::getSingletonPtr();

		_resource_group_manager->addResourceLocation("media/models/dog", "mm_file_system", "media/models/dog");

		_resource_group_manager->initialiseResourceGroup(Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

		_resource_group_manager->initialiseResourceGroup("media/models/dog");

		Ogre::SkeletonManager* _skeleton_manager = Ogre::SkeletonManager::getSingletonPtr();

		//Ogre::ResourcePtr _resource_ptr = _skeleton_mgr.load("Cube.skeleton", "media/scene/level_0/model/Cube");
		//this->d_cube_skeleton = (Ogre::Skeleton*)_resource_ptr.get();
		//mm_attach_skeleton(this->d_cube_skeleton, "bend_l.skeleton", "media/scene/level_0/model/Cube");
		//mm_attach_skeleton(this->d_cube_skeleton, "bend_r.skeleton", "media/scene/level_0/model/Cube");
		this->d_skeleton_resource_ptr = _skeleton_manager->load("dog.SKELETON", "media/models/dog");
		this->d_cube_skeleton = (Ogre::Skeleton*)this->d_skeleton_resource_ptr.get();
		mm_attach_skeleton(this->d_cube_skeleton, "run.SKELETON", "media/models/dog");
		mm_attach_skeleton(this->d_cube_skeleton, "walk.SKELETON", "media/models/dog");
		mm_attach_skeleton(this->d_cube_skeleton, "idle.SKELETON", "media/models/dog");

		this->d_ogrehead_node_0 = this->d_root_node->createChildSceneNode();
		this->d_ogrehead_node_1 = this->d_ogrehead_node_0->createChildSceneNode();
		this->d_ogrehead_node_1->setPosition(0,2,0);
		this->d_ogrehead_node_1->yaw(Ogre::Radian(Ogre::Degree((Ogre::Real) - 180)));
		this->d_node_camera->setPosition(0, 10, 10);
		this->d_node_camera->pitch(Ogre::Radian(Ogre::Degree((Ogre::Real) - 30)));

		//this->d_ogrehead_mesh_0 = this->d_scene_manager->createEntity("Cube_0", "Cube.mesh", "media/scene/level_0/model/Cube");
		//this->d_ogrehead_node_0->scale(Ogre::Vector3(0.05, 0.05, 0.05));
		//this->d_ogrehead_node_0->attachObject(this->d_ogrehead_mesh_0);

		//this->d_unit_animation.d_entity = this->d_ogrehead_mesh_0;
		//this->d_unit_animation.addAnimationTrack("bend_l");
		//this->d_unit_animation.addAnimationTrack("bend_r");
		//this->d_unit_animation.play("bend_l", true);
		Ogre::Root* _ogre_root = this->d_flake_context->d_ogre_system.get_ogre_root();

		this->d_audio_factory = OGRE_NEW_T(OgreOggSound::OgreOggSoundFactory, Ogre::MEMCATEGORY_GENERAL)();
		_ogre_root->addMovableObjectFactory(this->d_audio_factory, true);

		this->d_audio_manager = OGRE_NEW_T(OgreOggSound::OgreOggSoundManager, Ogre::MEMCATEGORY_GENERAL)();

		this->d_audio_manager->init();

		//this->d_unit_animation_n.set_scene_manager(this->d_scene_manager);
		//this->d_unit_animation_n.set_scene_node(this->d_ogrehead_node_0);
		//this->d_unit_animation_n.set_resource_group("media/scene/level_0/model/Cube");
		//this->d_unit_animation_n.set_entity_asset("Cube.mesh");
		//this->d_unit_animation_n.add_animation_track("bend_l", "bend_l");
		//this->d_unit_animation_n.add_animation_track("bend_r", "bend_r");
		////this->d_unit_animation_n.play("bend_l", true);
		//this->d_unit_animation_n.play("bend_r", true);

		//this->d_unit_audio_n.set_audio_manager(this->d_audio_manager);
		//this->d_unit_audio_n.set_scene_node(this->d_ogrehead_node_0);
		//this->d_unit_audio_n.set_resource_group("media/audio");
		//this->d_unit_audio_n.add_audio_track("shake", "dog_tic_shake.ogg");
		//// this->d_unit_audio_n.play("shake", false);

		Ogre::MeshManager* _mesh_manager = Ogre::MeshManager::getSingletonPtr();
		this->d_dog_resource_ptr = _mesh_manager->load("dog.MESH", "media/models/dog");

		this->d_unit_animation_n.set_scene_manager(this->d_scene_manager);
		this->d_unit_animation_n.set_scene_node(this->d_ogrehead_node_0);
		this->d_unit_animation_n.set_resource_group("media/models/dog");
		this->d_unit_animation_n.set_entity_asset("dog.MESH");
		this->d_unit_animation_n.entity_produce();
		this->d_unit_animation_n.add_animation_track("run", "run");
		this->d_unit_animation_n.add_animation_track("walk", "walk");
		this->d_unit_animation_n.add_animation_track("idle", "idle");
		this->d_unit_animation_n.play("idle", true);
		//this->d_unit_animation_n.play("run", true);

		//this->d_unit_audio_n.set_audio_manager(this->d_audio_manager);
		//this->d_unit_audio_n.set_scene_node(this->d_ogrehead_node_0);
		//this->d_unit_audio_n.set_resource_group("media/audio");
		//this->d_unit_audio_n.add_audio_track("shake", "dog_tic_shake.ogg");
		// this->d_unit_audio_n.play("shake", false);


		// create a floor mesh resource
		this->d_floor_resource_ptr = _mesh_manager->createPlane("floor", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
			Ogre::Plane(Ogre::Vector3::UNIT_Y, 0), 100, 100, 10, 10, true, 1, 10, 10, Ogre::Vector3::UNIT_Z);

		// create a floor entity, give it a material, and place it at the origin
		this->d_floor_mash = this->d_scene_manager->createEntity("Floor", "floor");
		this->d_floor_mash->setMaterialName("floor/grass");
		this->d_floor_mash->setCastShadows(false);
		//this->d_scene_manager->getRootSceneNode()->attachObject(floor);
		this->d_floor_node = this->d_root_node->createChildSceneNode();
		this->d_floor_node->attachObject(this->d_floor_mash);
	}
	void KO_dog_test_animation::on_scene_terminate()
	{
		Ogre::Root* _ogre_root = this->d_flake_context->d_ogre_system.get_ogre_root();

		this->d_floor_node->detachObject(this->d_floor_mash);
		this->d_scene_manager->destroyEntity(this->d_floor_mash);
		this->d_scene_manager->destroySceneNode(this->d_floor_node);

		this->d_unit_animation_n.entity_recycle();
		this->d_unit_animation_n.clear_animation_track();
		this->d_unit_audio_n.clear_audio_track();

		OGRE_DELETE_T(this->d_audio_manager, OgreOggSoundManager, Ogre::MEMCATEGORY_GENERAL);

		_ogre_root->removeMovableObjectFactory(this->d_audio_factory);
		OGRE_DELETE_T(this->d_audio_factory, OgreOggSoundFactory, Ogre::MEMCATEGORY_GENERAL);

		Ogre::MeshManager* _mesh_manager = Ogre::MeshManager::getSingletonPtr();

		_mesh_manager->unload(this->d_floor_resource_ptr->getName(), Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
		_mesh_manager->remove(this->d_floor_resource_ptr->getName(), Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
		this->d_floor_resource_ptr.reset();

		_mesh_manager->unload(this->d_dog_resource_ptr->getName(), "media/models/dog");
		_mesh_manager->remove(this->d_dog_resource_ptr->getName(), "media/models/dog");
		this->d_dog_resource_ptr.reset();

		Ogre::SkeletonManager* _skeleton_manager = Ogre::SkeletonManager::getSingletonPtr();

		//mm_detach_skeleton(this->d_cube_skeleton, "bend_l");
		//mm_detach_skeleton(this->d_cube_skeleton, "bend_r");

		mm_detach_skeleton(this->d_cube_skeleton, "walk");
		mm_detach_skeleton(this->d_cube_skeleton, "run");
		mm_detach_skeleton(this->d_cube_skeleton, "idle");

		_skeleton_manager->unload(this->d_skeleton_resource_ptr->getName(), "media/models/dog");
		_skeleton_manager->remove(this->d_skeleton_resource_ptr->getName(), "media/models/dog");
		this->d_skeleton_resource_ptr.reset();
		this->d_cube_skeleton = NULL;

		//this->d_scene_manager->destroyEntity(this->d_ogrehead_mesh_0);
		this->d_scene_manager->destroySceneNode(this->d_ogrehead_node_0);

		Ogre::ResourceGroupManager* _resource_group_manager = Ogre::ResourceGroupManager::getSingletonPtr();

		_resource_group_manager->removeResourceLocation("media/models/dog", "media/models/dog");
	}
	void KO_dog_test_animation::on_scene_layer_launching()
	{
		/////////////////////////////////////////////////////////////////////
		CEGUI::GUIContext* _gui_context = this->d_surface->d_gui_context;
		//////////////////////////////////////////////////////////////////////////
		//int index = 0;
		//char index_string[64] = { 0 };
		//mm_sprintf(index_string, "_%d", index);

		//std::string system_font_12_name = "system_font_12";
		//system_font_12_name = system_font_12_name + index_string;
		////////////////////////////////////////////////////////////////////////////
		//// CEGUI relies on various systems being set-up, so this is what we do
		//// here first.
		////
		//// The first thing to do is load a CEGUI 'scheme' this is basically a file
		//// that groups all the required resources and definitions for a particular
		//// skin so they can be loaded / initialised easily
		////
		//// So, we use the SchemeManager singleton to load in a scheme that loads the
		//// imagery and registers widgets for the TaharezLook skin.  This scheme also
		//// loads in a font that gets used as the system default.
		//CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme");

		//// create the default surface font.
		//CEGUI::Font& _defaultFont = this->d_flake_context->d_cegui_system.create_system_font_by_size(this->d_surface->get_canvas_size(), system_font_12_name.c_str(), 12.0f);

		//// The next thing we do is to set a default mouse cursor image.  This is
		//// not strictly essential, although it is nice to always have a visible
		//// cursor if a window or widget does not explicitly set one of its own.
		////
		//// The TaharezLook Imageset contains an Image named "MouseArrow" which is
		//// the ideal thing to have as a defult mouse cursor image.
		//_gui_context->getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");

		//// load font and setup default if not loaded via scheme
		//// Set default font for the gui context
		//_gui_context->setDefaultFont(&_defaultFont);
		//////////////////////////////////////////////////////////////////////////
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		//std::string _root_window_name = "root_window";
		//_root_window_name = _root_window_name + index_string;
		this->d_window = (CEGUI::Window*)_window_manager->createWindow("DefaultWindow", "root_window_1");
		this->l_layer_dog_a1 = _window_manager->loadLayoutFromFile("l_layer_dog_a1.layout");

		this->Label_jiaodu = this->l_layer_dog_a1->getChild("Label_jiaodu");
		this->Label_zongchang = this->l_layer_dog_a1->getChild("Label_zongchang");
		this->Label_sudu_v = this->l_layer_dog_a1->getChild("Label_sudu_v");
		this->Label_quyu = this->l_layer_dog_a1->getChild("Label_quyu");
		this->l_s_button_out = this->l_layer_dog_a1->getChild("l_s_button_out");

		this->StaticImage = this->l_layer_dog_a1->getChild("StaticImage");
		this->StaticImage->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_test_animation::on_handle_StaticImage, this));
		this->l_s_button_out->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_test_animation::on_handle_l_s_button_out, this));

		this->Label_jiaodu->setText("0 (du)");
		this->Label_zongchang->setText("0");
		//this->l_ensure->setVisible(false);
		this->d_window->addChild(this->l_layer_dog_a1);
		_gui_context->setRootWindow(this->d_window);

		_gui_context->getMouseCursor().setVisible(false);


		/////////////////////////////////////////////////////////////////////////
		// d_anchor_center.
		double _window_size_x = this->d_surface->d_window_size.x;
		double _window_size_y = this->d_surface->d_window_size.y;

		const CEGUI::URect& area = this->StaticImage->getArea();

		const CEGUI::UVector2& _r_min = area.d_min;
		const CEGUI::UVector2& _r_max = area.d_max;

		CEGUI::UVector2 _r_size = CEGUI::UVector2(_r_max.d_x - _r_min.d_x, _r_max.d_y - _r_min.d_y);
		CEGUI::UVector2 _r_center = _r_min + _r_size / CEGUI::UDim(2.0f, 0);

		this->d_anchor_center.x = (_r_center.d_x.d_scale * _window_size_x) + _r_center.d_x.d_offset;
		this->d_anchor_center.y = (_r_center.d_y.d_scale * _window_size_y) + _r_center.d_y.d_offset;

		/////////////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////////////
		//Ogre::ResourceGroupManager& _resource_group_mgr = Ogre::ResourceGroupManager::getSingleton();

		//_resource_group_mgr.addResourceLocation("media/models/ogrehead", "mm_file_system", "media/models/ogrehead");
		//_resource_group_mgr.addResourceLocation("media/models/cube", "mm_file_system", "media/models/cube");

		//_resource_group_mgr.initialiseResourceGroup("media/models/ogrehead");
		//_resource_group_mgr.initialiseResourceGroup("media/models/cube");

		//this->d_damagedhelmet_mesh_0 = this->d_scene_manager->createEntity("ogrehead", "ogrehead.mesh", "media/models/ogrehead");
		////this->d_damagedhelmet_mesh_0 = this->d_scene_manager->createEntity("cube_0", "Cube.mesh", "media/models/cube");
		//this->d_damagedhelmet_node_0 = this->d_root_node->createChildSceneNode();
		//this->d_damagedhelmet_node_0->attachObject(this->d_damagedhelmet_mesh_0);
		//this->d_damagedhelmet_node_0->showBoundingBox(true);
		//this->d_damagedhelmet_node_0->setScale(Ogre::Vector3(0.03f, 0.03f, 0.03f));
	}

	void KO_dog_test_animation::on_scene_layer_terminate()
	{
		//this->d_scene_manager->destroyEntity(this->d_damagedhelmet_mesh_0);
		//this->d_scene_manager->destroySceneNode(this->d_damagedhelmet_node_0);

		//Ogre::ResourceGroupManager& _resource_group_mgr = Ogre::ResourceGroupManager::getSingleton();

		//_resource_group_mgr.removeResourceLocation("media/models/ogrehead", "media/models/ogrehead");
		//_resource_group_mgr.removeResourceLocation("media/models/cube", "media/models/cube");
		//////////////////////////////////////////////////////////////////////////
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		_window_manager->destroyWindow(this->l_layer_dog_a1);
		_window_manager->destroyWindow(this->d_window);
	}

	bool KO_dog_test_animation::on_event_updated(const mm_event_args& args)
	{
		const mm_event_surface_updated& evt = (const mm_event_surface_updated&)(args);
		//this->d_unit_animation.update((float)evt.interval);
		this->d_unit_animation_n.update((float)evt.interval);
		this->d_unit_audio_n.update((float)evt.interval);

		this->dog_mid.D_jiaodu +=(this->dog_tag.D_jiaodu - this->dog_ago.D_jiaodu) * (evt.interval / this->d_sync_interval);
		this->dog_mid.D_weizhi +=(this->dog_tag.D_weizhi - this->dog_ago.D_weizhi) * (evt.interval / this->d_sync_interval);
		__static_logic_data_to_view(&this->dog_mid, this->d_ogrehead_node_0);

		///////////////////////////////////////////////////////////////////////////////////////////////
		this->dog_v_4 = 3 * mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowUp) - mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowDown);
		this->dog_hudu_4_Dhudu = mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowLeft) - mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowRight);
		if (this->dog_v_4 != 0 && this->dog_running == 0)
		{
			this->d_unit_animation_n.stop("idle");
			mm_unit_animation_track* t = this->d_unit_animation_n.play("run", true);

			if (this->dog_v_4 > 0)
			{
				t->set_speed(1);
				this->dog_running = 1;
			}
			else
			{
				t->set_speed(-1);
				this->dog_running = -1;
			}
			
		}
		if(this->dog_v_4 > 0 && this->dog_running == -1)
		{
			mm_unit_animation_track* t = this->d_unit_animation_n.play("run", true);
			t->set_speed(1);
			this->dog_running = 1;
		}
		if (this->dog_v_4 < 0 && this->dog_running == 1)
		{
			mm_unit_animation_track* t = this->d_unit_animation_n.play("run", true);
			t->set_speed(-1);
			this->dog_running = -1;
		}


		if (this->dog_v_4 == 0 && this->dog_running != 0)
		{
			this->d_unit_animation_n.stop("run");
			this->d_unit_animation_n.play("idle", true);
			this->dog_running = false;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////
		this->Label_sudu_v->setText("v:" + this->dog_v_4.to_string());
		return false;
	}

	bool KO_dog_test_animation::on_event_mouse_moved(const mm_event_args& args)
	{
		const mm_event_mouse& evt = (const mm_event_mouse&)(args);

		double _m_z = evt.content.abs_z - this->d_camera_moved_pos.z;

		this->d_camera_moved_pos.z = evt.content.abs_z;

		if (this->now_camra_node != NULL)
		{
			if (true == this->d_is_touch_began)
			{
				double _m_x = evt.content.abs_x - this->d_camera_moved_pos.x;
				double _m_y = evt.content.abs_y - this->d_camera_moved_pos.y;

				this->d_camera_moved_pos.x = evt.content.abs_x;
				this->d_camera_moved_pos.y = evt.content.abs_y;

				this->now_camra_node->yaw(Ogre::Radian(Ogre::Degree((Ogre::Real)-_m_x)));
				this->now_camra_node->pitch(Ogre::Radian(Ogre::Degree((Ogre::Real)-_m_y)));
			}
			this->now_camra_node->roll(Ogre::Radian(Ogre::Degree((Ogre::Real)-_m_z)));
		}		

		printf("is in area:%d \n", this->d_is_anchor_touch_began);
		//控制器/////////////////////////////////////////////////////////////////
		this->update_anchor_quaternion(evt.content.abs_x, evt.content.abs_y);

		return false;
	}
	bool KO_dog_test_animation::on_event_mouse_began(const mm_event_args& args)
	{
		const mm_event_mouse& evt = (const mm_event_mouse&)(args);
		this->d_camera_moved_pos.x = evt.content.abs_x;
		this->d_camera_moved_pos.t = evt.content.abs_y;
		this->d_camera_moved_pos.z = evt.content.abs_z;
		this->d_is_touch_began = true;
		/////////////////////////////////////////////////////////////////////////
		double _window_size_x = this->d_surface->d_window_size.x;
		double _window_size_y = this->d_surface->d_window_size.y;

		const CEGUI::URect& area = this->StaticImage->getArea();

		const CEGUI::UVector2& _r_min = area.d_min;
		const CEGUI::UVector2& _r_max = area.d_max;

		struct mm_vector2 _r_min_f;
		struct mm_vector2 _r_max_f;

		_r_min_f.x = (_r_min.d_x.d_scale * _window_size_x) + _r_min.d_x.d_offset;
		_r_min_f.y = (_r_min.d_y.d_scale * _window_size_y) + _r_min.d_y.d_offset;

		_r_max_f.x = (_r_max.d_x.d_scale * _window_size_x) + _r_max.d_x.d_offset;
		_r_max_f.y = (_r_max.d_y.d_scale * _window_size_y) + _r_max.d_y.d_offset;

		if ((_r_min_f.x <= evt.content.abs_x) &&
			(_r_max_f.x > evt.content.abs_x) &&
			(_r_min_f.y <= evt.content.abs_y) &&
			(_r_max_f.y > evt.content.abs_y))
		{
			// touch position at area.
			this->d_is_anchor_touch_began = true;
			//
			this->update_anchor_quaternion(evt.content.abs_x, evt.content.abs_y);
		}

		/////////////////////////////////////////////////////////////////////////
		return false;
	}
	bool KO_dog_test_animation::on_event_mouse_ended(const mm_event_args& args)
	{
		const mm_event_mouse& evt = (const mm_event_mouse&)(args);
		this->d_is_touch_began = false;
		if (true == this->d_is_anchor_touch_began)
		{
			this->d_is_anchor_touch_began = false;
		}
		return false;
	}
	bool KO_dog_test_animation::on_event_key_pressed(const mm_event_args& args)
	{
		const mm_event_key& evt = (const mm_event_key&)(args);		
				
		if (evt.content.key == mm::mm_key::ArrowUp && 1 != mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowUp))
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowUp, 1);
		}
		if (evt.content.key == mm::mm_key::ArrowDown && 1 != mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowDown))
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowDown, 1);
		}
		if (evt.content.key == mm::mm_key::ArrowLeft && 1 != mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowLeft))
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowLeft, 1);

		}
		if (evt.content.key == mm::mm_key::ArrowRight && 1 != mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowRight))
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowRight, 1);
		}

		if (evt.content.key == mm::mm_key::C && 1 != mm_bitset_get(&this->keyb_s, mm::mm_key::C))
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::C, 1);
			if (this->now_camra_node == this->d_ogrehead_node_1)
			{
				this->now_camra_node->detachObject(this->d_camera);
				this->d_node_camera->attachObject(this->d_camera);
				this->now_camra_node = this->d_node_camera;
			}
			else
			{
				this->now_camra_node->detachObject(this->d_camera);
				this->d_ogrehead_node_1->attachObject(this->d_camera);
				this->now_camra_node = this->d_ogrehead_node_1;
			}

		}

		this->dog_v_4 = 3 * mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowUp) - mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowDown);
		this->dog_hudu_4_Dhudu = mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowLeft) - mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowRight);


		return false;
	}
	bool KO_dog_test_animation::on_event_key_release(const mm_event_args& args)
	{
		const mm_event_key& evt = (const mm_event_key&)(args);
		if (evt.content.key == mm::mm_key::ArrowUp)
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowUp, 0);
		}
		if (evt.content.key == mm::mm_key::ArrowDown)
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowDown, 0);
		}
		if (evt.content.key == mm::mm_key::ArrowLeft)
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowLeft, 0);
		}
		if (evt.content.key == mm::mm_key::ArrowRight)
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowRight, 0);
		}

		if (evt.content.key == mm::mm_key::C)
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::C, 0);
		}

		this->dog_v_4 = 3 * mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowUp) - mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowDown);
		this->dog_hudu_4_Dhudu = mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowLeft) - mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowRight);


		return false;
	}
	void KO_dog_test_animation::on_synchronize_launching()
	{
		this->d_sync_frequency = 30.0f;
		this->d_sync_interval = 1.0f / this->d_sync_frequency;

		this->d_flake_context->set_logical_frequency(this->d_sync_frequency);
		this->d_flake_context->set_display_frequency(60.0);

		mm_adaptive_timer_schedule(&this->d_flake_context->d_adaptive_timer, "framelk", this->d_sync_frequency, 1, &__static_flake_context_adaptive_timer_unit_update_synchronize, this);
		mm_adaptive_timer_assign_active(&this->d_flake_context->d_adaptive_timer, "framelk", 1);
	}
	void KO_dog_test_animation::on_synchronize_terminate()
	{
		mm_adaptive_timer_assign_active(&this->d_flake_context->d_adaptive_timer, "framelk",0);
	}

	void KO_dog_test_animation::on_update_synchronize(double interval)
	{
		///////////////////////////////////////////////////////////////////////////////////////
		__static_logic_data_to_view(&this->dog_tag, this->d_ogrehead_node_0);
		///////////////////////////////////////////////////////////////////////////////////////////////
		this->dog_ago = this->dog_tag;
		this->dog_tag = this->dog_now;
		this->dog_mid = this->dog_ago;
		///////////////////////////////////////////////////////////////////////////////////////
		mm_fix32 ctrl_list_now = this->dog_hudu_4_Dhudu;//从命令队列中弹出的当前帧命令

		mm_fix32 drv = ctrl_list_now * 60 * this->d_sync_interval;
		this->dog_now.D_jiaodu += drv * mm_fix32::MM_PI_DIV_180;

		mm_fix32_quaternion dog_4_data;
		dog_4_data.from_angle_axis(this->dog_now.D_jiaodu, mm_fix32_vector3::UNIT_Y);
		mm_fix32_vector3 dog_ds = mm_fix32_vector3::UNIT_Z * this->dog_v_4 * this->d_sync_interval;
		this->dog_now.D_weizhi += dog_4_data * dog_ds;
		///////////////////////////////////////////////////////////////////////////////////////
		this->dog_ds_all = dog_ds.length() + this->dog_ds_all;
		this->Label_jiaodu->setText(this->dog_now.D_jiaodu.to_string() + " (du)");
		this->Label_zongchang->setText(this->dog_ds_all.to_string());
		///////////////////////////////////////////////////////////////////////////////////////
	}
	static void __static_flake_context_adaptive_timer_unit_update_synchronize(void* obj, double interval)
	{
		struct mm_adaptive_timer_unit* unit = (struct mm_adaptive_timer_unit*)(obj);
		KO_dog_test_animation* p = (KO_dog_test_animation*)(unit->callback.obj);
		p->on_update_synchronize(interval);
	}
	static void __static_logic_data_to_view(struct zhen_dog_luoji_data *d, Ogre::SceneNode* n)
	{
		mm_fix32_quaternion dog_4_data;
		dog_4_data.from_angle_axis(d->D_jiaodu, mm_fix32_vector3::UNIT_Y);

		Ogre::Quaternion dog_4_xunruanqi(dog_4_data.w, dog_4_data.x, dog_4_data.y, dog_4_data.z);
		n->setOrientation(dog_4_xunruanqi);
		n->setPosition(d->D_weizhi.x, d->D_weizhi.y, d->D_weizhi.z);
	}

	bool KO_dog_test_animation::on_handle_StaticImage(const CEGUI::EventArgs& args)
	{
		//mm_event_args evt_ags;
		////mm_event_animation_close evt_closd("args");
		//this->d_event_set.fire_event(KO_dog_test_animation::event_close, evt_ags);
		return false;
	}
	bool KO_dog_test_animation::on_handle_l_s_button_out(const CEGUI::EventArgs& args)
	{
		mm_event_args evt_ags;
		//mm_event_animation_close evt_closd("args");
		this->d_event_set.fire_event(KO_dog_test_animation::event_close, evt_ags);
		return false;
	}
	void KO_dog_test_animation::update_anchor_quaternion(double abs_x, double abs_y)
	{
		if (true == this->d_is_anchor_touch_began)
		{
			double dx = abs_x - this->d_anchor_center.x;
			double dy = abs_y - this->d_anchor_center.y;

			this->d_rotation = atan2(dy, dx) - MM_PI_2;

			// the original quaternion is -pi / 2.
			CEGUI::Quaternion ce_quaternion = CEGUI::Quaternion::axisAngleRadians(CEGUI::Vector3f(0, 0, 1), (float)(this->d_rotation));
			this->StaticImage->setRotation(ce_quaternion);

			this->StaticImage->setVisible(true);
		}
		else
		{
			this->StaticImage->setVisible(false);
		}
	}
}

