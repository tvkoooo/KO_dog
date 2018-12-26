#include "KO_dog_data_log_view.h"


namespace mm
{	
	//mm_event_data_log_view/////////////////////////////////////////////////////////////////////////////////
	mm_event_data_log_view::mm_event_data_log_view()
		: code(0)
		, desc("")
		, view("")
	{

	}
	mm_event_data_log_view::~mm_event_data_log_view()
	{

	}

	//KO_dog_data_log_view/////////////////////////////////////////////////////////////////////////////////
	const std::string KO_dog_data_log_view::event_log_view("event_log_view");

	KO_dog_data_log_view::KO_dog_data_log_view()
		: d_event_set()
		, l_log()
		, pop_num(50)
	{
		mm_spinlock_init(&this->locker_l_log, NULL);
	}

	KO_dog_data_log_view::~KO_dog_data_log_view()
	{
		mm_spinlock_destroy(&this->locker_l_log);
	}

	void KO_dog_data_log_view::set_pop_number(size_t pop_num)
	{
		this->pop_num = pop_num;
	}
	void KO_dog_data_log_view::push(const mm_event_data_log_view& e)
	{
		mm_spinlock_lock(&this->locker_l_log);
		this->l_log.push_back(e);
		mm_spinlock_unlock(&this->locker_l_log);
	}

	
	void KO_dog_data_log_view::pop(size_t pop_num)
	{
		for (size_t i = 0; 0 != this->l_log.size() && i < pop_num; i++)
		{
			//发布到界面输出错误日志    发布内容  evt_ags
			mm::mm_event_data_log_view evt_ags;
			mm_spinlock_lock(&this->locker_l_log);
			evt_ags = *this->l_log.begin();
			this->l_log.pop_front();
			mm_spinlock_unlock(&this->locker_l_log);
			this->d_event_set.fire_event(mm::KO_dog_data_log_view::event_log_view, evt_ags);
		}
	}
	//pop queue to clear or pop number limit
	void KO_dog_data_log_view::thread_handle()
	{
		this->pop(this->pop_num);
	}


}