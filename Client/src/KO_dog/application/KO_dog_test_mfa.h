#ifndef __KO_dog_test_mfa_h__
#define __KO_dog_test_mfa_h__

#include "core/mm_core.h"
#include <map>
#include "flake/mm_flake_surface.h"

#include "dish/mm_event.h"

#include "CEGUI/widgets/Listbox.h"
#include "CEGUI/widgets/ListboxItem.h"
#include "CEGUI/widgets/ListboxTextItem.h"
#include "toolkit/mm_elem_map.h"

#include "dotsceneloader/DotSceneLoader.h"

#include "container/mm_bitset.h"

#include "model_data/KO_dog_data_user_basic.h"
#include "model_data/KO_dog_data_relation.h"

//////////////////////////////////////////////////////////////////////////
namespace mm
{	
	typedef elem_event_map<mm_uint64_t, data_basic_friend_info> mm_data_basic_friend_info_map_type;
	typedef mm_data_basic_friend_info_map_type::mm_event_map_ags data_basic_friend_info_args;

	// 视图，用于绑定数据层的: data_basic_friend_info
	class mm_bfi_list_item : public CEGUI::ListboxTextItem
	{
	public:
		data_basic_friend_info* d_m;
	public:
		mm_event_handler d_event_update_conn;
	public:
		mm_bfi_list_item();
	public:
		void set_model(data_basic_friend_info* m);
	public:
		bool on_event_update(const mm_event_args& args);
	};

	// 视图，用于绑定数据层的: data.data_user_basic.m_friend_apply
	class mm_bfi
	{
	public:
		typedef std::map<mm_uint64_t, mm_bfi_list_item*> item_map_type;
	public:
		mm_data_basic_friend_info_map_type* d_m;
	public:
		CEGUI::Window* Listbox_nt;
	public:
		mm_event_handler d_event_add_conn;
		mm_event_handler d_event_rmv_conn;
	public:
		item_map_type d_item_map;
	public:
		mm_bfi();
	public:
		void set_layer(CEGUI::Window* l);
	public:
		void set_model(mm_data_basic_friend_info_map_type* m);
	public:
		// 需要注意视图层的清除,以避免视图层产生内存泄漏
		void clear_item();
	public:
		bool on_event_add(const mm_event_args& args);
		bool on_event_rmv(const mm_event_args& args);
	};


	typedef elem_event_map<mm_uint64_t, data_relation_groupInfo> data_relation_group_map_type;
	typedef data_relation_group_map_type::mm_event_map_ags data_relation_group_map_ags;


	// 视图，用于绑定数据层的: data_relation_groupInfo
	class mm_mfa_list_item : public CEGUI::ListboxTextItem
	{
	public:
		data_relation_groupInfo* d_m;
	public:
		mm_event_handler d_event_update_conn;
	public:
		mm_mfa_list_item();
	public:
		void set_model(data_relation_groupInfo* m);
	public:
		bool on_event_update(const mm_event_args& args);
	};

	// 视图，用于绑定数据层的: data.data_relation.groupId_groupName_map
	class mm_mfa
	{
	private:
		mm_flake_context* d_flake_context;
		mm_flake_surface* d_surface;
	private:
		CEGUI::Window* l_home_lj_mailbox_friend_apply;
		//
		CEGUI::Window* StaticText_apply_info;
		CEGUI::Window* StaticText_user_info;
		CEGUI::Window* StaticText_friend;
		CEGUI::Window* Button_set;
		CEGUI::Window* StaticText_remark;
		CEGUI::Window* Editbox_remark;
		CEGUI::Window* StaticText_group;
		CEGUI::Window* Combobox;
		CEGUI::Window* StaticText_opcode;
		CEGUI::Window* Button_agree;
		CEGUI::Window* Button_refuse;
		////
	public:
		typedef std::map<mm_uint64_t, mm_mfa_list_item*> item_map_type;
	public:
		data_relation_group_map_type* d_m;
	public:
		mm_event_handler d_event_add_conn;
		mm_event_handler d_event_rmv_conn;
	public:
		item_map_type d_item_map;
	public:
		void set_model(data_relation_group_map_type* m);
	public:
		// 需要注意视图层的清除,以避免视图层产生内存泄漏
		void clear_item();
	public:
		bool on_event_add(const mm_event_args& args);
		bool on_event_rmv(const mm_event_args& args);
	public:
		//Combobox_data cbbo_data;
		//elem_p_map<mm_uint64_t, CEGUI::ListboxTextItem*> map_group_wp;
		mm::data_relation_groupInfo* p_groupId_chose;
		mm::data_basic_friend_info* p_friend_apply;
	private:
		mm_event_handler d_event_data_relation_add_friend_group_conn;
		mm_event_handler d_event_data_relation_rmv_friend_group_conn;
		mm_event_handler d_event_groupId_groupName_map_set_model_conn;
	public:
		mm_mfa();
		virtual ~mm_mfa();
	public:// set
		void set_data(mm_flake_context* d_flake_context, mm_flake_surface* d_surface);
		void set_l_layer(CEGUI::Window* l_layer);
		virtual void on_finish_launching();
		virtual void on_before_terminate();

	public:// I/O
		void setVisible(bool b);
		void setVisible_opcode(bool b);
		void setVisible_friend(bool b);

	private:
		bool on_handle_StaticText_user_info(const CEGUI::EventArgs& args);
		bool on_handle_Button_agree(const CEGUI::EventArgs& args);
		bool on_handle_Button_refuse(const CEGUI::EventArgs& args);
		bool on_handle_Button_set(const CEGUI::EventArgs& args);
		bool on_handle_Combobox_select(const CEGUI::EventArgs& args);

		bool on_handle_event_data_relation_add_friend_group(const mm_event_args& args);
		bool on_handle_event_data_relation_rmv_friend_group(const mm_event_args& args);
		bool on_handle_event_groupId_groupName_map_set_model(const mm_event_args& args);

	};
}
//////////////////////////////////////////////////////////////////////////


#endif//__KO_dog_test_mfa_h__