#ifndef __KO_dog_mailbox_game_playing__
#define __KO_dog_mailbox_game_playing__

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

#include "emu/mm_emu_machine.h"

#include "math/mm_fix32_linear.h"
#include "container/mm_bitset.h"
#include "toolkit/mm_rocker_key.h"

namespace mm
{


	class KO_dog_mailbox_game_playing
	{
	public:
		mm_flake_context* d_flake_context;
		mm_flake_surface* d_surface;

		
	public:
		mm_event_handler d_event_updated_conn;

		mm_event_handler d_event_mouse_moved_conn;
		mm_event_handler d_event_mouse_began_conn;
		mm_event_handler d_event_mouse_ended_conn;

		mm_event_handler d_event_key_pressed_conn;
		mm_event_handler d_event_key_release_conn;
	public:
		CEGUI::Event::Connection StaticImage_table_EventUpdated;

	public:
		CEGUI::Window* l_layer;
		CEGUI::Window* StaticImage_basic;
		CEGUI::Window* Button_A;
		CEGUI::Window* Button_B;
		CEGUI::Window* Button_C;
		CEGUI::Window* Button_D;
		CEGUI::Window* Button_select;
		CEGUI::Window* Button_start;
		CEGUI::Window* Button_quit;
		CEGUI::Window* StaticImage_yaogan;
		CEGUI::Window* DefaultWindow_mid;
		CEGUI::Window* StaticImage_table;
		CEGUI::Window* StaticText_test;
		CEGUI::Window* StaticImage_AB;
		CEGUI::Window* StaticImage_CD;
		CEGUI::Window* Button_AB;
		CEGUI::Window* Button_CD;

	public:
		struct mm_bitset keyb_s;
		mm_rocker_key rocker_key;

	public:
		bool d_is_anchor_touch_began;
		struct mm_vector2 d_anchor_center;
		double d_rotation;

	public:
		struct mm_emu_machine d_emu_machine;
		std::string d_data_path_prefix;


	public:
		static const std::string event_close;
	public:
		// this member is event drive.
		mm_event_set d_event_set;
	public:
		KO_dog_mailbox_game_playing();
		virtual ~KO_dog_mailbox_game_playing();
	public:
		void set_data(mm_flake_context* flake_context , mm_flake_surface* surface);
		void set_l_layer(CEGUI::Window* l_layer);
		void setVisible(bool b);
		void start_games();
		void stop_games();
	public:
		virtual void on_finish_launching();
		virtual void on_before_terminate();

	public:
		
		bool on_event_updated(const mm_event_args& args);

		bool on_event_mouse_moved(const mm_event_args& args);
		bool on_event_mouse_began(const mm_event_args& args);
		bool on_event_mouse_ended(const mm_event_args& args);

		bool on_event_key_pressed(const mm_event_args& args);
		bool on_event_key_release(const mm_event_args& args);
		

	public:
		bool on_handle_StaticImage(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_out(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_A_UP(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_B_UP(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_C_UP(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_D_UP(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_select_UP(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_start_UP(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_A_DOWN(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_B_DOWN(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_C_DOWN(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_D_DOWN(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_select_DOWN(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_start_DOWN(const CEGUI::EventArgs& args);
		bool on_handle_l_s_button_camera(const CEGUI::EventArgs& args);
		bool on_StaticImage_table_EventUpdated(const CEGUI::EventArgs& args);

	public:
		void update_anchor_quaternion(double abs_x, double abs_y);

	};
}

#endif//__KO_dog_mailbox_game_playing__