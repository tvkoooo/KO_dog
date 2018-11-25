#ifndef __lj_KO_dog_test_h__
#define __lj_KO_dog_test_h__

#include "core/mm_timer.h"


//////////////////////////////////////////////////////////////////////////
namespace mm
{
	class lj_struct_timer_test
	{
	public:
		lj_struct_timer_test();
		~lj_struct_timer_test();

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


#endif//__lj_KO_dog_test_h__