#ifndef __KO_dog_interface_manager_h__
#define __KO_dog_interface_manager_h__

#include "core/mm_core.h"

#include "flake/mm_flake_surface.h"

#include "dish/mm_event.h"

#include "math/mm_vector3.h"

#include "OgreSceneNode.h"
#include "OgreCamera.h"
#include "OgreViewport.h"
#include "OgreEntity.h"

#include "dotsceneloader/DotSceneLoader.h"

#include "unit/mm_unit_animation.h"
#include "unit/mm_unit_audio.h"

#include "toolkit/mm_single_view_map.h"

#include "math/mm_fix32_linear.h"
#include "container/mm_bitset.h"

#include "KO_dog_window_ip.h"
#include "KO_dog_zhujiemian.h"
#include "KO_dog_test_animation.h"
#include "KO_dog_mailbox.h"
#include "KO_dog_mailbox_game_playing.h"
//#include "KO_dog_mailbox_search.h"

//////////////////////////////////////////////////////////////////////////
namespace mm
{
	class KO_dog_interface_manager
	{
	private:
		mm_flake_context* d_flake_context;
		mm_flake_surface* d_surface;

	public:
		CEGUI::Window* l_home_lj_interface_manager;  //strongly reference
		CEGUI::Window* l_home_lj_login;                      //strongly reference
		CEGUI::Window* l_layer_dog_window_ip_entry;          //strongly reference
		CEGUI::Window* l_layer_dog_window_ip_lobby;          //strongly reference
		//CEGUI::Window* l_layer_dog_a1;                       //strongly reference
		CEGUI::Window* l_home_lj_mailbox;                    //strongly reference
		CEGUI::Window* l_home_lj_mailbox_game_playing;       //strongly reference

		//CEGUI::Window* l_home_lj_mailbox_search;             //strongly reference

	private:
		CEGUI::Window* DefaultWindow;                        //Get Weak reference
		CEGUI::Window* DefaultWindow_entry;                  //Get Weak reference
		CEGUI::Window* DefaultWindow_lobby;			         //Get Weak reference

	private:
		KO_dog_window_ip window_ip_entry;
		KO_dog_window_ip window_ip_lobby;
		KO_dog_zhujiemian zhujiemian;
		KO_dog_test_animation test_animation;
		KO_dog_mailbox mailbox;
		KO_dog_mailbox_game_playing mailbox_game_playing;
		//KO_dog_mailbox_search mailbox_search;

	private:
		mm_event_handler d_event_closed_conn;
		mm_event_handler d_event_game_conn;
		mm_event_handler d_event_game_quit_conn;
		mm_event_handler d_event_l_zhujiemian_login_conn;
		mm_event_handler d_event_userdata_user_token_update_conn;

	public:
		mm_single_view_map m_single_view;

	public:
		KO_dog_interface_manager();
		virtual ~KO_dog_interface_manager();

	public:
		virtual void assign_flake_context(mm_flake_context* flake_context);
	public:
		virtual void on_finish_launching(mm_flake_surface* surface);
		virtual void on_before_terminate(mm_flake_surface* surface);
	private:
		bool on_handle_closed(const mm_event_args& args);
		bool on_handle_game(const mm_event_args& args);
		bool on_handle_game_quit(const mm_event_args& args);
		bool on_handle_l_zhujiemian_login(const mm_event_args& args);
		bool on_handle_userdata_user_token_update(const mm_event_args& args);

	};
}
//////////////////////////////////////////////////////////////////////////


#endif//__KO_dog_interface_manager_h__