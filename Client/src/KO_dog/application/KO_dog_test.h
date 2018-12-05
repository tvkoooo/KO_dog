#ifndef __KO_dog_test_h__
#define __KO_dog_test_h__

#include "core/mm_timer.h"


//////////////////////////////////////////////////////////////////////////
namespace mm
{
	class struct_timer_test
	{
	public:
		struct_timer_test();
		~struct_timer_test();

	public:
		void start();
		void interrupt();
		void shutdown();
		void join();



	public:
		struct mm_timer timer;
	public:
		int a;
		int b;
	};


}
//////////////////////////////////////////////////////////////////////////


#endif//__KO_dog_test_h__