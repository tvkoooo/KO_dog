#include "KO_dog_test.h"




namespace mm
{
	static void __static_mm_msec_timer_test_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
	static void __static_mm_msec_timer_test1_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);


	struct_timer_test::struct_timer_test()
	{
		mm_timer_init(&this->timer);
		mm_timer_schedule(&this->timer, 10, 1000, &__static_mm_msec_timer_test_handle, this);
		mm_timer_schedule(&this->timer, 10, 2000, &__static_mm_msec_timer_test1_handle, this);
	}

	struct_timer_test::~struct_timer_test()
	{
		mm_timer_destroy(&this->timer);
	}

	void struct_timer_test::start()
	{
		mm_timer_start(&this->timer);
	}

	void struct_timer_test::interrupt()
	{
		mm_timer_interrupt(&this->timer);
	}

	void struct_timer_test::shutdown()
	{
		mm_timer_shutdown(&this->timer);
	}

	void struct_timer_test::join()
	{
		mm_timer_join(&this->timer);
	}

	//////////////////////////////////////////////////////////////////////////
	static void __static_mm_msec_timer_test_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
	{
		struct_timer_test* thissss = (struct_timer_test*)(entry->callback.obj);
		printf("struct_timer_test:%d  %d \n", thissss->a++, thissss->b++);
	}
	static void __static_mm_msec_timer_test1_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
	{
		struct_timer_test* thissss = (struct_timer_test*)(entry->callback.obj);
		printf("struct_timer_test:%d  %d \n", thissss->a+10, thissss->b+10);
	}
}