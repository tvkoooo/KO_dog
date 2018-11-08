#ifndef __mm_unit_transform_h__
#define __mm_unit_transform_h__

#include "LinearMath/btTransform.h"

namespace mm
{
	class mm_unit_transform
	{
	public:
		btTransform d_world_transform;
	public:
		mm_unit_transform();
		virtual ~mm_unit_transform();
	};
}
#endif//__mm_unit_transform_h__