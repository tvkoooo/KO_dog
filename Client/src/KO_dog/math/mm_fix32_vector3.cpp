#include "mm_fix32_vector3.h"

namespace mm
{
	const mm_fix32_vector3 mm_fix32_vector3::ZERO(0, 0, 0);

	const mm_fix32_vector3 mm_fix32_vector3::UNIT_X(1, 0, 0);
	const mm_fix32_vector3 mm_fix32_vector3::UNIT_Y(0, 1, 0);
	const mm_fix32_vector3 mm_fix32_vector3::UNIT_Z(0, 0, 1);
	const mm_fix32_vector3 mm_fix32_vector3::NEGATIVE_UNIT_X(-1, 0, 0);
	const mm_fix32_vector3 mm_fix32_vector3::NEGATIVE_UNIT_Y(0, -1, 0);
	const mm_fix32_vector3 mm_fix32_vector3::NEGATIVE_UNIT_Z(0, 0, -1);
	const mm_fix32_vector3 mm_fix32_vector3::UNIT_SCALE(1, 1, 1);

	mm_fix32_vector3 mm_fix32_vector3::perpendicular(void) const
	{
		// From Sam Hocevar's article "On picking an orthogonal
		// vector (and combing coconuts)"
		mm_fix32_vector3 perp = fabs(x) > fabs(z)
			? mm_fix32_vector3(-y, x, (mm_fix32)0.0) : mm_fix32_vector3((mm_fix32)0.0, -z, y);

		perp.normalise();

		return perp;
	}

	mm_fix32 mm_fix32_vector3::normalise()
	{
		mm_fix32 fLength = sqrt(x * x + y * y + z * z);

		// Will also work for zero-sized vectors, but will change nothing
		// We're not using epsilons because we don't need to.
		if (fLength > mm_fix32(0.0f))
		{
			mm_fix32 fInvLength = mm_fix32(1.0f) / fLength;
			this->x *= fInvLength;
			this->y *= fInvLength;
			this->z *= fInvLength;
		}

		return fLength;
	}

	mm_fix32 mm_fix32_vector3::angle_between(const mm_fix32_vector3& dest) const
	{
		mm_fix32 lenProduct = this->length() * dest.length();

		// Divide by zero check
		if (lenProduct < 1e-6f)
			lenProduct = 1e-6f;

		mm_fix32 f = this->dot_product(dest) / lenProduct;

		f = clamp(f, (mm_fix32)-1.0, (mm_fix32)1.0);
		return acos(f);

	}

	std::ostream& operator << (std::ostream& o, const mm_fix32_vector3& v)
	{
		o << "vector3(" << v.x << ", " << v.y << ", " << v.z << ")";
		return o;
	}
}