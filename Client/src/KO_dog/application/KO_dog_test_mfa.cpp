#include "KO_dog_test_mfa.h"

#include "CEGUI/widgets/Listbox.h"
#include "CEGUI/widgets/Combobox.h"
#include "CEGUI/widgets/ListboxItem.h"
#include "CEGUI/widgets/ListboxTextItem.h"

#include "dish/mm_value.h"

#include "KO_dog.h"
#include "network/network_handle.h"
#include "protodef/cxx/protodef/c_business_account.pb.h"
#include "protodef/cxx/protodef/c_business_relation.pb.h"

namespace mm
{
	// 在这里我们手动删除内存. auto_delete = false.
	mm_bfi_list_item::mm_bfi_list_item()
		: CEGUI::ListboxTextItem("", 0, NULL, false, false)
		, d_m(NULL)
	{
		this->setSelectionBrushImage("TaharezLook" "/TextSelectionBrush");
	}
	void mm_bfi_list_item::set_model(data_basic_friend_info* m)
	{
		//1 解绑事件
		if (NULL != this->d_m)
		{
			this->d_m->d_event_set.unsubscribe_event(data_basic_friend_info::event_update, this->d_event_update_conn);
		}
		//2 赋新的模组数据
		this->d_m = m;
		//3 绑定事件
		if (NULL != this->d_m)
		{
			this->d_event_update_conn = this->d_m->d_event_set.subscribe_event(data_basic_friend_info::event_update, &mm_bfi_list_item::on_event_update, this);

			//default Initialization
			mm_event_obj_ags args;
			args.e = this->d_m;
			this->on_event_update(args);
		}
	}
	bool mm_bfi_list_item::on_event_update(const mm_event_args& args)
	{
		if (NULL != this->d_m)
		{
			this->setText(this->d_m->name);
		}
		return false;
	}
	mm_bfi::mm_bfi()
		: d_m(NULL)
		, Listbox_nt(NULL)
	{

	}
	void mm_bfi::set_layer(CEGUI::Window*l)
	{
		this->Listbox_nt = l;
	}
	void mm_bfi::set_model(mm_data_basic_friend_info_map_type* m)
	{
		//1 解绑事件
		if (NULL != this->d_m)
		{
			//default rmv
			data_basic_friend_info_args args;

			typedef mm_data_basic_friend_info_map_type::map_type map_type;
			map_type& _map = this->d_m->m;
			for (map_type::iterator it = _map.begin(); 
				it != _map.end(); it++)
			{
				args.m = this->d_m;
				args.id = it->first;
				args.e = it->second;
				//
				this->on_event_rmv(args);
			}

			this->d_m->d_event_set.unsubscribe_event(mm_data_basic_friend_info_map_type::event_add, this->d_event_add_conn);
			this->d_m->d_event_set.unsubscribe_event(mm_data_basic_friend_info_map_type::event_rmv, this->d_event_rmv_conn);
		}
		//2 赋新的模组数据
		this->d_m = m;
		//3 绑定事件
		if (NULL != this->d_m)
		{
			this->d_event_add_conn = m->d_event_set.subscribe_event(mm_data_basic_friend_info_map_type::event_add, &mm_bfi::on_event_add, this);
			this->d_event_rmv_conn = m->d_event_set.subscribe_event(mm_data_basic_friend_info_map_type::event_rmv, &mm_bfi::on_event_rmv, this);

			//default Initialization
			data_basic_friend_info_args args;

			typedef mm_data_basic_friend_info_map_type::map_type map_type;
			map_type& _map = this->d_m->m;
			for (map_type::iterator it = _map.begin(); 
				it != _map.end(); it++)
			{
				args.m = this->d_m;
				args.id = it->first;
				args.e = it->second;
				//
				this->on_event_add(args);
			}
		}
	}

	void mm_bfi::clear_item()
	{
		CEGUI::Listbox* listbox = (CEGUI::Listbox*)this->Listbox_nt;

		mm_bfi_list_item* e = NULL;
		item_map_type::iterator it = this->d_item_map.begin();
		while (it != this->d_item_map.end())
		{
			e = it->second;

			listbox->removeItem(e);

			this->d_item_map.erase(it++);
			delete e;
		}
	}
	bool mm_bfi::on_event_add(const mm_event_args& args)
	{
		const data_basic_friend_info_args& evt = (const data_basic_friend_info_args&)args;

		CEGUI::Listbox* listbox = (CEGUI::Listbox*)this->Listbox_nt;

		mm_bfi_list_item* e = NULL;
		item_map_type::iterator it = this->d_item_map.find(evt.id);
		if (it != this->d_item_map.end())
		{
			e = it->second;
			e->set_model((data_basic_friend_info*)evt.e);
		}
		else
		{
			e = new mm_bfi_list_item();
			e->set_model((data_basic_friend_info*)evt.e);
			this->d_item_map.insert(item_map_type::value_type(evt.id, e));

			listbox->addItem(e);
		}
		return false;
	}
	bool mm_bfi::on_event_rmv(const mm_event_args& args)
	{
		const data_basic_friend_info_args& evt = (const data_basic_friend_info_args&)args;

		CEGUI::Listbox* listbox = (CEGUI::Listbox*)this->Listbox_nt;

		mm_bfi_list_item* e = NULL;
		item_map_type::iterator it = this->d_item_map.find(evt.id);
		if (it != this->d_item_map.end())
		{
			e = it->second;

			listbox->removeItem(e);

			this->d_item_map.erase(it);
			delete e;
		}
		return false;
	}

	// 在这里我们手动删除内存. auto_delete = false.
	mm_mfa_list_item::mm_mfa_list_item()
		: CEGUI::ListboxTextItem("", 0, NULL, false, false)
		, d_m(NULL)
	{

	}
	void mm_mfa_list_item::set_model(data_relation_groupInfo* m)
	{
		//1 解绑事件
		if (NULL != this->d_m)
		{
			this->d_m->d_event_set.unsubscribe_event(data_relation_groupInfo::event_update, this->d_event_update_conn);
		}
		//2 赋新的模组数据
		this->d_m = m;
		//3 绑定事件
		if (NULL != this->d_m)
		{
			this->d_event_update_conn = this->d_m->d_event_set.subscribe_event(data_relation_groupInfo::event_update, &mm_mfa_list_item::on_event_update, this);

			//default Initialization
			mm_event_obj_ags args;
			args.e = this->d_m;
			this->on_event_update(args);
		}
	}
	bool mm_mfa_list_item::on_event_update(const mm_event_args& args)
	{
		if (NULL != this->d_m)
		{
			this->setText(this->d_m->group_name);
		}
		return false;
	}
	void mm_mfa::set_model(data_relation_group_map_type* m)
	{
		//1 解绑事件
		if (NULL != this->d_m)
		{
			//default rmv
			data_relation_group_map_ags args;

			typedef data_relation_group_map_type::map_type map_type;
			map_type& _map = this->d_m->m;
			for (map_type::iterator it = _map.begin(); 
				it != _map.end(); it++)
			{
				args.m = this->d_m;
				args.id = it->first;
				args.e = it->second;
				//
				this->on_event_rmv(args);
			}

			this->d_m->d_event_set.unsubscribe_event(data_relation_group_map_type::event_add, this->d_event_add_conn);
			this->d_m->d_event_set.unsubscribe_event(data_relation_group_map_type::event_rmv, this->d_event_rmv_conn);
		}
		//2 赋新的模组数据
		this->d_m = m;
		//3 绑定事件
		if (NULL != this->d_m)
		{
			this->d_event_add_conn = m->d_event_set.subscribe_event(data_relation_group_map_type::event_add, &mm_mfa::on_event_add, this);
			this->d_event_rmv_conn = m->d_event_set.subscribe_event(data_relation_group_map_type::event_rmv, &mm_mfa::on_event_rmv, this);

			//default Initialization
			data_relation_group_map_ags args;

			typedef data_relation_group_map_type::map_type map_type;
			map_type& _map = this->d_m->m;
			for (map_type::iterator it = _map.begin(); 
				it != _map.end(); it++)
			{
				args.m = this->d_m;
				args.id = it->first;
				args.e = it->second;
				//
				this->on_event_add(args);
			}
		}
	}

	void mm_mfa::clear_item()
	{
		CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;

		mm_mfa_list_item* e = NULL;
		item_map_type::iterator it = this->d_item_map.begin();
		while (it != this->d_item_map.end())
		{
			e = it->second;

			cbbo->removeItem(e);

			this->d_item_map.erase(it++);
			delete e;
		}
	}
	bool mm_mfa::on_event_add(const mm_event_args& args)
	{
		const data_relation_group_map_ags& evt = (const data_relation_group_map_ags&)args;

		CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;

		mm_mfa_list_item* e = NULL;
		item_map_type::iterator it = this->d_item_map.find(evt.id);
		if (it != this->d_item_map.end())
		{
			e = it->second;
			e->set_model((data_relation_groupInfo*)evt.e);
		}
		else
		{
			e = new mm_mfa_list_item();
			e->set_model((data_relation_groupInfo*)evt.e);
			this->d_item_map.insert(item_map_type::value_type(evt.id, e));

			cbbo->addItem(e);
		}
		return false;
	}
	bool mm_mfa::on_event_rmv(const mm_event_args& args)
	{
		const data_relation_group_map_ags& evt = (const data_relation_group_map_ags&)args;

		CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;

		mm_mfa_list_item* e = NULL;
		item_map_type::iterator it = this->d_item_map.find(evt.id);
		if (it != this->d_item_map.end())
		{
			e = it->second;

			cbbo->removeItem(e);

			this->d_item_map.erase(it);
			delete e;
		}
		return false;
	}

	mm_mfa::mm_mfa()
		: d_flake_context(NULL)
		, d_surface(NULL)

		, l_home_lj_mailbox_friend_apply(NULL)

		, StaticText_apply_info(NULL)
		, StaticText_user_info(NULL)
		, StaticText_friend(NULL)
		, Button_set(NULL)
		, StaticText_remark(NULL)
		, Editbox_remark(NULL)
		, StaticText_group(NULL)
		, Combobox(NULL)
		, StaticText_opcode(NULL)
		, Button_agree(NULL)
		, Button_refuse(NULL)

		, d_m(NULL)

		, p_groupId_chose(NULL)
		, p_friend_apply(NULL)
	{

	}

	mm_mfa::~mm_mfa()
	{
		// 清除视图层的元素,保证释放.
		this->clear_item();
	}
	void mm_mfa::set_data(mm_flake_context* d_flake_context, mm_flake_surface* d_surface)
	{
		this->d_flake_context = d_flake_context;
		this->d_surface = d_surface;
	}
	void mm_mfa::set_l_layer(CEGUI::Window* l_layer)
	{
		this->l_home_lj_mailbox_friend_apply = l_layer;
	}
	void mm_mfa::on_finish_launching()
	{
		struct mm_logger* g_logger = mm_logger_instance();
		//////////////////////////////////////////////////////////////////////////

		this->StaticText_apply_info = this->l_home_lj_mailbox_friend_apply->getChild("StaticText_apply_info");
		this->StaticText_user_info = this->StaticText_apply_info->getChild("StaticText_user_info");
		this->StaticText_friend = this->l_home_lj_mailbox_friend_apply->getChild("StaticText_friend");
		this->Button_set = this->StaticText_friend->getChild("Button_set");
		this->StaticText_remark = this->StaticText_friend->getChild("StaticText_remark");
		this->Editbox_remark = this->StaticText_remark->getChild("Editbox_remark");
		this->StaticText_group = this->StaticText_friend->getChild("StaticText_group");
		this->Combobox = this->StaticText_group->getChild("Combobox");
		this->StaticText_opcode = this->l_home_lj_mailbox_friend_apply->getChild("StaticText_opcode");
		this->Button_agree = this->StaticText_opcode->getChild("Button_agree");
		this->Button_refuse = this->StaticText_opcode->getChild("Button_refuse");
		////////////////////////////////////////////////////////////////////////////////
		this->StaticText_friend->setVisible(false);
		this->StaticText_opcode->setVisible(false);
		////////////////////////////////////////////////////////////////////////////////
		this->Editbox_remark->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&mm_mfa::on_handle_StaticText_user_info, this));
		this->Button_agree->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&mm_mfa::on_handle_Button_agree, this));
		this->Button_refuse->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&mm_mfa::on_handle_Button_refuse, this));
		this->Button_set->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&mm_mfa::on_handle_Button_set, this));
		this->Combobox->subscribeEvent(CEGUI::Combobox::EventListSelectionAccepted, CEGUI::Event::Subscriber(&mm_mfa::on_handle_Combobox_select, this));
		////////////////////////////////////////////////////////////////////////////////

		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		//订阅KO_dog_data_user_basic 的 event_data_search_friend_basic_update 事件
		this->d_event_data_relation_add_friend_group_conn = p_dog->data.data_relation.groupId_groupName_map.d_event_set.subscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_add, &mm_mfa::on_handle_event_data_relation_add_friend_group, this);
		this->d_event_data_relation_rmv_friend_group_conn = p_dog->data.data_relation.groupId_groupName_map.d_event_set.subscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_rmv, &mm_mfa::on_handle_event_data_relation_rmv_friend_group, this);
		this->d_event_groupId_groupName_map_set_model_conn = p_dog->data.data_relation.d_event_set.subscribe_event(KO_dog_data_relation::event_groupId_groupName_map_set_model, &mm_mfa::on_handle_event_groupId_groupName_map_set_model, this);


		//初始化设置部分参数
		//this->map_group_wp.clear();
	}
	void mm_mfa::on_before_terminate()
	{
		//清理部分参数
		//this->map_group_wp.clear();

		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		p_dog->data.data_relation.groupId_groupName_map.d_event_set.unsubscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_add, this->d_event_data_relation_add_friend_group_conn);
		p_dog->data.data_relation.groupId_groupName_map.d_event_set.unsubscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_rmv, this->d_event_data_relation_rmv_friend_group_conn);
		p_dog->data.data_relation.d_event_set.unsubscribe_event(KO_dog_data_relation::event_groupId_groupName_map_set_model, this->d_event_groupId_groupName_map_set_model_conn);

		struct mm_logger* g_logger = mm_logger_instance();
		mm_logger_log_I(g_logger, "KO_dog_mailbox_friend_apply::%s %d success.", __FUNCTION__, __LINE__);
	}
	//
	void mm_mfa::setVisible(bool b)
	{
		this->l_home_lj_mailbox_friend_apply->setVisible(b);
		if (b)
		{
			std::string text = "";
			text += "id:           \n" + mm::mm_value::to_string(this->p_friend_apply->id) + "\n\n";
			text += "name:         \n" + mm::mm_value::to_string(this->p_friend_apply->name) + "\n\n";
			text += "nick:         \n" + mm::mm_value::to_string(this->p_friend_apply->nick) + "\n\n";
			text += "create_time:  \n" + mm::mm_value::to_string(this->p_friend_apply->create_time) + "\n\n";
			text += "apply_description:  \n" + mm::mm_value::to_string(this->p_friend_apply->apply_description);
			this->StaticText_user_info->setText(text);
		}
		else
		{
			this->StaticText_user_info->setText("");
		}
	}
	void mm_mfa::setVisible_opcode(bool b)
	{
		this->StaticText_opcode->setVisible(b);
	}
	void mm_mfa::setVisible_friend(bool b)
	{
		this->StaticText_friend->setVisible(b);
	}

	//
	bool mm_mfa::on_handle_StaticText_user_info(const CEGUI::EventArgs& args)
	{

		return false;
	}

	bool mm_mfa::on_handle_Button_agree(const CEGUI::EventArgs& args)
	{
		this->StaticText_friend->setVisible(true);
		this->Editbox_remark->setText(this->p_friend_apply->name);
		return false;
	}

	bool mm_mfa::on_handle_Button_refuse(const CEGUI::EventArgs& args)
	{
		mm::KO_dog* p = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_data_user_basic = &p->data.data_user_basic;
		struct data_user_basic* u_basic = &p_data_user_basic->basic;

		//发送新的请求
		c_business_relation::allow_friend_rq rq;
		rq.set_user_myself_id(u_basic->id);
		rq.set_user_allow_id(this->p_friend_apply->id);
		rq.set_user_myself_nick(u_basic->name);
		rq.set_user_allow_nick(this->p_friend_apply->name);
		rq.set_opcode(c_business_relation::allow_friend_rq::refuse);
		mm_client_tcps_flush_send_message(&p->network.tcp, u_basic->id, c_business_relation::allow_friend_rq_msg_id, &rq);

		return false;
	}
	bool mm_mfa::on_handle_Button_set(const CEGUI::EventArgs& args)
	{
		return false;
	}

	bool mm_mfa::on_handle_Combobox_select(const CEGUI::EventArgs& args)
	{
		return false;
	}

	
	bool mm_mfa::on_handle_event_data_relation_add_friend_group(const mm_event_args& args)
	{
		//bool flag = false;
		//mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags& evt_ags = (mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags&)args;
		//data_relation_groupInfo* p_groupInfo = (data_relation_groupInfo*)evt_ags.e;
		//CEGUI::ListboxTextItem* p_item = this->map_group_wp.get(evt_ags.id);
		//if (NULL == p_item)
		//{
		//	//Combobox 插入一条数据
		//	CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
		//	p_item = new CEGUI::ListboxTextItem(p_groupInfo->group_name, 0, p_groupInfo);
		//	cbbo->addItem(p_item);
		//	this->map_group_wp.add(evt_ags.id, p_item);
		//	flag = true;
		//}
		//else
		//{
		//	p_item->setText(p_groupInfo->group_name);
		//	p_item->setUserData(p_groupInfo);
		//	flag = true;
		//}
		return false;
	}
	bool mm_mfa::on_handle_event_data_relation_rmv_friend_group(const mm_event_args& args)
	{
		//bool flag = false;
		//mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags& evt_ags = (mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags&)args;
		//data_relation_groupInfo* p_groupInfo = (data_relation_groupInfo*)evt_ags.e;
		//CEGUI::ListboxTextItem* p_item = this->map_group_wp.get(evt_ags.id);
		//if (NULL != p_item)
		//{
		//	//Combobox 插入一条数据
		//	CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
		//	cbbo->removeItem(p_item);
		//	this->map_group_wp.rmv(evt_ags.id);
		//	flag = true;
		//}
		return false;
	}
	bool mm_mfa::on_handle_event_groupId_groupName_map_set_model(const mm_event_args& args)
	{
		return false;
	}

}