#ifndef __mm_rocker_key_h__
#define __mm_rocker_key_h__

#include "container/mm_bitset.h"
#include "emu/mm_emu_machine.h"
#include "math/mm_fix32_linear.h"

//////////////////////////////////////////////////////////////////////////
namespace mm
{
	class mm_rocker_key
	{
	public:
		struct mm_emu_machine* d_emu_machine;
		double d_rotation;

		bool w;
		bool a;
		bool s;
		bool d;

	public:
		mm_rocker_key();
		~mm_rocker_key();

	public:
		void set_emu_machine(struct mm_emu_machine* d_emu_machine);
		mm_fix32 input_rotation(double d_rotation);
		void rocker_noting();
	};





}
//////////////////////////////////////////////////////////////////////////
#endif//__mm_rocker_key_h__