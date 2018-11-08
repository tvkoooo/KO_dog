#ifndef __mm_fix32_vector2_h__
#define __mm_fix32_vector2_h__

#include "dish/mm_fix32.h"

#include <assert.h>
#include <sstream>

// https://www.ogre3d.org/

namespace mm
{
	/** \addtogroup Core
	*  @{
	*/
	/** \addtogroup Math
	*  @{
	*/
	/** Standard 2-dimensional vector.
	*	@remarks
	*		A direction in 2D space represented as distances along the 2
	*		orthogonal axes (x, y). Note that positions, directions and
	*		scaling factors can be represented by a vector, depending on how
	*		you interpret the values.
	*/
	struct mm_fix32_vector2
	{
	public:
		static const mm_fix32_vector2 ZERO;
		static const mm_fix32_vector2 UNIT_X;
		static const mm_fix32_vector2 UNIT_Y;
		static const mm_fix32_vector2 NEGATIVE_UNIT_X;
		static const mm_fix32_vector2 NEGATIVE_UNIT_Y;
		static const mm_fix32_vector2 UNIT_SCALE;
	public:
		union
		{
			struct { mm_fix32 x, y; };
			struct { mm_fix32 r, g; };
			struct { mm_fix32 s, t; };
			mm_fix32 d[2];
		};
	public:
		inline mm_fix32_vector2()
			: x(0)
			, y(0)
		{

		}
		inline mm_fix32_vector2(const mm_fix32_vector2& v)
			: x(v.x)
			, y(v.y)
		{

		}
		inline explicit mm_fix32_vector2(double scalar)
			: x(scalar)
			, y(scalar)
		{

		}
		inline explicit mm_fix32_vector2(double dx, double dy)
			: x(dx)
			, y(dy)
		{

		}
		inline explicit mm_fix32_vector2(mm_fix32 scalar)
			: x(scalar)
			, y(scalar)
		{

		}
		inline explicit mm_fix32_vector2(mm_fix32 fx, mm_fix32 fy)
			: x(fx)
			, y(fy)
		{

		}
	public:
		/** Exchange the contents of this vector with another.
		*/
		inline void swap(mm_fix32_vector2& other)
		{
			std::swap(this->x, other.x);
			std::swap(this->y, other.y);
		}
	public:
		inline mm_fix32 operator [] (const size_t i) const
		{
			assert(i < 2);
			return this->d[i];
		}

		inline mm_fix32& operator [] (const size_t i)
		{
			assert(i < 2);
			return this->d[i];
		}
		/// Pointer accessor for direct copying
		inline mm_fix32* ptr()
		{
			return this->d;
		}
		/// Pointer accessor for direct copying
		inline const mm_fix32* ptr() const
		{
			return this->d;
		}
	public:
		/** Assigns the value of the other vector.
		*	@param
		*		rkVector The other vector
		*/
		inline mm_fix32_vector2& operator = (const mm_fix32_vector2& rkVector)
		{
			this->x = rkVector.x;
			this->y = rkVector.y;
			return *this;
		}

		inline mm_fix32_vector2& operator = (const mm_fix32 fScalar)
		{
			this->x = fScalar;
			this->y = fScalar;
			return *this;
		}
	public:
		inline bool operator == (const mm_fix32_vector2& rkVector) const
		{
			return (this->x == rkVector.x && this->y == rkVector.y);
		}

		inline bool operator != (const mm_fix32_vector2& rkVector) const
		{
			return (this->x != rkVector.x || this->y != rkVector.y);
		}
	public:
		inline mm_fix32_vector2 operator + (const mm_fix32_vector2& rkVector) const
		{
			return mm_fix32_vector2(
				this->x + rkVector.x,
				this->y + rkVector.y);
		}

		inline mm_fix32_vector2 operator - (const mm_fix32_vector2& rkVector) const
		{
			return mm_fix32_vector2(
				this->x - rkVector.x,
				this->y - rkVector.y);
		}

		inline mm_fix32_vector2 operator * (const mm_fix32 fScalar) const
		{
			return mm_fix32_vector2(
				this->x * fScalar,
				this->y * fScalar);
		}

		inline mm_fix32_vector2 operator * (const mm_fix32_vector2& rhs) const
		{
			return mm_fix32_vector2(
				this->x * rhs.x,
				this->y * rhs.y);
		}

		inline mm_fix32_vector2 operator / (const mm_fix32 fScalar) const
		{
			assert(fScalar != 0.0);
			mm_fix32 fInv = mm_fix32(1.0f) / fScalar;
			return mm_fix32_vector2(
				x * fInv,
				y * fInv);
		}

		inline mm_fix32_vector2 operator / (const mm_fix32_vector2& rhs) const
		{
			return mm_fix32_vector2(
				this->x / rhs.x,
				this->y / rhs.y);
		}

		inline const mm_fix32_vector2& operator + () const
		{
			return *this;
		}

		inline mm_fix32_vector2 operator - () const
		{
			return mm_fix32_vector2(-this->x, -this->y);
		}

		inline friend mm_fix32_vector2 operator * (const mm_fix32 fScalar, const mm_fix32_vector2& rkVector)
		{
			return mm_fix32_vector2(
				fScalar * rkVector.x,
				fScalar * rkVector.y);
		}

		inline friend mm_fix32_vector2 operator / (const mm_fix32 fScalar, const mm_fix32_vector2& rkVector)
		{
			return mm_fix32_vector2(
				fScalar / rkVector.x,
				fScalar / rkVector.y);
		}

		inline friend mm_fix32_vector2 operator + (const mm_fix32_vector2& lhs, const mm_fix32 rhs)
		{
			return mm_fix32_vector2(
				lhs.x + rhs,
				lhs.y + rhs);
		}

		inline friend mm_fix32_vector2 operator + (const mm_fix32 lhs, const mm_fix32_vector2& rhs)
		{
			return mm_fix32_vector2(
				lhs + rhs.x,
				lhs + rhs.y);
		}

		inline friend mm_fix32_vector2 operator - (const mm_fix32_vector2& lhs, const mm_fix32 rhs)
		{
			return mm_fix32_vector2(
				lhs.x - rhs,
				lhs.y - rhs);
		}

		inline friend mm_fix32_vector2 operator - (const mm_fix32 lhs, const mm_fix32_vector2& rhs)
		{
			return mm_fix32_vector2(
				lhs - rhs.x,
				lhs - rhs.y);
		}
	public:
		inline mm_fix32_vector2& operator += (const mm_fix32 fScaler)
		{
			this->x += fScaler;
			this->y += fScaler;
			return *this;
		}
		inline mm_fix32_vector2& operator +=(const mm_fix32_vector2& v)
		{
			this->x += v.x;
			this->y += v.y;
			return *this;
		}
		inline mm_fix32_vector2& operator -= (const mm_fix32 fScaler)
		{
			this->x -= fScaler;
			this->y -= fScaler;
			return *this;
		}
		inline mm_fix32_vector2& operator -=(const mm_fix32_vector2& v)
		{
			this->x -= v.x;
			this->y -= v.y;
			return *this;
		}
		inline mm_fix32_vector2& operator *= (const mm_fix32 fScalar)
		{
			assert(fScalar != 0.0);
			mm_fix32 fInv = mm_fix32(1.0f) / fScalar;
			x *= fInv;
			y *= fInv;
			return *this;
		}
		inline mm_fix32_vector2& operator *=(const mm_fix32_vector2& v)
		{
			this->x *= v.x;
			this->y *= v.y;
			return *this;
		}
		inline mm_fix32_vector2& operator /= (const mm_fix32 fScaler)
		{
			this->x /= fScaler;
			this->y /= fScaler;
			return *this;
		}
		inline mm_fix32_vector2& operator /=(const mm_fix32_vector2& v)
		{
			this->x /= v.x;
			this->y /= v.y;
			return *this;
		}
	public:
		/// @copydoc vector2::length
		inline mm_fix32 length() const
		{
			return sqrt(this->x * this->x + this->y * this->y);
		}

		/// @copydoc vector2::squared_length
		inline mm_fix32 squared_length() const
		{
			return this->x * this->x + this->y * this->y;
		}

		/// @copydoc vector2::distance
		inline mm_fix32 distance(const mm_fix32_vector2& rhs) const
		{
			return (*this - rhs).length();
		}

		/// @copydoc vector2::squared_distance
		inline mm_fix32 squared_distance(const mm_fix32_vector2& rhs) const
		{
			return (*this - rhs).squared_length();
		}
	public:
		/** Generates a vector perpendicular to this vector (eg an 'up' vector).
		*	@remarks
		*		This method will return a vector which is perpendicular to this
		*		vector. There are an infinite number of possibilities but this
		*		method will guarantee to generate one of them. If you need more
		*		control you should use the Quaternion class.
		*/
		inline mm_fix32_vector2 perpendicular(void) const
		{
			return mm_fix32_vector2(-y, x);
		}

		/// @copydoc vector2::dot_product
		inline mm_fix32 dot_product(const mm_fix32_vector2& vec) const
		{
			return this->x * vec.x + this->y * vec.y;
		}

		/** Calculates the 2 dimensional cross-product of 2 vectors, which results
		*	in a single floating point value which is 2 times the area of the triangle.
		*/
		inline mm_fix32 cross_product(const mm_fix32_vector2& rkVector) const
		{
			return this->x * rkVector.y - this->y * rkVector.x;
		}
	public:
		/// @copydoc vector2::normalise
		inline mm_fix32 normalise();
	public:
		/** Returns true if the vector's scalar components are all greater
		*	that the ones of the vector it is compared against.
		*/
		inline bool operator < (const mm_fix32_vector2& rhs) const
		{
			return this->x < rhs.x && this->y < rhs.y;
		}

		/** Returns true if the vector's scalar components are all smaller
		*	that the ones of the vector it is compared against.
		*/
		inline bool operator > (const mm_fix32_vector2& rhs) const
		{
			return this->x > rhs.x && this->y > rhs.y;
		}
	public:
		/** Calculates a reflection vector to the plane with the given normal .
		*	@remarks NB assumes 'this' is pointing AWAY FROM the plane, invert if it is not.
		*/
		inline mm_fix32_vector2 reflect(const mm_fix32_vector2& normal) const
		{
			return mm_fix32_vector2(*this - (mm_fix32(2) * this->dot_product(normal) * normal));
		}

		/** Gets the angle between 2 vectors.
		*	@remarks
		*		Vectors do not have to be unit-length but must represent directions.
		*/
		mm_fix32 angle_between(const mm_fix32_vector2& other) const;

		/** Gets the oriented angle between 2 vectors.
		*	@remarks
		*		Vectors do not have to be unit-length but must represent directions.
		*		The angle is comprised between 0 and 2 PI.
		*/
		mm_fix32 angle_to(const mm_fix32_vector2& other) const;
	public:
		/** Function for writing to a stream.
		*/
		friend std::ostream& operator << (std::ostream& o, const mm_fix32_vector2& v);
	};
	/** @} */
	/** @} */
}

#endif//__mm_fix32_vector3_h__