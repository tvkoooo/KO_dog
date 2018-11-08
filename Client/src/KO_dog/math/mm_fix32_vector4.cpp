#include "mm_fix32_vector4.h"

namespace mm
{
	const mm_fix32_vector4 mm_fix32_vector4::ZERO(0, 0, 0, 0);

	std::ostream& operator << (std::ostream& o, const mm_fix32_vector4& v)
	{
		o << "vector4(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
		return o;
	}
}