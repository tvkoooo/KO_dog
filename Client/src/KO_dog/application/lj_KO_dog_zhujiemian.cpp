#include "lj_KO_dog_zhujiemian.h"


#include "CEGUI/System.h"
#include "CEGUI/GUIContext.h"
#include "CEGUI/SchemeManager.h"
#include "CEGUI/WindowManager.h"
#include "CEGUI/RenderingWindow.h"

namespace mm
{
	lj_KO_dog_zhujiemian::lj_KO_dog_zhujiemian()
		: d_flake_context(NULL)
		, d_surface(NULL)
		, d_window_login(NULL)
		, l_home_lj_login(NULL)
		, MenuWindow(NULL)
		, l_edit_text_id(NULL)
		, l_s_button_login(NULL)
		, l_s_button_out(NULL)
		, l_edit_text_pwd(NULL)
		, l_s_button_register(NULL)
		, l_text_id(NULL)
		, l_text_pwd(NULL)
		, l_text_notice(NULL)
		, StaticImage(NULL)
	{

	}

	lj_KO_dog_zhujiemian::~lj_KO_dog_zhujiemian()
	{

	}

	void lj_KO_dog_zhujiemian::set_data(mm_flake_context* d_flake_context, mm_flake_surface* d_surface)
	{
		this->d_flake_context = d_flake_context;
		this->d_surface = d_surface;
	}

	void lj_KO_dog_zhujiemian::on_finish_launching()
	{
		this->scene_layer_launching();
	}
	void lj_KO_dog_zhujiemian::on_before_terminate()
	{
		this->scene_layer_terminate();
		struct mm_logger* g_logger = mm_logger_instance();
		mm_logger_log_I(g_logger, "lj_KO_dog_zhujiemian::%s %d success.", __FUNCTION__, __LINE__);

	}
	void lj_KO_dog_zhujiemian::scene_layer_launching()
	{
		struct mm_logger* g_logger = mm_logger_instance();
		//////////////////////////////////////////////////////////////////////////
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();

		this->d_window_login = (CEGUI::Window*)_window_manager->createWindow("DefaultWindow", "root_window_0");
		this->l_home_lj_login = _window_manager->loadLayoutFromFile("l_home_lj_login.layout");

		this->MenuWindow = this->l_home_lj_login->getChild("MenuWindow");
		this->l_edit_text_id = this->MenuWindow->getChild("l_edit_text_id");
		this->l_s_button_login = this->MenuWindow->getChild("l_s_button_login");
		this->l_s_button_out = this->MenuWindow->getChild("l_s_button_out");
		this->l_edit_text_pwd = this->MenuWindow->getChild("l_edit_text_pwd");
		this->l_s_button_register = this->MenuWindow->getChild("l_s_button_register");
		this->l_text_id = this->MenuWindow->getChild("l_text_id");
		this->l_text_pwd = this->MenuWindow->getChild("l_text_pwd");
		this->l_text_notice = this->MenuWindow->getChild("l_text_notice");
		this->StaticImage = this->l_home_lj_login->getChild("StaticImage");


		this->l_text_id->setText("Your ID");
		this->l_text_pwd->setText("Your password");
		//this->l_ensure->setVisible(false);
		CEGUI::GUIContext* _gui_context = this->d_surface->d_gui_context;
		this->d_window_login->addChild(this->l_home_lj_login);

		_gui_context->setRootWindow(this->d_window_login);
		_gui_context->getMouseCursor().setVisible(false);

		this->l_s_button_login->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&lj_KO_dog_zhujiemian::on_handle_l_s_button_login, this));
		this->l_s_button_out->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&lj_KO_dog_zhujiemian::on_handle_l_s_button_out, this));
		this->l_s_button_register->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&lj_KO_dog_zhujiemian::on_handle_l_s_button_register, this));

		this->d_event_l_animation_closed_conn = this->test_animation.d_event_set.subscribe_event(KO_dog_test_animation::event_close, &lj_KO_dog_zhujiemian::on_handle_l_animation_closed, this);
		//////////////////////////////////////////////////////////////////////
		do
		{
			std::ifstream user_info_map;
			mm_logger_log_I(g_logger, "lj_KO_dog_zhujiemian::%s %d success.", __FUNCTION__, __LINE__);
			user_info_map.open("user_info.daSB");
			if (user_info_map.fail())
			{
				break;
			}
			while (!user_info_map.eof())
			{
				std::string key;
				std::string value;
				user_info_map >> key >> value;
				if (key != "")
				{
					this->user_info.insert(lj_type_map_string_string::value_type(key, value));
				}

			}
			user_info_map.close();
		} while (0);
		////////////////////////////////////////////////////////////////////////
	}
	void lj_KO_dog_zhujiemian::scene_layer_terminate()
	{
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		_window_manager->destroyWindow(this->l_home_lj_login);
		_window_manager->destroyWindow(this->d_window_login);
	}

	bool lj_KO_dog_zhujiemian::on_handle_l_s_button_login(const CEGUI::EventArgs& args)
	{
		std::string user_name = this->l_edit_text_id->getText().c_str();
		std::string pass_word = this->l_edit_text_pwd->getText().c_str();

		lj_type_map_string_string::iterator it;
		it = this->user_info.find(user_name);
		if (it == this->user_info.end())
		{
			//没有找到
			this->l_text_notice->setText("You haven't applied this yet");
		}
		else
		{
			//找到
			if (it->second != pass_word)
			{
				this->l_text_notice->setText("The password error");
			}
			else
			{
				this->l_text_notice->setText("Good luck");
				//mm_msleep(1000);
				this->test_animation.assign_flake_context(this->d_flake_context);
				this->test_animation.on_finish_launching(this->d_surface);
			}

		}
		return false;
	}
	bool lj_KO_dog_zhujiemian::on_handle_l_s_button_out(const CEGUI::EventArgs& args)
	{		
		this->d_flake_context->shutdown();
		return false;
	}
	bool lj_KO_dog_zhujiemian::on_handle_l_s_button_register(const CEGUI::EventArgs& args)
	{
		std::string user_name = this->l_edit_text_id->getText().c_str();
		std::string pass_word = this->l_edit_text_pwd->getText().c_str();
		
		lj_type_map_string_string::iterator it;
		it = this->user_info.find(user_name);
		if (it == this->user_info.end())
		{
			//没有找到
			this->user_info.insert(lj_type_map_string_string::value_type(user_name, pass_word));
			std::ofstream user_info_map;
			user_info_map.open("user_info.daSB", std::ofstream::app);
			user_info_map << user_name << "\t" << pass_word << std::endl;
			user_info_map.close();
		}
		else
		{
			//找到
			this->l_text_notice->setText("you have register !");
		}
		return false;
	}

	bool lj_KO_dog_zhujiemian::on_handle_l_animation_closed(const mm_event_args& args)
	{
		this->test_animation.on_before_terminate(this->d_surface);
		CEGUI::GUIContext* _gui_context = this->d_surface->d_gui_context;
		_gui_context->setRootWindow(this->d_window_login);
		return false;
	}

}