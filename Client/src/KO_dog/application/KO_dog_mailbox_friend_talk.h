#ifndef __KO_dog_mailbox_friend_talk_h__
#define __KO_dog_mailbox_friend_talk_h__

#include "core/mm_core.h"
#include <map>
#include "flake/mm_flake_surface.h"

#include "dish/mm_event.h"

//#include "math/mm_vector3.h"

#include "CEGUI/widgets/Listbox.h"
#include "CEGUI/widgets/ListboxItem.h"
#include "CEGUI/widgets/ListboxTextItem.h"
#include "toolkit/mm_elem_map.h"

#include "dotsceneloader/DotSceneLoader.h"

//#include "math/mm_fix32_linear.h"
#include "container/mm_bitset.h"

#include "model_data/KO_dog_data_user_basic.h"
#include "model_data/KO_dog_data_relation.h"
#include "widgets/KO_dog_combobox_group.h"
//////////////////////////////////////////////////////////////////////////
namespace mm
{	

	class KO_dog_mailbox_friend_talk
	{
	//public:
	//	class data_friend_apply_talk
	//	{
	//	public:
	//		CEGUI::ListboxTextItem* p_ListboxTextItem;
	//		mm_event_handler d_event_group_update;
	//		mm_event_handler d_event_group_update_name;
	//	public:
	//		data_friend_apply_talk()
	//			:p_ListboxTextItem(NULL)
	//		{

	//		}
	//	};
		//
	private:
		mm_flake_context* d_flake_context;
		mm_flake_surface* d_surface;

	private:
		CEGUI::Window* l_home_lj_mailbox_friend;
		//

		CEGUI::Window* StaticText_opcode;
		CEGUI::Window* StaticText_change_group;
		CEGUI::Window* Combobox;
		CEGUI::Window* StaticText_change_remark;
		CEGUI::Window* Button_set;
		CEGUI::Window* Editbox_remark;
		CEGUI::Window* StaticText_delete_group;
		CEGUI::Window* Button_delete;
		CEGUI::Window* StaticText_window;
		CEGUI::Window* StaticText_talk;
		CEGUI::Window* StaticText_write;
		CEGUI::Window* Editbox_write;
		CEGUI::Window* Button_send;
		////

	public:
		// model_data 数据 KO_dog_data_relation 类(class)的弱引用
		mm::KO_dog_data_relation::data_relation_groupId_groupName_map* p_groupId_groupName_map;
		// 创建 KO_dog_mailbox_friend_talk 视图自己对 KO_dog_data_relation 的 groupId_groupName_map 数据结构
		KO_dog_combobox_group combobox_group;

	public:		
		//Combobox_data cbbo_data;
		//elem_p_map<mm_uint64_t, CEGUI::ListboxTextItem*> map_group_wp;
		//elem_map<mm_uint64_t, data_friend_apply_talk> map_groupId_data;
		//mm::data_relation_groupInfo* p_groupId_chose;
		mm::data_relation_friendInfo* p_friend_talk;

	private:
		mm_event_handler d_event_data_relation_add_friend_group_conn;
		mm_event_handler d_event_data_relation_rmv_friend_group_conn;
		mm_event_handler d_event_groupId_groupName_map_set_model_conn;

	public:
		// this member is event drive.
		//mm_event_set d_event_set;


	public:
		KO_dog_mailbox_friend_talk();
		virtual ~KO_dog_mailbox_friend_talk();

	public:// set
		void set_context(mm_flake_context* d_flake_context, mm_flake_surface* d_surface);
		void set_layer(CEGUI::Window* l_layer);
		void unbinding_model_data();
		void binding_model_data(mm::KO_dog_data_relation::data_relation_groupId_groupName_map* p_groupId_groupName_map);

		void set_data_friend_talk(mm::data_relation_friendInfo* p_friend_talk);
		//
		//
		virtual void on_finish_launching();
		virtual void on_before_terminate();

	public:// I/O
		void setVisible(bool b);

	private:
		bool on_handle_StaticText_user_info(const CEGUI::EventArgs& args);
		bool on_handle_Button_agree(const CEGUI::EventArgs& args);
		bool on_handle_Button_delete(const CEGUI::EventArgs& args);
		bool on_handle_Button_set(const CEGUI::EventArgs& args);
		//bool on_handle_Combobox_select(const CEGUI::EventArgs& args);

		//bool on_handle_event_data_relation_add_friend_group(const mm_event_args& args);
		//bool on_handle_event_data_relation_rmv_friend_group(const mm_event_args& args);
		//bool on_handle_event_data_friend_group_update(const mm_event_args& args);
		//bool on_handle_event_data_friend_group_update_name(const mm_event_args& args);

		//bool on_handle_event_groupId_groupName_map_set_model(const mm_event_args& args);

	};
}
//////////////////////////////////////////////////////////////////////////


#endif//__KO_dog_mailbox_friend_talk_h__