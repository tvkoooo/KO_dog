//#ifndef __KO_dog_mailbox_friend_talk_h__
//#define __KO_dog_mailbox_friend_talk_h__
//
//#include "core/mm_core.h"
//#include <map>
//#include <string>
//
////#include "flake/mm_flake_surface.h"
//
//#include "dish/mm_event.h"
//#include "CEGUI/widgets/Listbox.h"
//#include "CEGUI/widgets/ListboxItem.h"
//#include "CEGUI/widgets/ListboxTextItem.h"
//#include "toolkit/mm_elem_map.h"
//
////#include "dotsceneloader/DotSceneLoader.h"
//
////#include "container/mm_bitset.h"
//
////#include "model_data/KO_dog_data_user_basic.h"
////#include "model_data/KO_dog_data_relation.h"
//
////////////////////////////////////////////////////////////////////////////
//namespace mm
//{	
//	class combobox_elem
//	{
//	public:
//		CEGUI::ListboxTextItem item;
//		mm_event_handler d_event_update_conn;
//	public:
//		combobox_elem();
//		~combobox_elem();
//
//	public:
//		void set_item_text(const std::string& text);
//		void set_item_id(mm_uint32_t item_id);
//		void set_item_data(void* item_data);
//		void set_auto_delete(bool auto_delete);
//
//	private:
//		//bool on_handle_event_update(const mm_event_args& args);
//	};
//
//
//	class KO_dog_combobox
//	{
//
//	public:
//		CEGUI::Window* Combobox;
//	public:
//		mm_event_handler d_event_add_conn;
//		mm_event_handler d_event_rmv_conn;
//		mm_event_handler d_event_set_model_conn;
//
//		elem_map<mm_uint64_t, combobox_elem> map_id_elem;
//		CEGUI::ListboxTextItem* chose_item;
//
//
//	public:
//		KO_dog_combobox();
//		virtual ~KO_dog_combobox();
//
//	public:// set
//		void set_data_model(CEGUI::Window* Combobox);
//
//	public:// I/O
//		void setVisible(bool b);
//
//	private:
//		bool on_handle_event_add(const mm_event_args& args);
//		bool on_handle_event_rmv(const mm_event_args& args);
//		bool on_handle_event_set_model(const mm_event_args& args);
//	};
//}
////////////////////////////////////////////////////////////////////////////
//
//
//#endif//__KO_dog_mailbox_friend_talk_h__