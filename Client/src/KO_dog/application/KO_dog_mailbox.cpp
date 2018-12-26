#include "KO_dog_mailbox.h"


#include "CEGUI/System.h"
#include "CEGUI/GUIContext.h"
#include "CEGUI/SchemeManager.h"
#include "CEGUI/WindowManager.h"
#include "CEGUI/RenderingWindow.h"

#include "CEGUI/widgets/Listbox.h"

#include "KO_dog.h"
#include "network/network_handle.h"
#include "protodef/cxx/protodef/c_business_account.pb.h"

namespace mm
{
	const std::string KO_dog_mailbox::event_quit("event_quit");
	const std::string KO_dog_mailbox::event_game("event_game");

	KO_dog_mailbox::KO_dog_mailbox()
		: d_flake_context(NULL)
		, d_surface(NULL)

		, l_home_lj_mailbox(NULL)

		//, l_layer_dog_a1(NULL)
		, l_home_lj_mailbox_search(NULL)

		, StaticImage_basic(NULL)
		, DefaultWindow_left(NULL)
		, Button_search(NULL)
		, Listbox_friend(NULL)
		, Button_game(NULL)
		, Listbox_group(NULL)
		, Button_quit(NULL)
		, DefaultWindow_right(NULL)
	{
		
	}

	KO_dog_mailbox::~KO_dog_mailbox()
	{
		
	}

	void KO_dog_mailbox::set_data(mm_flake_context* d_flake_context, mm_flake_surface* d_surface)
	{
		this->d_flake_context = d_flake_context;
		this->d_surface = d_surface;		
	}
	void KO_dog_mailbox::set_l_layer(CEGUI::Window* l_layer)
	{
		this->l_home_lj_mailbox = l_layer;
	}
	void KO_dog_mailbox::on_finish_launching()
	{
		struct mm_logger* g_logger = mm_logger_instance();
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		//////////////////////////////////////////////////////////////////////////
		//this->l_layer_dog_a1 = _window_manager->loadLayoutFromFile("l_layer_dog_a1.layout");
		this->l_home_lj_mailbox_search = _window_manager->loadLayoutFromFile("l_home_lj_mailbox_search.layout");
		//////////////////////////////////////////////////////////////////////////
		this->StaticImage_basic = this->l_home_lj_mailbox->getChild("StaticImage_basic");
		this->DefaultWindow_left = this->l_home_lj_mailbox->getChild("DefaultWindow_left");
		this->Button_search = this->DefaultWindow_left->getChild("Button_search");
		this->Listbox_friend = this->DefaultWindow_left->getChild("Listbox_friend");
		this->Button_game = this->DefaultWindow_left->getChild("Button_game");
		this->Listbox_group = this->DefaultWindow_left->getChild("Listbox_group");
		this->Button_quit = this->DefaultWindow_left->getChild("Button_quit");
		this->DefaultWindow_right = this->l_home_lj_mailbox->getChild("DefaultWindow_right");
		////////////////////////////////////////////////////////////////////////////////
		//Set up layers test_animation
		//this->test_animation.set_data(this->d_flake_context, this->d_surface);
		//this->test_animation.set_l_layer(this->l_layer_dog_a1);
		//this->test_animation.on_finish_launching();
		//Set up layers l_home_lj_mailbox_search
		this->mailbox_search.set_data(this->d_flake_context, this->d_surface);
		this->mailbox_search.set_l_layer(this->l_home_lj_mailbox_search);
		this->mailbox_search.on_finish_launching();
		////////////////////////////////////////////////////////////////////////////////
		//this->DefaultWindow_right->addChild(this->l_layer_dog_a1);
		this->DefaultWindow_right->addChild(this->l_home_lj_mailbox_search);
		CEGUI::URect  ur = { {0, 0}, {0, 0}, {1, 0}, {1, 0} };
		//this->l_layer_dog_a1->setArea(ur);
		this->l_home_lj_mailbox_search->setArea(ur);
		////////////////////////////////////////////////////////////////////////////////
		//this->l_layer_dog_a1->setVisible(false);
		this->l_home_lj_mailbox_search->setVisible(false);
		////////////////////////////////////////////////////////////////////////////////

		this->Button_search->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Button_search, this));
		this->Listbox_friend->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Listbox_friend, this));
		this->Button_game->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Button_game, this));
		this->Button_quit->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Button_quit, this));

	}
	void KO_dog_mailbox::on_before_terminate()
	{
		////////////////////////////////////////////////////////////////////////////////
		this->DefaultWindow_right->removeChild(this->l_home_lj_mailbox_search);
		//this->DefaultWindow_right->removeChild(this->l_layer_dog_a1);
		////////////////////////////////////////////////////////////////////////////////
		//destroy layers mailbox_search
		//this->mailbox_search.on_before_terminate();
		//destroy layers test_animation
/*		if ( 1 == this->test_animation.flag)
		{
			this->test_animation.flag = 0;
			this->test_animation.on_before_terminate();
		}*/		
		////////////////////////////////////////////////////////////////////////////////
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		_window_manager->destroyWindow(this->l_home_lj_mailbox_search);
		//_window_manager->destroyWindow(this->l_layer_dog_a1);
		////////////////////////////////////////////////////////////////////////////////

		struct mm_logger* g_logger = mm_logger_instance();
		mm_logger_log_I(g_logger, "KO_dog_mailbox::%s %d success.", __FUNCTION__, __LINE__);
	}

	bool KO_dog_mailbox::on_handle_Button_search(const CEGUI::EventArgs& args)
	{
		this->l_home_lj_mailbox_search->setVisible(true);
		return false;
	}

	bool KO_dog_mailbox::on_handle_Listbox_friend(const CEGUI::EventArgs& args)
	{
		this->l_home_lj_mailbox_search->setVisible(false);
		return false;
	}
	bool KO_dog_mailbox::on_handle_Button_game(const CEGUI::EventArgs& args)
	{
		this->l_home_lj_mailbox_search->setVisible(false);
		mm_event_args evt_ags;
		this->d_event_set.fire_event(KO_dog_mailbox::event_game, evt_ags);
		return false;
	}
	bool KO_dog_mailbox::on_handle_Button_quit(const CEGUI::EventArgs& args)
	{
		this->l_home_lj_mailbox_search->setVisible(false);
		mm_event_args evt_ags;
		this->d_event_set.fire_event(KO_dog_mailbox::event_quit, evt_ags);
		return false;
	}
}