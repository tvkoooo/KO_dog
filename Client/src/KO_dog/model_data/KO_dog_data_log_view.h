#ifndef __KO_dog_data_log_view_h__
#define __KO_dog_data_log_view_h__

#include <string>
#include <list>

#include "core/mm_core.h"
#include "core/mm_spinlock.h"

#include "dish/mm_event.h"


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
		typedef std::list<mm_event_data_log_view> list_log;
	public:
		KO_dog_data_log_view();
		~KO_dog_data_log_view();



		// 界面入场日志变更事件.
	public:	

		static const std::string event_log_view;
	public:
		// 事件驱动.
		mm::mm_event_set d_event_set;

	public:
		list_log l_log;
		size_t pop_num;
		mm_atomic_t locker_l_log;
	public:	
		void set_pop_number(size_t pop_num);
		void push(const mm_event_data_log_view& e);
		void pop(size_t pop_num);
		//pop queue to clear or pop number limit
		void thread_handle();
	};
}






#endif//__KO_dog_data_log_view_h__