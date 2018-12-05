#ifndef __KO_dog_zhujiemian_rtt_coin_h__
#define __KO_dog_zhujiemian_rtt_coin_h__
#include "KO_dog_zhujiemian_rtt.h"

#include "flake/mm_flake_surface.h"
#include "toolkit/mm_windows_target.h"

#include "OgreSceneNode.h"
#include "OgreCamera.h"
#include "OgreViewport.h"
#include "OgreEntity.h"

namespace mm
{
	class KO_dog_zhujiemian_rtt_coin :public KO_dog_zhujiemian_rtt
	{
		//数据结构/////////////////////////////////////////////////////////////////////////////
	public:
		//对象名字 （ name ）
		std::string n_target;

	public:
		//对象界面 rtt 图层（ layer ）
		CEGUI::Window* l_rtt;

	public:
		//对象属性 （ attribute ）
		Ogre::SceneNode* a_rtt_node;
		Ogre::Entity* a_rtt_mesh;


	public:
		//对象存储数据 ( data )
		float d_rtt_rotation;

		//接口方法/////////////////////////////////////////////////////////////////////////////
	public:
		KO_dog_zhujiemian_rtt_coin();
		virtual ~KO_dog_zhujiemian_rtt_coin();

	public:
		//配置rtt
		void set_rtt_parameter(const std::string& camera_name ,const std::string& target_name);
		virtual void on_finish_launching();
		virtual void on_before_terminate();

	};
}

#endif//__KO_dog_zhujiemian_rtt_coin_h__