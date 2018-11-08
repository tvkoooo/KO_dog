#ifndef __mm_fix32_quaternion_h__
#define __mm_fix32_quaternion_h__

#include "dish/mm_fix32.h"

#include "math/mm_fix32_matrix3x3.h"

#include <assert.h>

// https://www.ogre3d.org/

namespace mm
{
	struct mm_fix32_quaternion
	{
	public:
		// Cutoff for sine near zero
		static const mm_fix32 EPSILON;

		// special values
		static const mm_fix32_quaternion ZERO;
		static const mm_fix32_quaternion IDENTITY;
	public:
		// Cutoff for sine near zero
		static const mm_fix32 msEpsilon;
	public:
		union
		{
			struct { mm_fix32 x, y, z, w; };
			struct { mm_fix32 r, g, b, a; };
			struct { mm_fix32 s, t, p, q; };
			mm_fix32 d[4];
		};
	public:
		inline mm_fix32_quaternion()
			: x(0)
			, y(0)
			, z(0)
			, w(0)
		{

		}
		inline mm_fix32_quaternion(const mm_fix32_quaternion& v)
			: x(v.x)
			, y(v.y)
			, z(v.z)
			, w(v.w)
		{

		}
		inline explicit mm_fix32_quaternion(double scalar)
			: x(scalar)
			, y(scalar)
			, z(scalar)
			, w(scalar)
		{

		}
		inline explicit mm_fix32_quaternion(double dx, double dy, double dz, double dw)
			: x(dx)
			, y(dy)
			, z(dz)
			, w(dw)
		{

		}
		inline explicit mm_fix32_quaternion(mm_fix32 scalar)
			: x(scalar)
			, y(scalar)
			, z(scalar)
			, w(scalar)
		{

		}
		inline explicit mm_fix32_quaternion(mm_fix32 fx, mm_fix32 fy, mm_fix32 fz, mm_fix32 fw)
			: x(fx)
			, y(fy)
			, z(fz)
			, w(fw)
		{

		}
		/// Construct a quaternion from a rotation matrix
		inline mm_fix32_quaternion(const mm_fix32_matrix3x3& rot)
		{
			this->from_rotation_matrix(rot);
		}
	public:
		inline void swap(mm_fix32_quaternion& other)
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
	public:
		inline mm_fix32_quaternion& operator = (const mm_fix32_quaternion& rkQ)
		{
			this->x = rkQ.x;
			this->y = rkQ.y;
			this->z = rkQ.z;
			this->w = rkQ.w;
			return *this;
		}
	public:
		inline bool operator == (const mm_fix32_quaternion& rhs) const
		{
			return 
				(rhs.x == x) && (rhs.y == y) &&
				(rhs.z == z) && (rhs.w == w);
		}
		inline bool operator != (const mm_fix32_quaternion& rhs) const
		{
			return !operator==(rhs);
		}
	public:
		mm_fix32_quaternion operator + (const mm_fix32_quaternion& rkQ) const;
		mm_fix32_quaternion operator - (const mm_fix32_quaternion& rkQ) const;
		mm_fix32_quaternion operator * (const mm_fix32_quaternion& rkQ) const;
		// Rotation of a vector by a quaternion
		mm_fix32_vector3 operator * (const mm_fix32_vector3& rkVector) const;
	public:
		friend mm_fix32_quaternion operator * (mm_fix32 fScalar, const mm_fix32_quaternion& rkQ);
		friend mm_fix32_quaternion operator * (const mm_fix32_quaternion& rkQ, mm_fix32 fScalar);
	public:
		inline const mm_fix32_quaternion& operator + () const
		{
			return *this;
		}

		inline mm_fix32_quaternion operator - () const
		{
			return mm_fix32_quaternion(-this->x, -this->y, -this->z, -this->w);
		}
	public:
		inline mm_fix32 dot_product(const mm_fix32_quaternion& rkQ) const
		{
			return w * rkQ.w + x * rkQ.x + y * rkQ.y + z * rkQ.z;
		}
	public:
		// Normalises this quaternion, and returns the previous length
		mm_fix32 normalise();
	public:
		// Apply to non-zero quaternion
		mm_fix32_quaternion inverse() const;
		// Apply to unit-length quaternion
		mm_fix32_quaternion unit_inverse() const;
		mm_fix32_quaternion quaternion_exp() const;
		mm_fix32_quaternion quaternion_log() const;
	public:
		void from_rotation_matrix(const mm_fix32_matrix3x3& kRot);
		void to_rotation_matrix(mm_fix32_matrix3x3& kRot) const;

		/** Setups the quaternion using the supplied vector, and "roll" around
		*	that vector by the specified radians.
		*/
		void from_angle_axis(const mm_fix32& rfAngle, const mm_fix32_vector3& rkAxis);
		void to_angle_axis(mm_fix32& rfAngle, mm_fix32_vector3& rkAxis) const;

		/** Constructs the quaternion using 3 axes, the axes are assumed to be orthonormal
		*	@see FromAxes
		*/
		void from_axes(const mm_fix32_vector3* akAxis);
		void from_axes(const mm_fix32_vector3& xAxis, const mm_fix32_vector3& yAxis, const mm_fix32_vector3& zAxis);
		/** Gets the 3 orthonormal axes defining the quaternion. @see FromAxes */
		void to_axes(mm_fix32_vector3* akAxis) const;
		void to_axes(mm_fix32_vector3& xAxis, mm_fix32_vector3& yAxis, mm_fix32_vector3& zAxis) const;

		/** Returns the X orthonormal axis defining the quaternion. Same as doing
		*	xAxis = Vector3::UNIT_X * this. Also called the local X-axis
		*/
		mm_fix32_vector3 x_axis(void) const;

		/** Returns the Y orthonormal axis defining the quaternion. Same as doing
		*	yAxis = Vector3::UNIT_Y * this. Also called the local Y-axis
		*/
		mm_fix32_vector3 y_axis(void) const;

		/** Returns the Z orthonormal axis defining the quaternion. Same as doing
		*	zAxis = Vector3::UNIT_Z * this. Also called the local Z-axis
		*/
		mm_fix32_vector3 z_axis(void) const;

		/** Calculate the local roll element of this quaternion.
		* @param reprojectAxis By default the method returns the 'intuitive' result
		*	that is, if you projected the local X of the quaternion onto the XY plane,
		*	the angle between it and global X is returned. The co-domain of the returned
		*	value is from -180 to 180 degrees. If set to false though, the result is
		*	the rotation around Z axis that could be used to implement the quaternion
		*	using some non-intuitive order of rotations. This behavior is preserved for
		*	backward compatibility, to decompose quaternion into yaw, pitch and roll use
		*	q.ToRotationMatrix().ToEulerAnglesYXZ(yaw, pitch, roll) instead.
		*/
		mm_fix32 get_rotate_x(bool reprojectAxis = true) const;

		/** Calculate the local pitch element of this quaternion
		* @param reprojectAxis By default the method returns the 'intuitive' result
		*	that is, if you projected the local Y of the quaternion onto the YZ plane,
		*	the angle between it and global Y is returned. The co-domain of the returned
		*	value is from -180 to 180 degrees. If set to false though, the result is
		*	the rotation around X axis that could be used to implement the quaternion
		*	using some non-intuitive order of rotations. This behavior is preserved for
		*	backward compatibility, to decompose quaternion into yaw, pitch and roll use
		*	q.ToRotationMatrix().ToEulerAnglesYXZ(yaw, pitch, roll) instead.
		*/
		mm_fix32 get_rotate_y(bool reprojectAxis = true) const;

		/** Calculate the local yaw element of this quaternion
		* @param reprojectAxis By default the method returns the 'intuitive' result
		*	that is, if you projected the local Z of the quaternion onto the ZX plane,
		*	the angle between it and global Z is returned. The co-domain of the returned
		*	value is from -180 to 180 degrees. If set to false though, the result is
		*	the rotation around Y axis that could be used to implement the quaternion
		*	using some non-intuitive order of rotations. This behavior is preserved for
		*	backward compatibility, to decompose quaternion into yaw, pitch and roll use
		*	q.ToRotationMatrix().ToEulerAnglesYXZ(yaw, pitch, roll) instead.
		*/
		mm_fix32 get_rotate_z(bool reprojectAxis = true) const;

		/** Equality with tolerance (tolerance is max angle difference)
		* @remark Both equals() and orientationEquals() measure the exact same thing.
		*	One measures the difference by angle, the other by a different, non-linear metric.
		*/
		bool equals(const mm_fix32_quaternion& rhs, const mm_fix32& tolerance) const;

		/** Compare two quaternions which are assumed to be used as orientations.
		* @remark Both equals() and orientationEquals() measure the exact same thing.
		*	One measures the difference by angle, the other by a different, non-linear metric.
		* @return true if the two orientations are the same or very close, relative to the given tolerance.
		*	Slerp ( 0.75f, A, B ) != Slerp ( 0.25f, B, A );
		*	therefore be careful if your code relies in the order of the operands.
		*	This is specially important in IK animation.
		*/
		inline bool orientation_equals(const mm_fix32_quaternion& other, mm_fix32 tolerance = 1e-3) const
		{
			mm_fix32 d = this->dot_product(other);
			return 1 - d * d < tolerance;
		}
	public:
		/** Gets the shortest arc quaternion to rotate this vector to the destination
		*	vector.
		*	@remarks
		*		If you call this with a dest vector that is close to the inverse
		*		of this vector, we will rotate 180 degrees around the 'fallbackAxis'
		*		(if specified, or a generated axis if not) since in this case
		*		ANY axis of rotation is valid.
		*/
		static mm_fix32_quaternion get_rotation_to(const mm_fix32_vector3& rkVector, const mm_fix32_vector3& dest, const mm_fix32_vector3& fallbackAxis = mm_fix32_vector3::ZERO);
	public:
		/** Performs Spherical linear interpolation between two quaternions, and returns the result.
		* Slerp ( 0.0f, A, B ) = A
		* Slerp ( 1.0f, A, B ) = B
		* @return Interpolated quaternion
		* @remarks
		*	Slerp has the proprieties of performing the interpolation at constant
		*	velocity, and being torque-minimal (unless shortestPath=false).
		*	However, it's NOT commutative, which means
		*	Slerp ( 0.75f, A, B ) != Slerp ( 0.25f, B, A );
		*	therefore be careful if your code relies in the order of the operands.
		*	This is specially important in IK animation.
		*/
		static mm_fix32_quaternion slerp(
			mm_fix32 fT, 
			const mm_fix32_quaternion& rkP, 
			const mm_fix32_quaternion& rkQ, 
			bool shortestPath = false);

		/** @see Slerp. It adds extra "spins" (i.e. rotates several times) specified
		* by parameter 'iExtraSpins' while interpolating before arriving to the
		* final values
		*/
		static mm_fix32_quaternion slerp_extra_spins(
			mm_fix32 fT, 
			const mm_fix32_quaternion& rkP, 
			const mm_fix32_quaternion& rkQ, 
			int iExtraSpins);

		// Setup for spherical quadratic interpolation
		static void intermediate(
			const mm_fix32_quaternion& rkQ0, 
			const mm_fix32_quaternion& rkQ1, 
			const mm_fix32_quaternion& rkQ2, 
			mm_fix32_quaternion& rka, 
			mm_fix32_quaternion& rkB);

		// Spherical quadratic interpolation
		static mm_fix32_quaternion squad(
			mm_fix32 fT, 
			const mm_fix32_quaternion& rkP, 
			const mm_fix32_quaternion& rkA, 
			const mm_fix32_quaternion& rkB, 
			const mm_fix32_quaternion& rkQ, 
			bool shortestPath = false);

		/** Performs Normalised linear interpolation between two quaternions, and returns the result.
		* nlerp ( 0.0f, A, B ) = A
		* nlerp ( 1.0f, A, B ) = B
		* @remarks
		*	Nlerp is faster than Slerp.
		*	Nlerp has the proprieties of being commutative (@see Slerp;
		*	commutativity is desired in certain places, like IK animation), and
		*	being torque-minimal (unless shortestPath=false). However, it's performing
		*	the interpolation at non-constant velocity; sometimes this is desired,
		*	sometimes it is not. Having a non-constant velocity can produce a more
		*	natural rotation feeling without the need of tweaking the weights; however
		*	if your scene relies on the timing of the rotation or assumes it will point
		*	at a specific angle at a specific weight value, Slerp is a better choice.
		*/
		static mm_fix32_quaternion nlerp(
			mm_fix32 fT, 
			const mm_fix32_quaternion& rkP, 
			const mm_fix32_quaternion& rkQ, 
			bool shortestPath = false);
	public:
		friend std::ostream& operator << (std::ostream& o, const mm_fix32_quaternion& q);
	};
}

#endif//__mm_fix32_quaternion_h__