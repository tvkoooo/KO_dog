#include "KO_dog_mailbox_search.h"


//#include "CEGUI/System.h"
//#include "CEGUI/GUIContext.h"
//#include "CEGUI/SchemeManager.h"
//#include "CEGUI/WindowManager.h"
//#include "CEGUI/RenderingWindow.h"

#include "CEGUI/widgets/Listbox.h"
#include "CEGUI/widgets/ListboxItem.h"
#include "CEGUI/widgets/ListboxTextItem.h"

#include "dish/mm_value.h"

#include "KO_dog.h"
#include "network/network_handle.h"
#include "protodef/cxx/protodef/c_business_account.pb.h"

namespace mm
{

	KO_dog_mailbox_search::KO_dog_mailbox_search()
		: d_flake_context(NULL)
		, d_surface(NULL)

		, l_home_lj_mailbox_search(NULL)

		, StaticImage_basic(NULL)
		, StaticImage_widget(NULL)

		, StaticText_condition(NULL)
		, Editbox_condition(NULL)
		, StaticText_result(NULL)
		, Listbox_search(NULL)
		, Button_search(NULL)
		, Button_add(NULL)
		, StaticText_user_info(NULL)
	{

	}

	KO_dog_mailbox_search::~KO_dog_mailbox_search()
	{

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
		this->StaticImage_basic = this->l_home_lj_mailbox_search->getChild("StaticImage_basic");
		this->StaticImage_widget = this->l_home_lj_mailbox_search->getChild("StaticImage_widget");

		this->StaticText_condition = this->StaticImage_widget->getChild("StaticText_condition");
		this->Editbox_condition = this->StaticImage_widget->getChild("Editbox_condition");
		this->StaticText_result = this->StaticImage_widget->getChild("StaticText_result");
		this->Listbox_search = this->StaticImage_widget->getChild("Listbox_search");
		this->Button_search = this->StaticImage_widget->getChild("Button_search");
		this->Button_add = this->StaticImage_widget->getChild("Button_add");
		this->StaticText_user_info = this->StaticImage_widget->getChild("StaticText_user_info");
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

		struct mm_logger* g_logger = mm_logger_instance();
		mm_logger_log_I(g_logger, "KO_dog_mailbox_search::%s %d success.", __FUNCTION__, __LINE__);
	}

	bool KO_dog_mailbox_search::on_handle_Button_search(const CEGUI::EventArgs& args)
	{
		const CEGUI::String & s_condition = this->Editbox_condition->getText();

		mm::KO_dog* p = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_data_user_basic = &p->data.data_user_basic;
		struct data_user_basic* u_basic = &p_data_user_basic->basic;
		//删除容器里面旧的数据
		p_data_user_basic->friend_basics.clear();

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

		size_t all = listb->getItemCount();
		size_t choices_num = listb->getSelectedCount();

		if (choices_num > 0 )
		{
			CEGUI::ListboxItem*	getFirst = listb->getFirstSelectedItem();
			size_t num = listb->getItemIndex(getFirst);
			//typedef 做一个短名称
			typedef mm::KO_dog_data_user_basic::v_friend_basic user_basic_vec;
			user_basic_vec& vec = p_data_user_basic->friend_basics;
			mm::data_search_friend_basic& e = vec.at(num);
			//
			std::string text = "";
			text += "id           " + mm::mm_value::to_string(e.id) + "\n";
			text += "name         " + mm::mm_value::to_string(e.name) + "\n";
			text += "nick         " + mm::mm_value::to_string(e.nick) + "\n";
			text += "create_time  " + mm::mm_value::to_string(e.create_time);
			this->StaticText_user_info->setText(text);
		}
		else
		{
			this->StaticText_user_info->setText("");
		}
		
		return false;
	}
	bool KO_dog_mailbox_search::on_handle_StaticText_user_info(const CEGUI::EventArgs& args)
	{

		return false;
	}
	bool KO_dog_mailbox_search::on_handle_Button_add(const CEGUI::EventArgs& args)
	{

		return false;
	}

	bool KO_dog_mailbox_search::on_handle_event_search_friend_update(const mm_event_args& args)
	{
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_data_user_basic = &p_dog->data.data_user_basic;
		CEGUI::Listbox* listb = (CEGUI::Listbox*)this->Listbox_search;


		//CEGUI::ListboxTextItem* item1 = new CEGUI::ListboxTextItem("Listbox Item 1", 1);
		//CEGUI::ListboxTextItem* item2 = new CEGUI::ListboxTextItem("Listbox Item 2", 2);
		//CEGUI::ListboxTextItem* item3 = new CEGUI::ListboxTextItem("Listbox Item 3", 3);

		//listb->addItem(item1);
		//listb->addItem(item2);
		//listb->addItem(item3);

		//每次回复新数据先清除旧数据
		listb->resetList();

		//更新新数据
		int i = 0;
		//typedef 做一个短名称
		typedef mm::KO_dog_data_user_basic::v_friend_basic user_basic_vec;
		user_basic_vec& vec = p_data_user_basic->friend_basics;

		//遍历容器
		for (user_basic_vec::iterator it = vec.begin();
			it != vec.end(); it++,i++)
		{
			//获取具体迭代器包含的元素引用
			mm::data_search_friend_basic& e = *it;
			//对拷贝数据
			//e.id = u->user_id();
			//e.name = u->user_name();
			//e.nick = u->user_nick();
			//e.create_time = u->create_time();
			std::string text = mm::mm_value::to_string(e.id) + " " + e.name;
			CEGUI::ListboxTextItem* item = new CEGUI::ListboxTextItem(text, i);
			listb->addItem(item);
		}
			   
		return false;
	}

}