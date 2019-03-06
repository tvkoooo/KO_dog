#include "mm_rocker_key.h"

#include "flake/mm_system_event_key.h"
#include "math/mm_math_const.h"

namespace mm
{
	mm_rocker_key::mm_rocker_key()
		: d_emu_machine(NULL)
		, d_rotation(0)

		, w(false)
		, a(false)
		, s(false)
		, d(false)
	{

	}
	mm_rocker_key::~mm_rocker_key()
	{	

	}

	void mm_rocker_key::set_emu_machine(struct mm_emu_machine* d_emu_machine)
	{
		this->d_emu_machine = d_emu_machine;
	}
	mm_fix32 mm_rocker_key::input_rotation(double d_rotation)
	{
		this->d_rotation = d_rotation;
		mm_fix32 k_yaogan_hudu = fmod(5 * MM_PI_2 - (d_rotation), MM_PI_2 * 4);
		if (k_yaogan_hudu >= (MM_PI_4 * 1/2) && k_yaogan_hudu < (MM_PI_4 * 7 / 2))
		{
			if (!this->s)
			{
				this->s = true;
				mm_emu_machine_KeyboardPressed(this->d_emu_machine, mm::mm_key::S);
			}
		}
		else
		{
			if (this->s)
			{
				this->s = false;
				mm_emu_machine_KeyboardRelease(this->d_emu_machine, mm::mm_key::S);
			}
		}
		//
		if (k_yaogan_hudu >= (MM_PI_4 * 5 / 2) && k_yaogan_hudu < (MM_PI_4 * 11 / 2))
		{
			if (!this->d)
			{
				this->d = true;
				mm_emu_machine_KeyboardPressed(this->d_emu_machine, mm::mm_key::D);
			}
		}
		else
		{
			if (this->d)
			{
				this->d = false;
				mm_emu_machine_KeyboardRelease(this->d_emu_machine, mm::mm_key::D);
			}
		}
		//
		if (k_yaogan_hudu >= (MM_PI_4 * 9 / 2) && k_yaogan_hudu  < (MM_PI_4 * 15 / 2))
		{
			if (!this->w)
			{
				this->w = true;
				mm_emu_machine_KeyboardPressed(this->d_emu_machine, mm::mm_key::W);
			}
		}
		else
		{
			if (this->w)
			{
				this->w = false;
				mm_emu_machine_KeyboardRelease(this->d_emu_machine, mm::mm_key::W);
			}
		}
		//
		if (k_yaogan_hudu >= (MM_PI_4 * 13 / 2) || k_yaogan_hudu  < (MM_PI_4 * 3 / 2))
		{
			if (!this->a)
			{
				this->a = true;
				mm_emu_machine_KeyboardPressed(this->d_emu_machine, mm::mm_key::A);
			}
		}
		else
		{
			if (this->a)
			{
				this->a = false;
				mm_emu_machine_KeyboardRelease(this->d_emu_machine, mm::mm_key::A);
			}
		}
		return k_yaogan_hudu;
	}
	
	void mm_rocker_key::rocker_noting()
	{
		this->d_rotation = 0;
		if (this->s)
		{
			this->s = false;
			mm_emu_machine_KeyboardRelease(this->d_emu_machine, mm::mm_key::S);
		}
		if (this->d)
		{
			this->d = false;
			mm_emu_machine_KeyboardRelease(this->d_emu_machine, mm::mm_key::D);
		}
		if (this->w)
		{
			this->w = false;
			mm_emu_machine_KeyboardRelease(this->d_emu_machine, mm::mm_key::W);
		}
		if (this->a)
		{
			this->a = false;
			mm_emu_machine_KeyboardRelease(this->d_emu_machine, mm::mm_key::A);
		}
	}
}