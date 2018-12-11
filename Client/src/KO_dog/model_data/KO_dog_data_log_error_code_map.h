#ifndef __KO_dog_data_log_error_code_map_h__
#define __KO_dog_data_log_error_code_map_h__

#include <string>
#include <map>
#include "core/mm_core.h"
#include "dish/mm_event.h"

namespace mm
{


	class KO_dog_data_log_error_code_map
	{
		typedef std::map<mm_uint32_t, std::string>  log_error_code_map_type;//类型实例化，泛型要实例化操作

	public:
		KO_dog_data_log_error_code_map();
		~KO_dog_data_log_error_code_map();

	public:
		void clear();
		void load();
		void add(mm_uint32_t code, const std::string& view);
		void remove(mm_uint32_t code);
		//const std::string& get(mm_uint32_t code);

	private:
		log_error_code_map_type map_err_code;
	};


}

#endif//__KO_dog_data_log_error_code_map_h__