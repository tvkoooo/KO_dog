#include "KO_dog_mailbox_friend_apply.h"

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
	KO_dog_mailbox_friend_apply::KO_dog_mailbox_friend_apply()
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

		, p_groupId_chose(NULL)
		, p_friend_apply(NULL)
	{

	}

	KO_dog_mailbox_friend_apply::~KO_dog_mailbox_friend_apply()
	{

	}

	void KO_dog_mailbox_friend_apply::set_data(mm_flake_context* d_flake_context, mm_flake_surface* d_surface)
	{
		this->d_flake_context = d_flake_context;
		this->d_surface = d_surface;
	}
	void KO_dog_mailbox_friend_apply::set_l_layer(CEGUI::Window* l_layer)
	{
		this->l_home_lj_mailbox_friend_apply = l_layer;
	}
	void KO_dog_mailbox_friend_apply::set_friend_apply(mm::data_basic_friend_info* p_friend_apply)
	{
		this->p_friend_apply = p_friend_apply;
	}
	void KO_dog_mailbox_friend_apply::set_data_model()
	{
		
	}
	void KO_dog_mailbox_friend_apply::on_finish_launching()
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
		this->Editbox_remark->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&KO_dog_mailbox_friend_apply::on_handle_StaticText_user_info, this));
		this->Button_agree->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox_friend_apply::on_handle_Button_agree, this));
		this->Button_refuse->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox_friend_apply::on_handle_Button_refuse, this));
		this->Button_set->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox_friend_apply::on_handle_Button_set, this));
		this->Combobox->subscribeEvent(CEGUI::Combobox::EventListSelectionAccepted, CEGUI::Event::Subscriber(&KO_dog_mailbox_friend_apply::on_handle_Combobox_select, this));
		////////////////////////////////////////////////////////////////////////////////

		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		//订阅KO_dog_data_user_basic 的 event_data_search_friend_basic_update 事件
		this->d_event_data_relation_add_friend_group_conn = p_dog->data.data_relation.groupId_groupName_map.d_event_set.subscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_add, &KO_dog_mailbox_friend_apply::on_handle_event_data_relation_add_friend_group, this);
		this->d_event_data_relation_rmv_friend_group_conn = p_dog->data.data_relation.groupId_groupName_map.d_event_set.subscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_rmv, &KO_dog_mailbox_friend_apply::on_handle_event_data_relation_rmv_friend_group, this);
		this->d_event_groupId_groupName_map_set_model_conn = p_dog->data.data_relation.d_event_set.subscribe_event(KO_dog_data_relation::event_groupId_groupName_map_set_model, &KO_dog_mailbox_friend_apply::on_handle_event_groupId_groupName_map_set_model, this);


		//初始化设置部分参数
		this->map_group_wp.clear();
	}
	void KO_dog_mailbox_friend_apply::on_before_terminate()
	{
		//清理部分参数
		this->map_group_wp.clear();

		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		p_dog->data.data_relation.groupId_groupName_map.d_event_set.unsubscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_add, this->d_event_data_relation_add_friend_group_conn);
		p_dog->data.data_relation.groupId_groupName_map.d_event_set.unsubscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_rmv, this->d_event_data_relation_rmv_friend_group_conn);
		p_dog->data.data_relation.d_event_set.unsubscribe_event(KO_dog_data_relation::event_groupId_groupName_map_set_model, this->d_event_groupId_groupName_map_set_model_conn);

		struct mm_logger* g_logger = mm_logger_instance();
		mm_logger_log_I(g_logger, "KO_dog_mailbox_friend_apply::%s %d success.", __FUNCTION__, __LINE__);
	}
	//
	void KO_dog_mailbox_friend_apply::setVisible(bool b)
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
	void KO_dog_mailbox_friend_apply::setVisible_opcode(bool b)
	{
		this->StaticText_opcode->setVisible(b);
	}
	void KO_dog_mailbox_friend_apply::setVisible_friend(bool b)
	{
		this->StaticText_friend->setVisible(b);
	}

	//
	bool KO_dog_mailbox_friend_apply::on_handle_StaticText_user_info(const CEGUI::EventArgs& args)
	{

		return false;
	}

	bool KO_dog_mailbox_friend_apply::on_handle_Button_agree(const CEGUI::EventArgs& args)
	{
		this->StaticText_friend->setVisible(true);
		this->Editbox_remark->setText(this->p_friend_apply->name);
		CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
		mm::KO_dog_mailbox_friend_apply::data_friend_apply* p_data = this->map_groupId_data.get(0);
		cbbo->setItemSelectState(p_data->p_ListboxTextItem,true);
		this->p_groupId_chose = (mm::data_relation_groupInfo*)p_data->p_ListboxTextItem->getUserData();
		return false;
	}

	bool KO_dog_mailbox_friend_apply::on_handle_Button_refuse(const CEGUI::EventArgs& args)
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
		rq.set_friend_group_id(0);
		rq.set_opcode(c_business_relation::allow_friend_rq::refuse);
		mm_client_tcps_flush_send_message(&p->network.tcp, u_basic->id, c_business_relation::allow_friend_rq_msg_id, &rq);

		return false;
	}
	bool KO_dog_mailbox_friend_apply::on_handle_Button_set(const CEGUI::EventArgs& args)
	{
		mm::KO_dog* p = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_data_user_basic = &p->data.data_user_basic;
		struct data_user_basic* u_basic = &p_data_user_basic->basic;
		// 获取组重命名
		const CEGUI::String& remark = this->Editbox_remark->getText();
		// 获取组id
		mm_uint64_t group_id = this->p_groupId_chose->group_id;

		//发送新的请求
		c_business_relation::allow_friend_rq rq;
		rq.set_user_myself_id(u_basic->id);
		rq.set_user_allow_id(this->p_friend_apply->id);
		rq.set_user_myself_nick(u_basic->name);
		rq.set_user_allow_nick(remark.c_str());
		rq.set_friend_group_id(group_id);
		rq.set_opcode(c_business_relation::allow_friend_rq::allow);
		mm_client_tcps_flush_send_message(&p->network.tcp, u_basic->id, c_business_relation::allow_friend_rq_msg_id, &rq);

		return false;
	}

	bool KO_dog_mailbox_friend_apply::on_handle_Combobox_select(const CEGUI::EventArgs& args)
	{
		CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
		CEGUI::ListboxItem*	item = cbbo->getSelectedItem();
		this->p_groupId_chose = (mm::data_relation_groupInfo*)item->getUserData();
		return false;
	}

	
	bool KO_dog_mailbox_friend_apply::on_handle_event_data_relation_add_friend_group(const mm_event_args& args)
	{
		bool flag = false;
		mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags& evt_ags = (mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags&)args;
		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
		assert(NULL != p_groupInfo && "mm::data_relation_groupInfo mm_event_args Return null value.");
		mm_uint64_t group_id = evt_ags.id;
		mm::KO_dog_mailbox_friend_apply::data_friend_apply* p_data = this->map_groupId_data.get(group_id);
		if (NULL == p_data)
		{
			//增加一条新的好友组
			mm::KO_dog_mailbox_friend_apply::data_friend_apply* p_data = this->map_groupId_data.add(group_id);
			//Combobox 插入一条数据
			CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
			p_data->p_ListboxTextItem = new CEGUI::ListboxTextItem(p_groupInfo->group_name, 1, p_groupInfo);
			cbbo->addItem(p_data->p_ListboxTextItem);
			//
			p_data->d_event_group_update = p_groupInfo->d_event_set.subscribe_event(mm::data_relation_groupInfo::event_update, &KO_dog_mailbox_friend_apply::on_handle_event_data_friend_group_update, this);
			p_data->d_event_group_update_name = p_groupInfo->d_event_set.subscribe_event(mm::data_relation_groupInfo::event_update_name, &KO_dog_mailbox_friend_apply::on_handle_event_data_friend_group_update_name, this);
			flag = true;
		}
		else
		{
			//修改里面内容
			if (NULL != p_data->p_ListboxTextItem)
			{
				p_data->p_ListboxTextItem->setText(p_groupInfo->group_name);
				p_data->p_ListboxTextItem->setUserData(p_groupInfo);
			}
			flag = true;
		}
		return flag;
	}
	bool KO_dog_mailbox_friend_apply::on_handle_event_data_relation_rmv_friend_group(const mm_event_args& args)
	{
		bool flag = false;
		mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags& evt_ags = (mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags&)args;
		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
		assert(NULL != p_groupInfo && "mm::data_relation_groupInfo mm_event_args Return null value.");
		mm_uint64_t group_id = evt_ags.id;
		mm::KO_dog_mailbox_friend_apply::data_friend_apply* p_data = this->map_groupId_data.get(group_id);
		if (NULL != p_data)
		{
			//Combobox 先解除这条记录的绑定，并删除
			p_groupInfo->d_event_set.unsubscribe_event(mm::data_relation_groupInfo::event_update, p_data->d_event_group_update);
			p_groupInfo->d_event_set.unsubscribe_event(mm::data_relation_groupInfo::event_update_name, p_data->d_event_group_update_name);
			//
			CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
			cbbo->removeItem(p_data->p_ListboxTextItem);
			//
			this->map_groupId_data.rmv(group_id);
			flag = true;
		}
		return flag;
	}
	bool KO_dog_mailbox_friend_apply::on_handle_event_data_friend_group_update(const mm_event_args& args)
	{
		mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
		mm::KO_dog_mailbox_friend_apply::data_friend_apply* p_data = this->map_groupId_data.get(p_groupInfo->group_id);
		if (NULL != p_data)
		{			
			p_data->p_ListboxTextItem->setText(p_groupInfo->group_name);
			//p_data->p_ListboxTextItem->setUserData(p_groupInfo);
		}
		return false;
	}
	bool KO_dog_mailbox_friend_apply::on_handle_event_data_friend_group_update_name(const mm_event_args& args)
	{
		mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
		mm::KO_dog_mailbox_friend_apply::data_friend_apply* p_data = this->map_groupId_data.get(p_groupInfo->group_id);
		if (NULL != p_data)
		{
			p_data->p_ListboxTextItem->setText(p_groupInfo->group_name);
		}
		return false;
	}
	bool KO_dog_mailbox_friend_apply::on_handle_event_groupId_groupName_map_set_model(const mm_event_args& args)
	{
		return false;
	}
}