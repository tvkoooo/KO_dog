#ifndef __KO_dog_data_h__
#define __KO_dog_data_h__

#include "KO_dog_data_net.h"

namespace mm
{

	

	class KO_dog_data
	{
	public:
		static const std::string entry_ip_default;
		static const mm_ushort_t entry_port_default;

	public:
		KO_dog_data_net data_net;

	public:
		void set_entry_cofig(std::string entry_ip, mm_ushort_t entry_port);

	};

	
}






#endif//__KO_dog_data_h__