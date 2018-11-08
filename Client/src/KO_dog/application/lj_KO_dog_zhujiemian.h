#ifndef __lj_KO_dog_zhujiemian_h__
#define __lj_KO_dog_zhujiemian_h__

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
#include "KO_dog_test_animation.h"



//////////////////////////////////////////////////////////////////////////
namespace mm
{
	class lj_KO_dog_zhujiemian
	{
	public:
		mm_flake_context* d_flake_context;
		mm_flake_surface* d_surface;

	public:
		CEGUI::Window* d_window_login;
		CEGUI::Window* l_home_lj_login;
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

	public:
		mm_event_handler d_event_l_animation_closed_conn;

	public:
		typedef std::map<std::string, std::string> lj_type_map_string_string;
		lj_type_map_string_string user_info;

	public:
		KO_dog_test_animation test_animation;

	public:
		mm_event_handler d_event_updated_conn;

		mm_event_handler d_event_mouse_moved_conn;
		mm_event_handler d_event_mouse_began_conn;
		mm_event_handler d_event_mouse_ended_conn;

		mm_event_handler d_event_key_pressed_conn;
		mm_event_handler d_event_key_release_conn;

	public:
		lj_KO_dog_zhujiemian();
		virtual ~lj_KO_dog_zhujiemian();

	public:
		void set_data(mm_flake_context* d_flake_context, mm_flake_surface* d_surface);
		virtual void on_finish_launching();
		virtual void on_before_terminate();

	public:
		void scene_layer_launching();
		void scene_layer_terminate();

	public:
		bool on_handle_l_s_button_login(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_out(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_register(const CEGUI::EventArgs& args);

	public:		
		bool on_handle_l_animation_closed(const mm_event_args& args);


	};
}
//////////////////////////////////////////////////////////////////////////


#endif//__lj_KO_dog_zhujiemian_h__