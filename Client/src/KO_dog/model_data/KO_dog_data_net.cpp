#include "KO_dog_data_net.h"


namespace mm
{
	//struct ip_port_state ///////////////////////////////////////////////////////////////////////////////////

	void ip_port_state_init(struct ip_port_state *p)
	{
		p->ip = "::1"; //ip v6 回环地址
		p->port = 0;
		p->socket_state = ip_port_state::net_state_closed;
	}

	void ip_port_state_destroy(struct ip_port_state *p)
	{
		p->ip = "::1"; //ip v6 回环地址
		p->port = 0;
		p->socket_state = ip_port_state::net_state_closed;
	}

	//struct tcps_connect ///////////////////////////////////////////////////////////////////////////////////

	void tcps_connect_init(struct tcps_connect *p)
	{
		p->public_key = "";
		mm_openssl_rsa_init(&p->openssl_rsa_client);
		mm_openssl_rsa_init(&p->openssl_rsa_server);
		mm_openssl_rc4_init(&p->openssl_rc4);
		mm_openssl_rc4_key_init(&p->openssl_rc4_key);
		p->state = tcps_connect::tcps_state_closed;
		mm_openssl_rc4_srand(&p->openssl_rc4, (mm_uint64_t)time(NULL));
	}

	void tcps_connect_destroy(struct tcps_connect *p)
	{
		p->public_key = "";
		mm_openssl_rsa_destroy(&p->openssl_rsa_client);
		mm_openssl_rsa_destroy(&p->openssl_rsa_server);
		mm_openssl_rc4_destroy(&p->openssl_rc4);
		mm_openssl_rc4_key_destroy(&p->openssl_rc4_key);
		p->state = tcps_connect::tcps_state_closed;
	}

	//class KO_dog_data_net ///////////////////////////////////////////////////////////////////////////////////
	const std::string KO_dog_data_net::event_tcps_state_change("event_tcps_state_change");

	const std::string KO_dog_data_net::event_entry_update("event_entry_update");
	const std::string KO_dog_data_net::event_lobby_update("event_lobby_update");

	const std::string KO_dog_data_net::event_entry_socket_change("event_entry_socket_change");
	const std::string KO_dog_data_net::event_lobby_socket_change("event_lobby_socket_change");

	KO_dog_data_net::KO_dog_data_net()
		: d_event_set()
	{
		ip_port_state_init(&this->entry);
		ip_port_state_init(&this->lobby);
		tcps_connect_init(&this->lobby_tcps);
	}
	KO_dog_data_net::~KO_dog_data_net()
	{
		ip_port_state_destroy(&this->entry);
		ip_port_state_destroy(&this->lobby);
		tcps_connect_destroy(&this->lobby_tcps);

	}

}