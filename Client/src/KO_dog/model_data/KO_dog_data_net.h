#ifndef __KO_dog_data_net_h__
#define __KO_dog_data_net_h__

#include <string>
#include "core/mm_core.h"
#include "dish/mm_event.h"

namespace mm
{
	class KO_dog_data_net
	{
	public:
		enum socket_state 
		{
			net_state_closed = 0,// fd is closed,connect closed.invalid at all.
			net_state_motion = 1,// fd is opened,connect closed.at connecting.
			net_state_finish = 2,// fd is opened,connect opened.at connected.
			net_state_broken = 3,// fd is opened,connect broken.connect is broken fd not closed.
		};

	public:
		std::string entry_ip;
		mm_ushort_t entry_port;
		int entry_socket_state;

		std::string lobby_ip;
		mm_ushort_t lobby_port;
		int lobby_socket_state;

		//ip and port update
		static const std::string event_entry_update;
		static const std::string event_lobby_update;

		//the socket state change
		static const std::string event_entry_socket_change;
		static const std::string event_lobby_socket_change;

		// this member is event drive.
		mm::mm_event_set d_event_set;

	public:

	};
}






#endif//__KO_dog_data_net_h__