#ifndef __mm_fix32_vector4_h__
#define __mm_fix32_vector4_h__

#include "dish/mm_fix32.h"

#include <assert.h>

// https://www.ogre3d.org/

namespace mm
{
	/** \addtogroup Core
	*  @{
	*/
	/** \addtogroup Math
	*  @{
	*/
	/** 4-dimensional homogeneous vector.
	*/
	struct mm_fix32_vector4
	{
	public:
		static const mm_fix32_vector4 ZERO;
	public:
		union
		{
			struct { mm_fix32 x, y, z, w; };
			struct { mm_fix32 r, g, b, a; };
			struct { mm_fix32 s, t, p, q; };
			mm_fix32 d[3];
		};
	public:
		inline mm_fix32_vector4()
			: x(0)
			, y(0)
			, z(0)
			, w(0)
		{

		}
		inline mm_fix32_vector4(const mm_fix32_vector4& v)
			: x(v.x)
			, y(v.y)
			, z(v.z)
			, w(v.w)
		{

		}
		inline explicit mm_fix32_vector4(double scalar)
			: x(scalar)
			, y(scalar)
			, z(scalar)
			, w(scalar)
		{

		}
		inline explicit mm_fix32_vector4(double dx, double dy, double dz, double dw)
			: x(dx)
			, y(dy)
			, z(dz)
			, w(dw)
		{

		}
		inline explicit mm_fix32_vector4(mm_fix32 scalar)
			: x(scalar)
			, y(scalar)
			, z(scalar)
			, w(scalar)
		{

		}
		inline explicit mm_fix32_vector4(mm_fix32 fx, mm_fix32 fy, mm_fix32 fz, mm_fix32 fw)
			: x(fx)
			, y(fy)
			, z(fz)
			, w(fw)
		{

		}
	public:
		/** Exchange the contents of this vector with another.
		*/
		inline void swap(mm_fix32_vector4& other)
		{
			std::swap(this->x, other.x);
			std::swap(this->y, other.y);
			std::swap(this->z, other.z);
			std::swap(this->w, other.w);
		}
	public:
		inline mm_fix32 operator [] (const size_t i) const
		{
			assert(i < 4);
			return this->d[i];
		}

		inline mm_fix32& operator [] (const size_t i)
		{
			assert(i < 4);
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
		inline mm_fix32_vector4& operator = (const mm_fix32_vector4& rkVector)
		{
			this->x = rkVector.x;
			this->y = rkVector.y;
			this->z = rkVector.z;
			this->w = rkVector.w;
			return *this;
		}

		inline mm_fix32_vector4& operator = (const mm_fix32 fScalar)
		{
			this->x = fScalar;
			this->y = fScalar;
			this->z = fScalar;
			this->w = fScalar;
			return *this;
		}
	public:
		inline bool operator == (const mm_fix32_vector4& rkVector) const
		{
			return 
				this->x == rkVector.x &&
				this->y == rkVector.y &&
				this->z == rkVector.z &&
				this->w == rkVector.w;
		}

		inline bool operator != (const mm_fix32_vector4& rkVector) const
		{
			return 
				this->x != rkVector.x ||
				this->y != rkVector.y ||
				this->z != rkVector.z ||
				this->w != rkVector.w;
		}
	public:
		inline mm_fix32_vector4 operator + (const mm_fix32_vector4& rkVector) const
		{
			return mm_fix32_vector4(
				this->x + rkVector.x,
				this->y + rkVector.y,
				this->z + rkVector.z,
				this->w + rkVector.w);
		}

		inline mm_fix32_vector4 operator - (const mm_fix32_vector4& rkVector) const
		{
			return mm_fix32_vector4(
				this->x - rkVector.x,
				this->y - rkVector.y,
				this->z - rkVector.z,
				this->w - rkVector.w);
		}

		inline mm_fix32_vector4 operator * (const mm_fix32 fScalar) const
		{
			return mm_fix32_vector4(
				this->x * fScalar,
				this->y * fScalar,
				this->z * fScalar,
				this->w * fScalar);
		}

		inline mm_fix32_vector4 operator * (const mm_fix32_vector4& rhs) const
		{
			return mm_fix32_vector4(
				rhs.x * this->x,
				rhs.y * this->y,
				rhs.z * this->z,
				rhs.w * this->w);
		}

		inline mm_fix32_vector4 operator / (const mm_fix32 fScalar) const
		{
			assert(fScalar != 0.0);
			mm_fix32 fInv = mm_fix32(1.0f) / fScalar;
			return mm_fix32_vector4(
				this->x * fInv,
				this->y * fInv,
				this->z * fInv,
				this->w * fInv);
		}

		inline mm_fix32_vector4 operator / (const mm_fix32_vector4& rhs) const
		{
			return mm_fix32_vector4(
				this->x / rhs.x,
				this->y / rhs.y,
				this->z / rhs.z,
				this->w / rhs.w);
		}

		inline const mm_fix32_vector4& operator + () const
		{
			return *this;
		}

		inline mm_fix32_vector4 operator - () const
		{
			return mm_fix32_vector4(-this->x, -this->y, -this->z, -this->w);
		}

		inline friend mm_fix32_vector4 operator * (const mm_fix32 fScalar, const mm_fix32_vector4& rkVector)
		{
			return mm_fix32_vector4(
				fScalar * rkVector.x,
				fScalar * rkVector.y,
				fScalar * rkVector.z,
				fScalar * rkVector.w);
		}

		inline friend mm_fix32_vector4 operator / (const mm_fix32 fScalar, const mm_fix32_vector4& rkVector)
		{
			return mm_fix32_vector4(
				fScalar / rkVector.x,
				fScalar / rkVector.y,
				fScalar / rkVector.z,
				fScalar / rkVector.w);
		}

		inline friend mm_fix32_vector4 operator + (const mm_fix32_vector4& lhs, const mm_fix32 rhs)
		{
			return mm_fix32_vector4(
				lhs.x + rhs,
				lhs.y + rhs,
				lhs.z + rhs,
				lhs.w + rhs);
		}

		inline friend mm_fix32_vector4 operator + (const mm_fix32 lhs, const mm_fix32_vector4& rhs)
		{
			return mm_fix32_vector4(
				lhs + rhs.x,
				lhs + rhs.y,
				lhs + rhs.z,
				lhs + rhs.w);
		}

		inline friend mm_fix32_vector4 operator - (const mm_fix32_vector4& lhs, mm_fix32 rhs)
		{
			return mm_fix32_vector4(
				lhs.x - rhs,
				lhs.y - rhs,
				lhs.z - rhs,
				lhs.w - rhs);
		}

		inline friend mm_fix32_vector4 operator - (const mm_fix32 lhs, const mm_fix32_vector4& rhs)
		{
			return mm_fix32_vector4(
				lhs - rhs.x,
				lhs - rhs.y,
				lhs - rhs.z,
				lhs - rhs.w);
		}

		inline mm_fix32_vector4& operator += (const mm_fix32_vector4& rkVector)
		{
			this->x += rkVector.x;
			this->y += rkVector.y;
			this->z += rkVector.z;
			this->w += rkVector.w;
			return *this;
		}

		inline mm_fix32_vector4& operator -= (const mm_fix32_vector4& rkVector)
		{
			this->x -= rkVector.x;
			this->y -= rkVector.y;
			this->z -= rkVector.z;
			this->w -= rkVector.w;
			return *this;
		}

		inline mm_fix32_vector4& operator *= (const mm_fix32 fScalar)
		{
			this->x *= fScalar;
			this->y *= fScalar;
			this->z *= fScalar;
			this->w *= fScalar;
			return *this;
		}

		inline mm_fix32_vector4& operator += (const mm_fix32 fScalar)
		{
			this->x += fScalar;
			this->y += fScalar;
			this->z += fScalar;
			this->w += fScalar;
			return *this;
		}

		inline mm_fix32_vector4& operator -= (const mm_fix32 fScalar)
		{
			this->x -= fScalar;
			this->y -= fScalar;
			this->z -= fScalar;
			this->w -= fScalar;
			return *this;
		}

		inline mm_fix32_vector4& operator *= (const mm_fix32_vector4& rkVector)
		{
			this->x *= rkVector.x;
			this->y *= rkVector.y;
			this->z *= rkVector.z;
			this->w *= rkVector.w;
			return *this;
		}

		inline mm_fix32_vector4& operator /= (const mm_fix32 fScalar)
		{
			assert(fScalar != 0.0);
			mm_fix32 fInv = mm_fix32(1.0f) / fScalar;
			this->x *= fInv;
			this->y *= fInv;
			this->z *= fInv;
			this->w *= fInv;
			return *this;
		}

		inline mm_fix32_vector4& operator /= (const mm_fix32_vector4& rkVector)
		{
			this->x /= rkVector.x;
			this->y /= rkVector.y;
			this->z /= rkVector.z;
			this->w /= rkVector.w;
			return *this;
		}
	public:
		/** Calculates the dot (scalar) product of this vector with another.
		*	@param
		*		vec Vector with which to calculate the dot product (together
		*		with this one).
		*	@return
		*		A float representing the dot product value.
		*/
		inline mm_fix32 dot_product(const mm_fix32_vector4& vec) const
		{
			return this->x * vec.x + this->y * vec.y + this->z * vec.z + this->w * vec.w;
		}
		// High dimensional( > 3d) vector, cross product is not a vector. Less used now.
	public:
		/** Function for writing to a stream.
		*/
		friend std::ostream& operator << (std::ostream& o, const mm_fix32_vector4& v);
	};
	/** @} */
	/** @} */
}

#endif//__mm_fix32_vector3_h__