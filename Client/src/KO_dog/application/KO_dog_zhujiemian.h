#ifndef __KO_dog_zhujiemian_h__
#define __KO_dog_zhujiemian_h__

#include "core/mm_core.h"

#include "flake/mm_flake_surface.h"

#include "dish/mm_event.h"
#include "dish/mm_md5.h"

#include "math/mm_vector3.h"

//#include "OgreSceneNode.h"
//#include "OgreCamera.h"
//#include "OgreViewport.h"
//#include "OgreEntity.h"

#include "dotsceneloader/DotSceneLoader.h"

//#include "unit/DishUnitAnimation.h"
#include "unit/mm_unit_animation.h"
#include "unit/mm_unit_audio.h"

#include "math/mm_fix32_linear.h"
#include "container/mm_bitset.h"
#include "KO_dog_test_animation.h"

//#include "toolkit/mm_windows_target.h"
#include "KO_dog_zhujiemian_rtt_coin.h"

//////////////////////////////////////////////////////////////////////////
namespace mm
{
	class KO_dog_zhujiemian
	{
	private:
		mm_flake_context* d_flake_context;
		mm_flake_surface* d_surface;

	private:
		CEGUI::Window* l_home_lj_login;
		//
		CEGUI::Window* MenuWindow;
		CEGUI::Window* l_edit_text_id;
		CEGUI::Window* l_s_button_login;
		CEGUI::Window* l_s_button_out;
		CEGUI::Window* l_edit_text_pwd;
		CEGUI::Window* l_s_button_register;
		CEGUI::Window* l_text_id;
		CEGUI::Window* l_text_pwd;
		CEGUI::Window* l_text_notice;
		CEGUI::Window* StaticImage;
		CEGUI::Window* l_image_gold1;
		CEGUI::Window* l_image_gold2;
		CEGUI::Window* l_image_gold3;
		CEGUI::Window* l_image_gold4;
		CEGUI::Window* l_image_gold5;
		CEGUI::Window* l_image_gold_y1;
		CEGUI::Window* l_image_gold_y2;
		//


		//CEGUI::Window* l_image_gold_mov;

	private:
	//	struct mm_windows_target d_windows_target;
	//	mm_event_handler d_event_enter_background;
	//	mm_event_handler d_event_enter_foreground;

	//	Ogre::SceneManager* d_scene_manager;
	//	Ogre::SceneNode* d_root_node;

	//	Ogre::SceneNode* d_node_camera;
	//	Ogre::Camera* d_camera;
	//	Ogre::Viewport* d_viewport;

	//	Ogre::SceneNode* d_light_node;
	//	Ogre::Light* d_dir_light;
	//	//
	//	Ogre::SceneNode* d_coin_node;
	//	Ogre::Entity* d_coin_mesh;
	//	float d_coin_rotation;

	private:
		KO_dog_zhujiemian_rtt_coin rtt_coin;

	private:
		int image_gold_gif_n;
		float d_rotation;

	private:
		//mm_event_handler d_event_l_animation_closed_conn;
		mm_event_handler d_event_userdata_update_conn;
		mm_event_handler d_event_log_view_conn;


	private:
		typedef std::map<std::string, std::string> lj_type_map_string_string;
		lj_type_map_string_string user_info;
		struct mm_md5_context md5_context;

	private:
		//KO_dog_test_animation test_animation;

	private:
		//mm_event_handler d_event_updated_conn;

		//mm_event_handler d_event_mouse_moved_conn;
		//mm_event_handler d_event_mouse_began_conn;
		//mm_event_handler d_event_mouse_ended_conn;

		//mm_event_handler d_event_key_pressed_conn;
		//mm_event_handler d_event_key_release_conn;

	public:
		static const std::string event_login;
	public:
		// this member is event drive.
		mm_event_set d_event_set;


	public:
		KO_dog_zhujiemian();
		virtual ~KO_dog_zhujiemian();

	public:
		void set_data(mm_flake_context* d_flake_context, mm_flake_surface* d_surface);
		void set_l_layer(CEGUI::Window* l_layer);
		virtual void on_finish_launching();
		virtual void on_before_terminate();

	private:
		void scene_layer_launching();
		void scene_layer_terminate();

	private:
		bool on_handle_l_s_button_login(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_out(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_register(const CEGUI::EventArgs& args);

		bool on_handle_MenuWindow_updated(const CEGUI::EventArgs& args);

	private:
		//bool on_handle_l_animation_closed(const mm_event_args& args);
		bool on_handle_event_userdata_update(const mm_event_args& args);
		bool on_handle_event_log_view(const mm_event_args& args);
	private:
		bool on_event_enter_background(const mm_event_args& args);
		bool on_event_enter_foreground(const mm_event_args& args);
	};
}
//////////////////////////////////////////////////////////////////////////


#endif//__KO_dog_zhujiemian_h__