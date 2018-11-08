#ifndef __mm_fix32_matrix4x4_h__
#define __mm_fix32_matrix4x4_h__

#include "core/mm_string.h"

#include "dish/mm_fix32.h"

#include "math/mm_fix32_vector4.h"
#include "math/mm_fix32_quaternion.h"
#include "math/mm_fix32_matrix3x3.h"

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
	/** Class encapsulating a standard 4x4 homogeneous matrix.
	*	@remarks
	*		OGRE uses column vectors when applying matrix multiplications,
	*		This means a vector is represented as a single column, 4-row
	*		matrix. This has the effect that the transformations implemented
	*		by the matrices happens right-to-left e.g. if vector V is to be
	*		transformed by M1 then M2 then M3, the calculation would be
	*		M3 * M2 * M1 * V. The order that matrices are concatenated is
	*		vital since matrix multiplication is not commutative, i.e. you
	*		can get a different result if you concatenate in the wrong order.
	*	@par
	*		The use of column vectors and right-to-left ordering is the
	*		standard in most mathematical texts, and is the same as used in
	*		OpenGL. It is, however, the opposite of Direct3D, which has
	*		inexplicably chosen to differ from the accepted standard and uses
	*		row vectors and left-to-right matrix multiplication.
	*	@par
	*		OGRE deals with the differences between D3D and OpenGL etc.
	*		internally when operating through different render systems. OGRE
	*		users only need to conform to standard maths conventions, i.e.
	*		right-to-left matrix multiplication, (OGRE transposes matrices it
	*		passes to D3D to compensate).
	*	@par
	*		The generic form M * V which shows the layout of the matrix
	*		entries is shown below:
	*		<pre>
	*			[ m[0][0]  m[0][1]  m[0][2]  m[0][3] ]   {x}
	*			| m[1][0]  m[1][1]  m[1][2]  m[1][3] | * {y}
	*			| m[2][0]  m[2][1]  m[2][2]  m[2][3] |   {z}
	*			[ m[3][0]  m[3][1]  m[3][2]  m[3][3] ]   {1}
	*		</pre>
	*/
	struct mm_fix32_matrix4x4
	{
	public:
		static const mm_fix32_matrix4x4 ZERO;
		static const mm_fix32_matrix4x4 ZEROAFFINE;
		static const mm_fix32_matrix4x4 IDENTITY;
	public:
		/// The matrix entries, indexed by [row][col].
		union
		{
			mm_fix32 m[4][4];
			mm_fix32 d[16];
		};
	public:
		inline mm_fix32_matrix4x4()
		{
			mm_memset(this->d, 0, sizeof(mm_fix32) * 16);
		}

		inline mm_fix32_matrix4x4(const mm_fix32_matrix4x4& v)
		{
			mm_memcpy(this->d, v.d, sizeof(mm_fix32) * 16);
		}

		mm_fix32_matrix4x4(
			mm_fix32 m00, mm_fix32 m01, mm_fix32 m02, mm_fix32 m03,
			mm_fix32 m10, mm_fix32 m11, mm_fix32 m12, mm_fix32 m13,
			mm_fix32 m20, mm_fix32 m21, mm_fix32 m22, mm_fix32 m23,
			mm_fix32 m30, mm_fix32 m31, mm_fix32 m32, mm_fix32 m33);

		/** Creates a standard 4x4 transformation matrix with a zero translation part from a rotation/scaling 3x3 matrix.
		*/
		inline mm_fix32_matrix4x4(const mm_fix32_matrix3x3& m3x3)
		{
			operator=(IDENTITY);
			operator=(m3x3);
		}

		/** Creates a standard 4x4 transformation matrix with a zero translation part from a rotation/scaling Quaternion.
		*/
		inline mm_fix32_matrix4x4(const mm_fix32_quaternion& rot)
		{
			mm_fix32_matrix3x3 m3x3;
			rot.to_rotation_matrix(m3x3);
			operator=(IDENTITY);
			operator=(m3x3);
		}
	public:
		inline mm_fix32_matrix4x4& operator = (const mm_fix32_matrix4x4& rkMatrix)
		{
			mm_memcpy(m, rkMatrix.m, 16 * sizeof(mm_fix32));
			return *this;
		}

		/** Assignment from 3x3 matrix.
		*/
		void operator = (const mm_fix32_matrix3x3& mat3);
	public:
		/** Exchange the contents of this matrix with another.
		*/
		void swap(mm_fix32_matrix4x4& other);
	public:
		inline mm_fix32* operator [] (size_t iRow)
		{
			assert(iRow < 4);
			return m[iRow];
		}

		inline const mm_fix32 *operator [] (size_t iRow) const
		{
			assert(iRow < 4);
			return m[iRow];
		}
	public:
		mm_fix32_matrix4x4 concatenate(const mm_fix32_matrix4x4 &m2) const;

		/** Matrix concatenation using '*'.
		*/
		inline mm_fix32_matrix4x4 operator * (const mm_fix32_matrix4x4 &m2) const
		{
			return this->concatenate(m2);
		}

		/** Vector transformation using '*'.
		*	@remarks
		*		Transforms the given 3-D vector by the matrix, projecting the
		*		result back into <i>w</i> = 1.
		*	@note
		*		This means that the initial <i>w</i> is considered to be 1.0,
		*		and then all the tree elements of the resulting 3-D vector are
		*		divided by the resulting <i>w</i>.
		*/
		mm_fix32_matrix4x4 operator * (mm_fix32 scalar) const;

		/** Removed from Vector4 and made a non-member here because otherwise
		*	OgreMatrix4.h and OgreVector4.h have to try to include and inline each
		*	other, which frankly doesn't work ;)
		*/
		friend mm_fix32_vector4 operator * (const mm_fix32_vector4& v, const mm_fix32_matrix4x4& mat);
	public:
		/** Matrix addition.
		*/
		mm_fix32_matrix4x4 operator + (const mm_fix32_matrix4x4 &m2) const;

		/** Matrix subtraction.
		*/
		mm_fix32_matrix4x4 operator - (const mm_fix32_matrix4x4 &m2) const;

		/** Tests 2 matrices for equality.
		*/
		bool operator == (const mm_fix32_matrix4x4& m2) const;

		/** Tests 2 matrices for inequality.
		*/
		inline bool operator != (const mm_fix32_matrix4x4& m2) const
		{
			return !(operator ==(m2));
		}
	public:
		mm_fix32_matrix4x4 transpose(void) const;
		mm_fix32_matrix4x4 adjoint() const;
		mm_fix32 determinant() const;
		mm_fix32_matrix4x4 inverse() const;
	public:
		/*
		-----------------------------------------------------------------------
		Translation Transformation
		-----------------------------------------------------------------------
		*/
		/** Sets the translation transformation part of the matrix.
		*/
		inline void set_translation(const mm_fix32_vector3& v)
		{
			m[0][3] = v.x;
			m[1][3] = v.y;
			m[2][3] = v.z;
		}

		/** Extracts the translation transformation part of the matrix.
		*/
		inline mm_fix32_vector3 get_translation() const
		{
			return mm_fix32_vector3(m[0][3], m[1][3], m[2][3]);
		}


		/** Builds a translation matrix
		*/
		void make_translation(const mm_fix32_vector3& v);

		void make_translation(mm_fix32 tx, mm_fix32 ty, mm_fix32 tz);

		/** Gets a translation matrix.
		*/
		static mm_fix32_matrix4x4 get_translation(const mm_fix32_vector3& v);

		/** Gets a translation matrix - variation for not using a vector.
		*/
		static mm_fix32_matrix4x4 get_translation(mm_fix32 t_x, mm_fix32 t_y, mm_fix32 t_z);
	public:
		/*
		-----------------------------------------------------------------------
		Scale Transformation
		-----------------------------------------------------------------------
		*/
		/** Sets the scale part of the matrix.
		*/
		inline void set_scale(const mm_fix32_vector3& v)
		{
			m[0][0] = v.x;
			m[1][1] = v.y;
			m[2][2] = v.z;
		}

		/** Gets a scale matrix.
		*/
		static mm_fix32_matrix4x4 get_scale(const mm_fix32_vector3& v);

		/** Gets a scale matrix - variation for not using a vector.
		*/
		static mm_fix32_matrix4x4 get_scale(mm_fix32 s_x, mm_fix32 s_y, mm_fix32 s_z);

		/** Extracts the rotation / scaling part of the Matrix as a 3x3 matrix.
		@param m3x3 Destination Matrix3
		*/
		void extract_3x3_matrix(mm_fix32_matrix3x3& m3x3) const;

		/** Determines if this matrix involves a negative scaling. */
		inline bool has_negative_scale() const
		{
			return determinant() < 0;
		}

		/** Extracts the rotation / scaling part as a quaternion from the Matrix.
		*/
		inline mm_fix32_quaternion extractQuaternion() const
		{
			mm_fix32_matrix3x3 m3x3;
			this->extract_3x3_matrix(m3x3);
			return mm_fix32_quaternion(m3x3);
		}
	public:
		/** Building a Matrix4 from orientation / scale / position.
		*	@remarks
		*		Transform is performed in the order scale, rotate, translation, i.e. translation is independent
		*		of orientation axes, scale does not affect size of translation, rotation and scaling are always
		*		centered on the origin.
		*/
		void make_transform(const mm_fix32_vector3& position, const mm_fix32_vector3& scale, const mm_fix32_quaternion& orientation);

		/** Building an inverse Matrix4 from orientation / scale / position.
		*	@remarks
		*		As makeTransform except it build the inverse given the same data as makeTransform, so
		*		performing -translation, -rotate, 1/scale in that order.
		*/
		void make_inverse_transform(const mm_fix32_vector3& position, const mm_fix32_vector3& scale, const mm_fix32_quaternion& orientation);

		/** Decompose a Matrix4 to orientation / scale / position.
		*/
		void decomposition(mm_fix32_vector3& position, mm_fix32_vector3& scale, mm_fix32_quaternion& orientation) const;
	public:
		/** Check whether or not the matrix is affine matrix.
		*	@remarks
		*		An affine matrix is a 4x4 matrix with row 3 equal to (0, 0, 0, 1),
		*		e.g. no projective coefficients.
		*/
		inline bool is_affine(void) const
		{
			return m[3][0] == 0 && m[3][1] == 0 && m[3][2] == 0 && m[3][3] == 1;
		}

		/** Returns the inverse of the affine matrix.
		*	@note
		*		The matrix must be an affine matrix. @see Matrix4::isAffine.
		*/
		mm_fix32_matrix4x4 inverse_affine(void) const;

		/** Concatenate two affine matrices.
		*	@note
		*		The matrices must be affine matrix. @see Matrix4::isAffine.
		*/
		mm_fix32_matrix4x4 concatenate_affine(const mm_fix32_matrix4x4 &m2) const;

		/** 3-D Vector transformation specially for an affine matrix.
		*	@remarks
		*		Transforms the given 3-D vector by the 3x3 submatrix, without
		*		adding translation, as should be transformed directions and normals.
		*	@note
		*		The matrix must be an affine matrix. @see Matrix4::isAffine.
		*/
		mm_fix32_vector3 transform_direction_affine(const mm_fix32_vector3& v) const;

		/** 3-D Vector transformation specially for an affine matrix.
		*	@remarks
		*		Transforms the given 3-D vector by the matrix, projecting the
		*		result back into <i>w</i> = 1.
		*	@note
		*		The matrix must be an affine matrix. @see Matrix4::isAffine.
		*/
		mm_fix32_vector3 transform_affine(const mm_fix32_vector3& v) const;

		/** 4-D Vector transformation specially for an affine matrix.
		*	@note
		*		The matrix must be an affine matrix. @see Matrix4::isAffine.
		*/
		mm_fix32_vector4 transform_affine(const mm_fix32_vector4& v) const;
	public:
		friend std::ostream& operator << (std::ostream& o, const mm_fix32_matrix4x4& mat);
	};
	/** @} */
	/** @} */
}

#endif//__mm_fix32_matrix4x4_h__