#ifndef __KO_dog_window_ip_h__
#define __KO_dog_window_ip_h__

#include "CEGUI/Window.h"

#include "core/mm_core.h"

#include "flake/mm_flake_surface.h"

#include "dish/mm_event.h"

#include "model_data/KO_dog_data_net.h"

//////////////////////////////////////////////////////////////////////////
namespace mm
{
	class KO_dog_window_ip
	{
	//public:
		mm_flake_context* d_flake_context;         //Input Weak reference
		mm_flake_surface* d_surface;               //Input Weak reference

	//public:
		CEGUI::Window* l_layer;                    //Input Weak reference
		//
		CEGUI::Window* StaticImage_basic;          //Get Weak reference
		CEGUI::Window* Label_ip;				   //Get Weak reference
		CEGUI::Window* StaticImage_rc4;            //Get Weak reference
		CEGUI::Window* StaticImage_wifi;           //Get Weak reference
		//

	//public:
		std::string address_name;
		ip_port_state* p_ip_port_state;

	//public:
		mm_event_handler d_event_ip_port_update_conn;
		mm_event_handler d_event_socket_update_conn;
		mm_event_handler d_event_crypto_update_conn;

	public:
		KO_dog_window_ip();
		virtual ~KO_dog_window_ip();

	public:
		void set_context(mm_flake_context* d_flake_context, mm_flake_surface* d_surface);
		void set_l_layer(CEGUI::Window* l_layer);
		void set_data_model_name(const std::string& name);
		void set_data_model(ip_port_state* d);
	public:
		void scene_layer_launching();
		void scene_layer_terminate();

	public:		
		bool on_handle_event_ip_port_update(const mm_event_args& args);
		bool on_handle_event_socket_update(const mm_event_args& args);
		bool on_handle_event_crypto_update(const mm_event_args& args);
	};
}
//////////////////////////////////////////////////////////////////////////


#endif//__KO_dog_window_ip_h__