#ifndef __KO_dog_data_net_h__
#define __KO_dog_data_net_h__

#include <string>
#include "core/mm_core.h"
#include "dish/mm_event.h"



#define KO_DOG_DATA_NET_RSA_LENGTH 1024
#define KO_DOG_DATA_NET_RC4_LENGTH 16

namespace mm
{
	class ip_port_state
	{
	public:
		enum enum_socket_state
		{
			net_state_closed = 0,// fd is closed,connect closed.invalid at all.
			net_state_motion = 1,// fd is opened,connect closed.at connecting.
			net_state_finish = 2,// fd is opened,connect opened.at connected.
			net_state_broken = 3,// fd is opened,connect broken.connect is broken fd not closed.
		};
		enum enum_crypto_state
		{
			crypto_state_closed = 0,// tcps is closed,Unencrypted packages are not allowed to be sent.
			crypto_state_finish = 1,// tcps already completed,Unencrypted packages are allowed to be sent.
		};

	public:
		std::string ip;
		mm_ushort_t port;
		int socket_state;

		int crypto_state;

		//ip and port update
		static const std::string event_ip_port_update;

		//the socket update
		static const std::string event_socket_update;

		//crypto state update
		static const std::string event_crypto_update;
	public:
		// this member is event drive.
		mm::mm_event_set d_event_set;


	public:
		ip_port_state();
		~ip_port_state();
	};



	class KO_dog_data_net
	{
	public:
		ip_port_state entry;
		ip_port_state lobby;
		
	//public:
	//	
	//	//ip and port update
	//	static const std::string event_entry_update;
	//	static const std::string event_lobby_update;

	//	//the socket state change
	//	static const std::string event_entry_socket_change;
	//	static const std::string event_lobby_socket_change;

	//	//tcps state change
	//	static const std::string event_entry_crypto_change;
	//	static const std::string event_obby_crypto_change;

	//public:
	//	// this member is event drive.
	//	mm::mm_event_set d_event_set;

	};
}






#endif//__KO_dog_data_net_h__