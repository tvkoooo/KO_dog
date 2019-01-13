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
	//KO_dog_mailbox_friend_apply::Combobox_data::Combobox_data()
	//	: Combobox(NULL)
	//{
	//	this->m_groupId_Item.clear();
	//}

	//KO_dog_mailbox_friend_apply::Combobox_data::~Combobox_data()
	//{
	//	assert(this->m_groupId_Item.size() == 0 && "KO_dog_mailbox_friend_apply::Combobox_data logic data not clear !!");
	//	this->m_groupId_Item.clear();
	//}

	//void KO_dog_mailbox_friend_apply::Combobox_data::set_data(CEGUI::Window* Combobox)
	//{
	//	this->Combobox = Combobox;
	//}
	//void KO_dog_mailbox_friend_apply::Combobox_data::clear()
	//{
	//	if (this->m_groupId_Item.size() > 0)
	//	{
	//		CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
	//		cbbo->resetList();
	//		this->m_groupId_Item.clear();
	//	}
	//}
	//bool KO_dog_mailbox_friend_apply::Combobox_data::add(mm_uint64_t group_id, const std::string& group_name)
	//{
	//	bool flag = false;
	//	//寻找元素 
	//	map_groupId_Item::iterator it = this->m_groupId_Item.find(group_id);
	//	if (it == this->m_groupId_Item.end())
	//	{
	//		//Combobox 插入一条数据
	//		CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
	//		CEGUI::ListboxTextItem* itm = new CEGUI::ListboxTextItem(group_name, group_id);
	//		cbbo->addItem(itm);
	//		//插入一条数据
	//		this->m_groupId_Item.insert(map_groupId_Item::value_type(group_id, (CEGUI::Window*)itm));
	//	}
	//	return flag;
	//}
	//bool KO_dog_mailbox_friend_apply::Combobox_data::remove(mm_uint64_t group_id)
	//{
	//	bool flag = false;
	//	//寻找元素 
	//	map_groupId_Item::iterator it = this->m_groupId_Item.find(group_id);
	//	if (it != this->m_groupId_Item.end())
	//	{
	//		//Combobox 删除一条数据
	//		CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
	//		CEGUI::ListboxTextItem* itm = (CEGUI::ListboxTextItem*) it->second;
	//		cbbo->removeItem(itm);
	//		//删除一条数据
	//		this->m_groupId_Item.erase(it);
	//		flag = true;
	//	}
	//	return flag;
	//}
	//bool KO_dog_mailbox_friend_apply::Combobox_data::rename(mm_uint64_t group_id, const std::string group_name)
	//{
	//	bool flag = false;
	//	//寻找元素 
	//	map_groupId_Item::iterator it = this->m_groupId_Item.find(group_id);
	//	if (it != this->m_groupId_Item.end())
	//	{
	//		//Combobox 变更一条记录的text
	//		CEGUI::ListboxTextItem* itm = (CEGUI::ListboxTextItem*) it->second;
	//		itm->setText(group_name);
	//		flag = true;
	//	}
	//	return flag;
	//}
	//void KO_dog_mailbox_friend_apply::Combobox_data::set_model(void * model_addr)
	//{
	//	data_relation_groupId_groupName_map::map_groupId_groupName* p_groupId_groupName = (data_relation_groupId_groupName_map::map_groupId_groupName*)model_addr;
	//	CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
	//	//1 解绑清除
	//	this->clear();		
	//	//2 遍历数据源，重新绑定 
	//	mm::data_relation_groupId_groupName_map::map_groupId_groupName::iterator it;
	//	for (it = p_groupId_groupName->begin(); it != p_groupId_groupName->end(); it++)
	//	{
	//		this->add(it->first,it->second);
	//	}
	//}

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
		rq.set_opcode(c_business_relation::allow_friend_rq::refuse);
		mm_client_tcps_flush_send_message(&p->network.tcp, u_basic->id, c_business_relation::allow_friend_rq_msg_id, &rq);

		return false;
	}
	bool KO_dog_mailbox_friend_apply::on_handle_Button_set(const CEGUI::EventArgs& args)
	{
		return false;
	}

	bool KO_dog_mailbox_friend_apply::on_handle_Combobox_select(const CEGUI::EventArgs& args)
	{
		return false;
	}

	
	bool KO_dog_mailbox_friend_apply::on_handle_event_data_relation_add_friend_group(const mm_event_args& args)
	{
		mm::data_relation_groupId_groupName_map::mm_event_args_data& evt_ags = (mm::data_relation_groupId_groupName_map::mm_event_args_data&)args;
		this->map_group_wp.add(evt_ags.friend_group_id, evt_ags.group_name);
		return false;
	}
	bool KO_dog_mailbox_friend_apply::on_handle_event_data_relation_rmv_friend_group(const mm_event_args& args)
	{
		mm::data_relation_groupId_groupName_map::mm_event_args_data& evt_ags = (mm::data_relation_groupId_groupName_map::mm_event_args_data&)args;
		this->map_group_wp.add(evt_ags.friend_group_id, evt_ags.group_name);
		return false;
	}
	bool KO_dog_mailbox_friend_apply::on_handle_event_groupId_groupName_map_set_model(const mm_event_args& args)
	{
		mm::KO_dog_data_relation::mm_event_args_model& evt_ags = (mm::KO_dog_data_relation::mm_event_args_model&)args;



		this->cbbo_data.set_model(evt_ags.model_addr);
		return false;
	}

}