#ifndef __KO_dog_zhujiemian_rtt_h__
#define __KO_dog_zhujiemian_rtt_h__


#include "flake/mm_flake_surface.h"
#include "toolkit/mm_windows_target.h"

#include "OgreSceneNode.h"
#include "OgreCamera.h"
#include "OgreViewport.h"
#include "OgreEntity.h"

namespace mm
{
	class KO_dog_zhujiemian_rtt
	{
		//数据结构/////////////////////////////////////////////////////////////////////////////
	public:
		//camera 名字 （ name ）
		std::string n_camera;
	public:
		//数据承接上下文 ( context )
		mm_flake_context* c_flake_context;
		mm_flake_surface* c_surface;

	public:
		//Ogre 视图元素 
		//target
		struct mm_windows_target d_windows_target;

		//主控器
		Ogre::SceneManager* d_scene_manager;
		Ogre::SceneNode* d_root_node;
		//视口
		Ogre::SceneNode* d_node_camera;
		Ogre::Camera* d_camera;
		Ogre::Viewport* d_viewport;
		//灯光
		Ogre::SceneNode* d_light_node;
		Ogre::Light* d_dir_light;

	//public:
	//	//对象属性
	//	Ogre::SceneNode* d_rtt_node;
	//	Ogre::Entity* d_rtt_mesh;

	//public:
	//	//对象界面 rtt句柄
	//	CEGUI::Window* l_rtt;


	//public:
	//	对象存储数据 data 
	//	float d_rtt_rotation;

		//接口方法/////////////////////////////////////////////////////////////////////////////
	public:
		KO_dog_zhujiemian_rtt();
		virtual ~KO_dog_zhujiemian_rtt();

	public:
		//配置rtt
		void set_flake_context(mm_flake_context* d_flake_context, mm_flake_surface* d_surface);
		virtual void on_finish_launching();
		virtual void on_before_terminate();

	};
}

#endif//__KO_dog_zhujiemian_rtt_h__