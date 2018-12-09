#include "KO_dog_data_net.h"


namespace mm
{
	//ip and port update
	const std::string ip_port_state::event_ip_port_update("event_ip_port_update");

	//the socket update
	const std::string ip_port_state::event_socket_update("event_socket_update");

	//crypto state update
	const std::string ip_port_state::event_crypto_update("event_crypto_update");

	//class ip_port_state ///////////////////////////////////////////////////////////////////////////////////
	ip_port_state::ip_port_state()
		: ip("127.0.0.1")
		, port(0)
		, socket_state(ip_port_state::net_state_closed)
		, crypto_state(ip_port_state::crypto_state_closed)
		, d_event_set()
	{

	}

	ip_port_state::~ip_port_state()
	{

	}














	//struct ip_port_state ///////////////////////////////////////////////////////////////////////////////////

	//void ip_port_state_init(struct ip_port_state *p)
	//{
	//	p->ip = "::1"; //ip v6 回环地址
	//	p->port = 0;
	//	p->socket_state = ip_port_state::net_state_closed;
	//}

	//void ip_port_state_destroy(struct ip_port_state *p)
	//{
	//	p->ip = "::1"; //ip v6 回环地址
	//	p->port = 0;
	//	p->socket_state = ip_port_state::net_state_closed;
	//}


	////class KO_dog_data_net ///////////////////////////////////////////////////////////////////////////////////
	//const std::string KO_dog_data_net::event_tcps_state_change("event_tcps_state_change");

	//const std::string KO_dog_data_net::event_entry_update("event_entry_update");
	//const std::string KO_dog_data_net::event_lobby_update("event_lobby_update");

	//const std::string KO_dog_data_net::event_entry_socket_change("event_entry_socket_change");
	//const std::string KO_dog_data_net::event_lobby_socket_change("event_lobby_socket_change");

	//KO_dog_data_net::KO_dog_data_net()
	//{
	//	ip_port_state_init(&this->entry);
	//	ip_port_state_init(&this->lobby);
	//}
	//KO_dog_data_net::~KO_dog_data_net()
	//{
	//	ip_port_state_destroy(&this->entry);
	//	ip_port_state_destroy(&this->lobby);
	//}

}