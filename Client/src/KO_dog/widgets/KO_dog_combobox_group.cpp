#include "KO_dog_combobox_group.h"

#include "CEGUI/widgets/Listbox.h"
#include "CEGUI/widgets/Combobox.h"
#include "CEGUI/widgets/ListboxItem.h"
#include "CEGUI/widgets/ListboxTextItem.h"

#include "dish/mm_value.h"


namespace mm
{
	combobox_group::combobox_group()
		: item("", 0, NULL, false, false)
	{

	}
	combobox_group::combobox_group(const CEGUI::String& text, CEGUI::uint item_id , void* item_data , bool disabled , bool auto_delete )
		: item(text, item_id, item_data, disabled, auto_delete)
	{

	}
	combobox_group::~combobox_group()
	{

	}
	//
	void combobox_group::set_item_text(const CEGUI::String& text)
	{
		this->item.setText(text);
	}
	void combobox_group::set_item_id(mm_uint32_t item_id)
	{
		this->item.setID(item_id);
	}
	void combobox_group::set_item_data(void* item_data)
	{
		this->item.setUserData(item_data);
	}
	bool combobox_group::on_handle_event_update(const mm_event_args& args)
	{
		mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
		this->set_item_data(p_groupInfo);
		this->set_item_id(1);
		this->set_item_text(p_groupInfo->group_name);
		return false;
	}
	bool combobox_group::on_handle_event_update_name(const mm_event_args& args)
	{
		mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
		this->set_item_text(p_groupInfo->group_name);
		return false;
	}
	/////////////////////////////////////////////////////////////////////////////
	KO_dog_combobox_group::KO_dog_combobox_group()
		: Combobox(NULL)
		, p_groupId_groupName_map(NULL)
		, chose_item(NULL)
	{

	}
	KO_dog_combobox_group::~KO_dog_combobox_group()
	{

	}
	//
	void KO_dog_combobox_group::set_Combobox(CEGUI::Window* Combobox)
	{
		this->Combobox = Combobox;
	}
	void KO_dog_combobox_group::unbinding_model_data()
	{
		assert(NULL != this->Combobox && "KO_dog_combobox_group::unbinding_model_data() error, KO_dog_combobox_group::set_Combobox(CEGUI::Window* Combobox) is necessary.");
		if (NULL != this->p_groupId_groupName_map)
		{
			//解绑 mm::KO_dog_data_relation::data_relation_groupId_groupName_map 事件
			this->p_groupId_groupName_map->d_event_set.unsubscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_add, this->d_event_add_conn);
			this->p_groupId_groupName_map->d_event_set.unsubscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_rmv, this->d_event_rmv_conn);
		}
	}
	void KO_dog_combobox_group::binding_model_data(mm::KO_dog_data_relation::data_relation_groupId_groupName_map* p_groupId_groupName_map)
	{
		this->p_groupId_groupName_map = p_groupId_groupName_map;
		//解绑事件
		this->unbinding_model_data();
		//订阅 控件 Combobox 选择事件
		this->Combobox->subscribeEvent(CEGUI::Combobox::EventListSelectionAccepted, CEGUI::Event::Subscriber(&KO_dog_combobox_group::on_handle_Combobox_select, this));
		//订阅 mm::KO_dog_data_relation::data_relation_groupId_groupName_map 事件
		this->d_event_add_conn = this->p_groupId_groupName_map->d_event_set.subscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_add, &KO_dog_combobox_group::on_handle_event_add, this);
		this->d_event_rmv_conn = this->p_groupId_groupName_map->d_event_set.subscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_rmv, &KO_dog_combobox_group::on_handle_event_rmv, this);
	}
	void KO_dog_combobox_group::setVisible(bool b)
	{
		this->Combobox->setVisible(b);
	}
	void KO_dog_combobox_group::clear()
	{
		//遍历 map_id_elem
		typ_map_id_elem::iterator it = this->map_id_elem.begin();
		while (it != this->map_id_elem.end())
		{
			combobox_group* e = it->second;
			mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*) e->item.getUserData();
			p_groupInfo->d_event_set.unsubscribe_event(mm::data_relation_groupInfo::event_update, e->d_event_update_conn);
			p_groupInfo->d_event_set.unsubscribe_event(mm::data_relation_groupInfo::event_update_name, e->d_event_update_name_conn);
			//
			CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
			cbbo->removeItem(&e->item);
			//
			this->map_id_elem.erase(it++);
		}
		//解绑事件
		this->unbinding_model_data();
	}
	bool KO_dog_combobox_group::on_handle_event_add(const mm_event_args& args)
	{
		bool flag = false;
		mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags& evt_ags = (mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags&)args;
		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
		assert(NULL != p_groupInfo && "mm::data_relation_groupInfo mm_event_args Return null value.");
		mm_uint64_t group_id = evt_ags.id;
		//寻找元素 
		typ_map_id_elem::iterator it = this->map_id_elem.find(group_id);
		if (it == this->map_id_elem.end())
		{
			//没有找到内容，增加一条新的好友组
			combobox_group* e = new combobox_group(p_groupInfo->group_name, 1, p_groupInfo, false, false);
			this->map_id_elem.insert(typ_map_id_elem::value_type(group_id, e));
			//Combobox 插入一条数据
			CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
			cbbo->addItem(&e->item);
			//绑定 combobox_group 事件 event_update 和 event_update_name
			e->d_event_update_conn = p_groupInfo->d_event_set.subscribe_event(mm::data_relation_groupInfo::event_update, &combobox_group::on_handle_event_update, e);
			e->d_event_update_name_conn = p_groupInfo->d_event_set.subscribe_event(mm::data_relation_groupInfo::event_update_name, &combobox_group::on_handle_event_update_name, e);
			flag = true;
		}
		else
		{
			//修改里面内容
			combobox_group* e = it->second;
			e->set_item_data(p_groupInfo);
			e->set_item_id(1);
			e->set_item_text(p_groupInfo->group_name);
			flag = true;
		}
		return flag;
	}
	bool KO_dog_combobox_group::on_handle_event_rmv(const mm_event_args& args)
	{
		bool flag = false;
		mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags& evt_ags = (mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags&)args;
		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
		assert(NULL != p_groupInfo && "mm::data_relation_groupInfo mm_event_args Return null value.");
		mm_uint64_t group_id = evt_ags.id;
		//寻找元素 
		typ_map_id_elem::iterator it = this->map_id_elem.find(group_id);
		if (it != this->map_id_elem.end())
		{
			//找到内容，Combobox 先解除这条记录的绑定，并删除
			combobox_group* e = it->second;
			p_groupInfo->d_event_set.unsubscribe_event(mm::data_relation_groupInfo::event_update, e->d_event_update_conn);
			p_groupInfo->d_event_set.unsubscribe_event(mm::data_relation_groupInfo::event_update_name, e->d_event_update_name_conn);
			//
			CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
			cbbo->removeItem(&e->item);
			//
			this->map_id_elem.erase(it);
			flag = true;
		}
		return flag;
	}
	bool KO_dog_combobox_group::on_handle_Combobox_select(const CEGUI::EventArgs& args)
	{
		CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
		this->chose_item = (CEGUI::ListboxTextItem*)cbbo->getSelectedItem();
		return false;
	}

}