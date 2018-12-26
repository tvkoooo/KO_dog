#ifndef __KO_dog_mailbox_search_h__
#define __KO_dog_mailbox_search_h__

#include "core/mm_core.h"

#include "flake/mm_flake_surface.h"

#include "dish/mm_event.h"

#include "math/mm_vector3.h"




#include "dotsceneloader/DotSceneLoader.h"

#include "math/mm_fix32_linear.h"
#include "container/mm_bitset.h"



//////////////////////////////////////////////////////////////////////////
namespace mm
{


	class KO_dog_mailbox_search
	{
	private:
		mm_flake_context* d_flake_context;
		mm_flake_surface* d_surface;

	private:
		CEGUI::Window* l_home_lj_mailbox_search;
		//
		CEGUI::Window* StaticImage_basic;
		CEGUI::Window* StaticImage_widget;

		CEGUI::Window* StaticText_condition;
		CEGUI::Window* Editbox_condition;
		CEGUI::Window* StaticText_result;
		CEGUI::Window* Listbox_search;
		CEGUI::Window* Button_search;
		CEGUI::Window* Button_add;
		CEGUI::Window* StaticText_user_info;
		////

	private:
		mm_event_handler d_event_search_friend_update_conn;

	public:
		// this member is event drive.
		mm_event_set d_event_set;


	public:
		KO_dog_mailbox_search();
		virtual ~KO_dog_mailbox_search();

	public:
		void set_data(mm_flake_context* d_flake_context, mm_flake_surface* d_surface);
		void set_l_layer(CEGUI::Window* l_layer);
		virtual void on_finish_launching();
		virtual void on_before_terminate();


	private:
		bool on_handle_Button_search(const CEGUI::EventArgs& args);
		bool on_handle_Listbox_search(const CEGUI::EventArgs& args);
		bool on_handle_StaticText_user_info(const CEGUI::EventArgs& args);
		bool on_handle_Button_add(const CEGUI::EventArgs& args);

		bool on_handle_event_search_friend_update(const mm_event_args& args);

	};
}
//////////////////////////////////////////////////////////////////////////


#endif//__KO_dog_mailbox_search_h__