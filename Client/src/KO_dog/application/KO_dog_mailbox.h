#ifndef __KO_dog_mailbox_h__
#define __KO_dog_mailbox_h__

#include "core/mm_core.h"

#include "flake/mm_flake_surface.h"

#include "dish/mm_event.h"

#include "math/mm_vector3.h"

#include "dotsceneloader/DotSceneLoader.h"

#include "math/mm_fix32_linear.h"
#include "container/mm_bitset.h"

#include "KO_dog_test_animation.h"
#include "KO_dog_mailbox_search.h"
//////////////////////////////////////////////////////////////////////////
namespace mm
{
	class KO_dog_mailbox
	{
	private:
		mm_flake_context* d_flake_context;
		mm_flake_surface* d_surface;

	public:
		CEGUI::Window* l_home_lj_mailbox;					 //afferent reference
		//
		//CEGUI::Window* l_layer_dog_a1;                       //strongly reference
		CEGUI::Window* l_home_lj_mailbox_search;             //strongly reference
		//
		CEGUI::Window* StaticImage_basic;
		CEGUI::Window* DefaultWindow_left;
		CEGUI::Window* Button_search;
		CEGUI::Window* Listbox_friend;
		CEGUI::Window* Button_game;
		CEGUI::Window* Listbox_group;
		CEGUI::Window* Button_quit;
		CEGUI::Window* DefaultWindow_right;
		//

	private:
		//KO_dog_test_animation test_animation;
		KO_dog_mailbox_search mailbox_search;
		//mm_event_handler 
		//mm_event_handler d_event_userdata_update_conn;
		//mm_event_handler d_event_log_view_conn;

	public:
		//static const std::string event_search;
		static const std::string event_game;
		static const std::string event_quit;
	public:
		// this member is event drive.
		mm_event_set d_event_set;


	public:
		KO_dog_mailbox();
		virtual ~KO_dog_mailbox();

	public:
		void set_data(mm_flake_context* d_flake_context, mm_flake_surface* d_surface);
		void set_l_layer(CEGUI::Window* l_layer);
		virtual void on_finish_launching();
		virtual void on_before_terminate();


	private:
		bool on_handle_Button_search(const CEGUI::EventArgs& args);
		bool on_handle_Listbox_friend(const CEGUI::EventArgs& args);
		bool on_handle_Button_game(const CEGUI::EventArgs& args);
		bool on_handle_Button_quit(const CEGUI::EventArgs& args);

	};
}
//////////////////////////////////////////////////////////////////////////


#endif//__KO_dog_mailbox_h__