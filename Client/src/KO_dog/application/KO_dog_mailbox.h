#ifndef __KO_dog_mailbox_h__
#define __KO_dog_mailbox_h__

#include <map>
#include "core/mm_core.h"

#include "flake/mm_flake_surface.h"

#include "dish/mm_event.h"

#include "math/mm_vector3.h"

#include "dotsceneloader/DotSceneLoader.h"

#include "CEGUI/widgets/Listbox.h"
#include "CEGUI/widgets/ListboxItem.h"
#include "CEGUI/widgets/ListboxTextItem.h"
#include "toolkit/mm_elem_map.h"

#include "math/mm_fix32_linear.h"
#include "container/mm_bitset.h"

#include "KO_dog_mailbox_search.h"
#include "KO_dog_mailbox_friend_apply.h"
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
		CEGUI::Window* l_home_lj_mailbox_search;             //strongly reference
		CEGUI::Window* l_home_lj_mailbox_friend_apply;             //strongly reference
		//
		CEGUI::Window* StaticImage_basic;
		CEGUI::Window* DefaultWindow_left;
		CEGUI::Window* Button_search;
		CEGUI::Window* StaticImage_Tree_image;
		CEGUI::Window* Tree_friend;
		CEGUI::Window* Button_game;
		CEGUI::Window* StaticText_nt;
		CEGUI::Window* Listbox_nt;
		CEGUI::Window* Button_quit;
		CEGUI::Window* DefaultWindow_right;
		//
	private:
		mm_event_handler d_event_data_add_friend_nt_conn;
		mm_event_handler d_event_data_respond_friend_nt_conn;


	private:
		KO_dog_mailbox_search mailbox_search;
		KO_dog_mailbox_friend_apply mailbox_friend_apply;
	public:
		elem_p_map<mm_uint64_t, CEGUI::ListboxTextItem*> map_apply_friend_wp;
		data_basic_friend_info* p_apply_friend_info;


	public:
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
		bool on_handle_Tree_friend_Select(const CEGUI::EventArgs& args);
		bool on_handle_Tree_friend_Open(const CEGUI::EventArgs& args);
		bool on_handle_Tree_friend_Close(const CEGUI::EventArgs& args);
		bool on_handle_Button_game(const CEGUI::EventArgs& args);
		bool on_handle_Button_quit(const CEGUI::EventArgs& args);
		bool on_handle_Listbox_nt_select(const CEGUI::EventArgs& args);
		//
		bool on_handle_event_data_add_friend_nt(const mm_event_args& args);
		bool on_handle_event_data_respond_friend_nt(const mm_event_args& args);
	};
}
//////////////////////////////////////////////////////////////////////////


#endif//__KO_dog_mailbox_h__