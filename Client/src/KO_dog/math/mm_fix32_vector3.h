#ifndef __mm_fix32_vector3_h__
#define __mm_fix32_vector3_h__

#include "dish/mm_fix32.h"

//#include "math/mm_fix32_quaternion.h"

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
	/** Standard 3-dimensional vector.
	*	@remarks
	*		A direction in 3D space represented as distances along the 3
	*		orthogonal axes (x, y, z). Note that positions, directions and
	*		scaling factors can be represented by a vector, depending on how
	*		you interpret the values.
	*/
	struct mm_fix32_vector3
	{
	public:
		static const mm_fix32_vector3 ZERO;
		static const mm_fix32_vector3 UNIT_X;
		static const mm_fix32_vector3 UNIT_Y;
		static const mm_fix32_vector3 UNIT_Z;
		static const mm_fix32_vector3 NEGATIVE_UNIT_X;
		static const mm_fix32_vector3 NEGATIVE_UNIT_Y;
		static const mm_fix32_vector3 NEGATIVE_UNIT_Z;
		static const mm_fix32_vector3 UNIT_SCALE;
	public:
		union
		{
			struct { mm_fix32 x, y, z; };
			struct { mm_fix32 r, g, b; };
			struct { mm_fix32 s, t, p; };
			mm_fix32 d[3];
		};
	public:
		inline mm_fix32_vector3()
			: x(0)
			, y(0)
			, z(0)
		{

		}
		inline mm_fix32_vector3(const mm_fix32_vector3& v)
			: x(v.x)
			, y(v.y)
			, z(v.z)
		{

		}
		inline explicit mm_fix32_vector3(double scalar)
			: x(scalar)
			, y(scalar)
			, z(scalar)
		{

		}
		inline explicit mm_fix32_vector3(double dx, double dy, double dz)
			: x(dx)
			, y(dy)
			, z(dz)
		{

		}
		inline explicit mm_fix32_vector3(mm_fix32 scalar)
			: x(scalar)
			, y(scalar)
			, z(scalar)
		{

		}
		inline explicit mm_fix32_vector3(mm_fix32 fx, mm_fix32 fy, mm_fix32 fz)
			: x(fx)
			, y(fy)
			, z(fz)
		{

		}
	public:
		/** Exchange the contents of this vector with another.
		*/
		inline void swap(mm_fix32_vector3& other)
		{
			std::swap(this->x, other.x);
			std::swap(this->y, other.y);
			std::swap(this->z, other.z);
		}
	public:
		inline mm_fix32 operator [] (const size_t i) const
		{
			assert(i < 3);
			return this->d[i];
		}

		inline mm_fix32& operator [] (const size_t i)
		{
			assert(i < 3);
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
		inline mm_fix32_vector3& operator = (const mm_fix32_vector3& rkVector)
		{
			this->x = rkVector.x;
			this->y = rkVector.y;
			this->z = rkVector.z;
			return *this;
		}

		inline mm_fix32_vector3& operator = (const mm_fix32 fScaler)
		{
			this->x = fScaler;
			this->y = fScaler;
			this->z = fScaler;
			return *this;
		}
	public:
		inline bool operator == (const mm_fix32_vector3& rkVector) const
		{
			return (this->x == rkVector.x && this->y == rkVector.y && this->z == rkVector.z);
		}

		inline bool operator != (const mm_fix32_vector3& rkVector) const
		{
			return (this->x != rkVector.x || this->y != rkVector.y || this->z != rkVector.z);
		}
	public:
		inline mm_fix32_vector3 operator + (const mm_fix32_vector3& rkVector) const
		{
			return mm_fix32_vector3(
				this->x + rkVector.x,
				this->y + rkVector.y,
				this->z + rkVector.z);
		}

		inline mm_fix32_vector3 operator - (const mm_fix32_vector3& rkVector) const
		{
			return mm_fix32_vector3(
				this->x - rkVector.x,
				this->y - rkVector.y,
				this->z - rkVector.z);
		}

		inline mm_fix32_vector3 operator * (const mm_fix32 fScalar) const
		{
			return mm_fix32_vector3(
				this->x * fScalar,
				this->y * fScalar,
				this->z * fScalar);
		}

		inline mm_fix32_vector3 operator * (const mm_fix32_vector3& rhs) const
		{
			return mm_fix32_vector3(
				this->x * rhs.x,
				this->y * rhs.y,
				this->z * rhs.z);
		}

		inline mm_fix32_vector3 operator / (const mm_fix32 fScalar) const
		{
			assert(fScalar != 0.0);
			mm_fix32 fInv = mm_fix32(1.0f) / fScalar;
			return mm_fix32_vector3(
				this->x * fInv,
				this->y * fInv,
				this->z * fInv);
		}

		inline mm_fix32_vector3 operator / (const mm_fix32_vector3& rhs) const
		{
			return mm_fix32_vector3(
				this->x / rhs.x,
				this->y / rhs.y,
				this->z / rhs.z);
		}

		inline const mm_fix32_vector3& operator + () const
		{
			return *this;
		}

		inline mm_fix32_vector3 operator - () const
		{
			return mm_fix32_vector3(-x, -y, -z);
		}

		inline friend mm_fix32_vector3 operator * (const mm_fix32 fScalar, const mm_fix32_vector3& rkVector)
		{
			return mm_fix32_vector3(
				fScalar * rkVector.x,
				fScalar * rkVector.y,
				fScalar * rkVector.z);
		}

		inline friend mm_fix32_vector3 operator / (const mm_fix32 fScalar, const mm_fix32_vector3& rkVector)
		{
			return mm_fix32_vector3(
				fScalar / rkVector.x,
				fScalar / rkVector.y,
				fScalar / rkVector.z);
		}

		inline friend mm_fix32_vector3 operator + (const mm_fix32_vector3& lhs, const mm_fix32 rhs)
		{
			return mm_fix32_vector3(
				lhs.x + rhs,
				lhs.y + rhs,
				lhs.z + rhs);
		}

		inline friend mm_fix32_vector3 operator + (const mm_fix32 lhs, const mm_fix32_vector3& rhs)
		{
			return mm_fix32_vector3(
				lhs + rhs.x,
				lhs + rhs.y,
				lhs + rhs.z);
		}

		inline friend mm_fix32_vector3 operator - (const mm_fix32_vector3& lhs, const mm_fix32 rhs)
		{
			return mm_fix32_vector3(
				lhs.x - rhs,
				lhs.y - rhs,
				lhs.z - rhs);
		}

		inline friend mm_fix32_vector3 operator - (const mm_fix32 lhs, const mm_fix32_vector3& rhs)
		{
			return mm_fix32_vector3(
				lhs - rhs.x,
				lhs - rhs.y,
				lhs - rhs.z);
		}

		inline mm_fix32_vector3& operator += (const mm_fix32_vector3& rkVector)
		{
			this->x += rkVector.x;
			this->y += rkVector.y;
			this->z += rkVector.z;
			return *this;
		}

		inline mm_fix32_vector3& operator += (const mm_fix32 fScalar)
		{
			this->x += fScalar;
			this->y += fScalar;
			this->z += fScalar;
			return *this;
		}

		inline mm_fix32_vector3& operator -= (const mm_fix32_vector3& rkVector)
		{
			this->x -= rkVector.x;
			this->y -= rkVector.y;
			this->z -= rkVector.z;
			return *this;
		}

		inline mm_fix32_vector3& operator -= (const mm_fix32 fScalar)
		{
			this->x -= fScalar;
			this->y -= fScalar;
			this->z -= fScalar;
			return *this;
		}

		inline mm_fix32_vector3& operator *= (const mm_fix32 fScalar)
		{
			this->x *= fScalar;
			this->y *= fScalar;
			this->z *= fScalar;
			return *this;
		}

		inline mm_fix32_vector3& operator *= (const mm_fix32_vector3& rkVector)
		{
			x *= rkVector.x;
			y *= rkVector.y;
			z *= rkVector.z;
			return *this;
		}

		inline mm_fix32_vector3& operator /= (const mm_fix32 fScalar)
		{
			assert(fScalar != 0.0);
			mm_fix32 fInv = mm_fix32(1.0f) / fScalar;
			x *= fInv;
			y *= fInv;
			z *= fInv;
			return *this;
		}

		inline mm_fix32_vector3& operator /= (const mm_fix32_vector3& rkVector)
		{
			this->x /= rkVector.x;
			this->y /= rkVector.y;
			this->z /= rkVector.z;
			return *this;
		}
	public:
		/** Returns the length (magnitude) of the vector.
		*	@warning
		*		This operation requires a square root and is expensive in
		*		terms of CPU operations. If you don't need to know the exact
		*		length (e.g. for just comparing lengths) use squaredLength()
		*		instead.
		*/
		inline mm_fix32 length() const
		{
			return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
		}

		/** Returns the square of the length(magnitude) of the vector.
		*	@remarks
		*		This  method is for efficiency - calculating the actual
		*		length of a vector requires a square root, which is expensive
		*		in terms of the operations required. This method returns the
		*		square of the length of the vector, i.e. the same as the
		*		length but before the square root is taken. Use this if you
		*		want to find the longest / shortest vector without incurring
		*		the square root.
		*/
		inline mm_fix32 squared_length() const
		{
			return this->x * this->x + this->y * this->y + this->z * this->z;
		}

		/** Returns the distance to another vector.
		*	@warning
		*		This operation requires a square root and is expensive in
		*		terms of CPU operations. If you don't need to know the exact
		*		distance (e.g. for just comparing distances) use squaredDistance()
		*		instead.
		*/
		inline mm_fix32 distance(const mm_fix32_vector3& rhs) const
		{
			return (*this - rhs).length();
		}

		/** Returns the square of the distance to another vector.
		*	@remarks
		*		This method is for efficiency - calculating the actual
		*		distance to another vector requires a square root, which is
		*		expensive in terms of the operations required. This method
		*		returns the square of the distance to another vector, i.e.
		*		the same as the distance but before the square root is taken.
		*		Use this if you want to find the longest / shortest distance
		*		without incurring the square root.
		*/
		inline mm_fix32 squared_distance(const mm_fix32_vector3& rhs) const
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
		mm_fix32_vector3 perpendicular(void) const;

		/** Calculates the dot (scalar) product of this vector with another.
		*	@remarks
		*		The dot product can be used to calculate the angle between 2
		*		vectors. If both are unit vectors, the dot product is the
		*		cosine of the angle; otherwise the dot product must be
		*		divided by the product of the lengths of both vectors to get
		*		the cosine of the angle. This result can further be used to
		*		calculate the distance of a point from a plane.
		*	@param
		*		vec Vector with which to calculate the dot product (together
		*		with this one).
		*	@return
		*		A float representing the dot product value.
		*/
		inline mm_fix32 dot_product(const mm_fix32_vector3& vec) const
		{
			return this->x * vec.x + this->y * vec.y + this->z * vec.z;
		}

		/** Calculates the cross-product of 2 vectors, i.e. the vector that
		*	lies perpendicular to them both.
		*	@remarks
		*		The cross-product is normally used to calculate the normal
		*		vector of a plane, by calculating the cross-product of 2
		*		non-equivalent vectors which lie on the plane (e.g. 2 edges
		*		of a triangle).
		*	@param rkVector
		*		Vector which, together with this one, will be used to
		*		calculate the cross-product.
		*	@return
		*		A vector which is the result of the cross-product. This
		*		vector will <b>NOT</b> be normalised, to maximise efficiency
		*		- call Vector3::normalise on the result if you wish this to
		*		be done. As for which side the resultant vector will be on, the
		*		returned vector will be on the side from which the arc from 'this'
		*		to rkVector is anticlockwise, e.g. UNIT_Y.crossProduct(UNIT_Z)
		*		= UNIT_X, whilst UNIT_Z.crossProduct(UNIT_Y) = -UNIT_X.
		*		This is because OGRE uses a right-handed coordinate system.
		*	@par
		*		For a clearer explanation, look a the left and the bottom edges
		*		of your monitor's screen. Assume that the first vector is the
		*		left edge and the second vector is the bottom edge, both of
		*		them starting from the lower-left corner of the screen. The
		*		resulting vector is going to be perpendicular to both of them
		*		and will go <i>inside</i> the screen, towards the cathode tube
		*		(assuming you're using a CRT monitor, of course).
		*/
		inline mm_fix32_vector3 cross_product(const mm_fix32_vector3& rkVector) const
		{
			return mm_fix32_vector3(
				this->y * rkVector.z - this->z * rkVector.y,
				this->z * rkVector.x - this->x * rkVector.z,
				this->x * rkVector.y - this->y * rkVector.x);
		}
	public:
		/** Normalises the vector.
		*	@remarks
		*		This method normalises the vector such that it's
		*		length / magnitude is 1. The result is called a unit vector.
		*	@note
		*		This function will not crash for zero-sized vectors, but there
		*		will be no changes made to their components.
		*	@return The previous length of the vector.
		*/
		mm_fix32 normalise();
	public:
		/** Returns true if the vector's scalar components are all greater
		*	that the ones of the vector it is compared against.
		*/
		inline bool operator < (const mm_fix32_vector3& rhs) const
		{
			return this->x < rhs.x && this->y < rhs.y && this->z < rhs.z;
		}

		/** Returns true if the vector's scalar components are all smaller
		*	that the ones of the vector it is compared against.
		*/
		inline bool operator > (const mm_fix32_vector3& rhs) const
		{
			return this->x > rhs.x && this->y > rhs.y && this->z > rhs.z;
		}
	public:
		/** Calculates a reflection vector to the plane with the given normal .
		*	@remarks NB assumes 'this' is pointing AWAY FROM the plane, invert if it is not.
		*/
		inline mm_fix32_vector3 reflect(const mm_fix32_vector3& normal) const
		{
			return mm_fix32_vector3(*this - (mm_fix32(2) * this->dot_product(normal) * normal));
		}

		/** Gets the angle between 2 vectors.
		*	@remarks
		*		Vectors do not have to be unit-length but must represent directions.
		*/
		mm_fix32 angle_between(const mm_fix32_vector3& dest) const;
	public:
		/** Function for writing to a stream.
		*/
		friend std::ostream& operator << (std::ostream& o, const mm_fix32_vector3& v);
	};
	/** @} */
	/** @} */
}

#endif//__mm_fix32_vector3_h__