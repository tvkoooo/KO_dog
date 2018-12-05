#ifndef __KO_dog_data_net_h__
#define __KO_dog_data_net_h__

#include <string>
#include "core/mm_core.h"
#include "dish/mm_event.h"

#include "openssl/mm_openssl_rsa.h"
#include "openssl/mm_openssl_rc4.h"

#define KO_DOG_DATA_NET_RSA_LENGTH 1024
#define KO_DOG_DATA_NET_RC4_LENGTH 16

namespace mm
{
	struct ip_port_state
	{
		enum socket_state 
		{
			net_state_closed = 0,// fd is closed,connect closed.invalid at all.
			net_state_motion = 1,// fd is opened,connect closed.at connecting.
			net_state_finish = 2,// fd is opened,connect opened.at connected.
			net_state_broken = 3,// fd is opened,connect broken.connect is broken fd not closed.
		};
		std::string ip;
		mm_ushort_t port;
		int socket_state;
	};
	void ip_port_state_init(struct ip_port_state *p);
	void ip_port_state_destroy(struct ip_port_state *p);

	struct tcps_connect
	{
		enum tcps_state 
		{
			tcps_state_closed = 0,// tcps is closed,Unencrypted packages are not allowed to be sent.
			tcps_state_finish = 1,// tcps already completed,Unencrypted packages are allowed to be sent.
		};
		std::string public_key;
		struct mm_openssl_rsa openssl_rsa_client;
		struct mm_openssl_rsa openssl_rsa_server;
		struct mm_openssl_rc4 openssl_rc4;
		struct mm_openssl_rc4_key openssl_rc4_key;
		int state;
	};
	void tcps_connect_init(struct tcps_connect *p);
	void tcps_connect_destroy(struct tcps_connect *p);





	class KO_dog_data_net
	{
	public:
		struct ip_port_state entry;
		struct ip_port_state lobby;

	public:
		struct tcps_connect lobby_tcps;

	public:
		//tcps state change
		static const std::string event_tcps_state_change;


		//ip and port update
		static const std::string event_entry_update;
		static const std::string event_lobby_update;

		//the socket state change
		static const std::string event_entry_socket_change;
		static const std::string event_lobby_socket_change;
	public:
		// this member is event drive.
		mm::mm_event_set d_event_set;

	public:
		KO_dog_data_net();
		~KO_dog_data_net();

	};
}






#endif//__KO_dog_data_net_h__