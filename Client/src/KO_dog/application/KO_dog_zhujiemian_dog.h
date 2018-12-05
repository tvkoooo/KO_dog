#ifndef __KO_dog_zhujiemian_dog_h__
#define __KO_dog_zhujiemian_dog_h__
#include "KO_dog_zhujiemian_rtt.h"

#include "flake/mm_flake_surface.h"
#include "toolkit/mm_windows_target.h"

#include "OgreSceneNode.h"
#include "OgreCamera.h"
#include "OgreViewport.h"
#include "OgreEntity.h"

#include "math/mm_fix32_linear.h"
#include "unit/mm_unit_animation.h"
#include "unit/mm_unit_audio.h"

namespace mm
{
	struct fix32_node_vector4_data
	{
		mm_fix32_vector3 weizhi;
		mm_fix32 jiaodu;
	};

	class KO_dog_zhujiemian_dog_data
	{
	public:
		//����ռ�λ��
		struct fix32_node_vector4_data d_vector4;
		//��������������ڵ�
		Ogre::SceneNode* obj_node_camera;//Dog horizon node

	public:
		KO_dog_zhujiemian_dog_data();
		~KO_dog_zhujiemian_dog_data();
	};

	class KO_dog_zhujiemian_dog 
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



	public:
		//�������ԣ� attribute ��
		Ogre::SceneNode* a_node_horizon;//Dog horizon node
		Ogre::SceneNode* a_node_head;   //Dog head node
		Ogre::Entity* a_mesh;

	public:
		//��Դ�� �� resource ��
		Ogre::ResourcePtr r_skeleton_resource_ptr;
		Ogre::Skeleton* r_cube_skeleton;
		Ogre::MeshPtr r_mesh_resource_ptr;		


	public:
		//���� �� animation �� 
		mm_unit_animation am_unit_animation;

	public:
		//dog �洢���� ( data )
		KO_dog_zhujiemian_dog_data dog_ago;
		KO_dog_zhujiemian_dog_data dog_tag;
		KO_dog_zhujiemian_dog_data dog_now;
		KO_dog_zhujiemian_dog_data dog_mid;

		//������ͷλ��
		Ogre::SceneNode* now_camra_node;

		//audio
		mm_unit_audio d_unit_audio_n;
		OgreOggSound::OgreOggSoundFactory* d_audio_factory;
		OgreOggSound::OgreOggSoundManager* d_audio_manager;

	public:
		//floor
		Ogre::SceneNode* d_floor_node;
		Ogre::Entity* d_floor_mash;
		Ogre::MeshPtr d_floor_resource_ptr;



		//�ӿڷ���/////////////////////////////////////////////////////////////////////////////
	public:
		KO_dog_zhujiemian_dog();
		virtual ~KO_dog_zhujiemian_dog();

	public:
		//����rtt
		void set_flake_context(mm_flake_context* d_flake_context, mm_flake_surface* d_surface);
		void on_finish_launching();
		void on_before_terminate();

	};
}

#endif//__KO_dog_zhujiemian_dog_h__