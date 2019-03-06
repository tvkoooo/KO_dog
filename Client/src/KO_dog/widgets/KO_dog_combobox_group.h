#ifndef __KO_dog_combobox_group_group_h__
#define __KO_dog_combobox_group_group_h__

#include "core/mm_core.h"
#include <map>
#include <string>

#include "dish/mm_event.h"
#include "CEGUI/widgets/Listbox.h"
#include "CEGUI/widgets/ListboxItem.h"
#include "CEGUI/widgets/ListboxTextItem.h"
#include "toolkit/mm_elem_map.h"

#include "model_data/KO_dog_data_relation.h"
//////////////////////////////////////////////////////////////////////////
namespace mm
{	
	class combobox_group
	{
	public:
		CEGUI::ListboxTextItem item;
		mm_event_handler d_event_update_conn;
		mm_event_handler d_event_update_name_conn;
	public:
		combobox_group();
		combobox_group(const CEGUI::String& text, CEGUI::uint item_id = 0, void* item_data = 0, bool disabled = false, bool auto_delete = true);
		~combobox_group();

	public:
		void set_item_text(const CEGUI::String& text);
		void set_item_id(mm_uint32_t item_id);
		void set_item_data(void* item_data);

	public:
		bool on_handle_event_update(const mm_event_args& args);
		bool on_handle_event_update_name(const mm_event_args& args);
	};

	/////////////////////////////////////////////////////////////////////////////
	class KO_dog_combobox_group
	{
	public:
		typedef std::map<mm_uint64_t, combobox_group*> typ_map_id_elem;
		
	public:
		CEGUI::Window* Combobox;
		mm::KO_dog_data_relation::data_relation_groupId_groupName_map* p_groupId_groupName_map;

	public:
		typ_map_id_elem map_id_elem;
		CEGUI::ListboxTextItem* chose_item;

		mm_event_handler d_event_add_conn;
		mm_event_handler d_event_rmv_conn;

	public:
		KO_dog_combobox_group();
		virtual ~KO_dog_combobox_group();

	public:// set
		void set_Combobox(CEGUI::Window* Combobox);
		void unbinding_model_data();
		void binding_model_data(mm::KO_dog_data_relation::data_relation_groupId_groupName_map* p_groupId_groupName_map);

	public:
		void setVisible(bool b);
		void clear();
		//
		
		bool on_handle_event_add(const mm_event_args& args);
		bool on_handle_event_rmv(const mm_event_args& args);
		bool on_handle_Combobox_select(const CEGUI::EventArgs& args);
	};
}
//////////////////////////////////////////////////////////////////////////


#endif//__KO_dog_combobox_group_group_h__