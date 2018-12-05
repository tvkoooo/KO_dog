#include "KO_dog_zhujiemian_rtt_coin.h"

namespace mm
{
	KO_dog_zhujiemian_rtt_coin::KO_dog_zhujiemian_rtt_coin()
		: n_target("")
		, l_rtt(NULL)
		, a_rtt_node(NULL)
		, a_rtt_mesh(NULL)

		, d_rtt_rotation(0)
	{

	}

	KO_dog_zhujiemian_rtt_coin::~KO_dog_zhujiemian_rtt_coin()
	{

	}
	void KO_dog_zhujiemian_rtt_coin::set_rtt_parameter(const std::string& n_camera, const std::string& n_target)
	{
		this->n_camera = n_camera;
		this->n_target = n_target;
	}
	void KO_dog_zhujiemian_rtt_coin::on_finish_launching()
	{
		//(1)//set_windows_target/////////////////////////////////////////////////////////////////
		this->l_rtt->setVisible(true);
		this->d_windows_target.d_name = this->n_target;
		this->d_windows_target.d_image_window = this->l_rtt;
		this->d_windows_target.d_cegui_system = &this->c_flake_context->d_cegui_system;
		mm_windows_target_launching(&this->d_windows_target);
		//(2)//basic rtt finish_launching ////////////////////////////////////////////////////////////
		KO_dog_zhujiemian_rtt::on_finish_launching();
		//(3)//load coin resources ////////////////////////////////////////////////////////////
		Ogre::ResourceGroupManager* _resource_group_manager = Ogre::ResourceGroupManager::getSingletonPtr();
		_resource_group_manager->addResourceLocation("media/models/coin", "mm_file_system", "media/models/coin");
		_resource_group_manager->initialiseResourceGroup(Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
		_resource_group_manager->initialiseResourceGroup("media/models/coin");
		this->a_rtt_mesh = this->d_scene_manager->createEntity("coin", "coin.mesh", "media/models/coin");
		this->a_rtt_node = this->d_root_node->createChildSceneNode();
		this->a_rtt_node->attachObject(this->a_rtt_mesh);
		//(4)//set rtt default parameter ////////////////////////////////////////////////////////////
		this->d_node_camera->setPosition(Ogre::Vector3(0, 4, 0));
		this->d_node_camera->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);
		Ogre::ColourValue _viewport_colour(0, 0, 0, 0);
		this->d_viewport->setBackgroundColour(_viewport_colour);
		this->d_viewport->setClearEveryFrame(true);
	}
	void KO_dog_zhujiemian_rtt_coin::on_before_terminate()
	{
		Ogre::Root* _ogre_root = this->c_flake_context->d_ogre_system.get_ogre_root();
		////////////////////////////////////////////////////////////////////////
		this->a_rtt_node->detachObject(this->a_rtt_mesh);
		this->d_scene_manager->destroySceneNode(this->a_rtt_node);
		this->d_scene_manager->destroyEntity(this->a_rtt_mesh);

		Ogre::ResourceGroupManager* _resource_group_manager = Ogre::ResourceGroupManager::getSingletonPtr();
		_resource_group_manager->removeResourceLocation("media/models/coin", "media/models/coin");
		//basic rtt before_terminate //////////////////////////////////////////////////////////////////////
		KO_dog_zhujiemian_rtt::on_before_terminate();
	}

}
