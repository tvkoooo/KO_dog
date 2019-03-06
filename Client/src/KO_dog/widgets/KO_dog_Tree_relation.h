//#ifndef __KO_dog_Tree_relation_h__
//#define __KO_dog_Tree_relation_h__
//
//#include "core/mm_core.h"
//#include <map>
//#include <string>
//
//#include "dish/mm_event.h"
//#include "CEGUI/widgets/Listbox.h"
//#include "CEGUI/widgets/ListboxItem.h"
//#include "CEGUI/widgets/ListboxTextItem.h"
//#include "CEGUI/widgets/Tree.h"
//#include "toolkit/mm_elem_map.h"
//
//#include "model_data/KO_dog_data_relation.h"
////////////////////////////////////////////////////////////////////////////
//namespace mm
//{	
//	class tree_friendInfo
//	{
//	public:
//		CEGUI::TreeItem item;
//		CEGUI::TreeItem* father_item;
//		mm_event_handler d_event_update_conn;
//		mm_event_handler d_event_update_remark_conn;
//		mm_event_handler d_event_update_group_conn;
//	public:
//		tree_friendInfo();
//		tree_friendInfo(const CEGUI::String& text, CEGUI::uint item_id = 0, void* item_data = 0, bool disabled = false, bool auto_delete = true);
//		~tree_friendInfo();
//
//	public:
//		void set_item_text(const CEGUI::String& text);
//		void set_item_id(mm_uint32_t item_id);
//		void set_item_data(void* item_data);
//
//	public:
//		bool on_handle_event_update(const mm_event_args& args);
//		bool on_handle_event_update_remark(const mm_event_args& args);
//		bool on_handle_event_update_group(const mm_event_args& args);
//	};
//
//	/////////////////////////////////////////////////////////////////////////////
//	class tree_groupInfo
//	{
//	public:
//		CEGUI::TreeItem item;
//		mm_event_handler d_event_update_conn;
//		mm_event_handler d_event_update_name_conn;
//	public:
//		tree_groupInfo();
//		tree_groupInfo(const CEGUI::String& text, CEGUI::uint item_id = 0, void* item_data = 0, bool disabled = false, bool auto_delete = true);
//		~tree_groupInfo();
//
//	public:
//		void set_item_text(const CEGUI::String& text);
//		void set_item_id(mm_uint32_t item_id);
//		void set_item_data(void* item_data);
//
//	public:
//		bool on_handle_event_update(const mm_event_args& args);
//		bool on_handle_event_update_name(const mm_event_args& args);
//	};
//
//	/////////////////////////////////////////////////////////////////////////////
//	class KO_dog_Tree_relation
//	{
//	public:
//		typedef std::map<mm_uint64_t, tree_friendInfo*> typ_map_id_friendInfo;
//		typedef std::map<mm_uint64_t, tree_groupInfo*> typ_map_id_groupInfo;
//
//	public:
//		CEGUI::Window* widgits;
//		mm::KO_dog_data_relation* p_data_relation;
//
//	public:
//		typ_map_id_friendInfo map_id_friendInfo;
//		typ_map_id_groupInfo map_id_groupInfo;
//
//		CEGUI::TreeItem* chose_item;
//
//		mm_event_handler d_event_add_friend_conn;
//		mm_event_handler d_event_rmv_friend_conn;
//		mm_event_handler d_event_add_group_conn;
//		mm_event_handler d_event_rmv_group_conn;
//
//	public:
//		KO_dog_Tree_relation();
//		virtual ~KO_dog_Tree_relation();
//
//	public:// set
//		void set_widgits(CEGUI::Window* widgits);
//		void unbinding_model_data();
//		void binding_model_data(mm::KO_dog_data_relation* p_data_relation);
//
//	public:
//		void setVisible(bool b);
//		void clear();
//		//
//		bool on_handle_event_add_friend(const mm_event_args& args);
//		bool on_handle_event_rmv_friend(const mm_event_args& args);
//		bool on_handle_event_add_group(const mm_event_args& args);
//		bool on_handle_event_rmv_group(const mm_event_args& args);
//		bool on_handle_event_chg_group(const mm_event_args& args);
//		bool on_handle_Tree_friend_Select(const CEGUI::EventArgs& args);
//	};
//}
////////////////////////////////////////////////////////////////////////////
//
//
//#endif//__KO_dog_Tree_relation_h__