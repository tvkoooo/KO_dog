#ifndef __KO_dog_data_log_view_h__
#define __KO_dog_data_log_view_h__

#include <string>
#include "core/mm_core.h"
#include "dish/mm_event.h"

#include "KO_dog_data_log_error_code_map.h"

namespace mm
{
	class mm_event_data_log_view : public mm_event_args
	{
	public:
		mm_event_data_log_view();
		~mm_event_data_log_view();


		mm_uint32_t code;
		std::string desc;
		std::string view;
	};




	class KO_dog_data_log_view
	{
	public:
		//������
		KO_dog_data_log_error_code_map code_map;

		// �����볡��־����¼�.
	public:	

		static const std::string event_log_view;
		// �¼�����.
		mm::mm_event_set d_event_set;

	};
}






#endif//__KO_dog_data_log_view_h__