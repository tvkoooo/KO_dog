#include "KO_dog_mailbox_search.h"


//#include "CEGUI/System.h"
//#include "CEGUI/GUIContext.h"
//#include "CEGUI/SchemeManager.h"
//#include "CEGUI/WindowManager.h"
//#include "CEGUI/RenderingWindow.h"




#include "dish/mm_value.h"

#include "KO_dog.h"
#include "network/network_handle.h"
#include "protodef/cxx/protodef/c_business_account.pb.h"
#include "protodef/cxx/protodef/c_business_relation.pb.h"

namespace mm
{

	KO_dog_mailbox_search::KO_dog_mailbox_search()
		: d_flake_context(NULL)
		, d_surface(NULL)

		, l_home_lj_mailbox_search(NULL)

		, StaticText_condition(NULL)
		, Editbox_condition(NULL)
		, Editbox_description(NULL)
		, StaticText_result(NULL)
		, Listbox_search(NULL)
		, Button_search(NULL)
		, Button_add(NULL)
		, StaticText_user_info(NULL)
		, p_friend_info(NULL)
	{
		data_search_friend_basic_init(&this->chose_friend);
	}

	KO_dog_mailbox_search::~KO_dog_mailbox_search()
	{
		data_search_friend_basic_destroy(&this->chose_friend);
	}

	void KO_dog_mailbox_search::set_data(mm_flake_context* d_flake_context, mm_flake_surface* d_surface)
	{
		this->d_flake_context = d_flake_context;
		this->d_surface = d_surface;
	}
	void KO_dog_mailbox_search::set_l_layer(CEGUI::Window* l_layer)
	{
		this->l_home_lj_mailbox_search = l_layer;
	}
	void KO_dog_mailbox_search::on_finish_launching()
	{
		struct mm_logger* g_logger = mm_logger_instance();
		//////////////////////////////////////////////////////////////////////////

		this->StaticText_condition = this->l_home_lj_mailbox_search->getChild("StaticText_condition");
		this->Editbox_condition = this->l_home_lj_mailbox_search->getChild("Editbox_condition");
		this->Editbox_description = this->l_home_lj_mailbox_search->getChild("Editbox_description");
		this->StaticText_result = this->l_home_lj_mailbox_search->getChild("StaticText_result");
		this->Listbox_search = this->l_home_lj_mailbox_search->getChild("Listbox_search");
		this->Button_search = this->l_home_lj_mailbox_search->getChild("Button_search");
		this->Button_add = this->l_home_lj_mailbox_search->getChild("Button_add");
		this->StaticText_user_info = this->l_home_lj_mailbox_search->getChild("StaticText_user_info");
		////////////////////////////////////////////////////////////////////////////////

		this->Button_search->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox_search::on_handle_Button_search, this));
		this->Listbox_search->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&KO_dog_mailbox_search::on_handle_Listbox_search, this));
		this->StaticText_user_info->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&KO_dog_mailbox_search::on_handle_StaticText_user_info, this));
		this->Button_add->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox_search::on_handle_Button_add, this));
		////////////////////////////////////////////////////////////////////////////////

		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		//订阅KO_dog_data_user_basic 的 event_data_search_friend_basic_update 事件
		this->d_event_search_friend_update_conn = p_dog->data.data_user_basic.d_event_set.subscribe_event(KO_dog_data_user_basic::event_data_search_friend_basic_update, &KO_dog_mailbox_search::on_handle_event_search_friend_update, this);

	}
	void KO_dog_mailbox_search::on_before_terminate()
	{
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		p_dog->data.data_user_basic.d_event_set.unsubscribe_event(KO_dog_data_user_basic::event_data_search_friend_basic_update, this->d_event_search_friend_update_conn);

		struct mm_logger* g_logger = mm_logger_instance();
		mm_logger_log_I(g_logger, "KO_dog_mailbox_search::%s %d success.", __FUNCTION__, __LINE__);
	}

	bool KO_dog_mailbox_search::on_handle_Button_search(const CEGUI::EventArgs& args)
	{
		const CEGUI::String & s_condition = this->Editbox_condition->getText();

		mm::KO_dog* p = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_data_user_basic = &p->data.data_user_basic;
		struct data_user_basic* u_basic = &p_data_user_basic->basic;

		//发送新的请求
		c_business_account::search_account_rq rq;
		rq.set_condition(s_condition.c_str());
		mm_client_tcps_flush_send_message(&p->network.tcp, u_basic->id, c_business_account::search_account_rq_msg_id, &rq);
		return false;
	}

	bool KO_dog_mailbox_search::on_handle_Listbox_search(const CEGUI::EventArgs& args)
	{
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_data_user_basic = &p_dog->data.data_user_basic;
		CEGUI::Listbox* listb = (CEGUI::Listbox*)this->Listbox_search;

		size_t choices_num = listb->getSelectedCount();
		CEGUI::ListboxItem* item = listb->getFirstSelectedItem();

		if (choices_num > 0 && NULL != item)
		{			
			this->p_friend_info = (data_basic_friend_info*)item->getUserData();
			std::string text = "";
			text += "id:           \n" + mm::mm_value::to_string(this->p_friend_info->id) + "\n\n";
			text += "name:         \n" + mm::mm_value::to_string(this->p_friend_info->name) + "\n\n";
			text += "nick:         \n" + mm::mm_value::to_string(this->p_friend_info->nick) + "\n\n";
			text += "create_time:  \n" + mm::mm_value::to_string(this->p_friend_info->create_time);
			this->StaticText_user_info->setText(text);

		}
		else
		{
			this->StaticText_user_info->setText("");
			this->p_friend_info = NULL;
		}		
		return false;
	}
	bool KO_dog_mailbox_search::on_handle_StaticText_user_info(const CEGUI::EventArgs& args)
	{

		return false;
	}
	bool KO_dog_mailbox_search::on_handle_Button_add(const CEGUI::EventArgs& args)
	{
		const CEGUI::String & s_description = this->Editbox_description->getText();

		mm::KO_dog* p = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_data_user_basic = &p->data.data_user_basic;
		struct data_user_basic* u_basic = &p_data_user_basic->basic;

		if (this->p_friend_info != NULL)
		{
			//发送新的请求
			c_business_relation::add_friend_rq rq;
			rq.set_user_myself_id(u_basic->id);
			rq.set_user_add_id(this->p_friend_info->id);
			rq.set_user_remark(this->p_friend_info->nick);
			rq.set_description(s_description.c_str());
			mm_client_tcps_flush_send_message(&p->network.tcp, u_basic->id, c_business_relation::add_friend_rq_msg_id, &rq);

		}
		else
		{
			this->StaticText_user_info->setText("Warning!!! \nyou haven't selected \nany users yet !!");
		}

		return false;
	}

	bool KO_dog_mailbox_search::on_handle_event_search_friend_update(const mm_event_args& args)
	{
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_data_user_basic = &p_dog->data.data_user_basic;
		CEGUI::Listbox* listb = (CEGUI::Listbox*)this->Listbox_search;
		//每次回复新数据先清除旧数据
		listb->resetList();
		//遍历容器 更新新数据		
		for (mm::elem_event_map<mm_uint64_t, data_basic_friend_info>::map_type::iterator it = p_data_user_basic->m_friend_search.m.begin();
			it != p_data_user_basic->m_friend_search.m.end(); it++)
		{
			CEGUI::ListboxTextItem* item = new CEGUI::ListboxTextItem(it->second->name, 0, it->second);
			item->setSelectionBrushImage("TaharezLook" "/TextSelectionBrush");
			listb->addItem(item);
			this->map_friend_wp.add(it->second->id, item);
		}
		return false;
	}

}