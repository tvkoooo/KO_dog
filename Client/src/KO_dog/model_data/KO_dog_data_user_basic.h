#ifndef __KO_dog_data_user_basic_h__
#define __KO_dog_data_user_basic_h__

#include <string>
#include "core/mm_core.h"
#include "dish/mm_event.h"

namespace mm
{
	class KO_dog_data_user_basic
	{
	public:
		std::string name;// �û���.
		mm_uint64_t id;// �û�id.
		std::string token;// �û���.

		static const std::string event_userdata_update;
		// this member is event drive.
		mm::mm_event_set d_event_set;

	public:

	};
}






#endif//__KO_dog_data_user_basic_h__