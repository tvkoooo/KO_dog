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
		std::string entry_ip;
		mm_ushort_t entry_port;

		std::string lobby_ip;
		mm_ushort_t lobby_port;

		static const std::string event_entry_update;
		static const std::string event_lobby_update;
		// this member is event drive.
		mm::mm_event_set d_event_set;

	public:

	};
}






#endif//__KO_dog_data_net_h__