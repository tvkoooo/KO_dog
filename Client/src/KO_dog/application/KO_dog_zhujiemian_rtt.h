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
		//���ݽṹ/////////////////////////////////////////////////////////////////////////////
	public:
		//camera ���� �� name ��
		std::string n_camera;
	public:
		//���ݳн������� ( context )
		mm_flake_context* c_flake_context;
		mm_flake_surface* c_surface;

	public:
		//Ogre ��ͼԪ�� 
		//target
		struct mm_windows_target d_windows_target;

		//������
		Ogre::SceneManager* d_scene_manager;
		Ogre::SceneNode* d_root_node;
		//�ӿ�
		Ogre::SceneNode* d_node_camera;
		Ogre::Camera* d_camera;
		Ogre::Viewport* d_viewport;
		//�ƹ�
		Ogre::SceneNode* d_light_node;
		Ogre::Light* d_dir_light;

	//public:
	//	//��������
	//	Ogre::SceneNode* d_rtt_node;
	//	Ogre::Entity* d_rtt_mesh;

	//public:
	//	//������� rtt���
	//	CEGUI::Window* l_rtt;


	//public:
	//	����洢���� data 
	//	float d_rtt_rotation;

		//�ӿڷ���/////////////////////////////////////////////////////////////////////////////
	public:
		KO_dog_zhujiemian_rtt();
		virtual ~KO_dog_zhujiemian_rtt();

	public:
		//����rtt
		void set_flake_context(mm_flake_context* d_flake_context, mm_flake_surface* d_surface);
		virtual void on_finish_launching();
		virtual void on_before_terminate();

	};
}

#endif//__KO_dog_zhujiemian_rtt_h__