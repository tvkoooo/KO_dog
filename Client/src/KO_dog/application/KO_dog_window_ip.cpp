#include "KO_dog_window_ip.h"


#include "CEGUI/System.h"
#include "CEGUI/GUIContext.h"
#include "CEGUI/SchemeManager.h"
#include "CEGUI/WindowManager.h"
#include "CEGUI/RenderingWindow.h"

#include "dish/mm_value.h"

//#include "KO_dog.h"
//#include "network/network_handle.h"
//#include "protodef/cxx/protodef/c_business_account.pb.h"
//
//#include "lua/mm_lua.h"

namespace mm
{
	//KO_dog_window_ip/////////////////////////////////////////////////////////////////////////////////////

	KO_dog_window_ip::KO_dog_window_ip()
		: d_flake_context(NULL)
		, d_surface(NULL)

		, l_layer(NULL)

		, StaticImage_basic(NULL)
		, Label_ip(NULL)
		, StaticImage_rc4(NULL)
		, StaticImage_wifi(NULL)

		, address_name("")
		, p_ip_port_state(NULL)
	{

	}

	KO_dog_window_ip::~KO_dog_window_ip()
	{
		
	}

	void KO_dog_window_ip::set_context(mm_flake_context* d_flake_context, mm_flake_surface* d_surface)
	{
		this->d_flake_context = d_flake_context;
		this->d_surface = d_surface;
	}
	void KO_dog_window_ip::set_l_layer(CEGUI::Window* l_layer)
	{
		this->l_layer = l_layer;
	}
	void KO_dog_window_ip::set_data_model_name(const std::string& name)
	{
		this->address_name = name;
	}
	void KO_dog_window_ip::set_data_model(ip_port_state* d)
	{
		//1 解绑事件
		if (NULL != this->p_ip_port_state)
		{			
			this->p_ip_port_state->d_event_set.unsubscribe_event(ip_port_state::event_ip_port_update, this->d_event_ip_port_update_conn);
			this->p_ip_port_state->d_event_set.unsubscribe_event(ip_port_state::event_socket_update, this->d_event_socket_update_conn);
			this->p_ip_port_state->d_event_set.unsubscribe_event(ip_port_state::event_crypto_update, this->d_event_crypto_update_conn);
		}
		//2 赋新的模组数据
		this->p_ip_port_state = d;
		//3 绑定事件
		if (NULL != this->p_ip_port_state)
		{
			this->d_event_ip_port_update_conn = this->p_ip_port_state->d_event_set.subscribe_event(ip_port_state::event_ip_port_update, &KO_dog_window_ip::on_handle_event_ip_port_update, this);
			this->d_event_socket_update_conn = this->p_ip_port_state->d_event_set.subscribe_event(ip_port_state::event_socket_update, &KO_dog_window_ip::on_handle_event_socket_update, this);
			this->d_event_crypto_update_conn = this->p_ip_port_state->d_event_set.subscribe_event(ip_port_state::event_crypto_update, &KO_dog_window_ip::on_handle_event_crypto_update, this);

			//default Initialization
			mm_event_args args;
			this->on_handle_event_ip_port_update(args);
			this->on_handle_event_socket_update(args);
			this->on_handle_event_crypto_update(args);
		}
	}

	void KO_dog_window_ip::scene_layer_launching()
	{
		struct mm_logger* g_logger = mm_logger_instance();
		//////////////////////////////////////////////////////////////////////////
		this->StaticImage_basic = this->l_layer->getChild("StaticImage_basic");
		this->Label_ip = this->StaticImage_basic->getChild("Label_ip");
		this->StaticImage_rc4 = this->StaticImage_basic->getChild("StaticImage_rc4");
		this->StaticImage_wifi = this->StaticImage_basic->getChild("StaticImage_wifi");
		////////////////////////////////////////////////////////////////////////////////
	}

	void KO_dog_window_ip::scene_layer_terminate()
	{
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		_window_manager->destroyWindow(this->l_layer);
	}

	bool KO_dog_window_ip::on_handle_event_ip_port_update(const mm_event_args& args)
	{
		this->Label_ip->setText(this->address_name + " " + this->p_ip_port_state->ip + ":" + mm_value::to_string(this->p_ip_port_state->port));
		return false;
	}
	bool KO_dog_window_ip::on_handle_event_socket_update(const mm_event_args& args)
	{
			//net_state_closed = 0,// gray
			//net_state_motion = 1,// blue
			//net_state_finish = 2,// green
			//net_state_broken = 3,// red

		static const CEGUI::Colour c[4] = 
		{
			CEGUI::Colour((CEGUI::argb_t)0xff7d7d7d),
			CEGUI::Colour((CEGUI::argb_t)0xff0000ff),
			CEGUI::Colour((CEGUI::argb_t)0xff00ff00),
			CEGUI::Colour((CEGUI::argb_t)0xffff0000),
		};
		int s = this->p_ip_port_state->socket_state;
		assert(ip_port_state::net_state_closed <= s && s <= ip_port_state::net_state_broken  && "Invalid enumeration");

		/*CEGUI::Colour c(1,0,0,1);*/
		CEGUI::ColourRect cr(c[s]);
		this->StaticImage_wifi->setProperty("ImageColours", CEGUI::PropertyHelper<CEGUI::ColourRect>::toString(cr));
		return false;
	}
	bool KO_dog_window_ip::on_handle_event_crypto_update(const mm_event_args& args)
	{
		if (ip_port_state::crypto_state_finish == this->p_ip_port_state->crypto_state)
		{
			this->StaticImage_rc4->setVisible(true);
		}
		else
		{
			this->StaticImage_rc4->setVisible(false);
		}		
		return false;
	}


}