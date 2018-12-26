#include "KO_dog_zhujiemian_dog.h"


#include "OgreMeshManager.h"
#include "OgreMesh.h"

#include "OgreSkeletonManager.h"
#include "toolkit/mm_util_mesh.h"
namespace mm
{

	KO_dog_zhujiemian_dog_data::KO_dog_zhujiemian_dog_data()
		: d_vector4()
		, obj_node_camera(NULL)
	{

	}

	KO_dog_zhujiemian_dog_data::~KO_dog_zhujiemian_dog_data()
	{

	}

	KO_dog_zhujiemian_dog::KO_dog_zhujiemian_dog()
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

		, a_node_horizon(NULL)
		, a_node_head(NULL)
		, a_mesh(NULL)

		, r_skeleton_resource_ptr()
		, r_cube_skeleton(NULL)
		, r_mesh_resource_ptr()
	{

	}

	KO_dog_zhujiemian_dog::~KO_dog_zhujiemian_dog()
	{

	}

	void KO_dog_zhujiemian_dog::set_flake_context(mm_flake_context* d_flake_context, mm_flake_surface* d_surface)
	{
		this->c_flake_context = d_flake_context;
		this->c_surface = d_surface;
	}
	void KO_dog_zhujiemian_dog::setVisible(bool b)
	{
		this->d_scene_manager->setCameraRelativeRendering(false);
	}
	void KO_dog_zhujiemian_dog::on_finish_launching()
	{
		Ogre::Root* _ogre_root = this->c_flake_context->d_ogre_system.get_ogre_root();
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

		this->d_viewport = this->c_surface->d_render_window->addViewport(this->d_camera);
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

		//
		Ogre::ResourceGroupManager* _resource_group_manager = Ogre::ResourceGroupManager::getSingletonPtr();
		_resource_group_manager->addResourceLocation("media/models/dog", "mm_file_system", "media/models/dog");
		_resource_group_manager->initialiseResourceGroup(Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
		_resource_group_manager->initialiseResourceGroup("media/models/dog");
		Ogre::SkeletonManager* _skeleton_manager = Ogre::SkeletonManager::getSingletonPtr();
		//
		this->r_skeleton_resource_ptr = _skeleton_manager->load("dog.SKELETON", "media/models/dog");
		this->r_cube_skeleton = (Ogre::Skeleton*)this->r_skeleton_resource_ptr.get();
		mm_attach_skeleton(this->r_cube_skeleton, "run.SKELETON", "media/models/dog");
		mm_attach_skeleton(this->r_cube_skeleton, "walk.SKELETON", "media/models/dog");
		mm_attach_skeleton(this->r_cube_skeleton, "idle.SKELETON", "media/models/dog");
		//
		this->a_node_horizon = this->d_root_node->createChildSceneNode();
		this->a_node_head = this->a_node_horizon->createChildSceneNode();
		this->a_node_head->setPosition(0, 2, 0);
		this->a_node_head->yaw(Ogre::Radian(Ogre::Degree((Ogre::Real) - 180)));
		this->d_node_camera->setPosition(0, 10, 10);
		this->d_node_camera->pitch(Ogre::Radian(Ogre::Degree((Ogre::Real) - 30)));
		//
		this->d_audio_factory = OGRE_NEW_T(OgreOggSound::OgreOggSoundFactory, Ogre::MEMCATEGORY_GENERAL)();
		_ogre_root->addMovableObjectFactory(this->d_audio_factory, true);
		this->d_audio_manager = OGRE_NEW_T(OgreOggSound::OgreOggSoundManager, Ogre::MEMCATEGORY_GENERAL)();
		this->d_audio_manager->init();
		//
		Ogre::MeshManager* _mesh_manager = Ogre::MeshManager::getSingletonPtr();
		this->r_mesh_resource_ptr = _mesh_manager->load("dog.MESH", "media/models/dog");

		this->am_unit_animation.set_scene_manager(this->d_scene_manager);
		this->am_unit_animation.set_scene_node(this->a_node_horizon);
		this->am_unit_animation.set_resource_group("media/models/dog");
		this->am_unit_animation.set_entity_asset("dog.MESH");
		this->am_unit_animation.entity_produce();
		this->am_unit_animation.add_animation_track("run", "run");
		this->am_unit_animation.add_animation_track("walk", "walk");
		this->am_unit_animation.add_animation_track("idle", "idle");
		this->am_unit_animation.play("idle", true);

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
	void KO_dog_zhujiemian_dog::on_before_terminate()
	{
		struct mm_logger* g_logger = mm_logger_instance();
		mm_flake_context* flake_context = this->c_flake_context;
		Ogre::Root* _ogre_root = flake_context->d_ogre_system.get_ogre_root();
		//////////////////////////////////////////////////////////////////////////
		this->c_surface->d_render_window->removeViewport(this->d_viewport->getZOrder());
		//
		this->d_floor_node->detachObject(this->d_floor_mash);
		this->d_scene_manager->destroyEntity(this->d_floor_mash);
		this->d_scene_manager->destroySceneNode(this->d_floor_node);
		//this->d_unit_animation_n.entity_recycle();
		//this->d_unit_animation_n.clear_animation_track();
		this->d_unit_audio_n.clear_audio_track();
		OGRE_DELETE_T(this->d_audio_manager, OgreOggSoundManager, Ogre::MEMCATEGORY_GENERAL);
		_ogre_root->removeMovableObjectFactory(this->d_audio_factory);
		OGRE_DELETE_T(this->d_audio_factory, OgreOggSoundFactory, Ogre::MEMCATEGORY_GENERAL);
		Ogre::MeshManager* _mesh_manager = Ogre::MeshManager::getSingletonPtr();
		_mesh_manager->unload(this->d_floor_resource_ptr->getName(), Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
		_mesh_manager->remove(this->d_floor_resource_ptr->getName(), Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
		this->d_floor_resource_ptr.reset();
		//
		this->am_unit_animation.entity_recycle();
		this->am_unit_animation.clear_animation_track();
		///////////////////////////////////////////////////////////////////////////////////////
		_mesh_manager->unload(this->r_mesh_resource_ptr->getName(), "media/models/dog");
		_mesh_manager->remove(this->r_mesh_resource_ptr->getName(), "media/models/dog");
		this->r_mesh_resource_ptr.reset();
		///////////////////////////////////////////////////////////////////////////////////////
		Ogre::SkeletonManager* _skeleton_manager = Ogre::SkeletonManager::getSingletonPtr();

		mm_detach_skeleton(this->r_cube_skeleton, "walk");
		mm_detach_skeleton(this->r_cube_skeleton, "run");
		mm_detach_skeleton(this->r_cube_skeleton, "idle");

		_skeleton_manager->unload(this->r_skeleton_resource_ptr->getName(), "media/models/dog");
		_skeleton_manager->remove(this->r_skeleton_resource_ptr->getName(), "media/models/dog");
		this->r_skeleton_resource_ptr.reset();
		this->r_cube_skeleton = NULL;

		this->d_scene_manager->destroySceneNode(this->a_node_horizon);
		Ogre::ResourceGroupManager* _resource_group_manager = Ogre::ResourceGroupManager::getSingletonPtr();
		_resource_group_manager->removeResourceLocation("media/models/dog", "media/models/dog");

		//
		//////////////////////////////////////////////////////////////////////////
		this->d_scene_manager->destroyLight(this->d_dir_light);
		this->d_scene_manager->destroySceneNode(this->d_light_node);
		this->d_scene_manager->destroyCamera(this->d_camera);
		this->d_scene_manager->destroySceneNode(this->d_node_camera);
		//////////////////////////////////////////////////////////////////////////
		Ogre::RTShader::ShaderGenerator::getSingletonPtr()->removeSceneManager(this->d_scene_manager);
		_ogre_root->destroySceneManager(this->d_scene_manager);
		mm_logger_log_I(g_logger, "KO_dog::%s %d success.", __FUNCTION__, __LINE__);

	}
}
