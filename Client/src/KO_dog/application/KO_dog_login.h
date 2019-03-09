#ifndef __KO_dog_login_h__
#define __KO_dog_login_h__

#include "core/mm_core.h"

#include "flake/mm_flake_surface.h"

#include "dish/mm_event.h"
#include "dish/mm_md5.h"

#include "math/mm_vector3.h"


#include "dotsceneloader/DotSceneLoader.h"

#include "unit/mm_unit_animation.h"
#include "unit/mm_unit_audio.h"

#include "math/mm_fix32_linear.h"
#include "container/mm_bitset.h"
#include "KO_dog_test_animation.h"


//////////////////////////////////////////////////////////////////////////
namespace mm
{
	class KO_dog;

	class KO_dog_login
	{
	private:
		mm_flake_context* d_flake_context;
		mm_flake_surface* d_surface;
		//
		KO_dog* p_dog;

	private:
		CEGUI::Window* layer;                              //Weak pointer
		//
		CEGUI::Window* StaticImage;
		CEGUI::Window* Button_login;
		CEGUI::Window* Button_quit;
		CEGUI::Window* Button_register;
		CEGUI::Window* Editbox_id;
		CEGUI::Window* Editbox_password;
		CEGUI::Window* StaticText_git;
		CEGUI::Window* StaticText_id;
		CEGUI::Window* StaticText_notice;
		CEGUI::Window* StaticText_password;
		//

	private:
		mm_event_handler d_event_userdata_update_conn;
		mm_event_handler d_event_log_view_conn;


	private:
		typedef std::map<std::string, std::string> lj_type_map_string_string;
		lj_type_map_string_string user_info;
		struct mm_md5_context md5_context;


	public:
		static const std::string event_login;
	public:
		// this member is event drive.
		mm_event_set d_event_set;


	public:
		KO_dog_login();
		virtual ~KO_dog_login();

	public:
		void set_context_surface_(mm_flake_context* d_flake_context, mm_flake_surface* d_surface);
		void set_layer(CEGUI::Window* layer);
		virtual void on_finish_launching();
		virtual void on_before_terminate();

	private:
		bool on_handle_l_s_button_login(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_out(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_register(const CEGUI::EventArgs& args);

		bool on_handle_MenuWindow_updated(const CEGUI::EventArgs& args);

	private:
		bool on_handle_event_userdata_update(const mm_event_args& args);
		bool on_handle_event_log_view(const mm_event_args& args);
	private:
		bool on_event_enter_background(const mm_event_args& args);
		bool on_event_enter_foreground(const mm_event_args& args);
	};
}
//////////////////////////////////////////////////////////////////////////


#endif//__KO_dog_login_h__