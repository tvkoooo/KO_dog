#include "mm_fix32_vector2.h"

namespace mm 
{
	const mm_fix32_vector2 mm_fix32_vector2::ZERO(0, 0);

	const mm_fix32_vector2 mm_fix32_vector2::UNIT_X(1, 0);
	const mm_fix32_vector2 mm_fix32_vector2::UNIT_Y(0, 1);
	const mm_fix32_vector2 mm_fix32_vector2::NEGATIVE_UNIT_X(-1, 0);
	const mm_fix32_vector2 mm_fix32_vector2::NEGATIVE_UNIT_Y(0, -1);
	const mm_fix32_vector2 mm_fix32_vector2::UNIT_SCALE(1, 1);

	mm_fix32 mm_fix32_vector2::normalise()
	{
		mm_fix32 fLength = sqrt(this->x * this->x + this->y * this->y);

		// Will also work for zero-sized vectors, but will change nothing
		// We're not using epsilons because we don't need to.
		if (fLength > mm_fix32(0.0f))
		{
			mm_fix32 fInvLength = mm_fix32(1.0f) / fLength;
			this->x *= fInvLength;
			this->y *= fInvLength;
		}

		return fLength;
	}

	mm_fix32 mm_fix32_vector2::angle_between(const mm_fix32_vector2& other) const
	{
		mm_fix32 lenProduct = this->length() * other.length();
		// Divide by zero check
		if (lenProduct < 1e-6f)
			lenProduct = 1e-6f;

		mm_fix32 f = this->dot_product(other) / lenProduct;

		f = clamp(f, (mm_fix32)-1.0, (mm_fix32)1.0);
		return acos(f);
	}

	mm_fix32 mm_fix32_vector2::angle_to(const mm_fix32_vector2& other) const
	{
		mm_fix32 angle = this->angle_between(other);

		if (this->cross_product(other)<0)
			angle = (mm_fix32)mm_fix32::MM_2_MUL_PI - angle;

		return angle;
	}

	std::ostream& operator << (std::ostream& o, const mm_fix32_vector2& v)
	{
		o << "vector2(" << v.x << ", " << v.y << ")";
		return o;
	}
}