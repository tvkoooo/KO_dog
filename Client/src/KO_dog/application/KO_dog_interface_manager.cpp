#include "KO_dog_interface_manager.h"


#include "CEGUI/System.h"
#include "CEGUI/GUIContext.h"
#include "CEGUI/SchemeManager.h"
#include "CEGUI/WindowManager.h"
#include "CEGUI/RenderingWindow.h"
#include "CEGUI/WindowFactoryManager.h"

#include "KO_dog_window_ip.h"
#include "application/KO_dog.h"

#include "network/network_handle.h"
#include "protodef/cxx/protodef/c_business_relation.pb.h"


namespace mm
{
	KO_dog_interface_manager::KO_dog_interface_manager()
		: d_flake_context(NULL)
		, d_surface(NULL)

		, l_home_lj_interface_manager(NULL)
		, l_home_lj_login(NULL)
		, l_layer_dog_window_ip_entry(NULL)
		, l_layer_dog_window_ip_lobby(NULL)
		, l_layer_dog_a1(NULL)
		, l_home_lj_mailbox(NULL)
		//, l_home_lj_mailbox_search(NULL)

		, DefaultWindow(NULL)
		, DefaultWindow_entry(NULL)
		, DefaultWindow_lobby(NULL)

		, window_ip_entry()
		, window_ip_lobby()
		, zhujiemian()
		, mailbox()
	{

	}

	KO_dog_interface_manager::~KO_dog_interface_manager()
	{

	}
	void KO_dog_interface_manager::assign_flake_context(mm_flake_context* flake_context)
	{
		this->d_flake_context = flake_context;
	}

	void KO_dog_interface_manager::on_finish_launching(mm_flake_surface* surface)
	{
		this->d_surface = surface;
		/////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////
		CEGUI::GUIContext* _gui_context = this->d_surface->d_gui_context;
		//////////////////////////////////////////////////////////////////////////
		int index = 0;
		char index_string[64] = { 5 };
		mm_sprintf(index_string, "_%d", index);

		std::string system_font_18_name = "system_font_18";
		system_font_18_name = system_font_18_name + index_string;
		//////////////////////////////////////////////////////////////////////////
		// CEGUI relies on various systems being set-up, so this is what we do
		// here first.
		//
		// The first thing to do is load a CEGUI 'scheme' this is basically a file
		// that groups all the required resources and definitions for a particular
		// skin so they can be loaded / initialised easily
		//
		// So, we use the SchemeManager singleton to load in a scheme that loads the
		// imagery and registers widgets for the TaharezLook skin.  This scheme also
		// loads in a font that gets used as the system default.
		CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme");

		// create the default surface font.
		CEGUI::Font& _defaultFont = this->d_flake_context->d_cegui_system.create_system_font_by_size(this->d_surface->get_canvas_size(), system_font_18_name.c_str(), 18.0f);

		// The next thing we do is to set a default mouse cursor image.  This is
		// not strictly essential, although it is nice to always have a visible
		// cursor if a window or widget does not explicitly set one of its own.
		//
		// The TaharezLook Imageset contains an Image named "MouseArrow" which is
		// the ideal thing to have as a defult mouse cursor image.
		_gui_context->getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");

		// load font and setup default if not loaded via scheme
		// Set default font for the gui context
		_gui_context->setDefaultFont(&_defaultFont);

		// Create an Interface Manager,Mount all layers		
		struct mm_logger* g_logger = mm_logger_instance();
		//////////////////////////////////////////////////////////////////////////
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();

		// Manager Mount resources
		{
			//0 Mouse not displayed
			_gui_context->getMouseCursor().setVisible(false);
			//1 Load Picture resources
			this->l_home_lj_interface_manager = _window_manager->loadLayoutFromFile("l_home_lj_interface_manager.layout");
			this->l_home_lj_login = _window_manager->loadLayoutFromFile("l_home_lj_login.layout");
			this->l_layer_dog_window_ip_entry = _window_manager->loadLayoutFromFile("l_layer_dog_window_ip.layout");
			this->l_layer_dog_window_ip_lobby = _window_manager->loadLayoutFromFile("l_layer_dog_window_ip.layout");
			this->l_layer_dog_a1 = _window_manager->loadLayoutFromFile("l_layer_dog_a1.layout");
			this->l_home_lj_mailbox = _window_manager->loadLayoutFromFile("l_home_lj_mailbox.layout");
			//this->l_home_lj_mailbox_search = _window_manager->loadLayoutFromFile("l_home_lj_mailbox_search.layout");
			//2 Manager mounts resources
			this->DefaultWindow = this->l_home_lj_interface_manager->getChild("DefaultWindow");
			this->DefaultWindow_entry = this->l_home_lj_interface_manager->getChild("DefaultWindow_entry");
			this->DefaultWindow_lobby = this->l_home_lj_interface_manager->getChild("DefaultWindow_lobby");
			this->DefaultWindow_entry->addChild(this->l_layer_dog_window_ip_entry);
			this->DefaultWindow_lobby->addChild(this->l_layer_dog_window_ip_lobby);

			//this->DefaultWindow->addChild(this->l_home_lj_login);
			//3 Control tiling resources : URect {{0, 0}, {0, 0}, {1, 0}, {1, 0}}   Pull-up enlargement of the whole image
			CEGUI::URect  ur = { {0, 0}, {0, 0}, {1, 0}, {1, 0} };
			this->l_layer_dog_window_ip_entry->setArea(ur);
			this->l_layer_dog_window_ip_lobby->setArea(ur);
			this->l_home_lj_login->setArea(ur);
			//this->l_home_lj_login->setVisible(false);
			//4 setRootWindow 			
			_gui_context->setRootWindow(this->l_home_lj_interface_manager);
			//5 Set up layers
			mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
			mm::KO_dog_data_user_basic* p_user_basic = &p_dog->data.data_user_basic;
			{
				
				ip_port_state* ip_port_state_entry = &p_dog->data.data_net.entry;
				ip_port_state* ip_port_state_lobby = &p_dog->data.data_net.lobby;
				////////////////////////////////////////////////////////////////////////////////
				//Set up layers entry
				this->window_ip_entry.set_data_model_name("entry");
				this->window_ip_entry.set_l_layer(this->l_layer_dog_window_ip_entry);
				this->window_ip_entry.scene_layer_launching();
				this->window_ip_entry.set_data_model(ip_port_state_entry);
				//Set up layers lobby
				this->window_ip_lobby.set_data_model_name("lobby");
				this->window_ip_lobby.set_l_layer(this->l_layer_dog_window_ip_lobby);
				this->window_ip_lobby.scene_layer_launching();
				this->window_ip_lobby.set_data_model(ip_port_state_lobby);
				//Set up layers zhujiemian
				this->zhujiemian.set_data(this->d_flake_context, this->d_surface);
				this->zhujiemian.set_l_layer(this->l_home_lj_login);
				this->zhujiemian.on_finish_launching();
				//Set up layers test_animation
				this->test_animation.set_data(this->d_flake_context, this->d_surface);
				this->test_animation.set_l_layer(this->l_layer_dog_a1);
				this->test_animation.on_finish_launching();
				//Set up layers l_home_lj_mailbox
				this->mailbox.set_data(this->d_flake_context, this->d_surface);
				this->mailbox.set_l_layer(this->l_home_lj_mailbox);
				this->mailbox.on_finish_launching();
				////Set up layers l_home_lj_mailbox_search
				//this->mailbox_search.set_data(this->d_flake_context, this->d_surface);
				//this->mailbox_search.set_l_layer(this->l_home_lj_mailbox_search);
				//this->mailbox_search.on_finish_launching();
			}
			this->DefaultWindow->addChild(this->l_home_lj_login);
			this->DefaultWindow->addChild(this->l_home_lj_mailbox);
			this->DefaultWindow->addChild(this->l_layer_dog_a1);
			//this->mailbox.DefaultWindow_right->addChild(this->l_home_lj_mailbox_search);

			this->l_home_lj_mailbox->setVisible(false);
			this->l_layer_dog_a1->setVisible(false);
			//this->mailbox.DefaultWindow_right->setVisible(false);

			//this->test_animation.setVisible(false);

			//6 Binding Home Screen Push Event
			this->d_event_closed_conn = this->mailbox.d_event_set.subscribe_event(KO_dog_mailbox::event_quit, &KO_dog_interface_manager::on_handle_closed, this);
			this->d_event_game_conn = this->mailbox.d_event_set.subscribe_event(KO_dog_mailbox::event_game, &KO_dog_interface_manager::on_handle_game, this);
			this->d_event_game_quit_conn = this->test_animation.d_event_set.subscribe_event(KO_dog_test_animation::event_close, &KO_dog_interface_manager::on_handle_game_quit, this);
			this->d_event_l_zhujiemian_login_conn = this->zhujiemian.d_event_set.subscribe_event(KO_dog_zhujiemian::event_login, &KO_dog_interface_manager::on_handle_l_zhujiemian_login, this);
			
			this->d_event_userdata_user_token_update_conn = p_user_basic->d_event_set.subscribe_event(KO_dog_data_user_basic::event_userdata_user_token_update, &KO_dog_interface_manager::on_handle_userdata_user_token_update, this);
		}


		// zhujiemian on_finish_launching
		//this->zhujiemian.set_data(this->d_flake_context,this->d_surface);
		//this->zhujiemian.on_finish_launching();
	}
	void KO_dog_interface_manager::on_before_terminate(mm_flake_surface* surface)
	{
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_user_basic = &p_dog->data.data_user_basic;

		p_user_basic->d_event_set.unsubscribe_event(KO_dog_data_user_basic::event_userdata_user_token_update, this->d_event_userdata_user_token_update_conn);

		this->zhujiemian.d_event_set.unsubscribe_event(KO_dog_zhujiemian::event_login, this->d_event_l_zhujiemian_login_conn);
		this->mailbox.d_event_set.unsubscribe_event(KO_dog_mailbox::event_quit, this->d_event_closed_conn);

		//this->mailbox.DefaultWindow_right->removeChild(this->l_home_lj_mailbox_search);
		this->DefaultWindow->removeChild(this->l_layer_dog_a1);
		this->DefaultWindow->removeChild(this->l_home_lj_mailbox);
		this->DefaultWindow->removeChild(this->l_home_lj_login);

		this->DefaultWindow_entry->removeChild(this->l_layer_dog_window_ip_entry);
		this->DefaultWindow_lobby->removeChild(this->l_layer_dog_window_ip_lobby);

		//destroy layers
		{
			//destroy layers mailbox_search
			//this->mailbox_search.on_before_terminate();
			//destroy layers mailbox
			this->mailbox.on_before_terminate();
			//destroy layers test_animation
			this->test_animation.on_before_terminate();
			//destroy layers zhujiemian
			this->zhujiemian.on_before_terminate();
			//destroy layers lobby
			this->window_ip_lobby.scene_layer_terminate();
			this->window_ip_lobby.set_data_model(NULL);
			//destroy layers entry
			this->window_ip_entry.scene_layer_terminate();
			this->window_ip_entry.set_data_model(NULL);
		}
		//this->zhujiemian.on_before_terminate();
		//
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		//_window_manager->destroyWindow(this->l_home_lj_mailbox_search);
		_window_manager->destroyWindow(this->l_home_lj_mailbox);
		_window_manager->destroyWindow(this->l_layer_dog_a1);
		_window_manager->destroyWindow(this->l_layer_dog_window_ip_lobby);
		_window_manager->destroyWindow(this->l_layer_dog_window_ip_entry);
		_window_manager->destroyWindow(this->l_home_lj_login);

		_window_manager->cleanDeadPool();
		//
		struct mm_logger* g_logger = mm_logger_instance();
		mm_logger_log_I(g_logger, "KO_dog_zhujiemian::%s %d success.", __FUNCTION__, __LINE__);
		CEGUI::SchemeManager::getSingleton().destroy("TaharezLook");
	}

	bool KO_dog_interface_manager::on_handle_closed(const mm_event_args& args)
	{
		//清空 l_home_lj_mailbox 逻辑资源
		this->mailbox.clear_data_before_terminate();
		this->l_home_lj_mailbox->setVisible(false);
		this->l_home_lj_login->setVisible(true);
		return false;
	}
	bool KO_dog_interface_manager::on_handle_game(const mm_event_args& args)
	{
		this->l_home_lj_mailbox->setVisible(false);
		this->l_layer_dog_a1->setVisible(true);
		return false;
	}
	bool KO_dog_interface_manager::on_handle_game_quit(const mm_event_args& args)
	{
		this->l_layer_dog_a1->setVisible(false);
		this->l_home_lj_mailbox->setVisible(true);
		return false;
	}
	bool KO_dog_interface_manager::on_handle_l_zhujiemian_login(const mm_event_args& args)
	{
		mm::KO_dog* p = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_data_user_basic = &p->data.data_user_basic;
		struct data_user_basic* u_basic = &p_data_user_basic->basic;

		this->l_home_lj_mailbox->setVisible(true);
		this->l_home_lj_login->setVisible(false);
		//登录后需要更新服务器好友关系列表
		c_business_relation::query_friends_rq rq;
		rq.set_user_myself_id(u_basic->id);
		mm_client_tcps_flush_send_message(&p->network.tcp, u_basic->id, c_business_relation::query_friends_rq_msg_id, &rq);
		//登录后需要更新服务器好友申请列表
		c_business_relation::query_friends_apply_rq rq1;
		rq1.set_user_myself_id(u_basic->id);
		mm_client_tcps_flush_send_message(&p->network.tcp, u_basic->id, c_business_relation::query_friends_apply_rq_msg_id, &rq1);

		return false;
	}
	bool KO_dog_interface_manager::on_handle_userdata_user_token_update(const mm_event_args& args)
	{
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_user_basic = &p_dog->data.data_user_basic;
		if (data_user_token::user_token_closed == p_user_basic->token.state  )
		{
			//清空 l_home_lj_mailbox 逻辑资源
			this->mailbox.clear_data_before_terminate();
			this->l_home_lj_mailbox->setVisible(false);
			this->l_home_lj_login->setVisible(true);
		}
		return false;
	}
}