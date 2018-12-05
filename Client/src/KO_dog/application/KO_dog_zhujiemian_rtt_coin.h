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
		//���ݽṹ/////////////////////////////////////////////////////////////////////////////
	public:
		//�������� �� name ��
		std::string n_target;

	public:
		//������� rtt ͼ�㣨 layer ��
		CEGUI::Window* l_rtt;

	public:
		//�������� �� attribute ��
		Ogre::SceneNode* a_rtt_node;
		Ogre::Entity* a_rtt_mesh;


	public:
		//����洢���� ( data )
		float d_rtt_rotation;

		//�ӿڷ���/////////////////////////////////////////////////////////////////////////////
	public:
		KO_dog_zhujiemian_rtt_coin();
		virtual ~KO_dog_zhujiemian_rtt_coin();

	public:
		//����rtt
		void set_rtt_parameter(const std::string& camera_name ,const std::string& target_name);
		virtual void on_finish_launching();
		virtual void on_before_terminate();

	};
}

#endif//__KO_dog_zhujiemian_rtt_coin_h__