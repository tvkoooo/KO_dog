#ifndef __KO_dog_data_h__
#define __KO_dog_data_h__

#include "KO_dog_data_net.h"
#include "KO_dog_data_user_basic.h"
#include "KO_dog_data_log_view.h"

namespace mm
{

	

	class KO_dog_data
	{
		
	public:
		KO_dog_data_net data_net;
		KO_dog_data_user_basic data_user_basic;
		KO_dog_data_log_view data_log_view;
	public:

		void thread_handle();


	};

	
}






#endif//__KO_dog_data_h__