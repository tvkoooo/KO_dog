#ifndef __mm_fix32_matrix3x3_h__
#define __mm_fix32_matrix3x3_h__

#include "core/mm_string.h"

#include "dish/mm_fix32.h"

#include "math/mm_fix32_vector3.h"

#include <assert.h>

// https://www.ogre3d.org/

// NB All code adapted from Wild Magic 0.2 Matrix math (free source code)
// http://www.geometrictools.com/

// NOTE.  The (x,y,z) coordinate system is assumed to be right-handed.
// Coordinate axis rotation matrices are of the form
//   RX =    1       0       0
//           0     cos(t) -sin(t)
//           0     sin(t)  cos(t)
// where t > 0 indicates a counterclockwise rotation in the yz-plane
//   RY =  cos(t)    0     sin(t)
//           0       1       0
//        -sin(t)    0     cos(t)
// where t > 0 indicates a counterclockwise rotation in the zx-plane
//   RZ =  cos(t) -sin(t)    0
//         sin(t)  cos(t)    0
//           0       0       1
// where t > 0 indicates a counterclockwise rotation in the xy-plane.

namespace mm
{
	/** \addtogroup Core
	*  @{
	*/
	/** \addtogroup Math
	*  @{
	*/
	/** A 3x3 matrix which can represent rotations around axes.
	*	@note
	*		<b>All the code is adapted from the Wild Magic 0.2 Matrix
	*		library (http://www.geometrictools.com/).</b>
	*	@par
	*		The coordinate system is assumed to be <b>right-handed</b>.
	*/
	struct mm_fix32_matrix3x3
	{
	public:
		static const mm_fix32 EPSILON;
		static const mm_fix32_matrix3x3 ZERO;
		static const mm_fix32_matrix3x3 IDENTITY;
	public:
		static const mm_fix32 msSvdEpsilon;
		static const unsigned int msSvdMaxIterations;
	public:
		union
		{
			mm_fix32 m[3][3];
			mm_fix32 d[9];
		};
	public:
		inline mm_fix32_matrix3x3()
		{
			mm_memset(this->d, 0, sizeof(mm_fix32) * 16);
		}
		/// Assignment and comparison
		inline mm_fix32_matrix3x3(const mm_fix32_matrix3x3& v)
		{
			mm_memcpy(this->d, v.d, sizeof(mm_fix32) * 16);
		}

		mm_fix32_matrix3x3(
			mm_fix32 fEntry00, mm_fix32 fEntry01, mm_fix32 fEntry02,
			mm_fix32 fEntry10, mm_fix32 fEntry11, mm_fix32 fEntry12,
			mm_fix32 fEntry20, mm_fix32 fEntry21, mm_fix32 fEntry22);
	public:
		/** Exchange the contents of this matrix with another.
		*/
		void swap(mm_fix32_matrix3x3& other);
	public:
		/// Member access, allows use of construct mat[r][c]
		inline const mm_fix32* operator [] (size_t iRow) const
		{
			assert(iRow < 3);
			return m[iRow];
		}

		inline mm_fix32* operator [] (size_t iRow)
		{
			assert(iRow < 3);
			return m[iRow];
		}
	public:
		inline mm_fix32_matrix3x3& operator = (const mm_fix32_matrix3x3& rkMatrix)
		{
			mm_memcpy(m, rkMatrix.m, 9 * sizeof(mm_fix32));
			return *this;
		}
	public:
		/** Tests 2 matrices for equality.
		*/
		bool operator == (const mm_fix32_matrix3x3& m2) const;

		/** Tests 2 matrices for inequality.
		*/
		inline bool operator != (const mm_fix32_matrix3x3& m2) const
		{
			return !operator==(m2);
		}
	public:
		// arithmetic operations
		/** Matrix addition.
		*/
		mm_fix32_matrix3x3 operator + (const mm_fix32_matrix3x3& m2) const;

		/** Matrix subtraction.
		*/
		mm_fix32_matrix3x3 operator - (const mm_fix32_matrix3x3& m2) const;
		/** Matrix concatenation using '*'.
		*/
		mm_fix32_matrix3x3 operator * (const mm_fix32_matrix3x3& m2) const;
		// matrix3x3 * vector3x1 [3x3 * 3x1 = 3x1]
		friend mm_fix32_vector3 operator * (const mm_fix32_matrix3x3& rkMatrix, const mm_fix32_vector3& rkVector);
		// vector1x3 * matrix3x3 [1x3 * 3x3 = 1x3]
		friend mm_fix32_vector3 operator * (const mm_fix32_vector3& rkVector, const mm_fix32_matrix3x3& rkMatrix);
		// Matrix * scalar
		friend mm_fix32_matrix3x3 operator * (const mm_fix32_matrix3x3& rkMatrix, mm_fix32 fScalar);
		// Scalar * matrix
		friend mm_fix32_matrix3x3 operator * (mm_fix32 fScalar, const mm_fix32_matrix3x3& rkMatrix);

		mm_fix32_matrix3x3 operator - () const;
	public:
		mm_fix32_matrix3x3 transpose() const;
		mm_fix32_matrix3x3 inverse() const;
		mm_fix32 determinant() const;
	public:
		// Singular value decomposition
		void singular_value_decomposition(mm_fix32_matrix3x3& kL, mm_fix32_vector3& kS, mm_fix32_matrix3x3& kR) const;
		void singular_value_composition(const mm_fix32_matrix3x3& rkL, const mm_fix32_vector3& rkS, const mm_fix32_matrix3x3& rkR);

		// Gram-Schmidt orthonormalization (applied to columns of rotation matrix)
		void orthonormalize();
		// Orthogonal Q, diagonal D, upper triangular U stored as (u01,u02,u12)
		void qdu_decomposition(mm_fix32_matrix3x3& kQ, mm_fix32_vector3& kD, mm_fix32_vector3& kU) const;

		mm_fix32 spectral_norm() const;

		// Note: Matrix must be orthonormal
		void to_angle_axis(mm_fix32_vector3& rkAxis, mm_fix32& rfRadians) const;
		void from_angle_axis(const mm_fix32_vector3& rkAxis, const mm_fix32& fRadians);

		/** The matrix must be orthonormal.  The decomposition is yaw*pitch*roll
		*	where yaw is rotation about the Up vector, pitch is rotation about the
		*	Right axis, and roll is rotation about the Direction axis. 
		*/
		bool to_euler_angles_xyz(mm_fix32& rfYAngle, mm_fix32& rfPAngle, mm_fix32& rfRAngle) const;
		void from_euler_angles_xyz(const mm_fix32& fYAngle, const mm_fix32& fPAngle, const mm_fix32& fRAngle);

		// Eigensolver, matrix must be symmetric
		void eigen_solve_symmetric(mm_fix32 afEigenvalue[3], mm_fix32_vector3 akEigenvector[3]) const;
	public:
		static void tensor_product(const mm_fix32_vector3& rkU, const mm_fix32_vector3& rkV, mm_fix32_matrix3x3& rkProduct);
	public:
		/** Function for writing to a stream.
		*/
		friend std::ostream& operator << (std::ostream& o, const mm_fix32_matrix3x3& mat);
	public:
		static void bidiagonalize(mm_fix32_matrix3x3& kA, mm_fix32_matrix3x3& kL, mm_fix32_matrix3x3& kR);
		static void golub_kahan_step(mm_fix32_matrix3x3& kA, mm_fix32_matrix3x3& kL, mm_fix32_matrix3x3& kR);
		// support for spectral norm
		static mm_fix32 max_cubic_root(mm_fix32 afCoeff[3]);
		// support for eigensolver
		void tridiagonal(mm_fix32 afDiag[3], mm_fix32 afSubDiag[3]);
		bool ql_algorithm(mm_fix32 afDiag[3], mm_fix32 afSubDiag[3]);
	};
	/** @} */
	/** @} */
}

#endif//__mm_fix32_matrix3x3_h__