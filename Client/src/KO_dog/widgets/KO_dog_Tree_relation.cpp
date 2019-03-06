//#include "KO_dog_Tree_relation.h"
//
//#include "CEGUI/widgets/Listbox.h"
//#include "CEGUI/widgets/Combobox.h"
//#include "CEGUI/widgets/ListboxItem.h"
//#include "CEGUI/widgets/ListboxTextItem.h"
//
//#include "dish/mm_value.h"
//
//
//namespace mm
//{
//	tree_friendInfo::tree_friendInfo()
//		: item("", 0, NULL, false, false)
//		, father_item(NULL)
//	{
//
//	}
//	tree_friendInfo::tree_friendInfo(const CEGUI::String& text, CEGUI::uint item_id , void* item_data , bool disabled , bool auto_delete )
//		: item(text, item_id, item_data, disabled, auto_delete)
//		, father_item(NULL)
//	{
//
//	}
//	tree_friendInfo::~tree_friendInfo()
//	{
//
//	}
//	//
//	void tree_friendInfo::set_item_text(const CEGUI::String& text)
//	{
//		this->item.setText(text);
//	}
//	void tree_friendInfo::set_item_id(mm_uint32_t item_id)
//	{
//		this->item.setID(item_id);
//	}
//	void tree_friendInfo::set_item_data(void* item_data)
//	{
//		this->item.setUserData(item_data);
//	}
//	bool tree_friendInfo::on_handle_event_update(const mm_event_args& args)
//	{
//		mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
//		mm::data_relation_friendInfo* p_elem = (mm::data_relation_friendInfo*)evt_ags.e;
//		this->set_item_data(p_elem);
//		this->set_item_id(2);
//		this->set_item_text(p_elem->friend_remark);
//		return false;
//	}
//	bool tree_friendInfo::on_handle_event_update_remark(const mm_event_args& args)
//	{
//		mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
//		mm::data_relation_friendInfo* p_elem = (mm::data_relation_friendInfo*)evt_ags.e;
//		this->set_item_text(p_elem->friend_remark);
//		return false;
//	}
//	bool tree_friendInfo::on_handle_event_update_group(const mm_event_args& args)
//	{
//		//无操作
//		return false;
//	}
//	/////////////////////////////////////////////////////////////////////////////
//	tree_groupInfo::tree_groupInfo()
//		: item("", 0, NULL, false, false)
//	{
//
//	}
//	tree_groupInfo::tree_groupInfo(const CEGUI::String& text, CEGUI::uint item_id , void* item_data , bool disabled , bool auto_delete )
//		: item(text, item_id, item_data, disabled, auto_delete)
//	{
//
//	}
//	tree_groupInfo::~tree_groupInfo()
//	{
//
//	}
//	//
//	void tree_groupInfo::set_item_text(const CEGUI::String& text)
//	{
//		this->item.setText(text);
//	}
//	void tree_groupInfo::set_item_id(mm_uint32_t item_id)
//	{
//		this->item.setID(item_id);
//	}
//	void tree_groupInfo::set_item_data(void* item_data)
//	{
//		this->item.setUserData(item_data);
//	}
//	bool tree_groupInfo::on_handle_event_update(const mm_event_args& args)
//	{
//		mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
//		mm::data_relation_groupInfo* p_elem = (mm::data_relation_groupInfo*)evt_ags.e;
//		this->set_item_data(p_elem);
//		this->set_item_id(1);
//		this->set_item_text(p_elem->group_name);
//		return false;
//	}
//	bool tree_groupInfo::on_handle_event_update_name(const mm_event_args& args)
//	{
//		mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
//		mm::data_relation_groupInfo* p_elem = (mm::data_relation_groupInfo*)evt_ags.e;
//		this->set_item_text(p_elem->group_name);
//		return false;
//	}
//	/////////////////////////////////////////////////////////////////////////////
//	KO_dog_Tree_relation::KO_dog_Tree_relation()
//		: widgits(NULL)
//		, p_data_relation(NULL)
//		, chose_item(NULL)
//	{
//
//	}
//	KO_dog_Tree_relation::~KO_dog_Tree_relation()
//	{
//		this->clear();
//	}
//	//
//	void KO_dog_Tree_relation::set_widgits(CEGUI::Window* widgits)
//	{
//		this->widgits = widgits;
//	}
//	void KO_dog_Tree_relation::unbinding_model_data()
//	{
//		assert(NULL != this->widgits && "KO_dog_Tree_relation::unbinding_model_data() error, KO_dog_Tree_relation::set_widgits(CEGUI::Window* widgits) is necessary.");
//		if (NULL != this->p_data_relation)
//		{
//			//解绑 mm::data_relation_friendId_friendInfo_map 事件
//			this->p_data_relation->friendId_friendInfo_map.d_event_set.unsubscribe_event(mm::data_relation_friendId_friendInfo_map::event_add, this->d_event_add_friend_conn);
//			this->p_data_relation->friendId_friendInfo_map.d_event_set.unsubscribe_event(mm::data_relation_friendId_friendInfo_map::event_rmv, this->d_event_rmv_friend_conn);
//			//解绑 mm::KO_dog_data_relation::data_relation_groupId_groupName_map 事件
//			this->p_data_relation->groupId_groupName_map.d_event_set.unsubscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_add, this->d_event_add_group_conn);
//			this->p_data_relation->groupId_groupName_map.d_event_set.unsubscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_rmv, this->d_event_rmv_group_conn);
//		}
//	}
//	void KO_dog_Tree_relation::binding_model_data(mm::KO_dog_data_relation* p_data_relation)
//	{
//		//绑定数据
//		this->p_data_relation = p_data_relation;
//		//解绑事件
//		this->unbinding_model_data();
//		//订阅 控件 Combobox 选择事件
//		this->widgits->subscribeEvent(CEGUI::Tree::EventSelectionChanged, CEGUI::Event::Subscriber(&KO_dog_Tree_relation::on_handle_Tree_friend_Select, this));
//		//订阅 mm::data_relation_friendId_friendInfo_map 事件
//		this->d_event_add_friend_conn = this->p_data_relation->friendId_friendInfo_map.d_event_set.subscribe_event(mm::data_relation_friendId_friendInfo_map::event_add, this->on_handle_event_add_friend, this);
//		this->d_event_rmv_friend_conn = this->p_data_relation->friendId_friendInfo_map.d_event_set.subscribe_event(mm::data_relation_friendId_friendInfo_map::event_rmv, this->on_handle_event_rmv_friend, this);
//		//订阅 mm::KO_dog_data_relation::data_relation_groupId_groupName_map 事件
//		this->d_event_add_group_conn = this->p_data_relation->groupId_groupName_map.d_event_set.subscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_add, this->on_handle_event_add_group, this);
//		this->d_event_rmv_group_conn = this->p_data_relation->groupId_groupName_map.d_event_set.subscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_rmv, this->on_handle_event_rmv_group, this);
//	}
//	void KO_dog_Tree_relation::setVisible(bool b)
//	{
//		this->widgits->setVisible(b);
//	}
//	void KO_dog_Tree_relation::clear()
//	{
//		//遍历 map_id_friendInfo
//		typ_map_id_friendInfo::iterator it = this->map_id_friendInfo.begin();
//		while (it != this->map_id_friendInfo.end())
//		{
//			//解绑事件
//			tree_friendInfo* e = it->second;
//			mm::data_relation_friendInfo* p_data = (mm::data_relation_friendInfo*) e->item.getUserData();
//			p_data->d_event_set.unsubscribe_event(mm::data_relation_friendInfo::event_update, e->d_event_update_conn);
//			p_data->d_event_set.unsubscribe_event(mm::data_relation_friendInfo::event_update_remark, e->d_event_update_remark_conn);
//			p_data->d_event_set.unsubscribe_event(mm::data_relation_friendInfo::event_update_group, e->d_event_update_group_conn);
//			//界面元素进行 group_item(father_item) 解除 friend_item(item)
//			e->father_item->removeItem(&e->item);
//			//删除 map 元素
//			this->map_id_friendInfo.erase(it++);
//		}
//		//遍历 map_id_groupInfo
//		typ_map_id_groupInfo::iterator it = this->map_id_groupInfo.begin();
//		while (it != this->map_id_groupInfo.end())
//		{
//
//
//		}
//		//解绑事件
//		this->unbinding_model_data();
//	}
//	bool KO_dog_Tree_relation::on_handle_event_add(const mm_event_args& args)
//	{
//		bool flag = false;
//		mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags& evt_ags = (mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags&)args;
//		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
//		assert(NULL != p_groupInfo && "mm::data_relation_groupInfo mm_event_args Return null value.");
//		mm_uint64_t group_id = evt_ags.id;
//		//寻找元素 
//		typ_map_id_elem::iterator it = this->map_id_elem.find(group_id);
//		if (it == this->map_id_elem.end())
//		{
//			//没有找到内容，增加一条新的好友组
//			tree_friendInfo* e = new tree_friendInfo(p_groupInfo->group_name, 1, p_groupInfo, false, false);
//			this->map_id_elem.insert(typ_map_id_elem::value_type(group_id, e));
//			//Combobox 插入一条数据
//			CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
//			cbbo->addItem(&e->item);
//			//绑定 tree_friendInfo 事件 event_update 和 event_update_name
//			e->d_event_update_conn = p_groupInfo->d_event_set.subscribe_event(mm::data_relation_groupInfo::event_update, &tree_friendInfo::on_handle_event_update, e);
//			e->d_event_update_name_conn = p_groupInfo->d_event_set.subscribe_event(mm::data_relation_groupInfo::event_update_name, &tree_friendInfo::on_handle_event_update_name, e);
//			flag = true;
//		}
//		else
//		{
//			//修改里面内容
//			tree_friendInfo* e = it->second;
//			e->set_item_data(p_groupInfo);
//			e->set_item_id(1);
//			e->set_item_text(p_groupInfo->group_name);
//			flag = true;
//		}
//		return flag;
//	}
//	bool KO_dog_Tree_relation::on_handle_event_rmv(const mm_event_args& args)
//	{
//		bool flag = false;
//		mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags& evt_ags = (mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags&)args;
//		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
//		assert(NULL != p_groupInfo && "mm::data_relation_groupInfo mm_event_args Return null value.");
//		mm_uint64_t group_id = evt_ags.id;
//		//寻找元素 
//		typ_map_id_elem::iterator it = this->map_id_elem.find(group_id);
//		if (it != this->map_id_elem.end())
//		{
//			//找到内容，Combobox 先解除这条记录的绑定，并删除
//			tree_friendInfo* e = it->second;
//			p_groupInfo->d_event_set.unsubscribe_event(mm::data_relation_groupInfo::event_update, e->d_event_update_conn);
//			p_groupInfo->d_event_set.unsubscribe_event(mm::data_relation_groupInfo::event_update_name, e->d_event_update_name_conn);
//			//
//			CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
//			cbbo->removeItem(&e->item);
//			//
//			this->map_id_elem.erase(it);
//			flag = true;
//		}
//		return flag;
//	}
//	bool KO_dog_Tree_relation::on_handle_Combobox_select(const CEGUI::EventArgs& args)
//	{
//		CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
//		this->chose_item = (CEGUI::ListboxTextItem*)cbbo->getSelectedItem();
//		return false;
//	}
//
//}