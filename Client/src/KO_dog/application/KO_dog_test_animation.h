#ifndef __KO_dog_test_animation__
#define __KO_dog_test_animation__

#include "core/mm_core.h"

#include "flake/mm_flake_surface.h"

#include "dish/mm_event.h"

#include "math/mm_vector3.h"

#include "OgreSceneNode.h"
#include "OgreCamera.h"
#include "OgreViewport.h"
#include "OgreEntity.h"

#include "dotsceneloader/DotSceneLoader.h"

//#include "unit/DishUnitAnimation.h"
#include "unit/mm_unit_animation.h"
#include "unit/mm_unit_audio.h"


#include "math/mm_fix32_linear.h"
#include "container/mm_bitset.h"

namespace mm
{
	struct zhen_dog_luoji_data
	{
		mm_fix32_vector3 D_weizhi;
		mm_fix32 D_jiaodu;
	};

	class mm_event_animation_close : public mm_event_args
	{
	public:
		explicit mm_event_animation_close(const std::string &ddd)
		{

		}
		std::string ddd;
	};

	class KO_dog_test_animation
	{
	public:
		mm_flake_context* d_flake_context;
		mm_flake_surface* d_surface;

		Ogre::SceneManager* d_scene_manager;
		Ogre::SceneNode* d_root_node;

		Ogre::SceneNode* d_node_camera;
		Ogre::Camera* d_camera;
		Ogre::Viewport* d_viewport;

		Ogre::SceneNode* d_light_node;
		Ogre::Light* d_dir_light;
	public:
		Ogre::SceneNode* d_ogrehead_node_0;
		Ogre::SceneNode* d_ogrehead_node_1;
		Ogre::Entity* d_ogrehead_mesh_0;
		
		Ogre::ResourcePtr d_skeleton_resource_ptr;
		Ogre::Skeleton* d_cube_skeleton;
		//dish::UnitAnimation d_unit_animation;

		Ogre::SceneNode* d_floor_node;
		Ogre::Entity* d_floor_mash;
	public:
		Ogre::MeshPtr d_dog_resource_ptr;
		Ogre::MeshPtr d_floor_resource_ptr;
	public:

		mm_unit_animation d_unit_animation_n;
		mm_unit_audio d_unit_audio_n;

		OgreOggSound::OgreOggSoundFactory* d_audio_factory;
		OgreOggSound::OgreOggSoundManager* d_audio_manager;
	public:
		mm_event_handler d_event_updated_conn;

		mm_event_handler d_event_mouse_moved_conn;
		mm_event_handler d_event_mouse_began_conn;
		mm_event_handler d_event_mouse_ended_conn;

		mm_event_handler d_event_key_pressed_conn;
		mm_event_handler d_event_key_release_conn;

	public:
		struct mm_vector3 d_camera_moved_pos;
		bool d_is_touch_began;

	public:
		struct mm_bitset keyb_s;

		bool dog_running;
		Ogre::SceneNode* now_camra_node;

	public:
		CEGUI::Window* d_window;
		CEGUI::Window* l_layer_dog_a1;
		CEGUI::Window* Label_jiaodu;
		CEGUI::Window* Label_zongchang;
		CEGUI::Window* StaticImage;

	public:
		//double dog_m_x;
		//struct mm_fix32_vector3 d_fix_v3;
		//struct mm_fix32_vector3 d_fix_s3;

	public:
		mm_fix32 dog_v_4;
		//mm_fix32 dog_hudu_4;
		mm_fix32 dog_hudu_4_Dhudu;
		mm_fix32 dog_ds_all;

		zhen_dog_luoji_data dog_ago;
		zhen_dog_luoji_data dog_tag;
		zhen_dog_luoji_data dog_now;
		zhen_dog_luoji_data dog_mid;

	public:
		mm_fix32 d_sync_frequency;
		mm_fix32 d_sync_interval;

	public:
		static const std::string event_close;
	public:
		// this member is event drive.
		mm_event_set d_event_set;
	public:
		KO_dog_test_animation();
		virtual ~KO_dog_test_animation();
	public:
		void assign_flake_context(mm_flake_context* flake_context);
	public:
		virtual void on_finish_launching(mm_flake_surface* surface);
		virtual void on_before_terminate(mm_flake_surface* surface);
	public:
		void on_scene_launching();
		void on_scene_terminate();
		void on_scene_layer_launching();
		void on_scene_layer_terminate();

	public:
		bool on_event_updated(const mm_event_args& args);

		bool on_event_mouse_moved(const mm_event_args& args);
		bool on_event_mouse_began(const mm_event_args& args);
		bool on_event_mouse_ended(const mm_event_args& args);

		bool on_event_key_pressed(const mm_event_args& args);
		bool on_event_key_release(const mm_event_args& args);
		
	public:
		void on_synchronize_launching();
		void on_synchronize_terminate();
		void on_update_synchronize(double interval);

	public:
		bool on_handle_StaticImage(const CEGUI::EventArgs& args);


	};
}

#endif//__KO_dog_test_scene__