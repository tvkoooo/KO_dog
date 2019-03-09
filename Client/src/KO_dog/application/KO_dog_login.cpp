#include "KO_dog_login.h"


#include "CEGUI/System.h"
#include "CEGUI/GUIContext.h"
#include "CEGUI/SchemeManager.h"
#include "CEGUI/WindowManager.h"
#include "CEGUI/RenderingWindow.h"

#include "KO_dog.h"
#include "network/network_handle.h"
#include "protodef/cxx/protodef/c_business_account.pb.h"


namespace mm
{
	const std::string KO_dog_login::event_login("event_login");

	KO_dog_login::KO_dog_login()
		: d_flake_context(NULL)
		, d_surface(NULL)
		, p_dog(NULL)
		, layer(NULL)

		, StaticImage(NULL)
		, Button_login(NULL)
		, Button_quit(NULL)
		, Button_register(NULL)
		, Editbox_id(NULL)
		, Editbox_password(NULL)
		, StaticText_git(NULL)
		, StaticText_id(NULL)
		, StaticText_notice(NULL)
		, StaticText_password(NULL)
	{
		
	}

	KO_dog_login::~KO_dog_login()
	{
		
	}

	void KO_dog_login::set_context_surface_(mm_flake_context* d_flake_context, mm_flake_surface* d_surface)
	{
		this->d_flake_context = d_flake_context;
		this->d_surface = d_surface;
		this->p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
	}
	void KO_dog_login::set_layer(CEGUI::Window* layer)
	{
		this->layer = layer;
	}

	void KO_dog_login::on_finish_launching()
	{
		struct mm_logger* g_logger = mm_logger_instance();
		//////////////////////////////////////////////////////////////////////////
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		this->StaticImage = this->layer->getChild("StaticImage");
		this->Button_login = this->StaticImage->getChild("Button_login");
		this->Button_quit = this->StaticImage->getChild("Button_quit");
		this->Button_register = this->StaticImage->getChild("Button_register");
		this->Editbox_id = this->StaticImage->getChild("Editbox_id");
		this->Editbox_password = this->StaticImage->getChild("Editbox_password");
		this->StaticText_git = this->StaticImage->getChild("StaticText_git");
		this->StaticText_id = this->StaticImage->getChild("StaticText_id");
		this->StaticText_notice = this->StaticImage->getChild("StaticText_notice");
		this->StaticText_password = this->StaticImage->getChild("StaticText_password");
		//////////////////////////////////////////////////////////////////////////
		this->Button_login->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_login::on_handle_l_s_button_login, this));
		this->Button_quit->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_login::on_handle_l_s_button_out, this));
		this->Button_register->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_login::on_handle_l_s_button_register, this));

		this->StaticImage->subscribeEvent(CEGUI::Window::EventUpdated, CEGUI::Event::Subscriber(&KO_dog_login::on_handle_MenuWindow_updated, this));
		//////////////////////////////////////////////////////////////////////////
		//订阅KO_dog_data_user_basic 的 event_userdata_update 事件
		this->d_event_userdata_update_conn = this->p_dog->data.data_user_basic.d_event_set.subscribe_event(KO_dog_data_user_basic::event_userdata_user_token_update, &KO_dog_login::on_handle_event_userdata_update, this);

		//订阅KO_dog_data_log_view 的 event_log_view 事件
		this->d_event_log_view_conn = this->p_dog->data.data_log_view.d_event_set.subscribe_event(KO_dog_data_log_view::event_log_view, &KO_dog_login::on_handle_event_log_view, this);

	}
	void KO_dog_login::on_before_terminate()
	{
		struct mm_logger* g_logger = mm_logger_instance();
		mm_logger_log_I(g_logger, "KO_dog_login::%s %d success.", __FUNCTION__, __LINE__);
		//////////////////////////////////////////////////////////////////////////
		//解除 注册 KO_dog_data_user_basic 的 event_userdata_update 事件
		this->p_dog->data.data_user_basic.d_event_set.unsubscribe_event(KO_dog_data_user_basic::event_userdata_user_token_update, this->d_event_userdata_update_conn);

		// 解除 注册 KO_dog_data_log_view 的 event_log_view 事件
		this->p_dog->data.data_log_view.d_event_set.unsubscribe_event(KO_dog_data_log_view::event_log_view, this->d_event_log_view_conn);
	}

	bool KO_dog_login::on_handle_l_s_button_login(const CEGUI::EventArgs& args)
	{		

		if (0 != this->p_dog->data.data_net.lobby.port)
		{	
			const CEGUI::String &user_name = this->Editbox_id->getText();
			const CEGUI::String &pass_word = this->Editbox_password->getText();

			md5_uint8 digest[16] = { 0 };
			mm_md5_starts(&this->md5_context);
			mm_md5_update(&this->md5_context, (md5_uint8 *)pass_word.c_str(), pass_word.length());
			mm_md5_finish(&this->md5_context, digest);

			char mima[33] = { 0 };
			for (size_t i = 0; i < 16; i++)
			{
				sprintf(&mima[2 * i], "%02x", digest[i]);
			}

			c_business_account::signed_in_rq rq;
			rq.set_user_name(user_name.c_str());
			rq.set_password((const char*)mima);
			mm_client_tcps_flush_send_message(&this->p_dog->network.tcp,0, c_business_account::signed_in_rq_msg_id, &rq);
			this->StaticText_notice->setText("Please wait.....");
		}
		else
		{
			this->StaticText_notice->setText("Network unstable, retry later!");
		}

		return false;
	}
	bool KO_dog_login::on_handle_l_s_button_out(const CEGUI::EventArgs& args)
	{
		this->d_flake_context->shutdown();
		return false;
	}
	bool KO_dog_login::on_handle_l_s_button_register(const CEGUI::EventArgs& args)
	{
		if (0 != this->p_dog->data.data_net.lobby.port)
		{
			const CEGUI::String &user_name = this->Editbox_id->getText();
			const CEGUI::String &pass_word = this->Editbox_password->getText();

			md5_uint8 digest[16] = { 0 };
			mm_md5_starts(&this->md5_context);
			mm_md5_update(&this->md5_context, (md5_uint8 *)pass_word.c_str(), pass_word.length());
			mm_md5_finish(&this->md5_context, digest);

			char mima[33] = { 0 };
			for (size_t i = 0; i < 16; i++)
			{
				sprintf(&mima[2*i],"%02x", digest[i]);
			}



			c_business_account::register_rq rq;
			rq.set_user_name(user_name.c_str());
			rq.set_password((const char*)mima);
			mm_client_tcps_flush_send_message(&this->p_dog->network.tcp, 0, c_business_account::register_rq_msg_id, &rq);
			this->StaticText_notice->setText("Please wait.....");
		}
		else
		{
			this->StaticText_notice->setText("Network unstable, retry later!");
		}
		return false;
	}

	bool KO_dog_login::on_handle_MenuWindow_updated(const CEGUI::EventArgs& args)
	{
		return false;
	}

	bool KO_dog_login::on_handle_event_userdata_update(const mm_event_args& args)
	{
		mm::KO_dog_data_user_basic* p_data_user_basic = &this->p_dog->data.data_user_basic;
		if (data_user_token::user_token_finish != p_data_user_basic->token.state)		
		{
			this->StaticText_notice->setText("Error in account or password!");
		}
		else
		{
			this->StaticText_notice->setText("Good luck.");

			mm_event_args evt_ags;
			this->d_event_set.fire_event(KO_dog_login::event_login, evt_ags);
		}
		return false;
	}
	bool KO_dog_login::on_handle_event_log_view(const mm_event_args& args)
	{
		const mm_event_data_log_view& evt = (const mm_event_data_log_view&)args;

		CEGUI::String text_view((const CEGUI::utf8*)evt.view.c_str(), evt.view.size());
		this->StaticText_notice->setText(text_view);
		return false;
	}
	bool KO_dog_login::on_event_enter_background(const mm_event_args& args)
	{
		return false;
	}
	bool KO_dog_login::on_event_enter_foreground(const mm_event_args& args)
	{
		return false;
	}
}