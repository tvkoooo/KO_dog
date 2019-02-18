//#include "KO_dog_combobox.h"
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
//	combobox_elem::combobox_elem()
//		: item("")
//	{
//
//	}
//	combobox_elem::~combobox_elem()
//	{
//
//	}
//
//	void combobox_elem::set_item_text(const std::string& text)
//	{
//
//	}
//	void combobox_elem::set_item_id(mm_uint32_t item_id)
//	{
//
//	}
//	void combobox_elem::set_item_data(void* item_data)
//	{
//
//	}
//	void combobox_elem::set_auto_delete(bool auto_delete)
//	{
//
//	}
//
//
//
//
//
//
//
//
//
//
//	KO_dog_combobox::KO_dog_combobox()
//		: d_flake_context(NULL)
//		, d_surface(NULL)
//
//		, l_home_lj_mailbox_friend(NULL)
//
//		, StaticText_opcode(NULL)
//		, StaticText_change_group(NULL)
//		, Combobox(NULL)
//		, StaticText_change_remark(NULL)
//		, Button_set(NULL)
//		, Editbox_remark(NULL)
//		, StaticText_delete_group(NULL)
//		, Button_delete(NULL)
//		, StaticText_window(NULL)
//		, StaticText_talk(NULL)
//		, StaticText_write(NULL)
//		, Editbox_write(NULL)
//		, Button_send(NULL)
//
//		, p_groupId_chose(NULL)
//		, p_friend_talk(NULL)
//	{
//
//	}
//
//	KO_dog_combobox::~KO_dog_combobox()
//	{
//
//	}
//
//	void KO_dog_combobox::set_context(mm_flake_context* d_flake_context, mm_flake_surface* d_surface)
//	{
//		this->d_flake_context = d_flake_context;
//		this->d_surface = d_surface;
//	}
//	void KO_dog_combobox::set_layer(CEGUI::Window* l_layer)
//	{
//		this->l_home_lj_mailbox_friend = l_layer;
//	}
//	void KO_dog_combobox::set_friend_talk(mm::data_relation_friendInfo* p_friend_talk)
//	{
//		this->p_friend_talk = p_friend_talk;
//	}
//	void KO_dog_combobox::set_data_model(mm::data_relation_friendInfo* p_friend_talk)
//	{
//		this->set_friend_talk(p_friend_talk);
//		this->StaticText_window->setText(p_friend_talk->friend_remark);
//		CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
//		mm::KO_dog_combobox::data_friend_apply_talk* p_data = this->map_groupId_data.get(p_friend_talk->friend_group_id);
//		cbbo->setItemSelectState(p_data->p_ListboxTextItem, true);
//		this->p_groupId_chose = (mm::data_relation_groupInfo*)p_data->p_ListboxTextItem->getUserData();
//		this->Editbox_remark->setText(p_friend_talk->friend_remark);
//	}
//	void KO_dog_combobox::on_finish_launching()
//	{
//		struct mm_logger* g_logger = mm_logger_instance();
//		//////////////////////////////////////////////////////////////////////////
//
//		this->StaticText_opcode = this->l_home_lj_mailbox_friend->getChild("StaticText_opcode");
//		this->StaticText_change_group = this->StaticText_opcode->getChild("StaticText_change_group");
//		this->Combobox = this->StaticText_change_group->getChild("Combobox");
//		this->StaticText_change_remark = this->StaticText_opcode->getChild("StaticText_change_remark");
//		this->Button_set = this->StaticText_opcode->getChild("Button_set");
//		this->Editbox_remark = this->StaticText_change_remark->getChild("Editbox_remark");
//		this->StaticText_delete_group = this->StaticText_opcode->getChild("StaticText_delete_group");
//		this->Button_delete = this->StaticText_delete_group->getChild("Button_delete");
//		this->StaticText_window = this->l_home_lj_mailbox_friend->getChild("StaticText_window");
//		this->StaticText_talk = this->StaticText_window->getChild("StaticText_talk");
//		this->StaticText_write = this->StaticText_window->getChild("StaticText_write");
//		this->Editbox_write = this->StaticText_write->getChild("Editbox_write");
//		this->Button_send = this->StaticText_write->getChild("Button_send");
//
//		this->l_home_lj_mailbox_friend->setVisible(false);
//		////////////////////////////////////////////////////////////////////////////////
//		//this->Editbox_remark->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&KO_dog_combobox::on_handle_StaticText_user_info, this));
//		this->Button_delete->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_combobox::on_handle_Button_delete, this));
//		this->Button_set->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_combobox::on_handle_Button_set, this));
//		this->Combobox->subscribeEvent(CEGUI::Combobox::EventListSelectionAccepted, CEGUI::Event::Subscriber(&KO_dog_combobox::on_handle_Combobox_select, this));
//		////////////////////////////////////////////////////////////////////////////////
//
//		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
//		//订阅KO_dog_data_user_basic 的 event_data_search_friend_basic_update 事件
//		this->d_event_data_relation_add_friend_group_conn = p_dog->data.data_relation.groupId_groupName_map.d_event_set.subscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_add, &KO_dog_combobox::on_handle_event_data_relation_add_friend_group, this);
//		this->d_event_data_relation_rmv_friend_group_conn = p_dog->data.data_relation.groupId_groupName_map.d_event_set.subscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_rmv, &KO_dog_combobox::on_handle_event_data_relation_rmv_friend_group, this);
//		this->d_event_groupId_groupName_map_set_model_conn = p_dog->data.data_relation.d_event_set.subscribe_event(KO_dog_data_relation::event_groupId_groupName_map_set_model, &KO_dog_combobox::on_handle_event_groupId_groupName_map_set_model, this);
//
//
//		//初始化设置部分参数
//		//this->map_group_wp.clear();
//	}
//	void KO_dog_combobox::on_before_terminate()
//	{
//		//清理部分参数
//		//this->map_group_wp.clear();
//
//		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
//		p_dog->data.data_relation.groupId_groupName_map.d_event_set.unsubscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_add, this->d_event_data_relation_add_friend_group_conn);
//		p_dog->data.data_relation.groupId_groupName_map.d_event_set.unsubscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_rmv, this->d_event_data_relation_rmv_friend_group_conn);
//		p_dog->data.data_relation.d_event_set.unsubscribe_event(KO_dog_data_relation::event_groupId_groupName_map_set_model, this->d_event_groupId_groupName_map_set_model_conn);
//
//		struct mm_logger* g_logger = mm_logger_instance();
//		mm_logger_log_I(g_logger, "KO_dog_combobox::%s %d success.", __FUNCTION__, __LINE__);
//	}
//	//
//	void KO_dog_combobox::setVisible(bool b)
//	{
//		this->l_home_lj_mailbox_friend->setVisible(b);
//		if (b)
//		{
//			//std::string text = "";
//			//text += "id:           \n" + mm::mm_value::to_string(this->p_friend_apply_talk->id) + "\n\n";
//			//text += "name:         \n" + mm::mm_value::to_string(this->p_friend_apply_talk->name) + "\n\n";
//			//text += "nick:         \n" + mm::mm_value::to_string(this->p_friend_apply_talk->nick) + "\n\n";
//			//text += "create_time:  \n" + mm::mm_value::to_string(this->p_friend_apply_talk->create_time) + "\n\n";
//			//text += "apply_description:  \n" + mm::mm_value::to_string(this->p_friend_apply_talk->apply_description);
//			//this->StaticText_user_info->setText(text);
//		}
//		else
//		{
//			//this->StaticText_user_info->setText("");
//		}
//	}
//
//	//
//	bool KO_dog_combobox::on_handle_StaticText_user_info(const CEGUI::EventArgs& args)
//	{
//
//		return false;
//	}
//
//	bool KO_dog_combobox::on_handle_Button_agree(const CEGUI::EventArgs& args)
//	{
//		//this->StaticText_friend->setVisible(true);
//		//this->Editbox_remark->setText(this->p_friend_apply_talk->name);
//		//CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
//		//mm::KO_dog_combobox::data_friend_apply_talk* p_data = this->map_groupId_data.get(0);
//		//cbbo->setItemSelectState(p_data->p_ListboxTextItem,true);
//		//this->p_groupId_chose = (mm::data_relation_groupInfo*)p_data->p_ListboxTextItem->getUserData();
//		return false;
//	}
//
//	bool KO_dog_combobox::on_handle_Button_delete(const CEGUI::EventArgs& args)
//	{
//		//mm::KO_dog* p = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
//		//mm::KO_dog_data_user_basic* p_data_user_basic = &p->data.data_user_basic;
//		//struct data_user_basic* u_basic = &p_data_user_basic->basic;
//
//		////发送新的请求
//		//c_business_relation::allow_friend_rq rq;
//		//rq.set_user_myself_id(u_basic->id);
//		//rq.set_user_allow_id(this->p_friend_apply_talk->id);
//		//rq.set_user_myself_nick(u_basic->name);
//		//rq.set_user_allow_nick(this->p_friend_apply_talk->name);
//		//rq.set_friend_group_id(0);
//		//rq.set_opcode(c_business_relation::allow_friend_rq::refuse);
//		//mm_client_tcps_flush_send_message(&p->network.tcp, u_basic->id, c_business_relation::allow_friend_rq_msg_id, &rq);
//
//		CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
//		mm::KO_dog_combobox::data_friend_apply_talk* p_data = this->map_groupId_data.get(0);
//		cbbo->setItemSelectState(p_data->p_ListboxTextItem, true);
//		this->p_groupId_chose = (mm::data_relation_groupInfo*)p_data->p_ListboxTextItem->getUserData();
//		return false;
//	}
//	bool KO_dog_combobox::on_handle_Button_set(const CEGUI::EventArgs& args)
//	{
//		mm::KO_dog* p = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
//		mm::KO_dog_data_user_basic* p_data_user_basic = &p->data.data_user_basic;
//		struct data_user_basic* u_basic = &p_data_user_basic->basic;
//		// 获取组重命名
//		const CEGUI::String& remark = this->Editbox_remark->getText();
//		// 获取组id
//		mm_uint64_t group_id = this->p_groupId_chose->group_id;
//
//		if (this->p_friend_talk->friend_remark != remark)
//		{
//			//发送新的请求
//			c_business_relation::rename_friend_remark_rq rq;
//			rq.set_user_myself_id(u_basic->id);
//			rq.set_user_friend_id(this->p_friend_talk->friend_id);
//			rq.set_user_friend_remark(remark.c_str());
//			mm_client_tcps_flush_send_message(&p->network.tcp, u_basic->id, c_business_relation::rename_friend_remark_rq_msg_id, &rq);
//		}
//		if (this->p_friend_talk->friend_group_id != group_id)
//		{
//			//发送新的请求
//			c_business_relation::change_friend_group_rq rq;
//			rq.set_user_myself_id(u_basic->id);
//			rq.set_user_friend_id(this->p_friend_talk->friend_id);
//			rq.set_user_friend_group_id_old(this->p_friend_talk->friend_group_id);
//			rq.set_user_friend_group_id_new(group_id);
//			mm_client_tcps_flush_send_message(&p->network.tcp, u_basic->id, c_business_relation::change_friend_group_rq_msg_id, &rq);
//		}
//		//this->l_home_lj_mailbox_friend->setVisible(false);
//		return false;
//	}
//
//	bool KO_dog_combobox::on_handle_Combobox_select(const CEGUI::EventArgs& args)
//	{
//		CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
//		CEGUI::ListboxItem*	item = cbbo->getSelectedItem();
//		this->p_groupId_chose = (mm::data_relation_groupInfo*)item->getUserData();
//		return false;
//	}
//
//	
//	bool KO_dog_combobox::on_handle_event_data_relation_add_friend_group(const mm_event_args& args)
//	{
//		bool flag = false;
//		mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags& evt_ags = (mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags&)args;
//		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
//		assert(NULL != p_groupInfo && "mm::data_relation_groupInfo mm_event_args Return null value.");
//		mm_uint64_t group_id = evt_ags.id;
//		mm::KO_dog_combobox::data_friend_apply_talk* p_data = this->map_groupId_data.get(group_id);
//		if (NULL == p_data)
//		{
//			//增加一条新的好友组
//			mm::KO_dog_combobox::data_friend_apply_talk* p_data = this->map_groupId_data.add(group_id);
//			//Combobox 插入一条数据
//			CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
//			p_data->p_ListboxTextItem = new CEGUI::ListboxTextItem(p_groupInfo->group_name, 1, p_groupInfo);
//			cbbo->addItem(p_data->p_ListboxTextItem);
//			//
//			p_data->d_event_group_update = p_groupInfo->d_event_set.subscribe_event(mm::data_relation_groupInfo::event_update, &KO_dog_combobox::on_handle_event_data_friend_group_update, this);
//			p_data->d_event_group_update_name = p_groupInfo->d_event_set.subscribe_event(mm::data_relation_groupInfo::event_update_name, &KO_dog_combobox::on_handle_event_data_friend_group_update_name, this);
//			flag = true;
//		}
//		else
//		{
//			//修改里面内容
//			if (NULL != p_data->p_ListboxTextItem)
//			{
//				p_data->p_ListboxTextItem->setText(p_groupInfo->group_name);
//				p_data->p_ListboxTextItem->setUserData(p_groupInfo);
//			}
//			flag = true;
//		}
//		return flag;
//	}
//	bool KO_dog_combobox::on_handle_event_data_relation_rmv_friend_group(const mm_event_args& args)
//	{
//		bool flag = false;
//		mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags& evt_ags = (mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags&)args;
//		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
//		assert(NULL != p_groupInfo && "mm::data_relation_groupInfo mm_event_args Return null value.");
//		mm_uint64_t group_id = evt_ags.id;
//		mm::KO_dog_combobox::data_friend_apply_talk* p_data = this->map_groupId_data.get(group_id);
//		if (NULL != p_data)
//		{
//			//Combobox 先解除这条记录的绑定，并删除
//			p_groupInfo->d_event_set.unsubscribe_event(mm::data_relation_groupInfo::event_update, p_data->d_event_group_update);
//			p_groupInfo->d_event_set.unsubscribe_event(mm::data_relation_groupInfo::event_update_name, p_data->d_event_group_update_name);
//			//
//			CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
//			cbbo->removeItem(p_data->p_ListboxTextItem);
//			//
//			this->map_groupId_data.rmv(group_id);
//			flag = true;
//		}
//		return flag;
//	}
//	bool KO_dog_combobox::on_handle_event_data_friend_group_update(const mm_event_args& args)
//	{
//		mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
//		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
//		mm::KO_dog_combobox::data_friend_apply_talk* p_data = this->map_groupId_data.get(p_groupInfo->group_id);
//		if (NULL != p_data)
//		{			
//			p_data->p_ListboxTextItem->setText(p_groupInfo->group_name);
//			//p_data->p_ListboxTextItem->setUserData(p_groupInfo);
//		}
//		return false;
//	}
//	bool KO_dog_combobox::on_handle_event_data_friend_group_update_name(const mm_event_args& args)
//	{
//		mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
//		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
//		mm::KO_dog_combobox::data_friend_apply_talk* p_data = this->map_groupId_data.get(p_groupInfo->group_id);
//		if (NULL != p_data)
//		{
//			p_data->p_ListboxTextItem->setText(p_groupInfo->group_name);
//		}
//		return false;
//	}
//	bool KO_dog_combobox::on_handle_event_groupId_groupName_map_set_model(const mm_event_args& args)
//	{
//		return false;
//	}
//}