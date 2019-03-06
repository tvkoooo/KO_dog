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

#include "CEGUI/widgets/Tree.h"
#include "toolkit/mm_elem_map.h"
#include "toolkit/mm_single_view_map.h"

#include "math/mm_fix32_linear.h"
#include "container/mm_bitset.h"

#include "KO_dog_mailbox_search.h"
#include "KO_dog_mailbox_friend_apply.h"
#include "KO_dog_mailbox_friend_talk.h"

//#include "KO_dog_test_mfa.h"
//////////////////////////////////////////////////////////////////////////
namespace mm
{
	class KO_dog_mailbox
	{
	public:
		class data_group
		{
		public:
			CEGUI::TreeItem* p_TextItem;
			mm_event_handler d_event_group_update;
			mm_event_handler d_event_group_update_name;
		public:
			data_group()
				: p_TextItem(NULL)
			{

			}
		};
		class data_friend
		{
		public:
			CEGUI::TreeItem* p_TextItem;
			mm_uint64_t group_id;
			mm_event_handler d_event_friend_update;
			mm_event_handler d_event_friend_update_remark;
			mm_event_handler d_event_friend_update_group;
		public:
			data_friend()
				: p_TextItem(NULL)
				, group_id(0)
			{

			}
		};


	private:
		mm_flake_context* d_flake_context;
		mm_flake_surface* d_surface;

	public:
		CEGUI::Window* l_home_lj_mailbox;					 //afferent reference
		//
		CEGUI::Window* l_home_lj_mailbox_search;             //strongly reference
		CEGUI::Window* l_home_lj_mailbox_friend_apply;       //strongly reference
		CEGUI::Window* l_home_lj_mailbox_friend;             //strongly reference
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
		mm_event_handler d_event_data_rmv_friend_nt_conn;
		mm_event_handler d_event_data_update_friend_nt_conn;
		//mm_event_handler d_event_data_update_description_friend_nt_conn;
		//组1
		mm_event_handler d_event_data_relation_add_friend_group_conn;
		mm_event_handler d_event_data_relation_rmv_friend_group_conn;
		//好友2
		mm_event_handler d_event_data_relation_add_friend_conn;
		mm_event_handler d_event_data_relation_rmv_friend_conn;

	private:
		KO_dog_mailbox_search mailbox_search;
		KO_dog_mailbox_friend_apply mailbox_friend_apply;
		KO_dog_mailbox_friend_talk mailbox_friend_talk;
		//
//		mm_mfa d_mfa;// 好友操作, 测试元素行和元素表的, 数据模组与视图绑定
//		mm_bfi d_bfi;// 谁来申请好友,测试元素行和元素表的, 数据模组与视图绑定

	public:
		// model_data 数据 KO_dog_data_relation 类(class)的弱引用
		mm::data_relation_friendId_friendInfo_map* p_friendId_friendInfo_map;
		mm::KO_dog_data_relation::data_relation_groupId_groupName_map* p_groupId_groupName_map;

	public:
		//选择操作的好友列表（好友）
		mm::data_relation_friendInfo* p_friend_friend;
		//选择操作的好友列表（好友分组）
		mm::data_relation_groupInfo* p_friend_group;
	public:
		//好友申请0 通知 apply_friend
		elem_p_map<mm_uint64_t, CEGUI::ListboxTextItem*> map_apply_friend_wp;
		elem_p_map<mm_uint64_t, mm_event_handler> map_apply_friend_event_handle;
		data_basic_friend_info* p_apply_friend_info;
		mm::elem_event_map<mm_uint64_t, data_basic_friend_info>* p_md;

		//组1 和 好友2
		elem_map<mm_uint64_t, data_group> map_groupId_data;
		elem_map<mm_uint64_t, data_friend> map_friendId_data;
	public:
		static const std::string event_game;
		static const std::string event_quit;
	public:
		// this member is event drive.
		mm_event_set d_event_set;

	public:
		mm_single_view_map m_single_view;

	public:
		KO_dog_mailbox();
		virtual ~KO_dog_mailbox();

	public:
		void set_data(mm_flake_context* d_flake_context, mm_flake_surface* d_surface);
		void set_l_layer(CEGUI::Window* l_layer);
		void set_friend_apply_model(mm::elem_event_map<mm_uint64_t, data_basic_friend_info>* md);
		//
		void clear_data_before_terminate();
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
		bool on_handle_event_data_rmv_friend_nt(const mm_event_args& args);
		bool on_handle_event_data_update_friend_nt(const mm_event_args& args);
		//bool on_handle_event_data_update_description_friend_nt(const mm_event_args& args);
		//组1 
		bool on_handle_event_data_relation_add_friend_group(const mm_event_args& args);
		bool on_handle_event_data_relation_rmv_friend_group(const mm_event_args& args);
		bool on_handle_event_data_friend_group_update(const mm_event_args& args);
		bool on_handle_event_data_friend_group_update_name(const mm_event_args& args);
		//好友2 
		bool on_handle_event_data_relation_add_friend(const mm_event_args& args);
		bool on_handle_event_data_relation_rmv_friend(const mm_event_args& args);
		bool on_handle_event_data_friend_update(const mm_event_args& args);
		bool on_handle_event_data_friend_update_remark(const mm_event_args& args);
		bool on_handle_event_data_friend_update_group(const mm_event_args& args);

	};
}
//////////////////////////////////////////////////////////////////////////


#endif//__KO_dog_mailbox_h__