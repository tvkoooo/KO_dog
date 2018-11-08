#include "mm_fix32_matrix3x3.h"

namespace mm
{
	const mm_fix32 mm_fix32_matrix3x3::EPSILON = 1e-06;
	const mm_fix32_matrix3x3 mm_fix32_matrix3x3::ZERO
	(
		0, 0, 0,
		0, 0, 0,
		0, 0, 0
	);

	const mm_fix32_matrix3x3 mm_fix32_matrix3x3::IDENTITY
	(
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
	);

	const mm_fix32 mm_fix32_matrix3x3::msSvdEpsilon = 1e-04;
	const unsigned int mm_fix32_matrix3x3::msSvdMaxIterations = 32;

	mm_fix32_matrix3x3::mm_fix32_matrix3x3(
		mm_fix32 fEntry00, mm_fix32 fEntry01, mm_fix32 fEntry02,
		mm_fix32 fEntry10, mm_fix32 fEntry11, mm_fix32 fEntry12,
		mm_fix32 fEntry20, mm_fix32 fEntry21, mm_fix32 fEntry22)
	{
		m[0][0] = fEntry00;
		m[0][1] = fEntry01;
		m[0][2] = fEntry02;
		m[1][0] = fEntry10;
		m[1][1] = fEntry11;
		m[1][2] = fEntry12;
		m[2][0] = fEntry20;
		m[2][1] = fEntry21;
		m[2][2] = fEntry22;
	}

	void mm_fix32_matrix3x3::swap(mm_fix32_matrix3x3& other)
	{
		std::swap(m[0][0], other.m[0][0]);
		std::swap(m[0][1], other.m[0][1]);
		std::swap(m[0][2], other.m[0][2]);
		std::swap(m[1][0], other.m[1][0]);
		std::swap(m[1][1], other.m[1][1]);
		std::swap(m[1][2], other.m[1][2]);
		std::swap(m[2][0], other.m[2][0]);
		std::swap(m[2][1], other.m[2][1]);
		std::swap(m[2][2], other.m[2][2]);
	}

	bool mm_fix32_matrix3x3::operator == (const mm_fix32_matrix3x3& m2) const
	{
		return
			m[0][0] != m2.m[0][0] || m[0][1] != m2.m[0][1] || m[0][2] != m2.m[0][2] ||
			m[1][0] != m2.m[1][0] || m[1][1] != m2.m[1][1] || m[1][2] != m2.m[1][2] ||
			m[2][0] != m2.m[2][0] || m[2][1] != m2.m[2][1] || m[2][2] != m2.m[2][2];
	}

	mm_fix32_matrix3x3 mm_fix32_matrix3x3::operator + (const mm_fix32_matrix3x3& m2) const
	{
		mm_fix32_matrix3x3 r;

		r.m[0][0] = m[0][0] + m2.m[0][0];
		r.m[0][1] = m[0][1] + m2.m[0][1];
		r.m[0][2] = m[0][2] + m2.m[0][2];

		r.m[1][0] = m[1][0] + m2.m[1][0];
		r.m[1][1] = m[1][1] + m2.m[1][1];
		r.m[1][2] = m[1][2] + m2.m[1][2];

		r.m[2][0] = m[2][0] + m2.m[2][0];
		r.m[2][1] = m[2][1] + m2.m[2][1];
		r.m[2][2] = m[2][2] + m2.m[2][2];

		return r;
	}

	mm_fix32_matrix3x3 mm_fix32_matrix3x3::operator - (const mm_fix32_matrix3x3& m2) const
	{
		mm_fix32_matrix3x3 r;
		r.m[0][0] = m[0][0] - m2.m[0][0];
		r.m[0][1] = m[0][1] - m2.m[0][1];
		r.m[0][2] = m[0][2] - m2.m[0][2];

		r.m[1][0] = m[1][0] - m2.m[1][0];
		r.m[1][1] = m[1][1] - m2.m[1][1];
		r.m[1][2] = m[1][2] - m2.m[1][2];

		r.m[2][0] = m[2][0] - m2.m[2][0];
		r.m[2][1] = m[2][1] - m2.m[2][1];
		r.m[2][2] = m[2][2] - m2.m[2][2];

		return r;
	}

	mm_fix32_matrix3x3 mm_fix32_matrix3x3::operator * (const mm_fix32_matrix3x3& m2) const
	{
		mm_fix32_matrix3x3 r;

		r.m[0][0] = m[0][0] * m2.m[0][0] + m[0][1] * m2.m[1][0] + m[0][2] * m2.m[2][0];
		r.m[0][1] = m[0][0] * m2.m[0][1] + m[0][1] * m2.m[1][1] + m[0][2] * m2.m[2][1];
		r.m[0][2] = m[0][0] * m2.m[0][2] + m[0][1] * m2.m[1][2] + m[0][2] * m2.m[2][2];

		r.m[1][0] = m[1][0] * m2.m[0][0] + m[1][1] * m2.m[1][0] + m[1][2] * m2.m[2][0];
		r.m[1][1] = m[1][0] * m2.m[0][1] + m[1][1] * m2.m[1][1] + m[1][2] * m2.m[2][1];
		r.m[1][2] = m[1][0] * m2.m[0][2] + m[1][1] * m2.m[1][2] + m[1][2] * m2.m[2][2];

		r.m[2][0] = m[2][0] * m2.m[0][0] + m[2][1] * m2.m[1][0] + m[2][2] * m2.m[2][0];
		r.m[2][1] = m[2][0] * m2.m[0][1] + m[2][1] * m2.m[1][1] + m[2][2] * m2.m[2][1];
		r.m[2][2] = m[2][0] * m2.m[0][2] + m[2][1] * m2.m[1][2] + m[2][2] * m2.m[2][2];

		return r;
	}

	mm_fix32_vector3 operator * (const mm_fix32_matrix3x3& rkMatrix, const mm_fix32_vector3& rkVector)
	{
		mm_fix32_vector3 kProd;

		kProd[0] = rkMatrix.m[0][0] * rkVector[0] + rkMatrix.m[0][1] * rkVector[1] + rkMatrix.m[0][2] * rkVector[2];
		kProd[1] = rkMatrix.m[1][0] * rkVector[0] + rkMatrix.m[1][1] * rkVector[1] + rkMatrix.m[1][2] * rkVector[2];
		kProd[2] = rkMatrix.m[2][0] * rkVector[0] + rkMatrix.m[2][1] * rkVector[1] + rkMatrix.m[2][2] * rkVector[2];

		return kProd;
	}

	mm_fix32_vector3 operator * (const mm_fix32_vector3& rkVector, const mm_fix32_matrix3x3& rkMatrix)
	{
		mm_fix32_vector3 kProd;

		kProd[0] = rkVector[0] * rkMatrix.m[0][0] + rkVector[1] * rkMatrix.m[1][0] + rkVector[2] * rkMatrix.m[2][0];
		kProd[1] = rkVector[0] * rkMatrix.m[0][1] + rkVector[1] * rkMatrix.m[1][1] + rkVector[2] * rkMatrix.m[2][1];
		kProd[2] = rkVector[0] * rkMatrix.m[0][2] + rkVector[1] * rkMatrix.m[1][2] + rkVector[2] * rkMatrix.m[2][2];

		return kProd;
	}

	mm_fix32_matrix3x3 operator * (const mm_fix32_matrix3x3& rkMatrix, mm_fix32 fScalar)
	{
		mm_fix32_matrix3x3 kProd;

		kProd[0][0] = fScalar * rkMatrix.m[0][0];
		kProd[0][1] = fScalar * rkMatrix.m[0][1];
		kProd[0][2] = fScalar * rkMatrix.m[0][2];

		kProd[1][0] = fScalar * rkMatrix.m[1][0];
		kProd[1][1] = fScalar * rkMatrix.m[1][1];
		kProd[1][2] = fScalar * rkMatrix.m[1][2];

		kProd[2][0] = fScalar * rkMatrix.m[2][0];
		kProd[2][1] = fScalar * rkMatrix.m[2][1];
		kProd[2][2] = fScalar * rkMatrix.m[2][2];

		return kProd;
	}

	mm_fix32_matrix3x3 operator * (mm_fix32 fScalar, const mm_fix32_matrix3x3& rkMatrix)
	{
		mm_fix32_matrix3x3 kProd;

		kProd[0][0] = fScalar * rkMatrix.m[0][0];
		kProd[0][1] = fScalar * rkMatrix.m[0][1];
		kProd[0][2] = fScalar * rkMatrix.m[0][2];

		kProd[1][0] = fScalar * rkMatrix.m[1][0];
		kProd[1][1] = fScalar * rkMatrix.m[1][1];
		kProd[1][2] = fScalar * rkMatrix.m[1][2];

		kProd[2][0] = fScalar * rkMatrix.m[2][0];
		kProd[2][1] = fScalar * rkMatrix.m[2][1];
		kProd[2][2] = fScalar * rkMatrix.m[2][2];

		return kProd;
	}

	mm_fix32_matrix3x3 mm_fix32_matrix3x3::operator - () const
	{
		mm_fix32_matrix3x3 r;

		r.m[0][0] = -m[0][0];
		r.m[0][1] = -m[0][1];
		r.m[0][2] = -m[0][2];

		r.m[1][0] = -m[1][0];
		r.m[1][1] = -m[1][1];
		r.m[1][2] = -m[1][2];

		r.m[2][0] = -m[2][0];
		r.m[2][1] = -m[2][1];
		r.m[2][2] = -m[2][2];

		return r;
	}

	mm_fix32_matrix3x3 mm_fix32_matrix3x3::transpose() const
	{
		mm_fix32_matrix3x3 kTranspose;

		kTranspose[0][0] = m[0][0];
		kTranspose[0][1] = m[1][0];
		kTranspose[0][2] = m[2][0];

		kTranspose[1][0] = m[0][1];
		kTranspose[1][1] = m[1][1];
		kTranspose[1][2] = m[2][1];

		kTranspose[2][0] = m[0][2];
		kTranspose[2][1] = m[1][2];
		kTranspose[2][2] = m[2][2];

		return kTranspose;
	}

	mm_fix32_matrix3x3 mm_fix32_matrix3x3::inverse() const
	{
		// Invert a 3x3 using cofactors.  This is about 8 times faster than
		// the Numerical Recipes code which uses Gaussian elimination.
		mm_fix32_matrix3x3 rkInverse;

		rkInverse[0][0] = m[1][1] * m[2][2] - m[1][2] * m[2][1];
		rkInverse[0][1] = m[0][2] * m[2][1] - m[0][1] * m[2][2];
		rkInverse[0][2] = m[0][1] * m[1][2] - m[0][2] * m[1][1];
		rkInverse[1][0] = m[1][2] * m[2][0] - m[1][0] * m[2][2];
		rkInverse[1][1] = m[0][0] * m[2][2] - m[0][2] * m[2][0];
		rkInverse[1][2] = m[0][2] * m[1][0] - m[0][0] * m[1][2];
		rkInverse[2][0] = m[1][0] * m[2][1] - m[1][1] * m[2][0];
		rkInverse[2][1] = m[0][1] * m[2][0] - m[0][0] * m[2][1];
		rkInverse[2][2] = m[0][0] * m[1][1] - m[0][1] * m[1][0];

		mm_fix32 fDet =
			m[0][0] * rkInverse[0][0] +
			m[0][1] * rkInverse[1][0] +
			m[0][2] * rkInverse[2][0];

		mm_fix32 fInvDet = 1.0f / fDet;

		rkInverse[0][0] *= fInvDet;
		rkInverse[0][1] *= fInvDet;
		rkInverse[0][2] *= fInvDet;

		rkInverse[1][0] *= fInvDet;
		rkInverse[1][1] *= fInvDet;
		rkInverse[1][2] *= fInvDet;

		rkInverse[2][0] *= fInvDet;
		rkInverse[2][1] *= fInvDet;
		rkInverse[2][2] *= fInvDet;

		return rkInverse;
	}
	mm_fix32 mm_fix32_matrix3x3::determinant() const
	{
		mm_fix32 fCofactor00 = m[1][1] * m[2][2] - m[1][2] * m[2][1];
		mm_fix32 fCofactor10 = m[1][2] * m[2][0] - m[1][0] * m[2][2];
		mm_fix32 fCofactor20 = m[1][0] * m[2][1] - m[1][1] * m[2][0];

		return 
			m[0][0] * fCofactor00 +
			m[0][1] * fCofactor10 +
			m[0][2] * fCofactor20;
	}
	// Singular value decomposition
	void mm_fix32_matrix3x3::singular_value_decomposition(mm_fix32_matrix3x3& kL, mm_fix32_vector3& kS, mm_fix32_matrix3x3& kR) const
	{
		// temas: currently unused
		//const int iMax = 16;
		size_t iRow, iCol;

		mm_fix32_matrix3x3 kA = *this;
		bidiagonalize(kA, kL, kR);

		for (unsigned int i = 0; i < msSvdMaxIterations; i++)
		{
			mm_fix32 fTmp, fTmp0, fTmp1;
			mm_fix32 fSin0, fCos0, fTan0;
			mm_fix32 fSin1, fCos1, fTan1;

			bool bTest1 = (fabs(kA[0][1]) <=
				msSvdEpsilon * (fabs(kA[0][0]) + fabs(kA[1][1])));
			bool bTest2 = (fabs(kA[1][2]) <=
				msSvdEpsilon * (fabs(kA[1][1]) + fabs(kA[2][2])));
			if (bTest1)
			{
				if (bTest2)
				{
					kS[0] = kA[0][0];
					kS[1] = kA[1][1];
					kS[2] = kA[2][2];
					break;
				}
				else
				{
					// 2x2 closed form factorization
					fTmp = (kA[1][1] * kA[1][1] - kA[2][2] * kA[2][2] +
						kA[1][2] * kA[1][2]) / (kA[1][2] * kA[2][2]);
					fTan0 = 0.5f*(fTmp + sqrt(fTmp*fTmp + 4.0f));
					fCos0 = inv_sqrt(1.0f + fTan0 * fTan0);
					fSin0 = fTan0 * fCos0;

					for (iCol = 0; iCol < 3; iCol++)
					{
						fTmp0 = kL[iCol][1];
						fTmp1 = kL[iCol][2];
						kL[iCol][1] = fCos0 * fTmp0 - fSin0 * fTmp1;
						kL[iCol][2] = fSin0 * fTmp0 + fCos0 * fTmp1;
					}

					fTan1 = (kA[1][2] - kA[2][2] * fTan0) / kA[1][1];
					fCos1 = inv_sqrt(1.0f + fTan1 * fTan1);
					fSin1 = -fTan1 * fCos1;

					for (iRow = 0; iRow < 3; iRow++)
					{
						fTmp0 = kR[1][iRow];
						fTmp1 = kR[2][iRow];
						kR[1][iRow] = fCos1 * fTmp0 - fSin1 * fTmp1;
						kR[2][iRow] = fSin1 * fTmp0 + fCos1 * fTmp1;
					}

					kS[0] = kA[0][0];
					kS[1] = fCos0 * fCos1*kA[1][1] -
						fSin1 * (fCos0*kA[1][2] - fSin0 * kA[2][2]);
					kS[2] = fSin0 * fSin1*kA[1][1] +
						fCos1 * (fSin0*kA[1][2] + fCos0 * kA[2][2]);
					break;
				}
			}
			else
			{
				if (bTest2)
				{
					// 2x2 closed form factorization
					fTmp = (kA[0][0] * kA[0][0] + kA[1][1] * kA[1][1] -
						kA[0][1] * kA[0][1]) / (kA[0][1] * kA[1][1]);
					fTan0 = 0.5f*(-fTmp + sqrt(fTmp*fTmp + 4.0f));
					fCos0 = inv_sqrt(1.0f + fTan0 * fTan0);
					fSin0 = fTan0 * fCos0;

					for (iCol = 0; iCol < 3; iCol++)
					{
						fTmp0 = kL[iCol][0];
						fTmp1 = kL[iCol][1];
						kL[iCol][0] = fCos0 * fTmp0 - fSin0 * fTmp1;
						kL[iCol][1] = fSin0 * fTmp0 + fCos0 * fTmp1;
					}

					fTan1 = (kA[0][1] - kA[1][1] * fTan0) / kA[0][0];
					fCos1 = inv_sqrt(1.0f + fTan1 * fTan1);
					fSin1 = -fTan1 * fCos1;

					for (iRow = 0; iRow < 3; iRow++)
					{
						fTmp0 = kR[0][iRow];
						fTmp1 = kR[1][iRow];
						kR[0][iRow] = fCos1 * fTmp0 - fSin1 * fTmp1;
						kR[1][iRow] = fSin1 * fTmp0 + fCos1 * fTmp1;
					}

					kS[0] = fCos0 * fCos1*kA[0][0] -
						fSin1 * (fCos0*kA[0][1] - fSin0 * kA[1][1]);
					kS[1] = fSin0 * fSin1*kA[0][0] +
						fCos1 * (fSin0*kA[0][1] + fCos0 * kA[1][1]);
					kS[2] = kA[2][2];
					break;
				}
				else
				{
					golub_kahan_step(kA, kL, kR);
				}
			}
		}

		// positize diagonal
		for (iRow = 0; iRow < 3; iRow++)
		{
			if (kS[iRow] < 0.0)
			{
				kS[iRow] = -kS[iRow];
				for (iCol = 0; iCol < 3; iCol++)
					kR[iRow][iCol] = -kR[iRow][iCol];
			}
		}
	}
	void mm_fix32_matrix3x3::singular_value_composition(const mm_fix32_matrix3x3& kL, const mm_fix32_vector3& kS, const mm_fix32_matrix3x3& kR)
	{
		size_t iRow, iCol;
		mm_fix32_matrix3x3 kTmp;

		// product S*R
		for (iRow = 0; iRow < 3; iRow++)
		{
			for (iCol = 0; iCol < 3; iCol++)
				kTmp[iRow][iCol] = kS[iRow] * kR[iRow][iCol];
		}

		// product L*S*R
		for (iRow = 0; iRow < 3; iRow++)
		{
			for (iCol = 0; iCol < 3; iCol++)
			{
				m[iRow][iCol] = 0.0;
				for (int iMid = 0; iMid < 3; iMid++)
					m[iRow][iCol] += kL[iRow][iMid] * kTmp[iMid][iCol];
			}
		}
	}
	void mm_fix32_matrix3x3::orthonormalize()
	{
		// Algorithm uses Gram-Schmidt orthogonalization.  If 'this' matrix is
		// M = [m0|m1|m2], then orthonormal output matrix is Q = [q0|q1|q2],
		//
		//   q0 = m0/|m0|
		//   q1 = (m1-(q0*m1)q0)/|m1-(q0*m1)q0|
		//   q2 = (m2-(q0*m2)q0-(q1*m2)q1)/|m2-(q0*m2)q0-(q1*m2)q1|
		//
		// where |V| indicates length of vector V and A*B indicates dot
		// product of vectors A and B.

		// compute q0
		mm_fix32 fInvLength = inv_sqrt(m[0][0] * m[0][0]
			+ m[1][0] * m[1][0] +
			m[2][0] * m[2][0]);

		m[0][0] *= fInvLength;
		m[1][0] *= fInvLength;
		m[2][0] *= fInvLength;

		// compute q1
		mm_fix32 fDot0 =
			m[0][0] * m[0][1] +
			m[1][0] * m[1][1] +
			m[2][0] * m[2][1];

		m[0][1] -= fDot0 * m[0][0];
		m[1][1] -= fDot0 * m[1][0];
		m[2][1] -= fDot0 * m[2][0];

		fInvLength = inv_sqrt(m[0][1] * m[0][1] +
			m[1][1] * m[1][1] +
			m[2][1] * m[2][1]);

		m[0][1] *= fInvLength;
		m[1][1] *= fInvLength;
		m[2][1] *= fInvLength;

		// compute q2
		mm_fix32 fDot1 =
			m[0][1] * m[0][2] +
			m[1][1] * m[1][2] +
			m[2][1] * m[2][2];

		fDot0 =
			m[0][0] * m[0][2] +
			m[1][0] * m[1][2] +
			m[2][0] * m[2][2];

		m[0][2] -= fDot0 * m[0][0] + fDot1 * m[0][1];
		m[1][2] -= fDot0 * m[1][0] + fDot1 * m[1][1];
		m[2][2] -= fDot0 * m[2][0] + fDot1 * m[2][1];

		fInvLength = inv_sqrt(m[0][2] * m[0][2] +
			m[1][2] * m[1][2] +
			m[2][2] * m[2][2]);

		m[0][2] *= fInvLength;
		m[1][2] *= fInvLength;
		m[2][2] *= fInvLength;
	}
	//-----------------------------------------------------------------------
	void mm_fix32_matrix3x3::qdu_decomposition(mm_fix32_matrix3x3& kQ, mm_fix32_vector3& kD, mm_fix32_vector3& kU) const
	{
		// Factor M = QR = QDU where Q is orthogonal, D is diagonal,
		// and U is upper triangular with ones on its diagonal.  Algorithm uses
		// Gram-Schmidt orthogonalization (the QR algorithm).
		//
		// If M = [ m0 | m1 | m2 ] and Q = [ q0 | q1 | q2 ], then
		//
		//   q0 = m0/|m0|
		//   q1 = (m1-(q0*m1)q0)/|m1-(q0*m1)q0|
		//   q2 = (m2-(q0*m2)q0-(q1*m2)q1)/|m2-(q0*m2)q0-(q1*m2)q1|
		//
		// where |V| indicates length of vector V and A*B indicates dot
		// product of vectors A and B.  The matrix R has entries
		//
		//   r00 = q0*m0  r01 = q0*m1  r02 = q0*m2
		//   r10 = 0      r11 = q1*m1  r12 = q1*m2
		//   r20 = 0      r21 = 0      r22 = q2*m2
		//
		// so D = diag(r00,r11,r22) and U has entries u01 = r01/r00,
		// u02 = r02/r00, and u12 = r12/r11.

		// Q = rotation
		// D = scaling
		// U = shear

		// D stores the three diagonal entries r00, r11, r22
		// U stores the entries U[0] = u01, U[1] = u02, U[2] = u12

		// build orthogonal matrix Q
		mm_fix32 fInvLength = inv_sqrt(m[0][0] * m[0][0] + m[1][0] * m[1][0] + m[2][0] * m[2][0]);

		kQ[0][0] = m[0][0] * fInvLength;
		kQ[1][0] = m[1][0] * fInvLength;
		kQ[2][0] = m[2][0] * fInvLength;

		mm_fix32 fDot = kQ[0][0] * m[0][1] + kQ[1][0] * m[1][1] +
			kQ[2][0] * m[2][1];
		kQ[0][1] = m[0][1] - fDot * kQ[0][0];
		kQ[1][1] = m[1][1] - fDot * kQ[1][0];
		kQ[2][1] = m[2][1] - fDot * kQ[2][0];
		fInvLength = inv_sqrt(kQ[0][1] * kQ[0][1] + kQ[1][1] * kQ[1][1] + kQ[2][1] * kQ[2][1]);

		kQ[0][1] *= fInvLength;
		kQ[1][1] *= fInvLength;
		kQ[2][1] *= fInvLength;

		fDot = kQ[0][0] * m[0][2] + kQ[1][0] * m[1][2] +
			kQ[2][0] * m[2][2];
		kQ[0][2] = m[0][2] - fDot * kQ[0][0];
		kQ[1][2] = m[1][2] - fDot * kQ[1][0];
		kQ[2][2] = m[2][2] - fDot * kQ[2][0];
		fDot = kQ[0][1] * m[0][2] + kQ[1][1] * m[1][2] +
			kQ[2][1] * m[2][2];
		kQ[0][2] -= fDot * kQ[0][1];
		kQ[1][2] -= fDot * kQ[1][1];
		kQ[2][2] -= fDot * kQ[2][1];
		fInvLength = inv_sqrt(kQ[0][2] * kQ[0][2] + kQ[1][2] * kQ[1][2] + kQ[2][2] * kQ[2][2]);

		kQ[0][2] *= fInvLength;
		kQ[1][2] *= fInvLength;
		kQ[2][2] *= fInvLength;

		// guarantee that orthogonal matrix has determinant 1 (no reflections)
		mm_fix32 fDet = kQ[0][0] * kQ[1][1] * kQ[2][2] + kQ[0][1] * kQ[1][2] * kQ[2][0] +
			kQ[0][2] * kQ[1][0] * kQ[2][1] - kQ[0][2] * kQ[1][1] * kQ[2][0] -
			kQ[0][1] * kQ[1][0] * kQ[2][2] - kQ[0][0] * kQ[1][2] * kQ[2][1];

		if (fDet < 0.0)
		{
			for (size_t iRow = 0; iRow < 3; iRow++)
				for (size_t iCol = 0; iCol < 3; iCol++)
					kQ[iRow][iCol] = -kQ[iRow][iCol];
		}

		// build "right" matrix R
		mm_fix32_matrix3x3 kR;
		kR[0][0] = kQ[0][0] * m[0][0] + kQ[1][0] * m[1][0] +
			kQ[2][0] * m[2][0];
		kR[0][1] = kQ[0][0] * m[0][1] + kQ[1][0] * m[1][1] +
			kQ[2][0] * m[2][1];
		kR[1][1] = kQ[0][1] * m[0][1] + kQ[1][1] * m[1][1] +
			kQ[2][1] * m[2][1];
		kR[0][2] = kQ[0][0] * m[0][2] + kQ[1][0] * m[1][2] +
			kQ[2][0] * m[2][2];
		kR[1][2] = kQ[0][1] * m[0][2] + kQ[1][1] * m[1][2] +
			kQ[2][1] * m[2][2];
		kR[2][2] = kQ[0][2] * m[0][2] + kQ[1][2] * m[1][2] +
			kQ[2][2] * m[2][2];

		// the scaling component
		kD[0] = kR[0][0];
		kD[1] = kR[1][1];
		kD[2] = kR[2][2];

		// the shear component
		mm_fix32 fInvD0 = 1.0f / kD[0];
		kU[0] = kR[0][1] * fInvD0;
		kU[1] = kR[0][2] * fInvD0;
		kU[2] = kR[1][2] / kD[1];
	}
	mm_fix32 mm_fix32_matrix3x3::spectral_norm() const
	{
		mm_fix32_matrix3x3 kP;
		size_t iRow, iCol;
		mm_fix32 fPmax = 0.0;
		for (iRow = 0; iRow < 3; iRow++)
		{
			for (iCol = 0; iCol < 3; iCol++)
			{
				kP[iRow][iCol] = 0.0;
				for (int iMid = 0; iMid < 3; iMid++)
				{
					kP[iRow][iCol] +=
						m[iMid][iRow] * m[iMid][iCol];
				}
				if (kP[iRow][iCol] > fPmax)
					fPmax = kP[iRow][iCol];
			}
		}

		mm_fix32 fInvPmax = 1.0f / fPmax;
		for (iRow = 0; iRow < 3; iRow++)
		{
			for (iCol = 0; iCol < 3; iCol++)
				kP[iRow][iCol] *= fInvPmax;
		}

		mm_fix32 afCoeff[3];
		afCoeff[0] = -(kP[0][0] * (kP[1][1] * kP[2][2] - kP[1][2] * kP[2][1]) +
			kP[0][1] * (kP[2][0] * kP[1][2] - kP[1][0] * kP[2][2]) +
			kP[0][2] * (kP[1][0] * kP[2][1] - kP[2][0] * kP[1][1]));
		afCoeff[1] = kP[0][0] * kP[1][1] - kP[0][1] * kP[1][0] +
			kP[0][0] * kP[2][2] - kP[0][2] * kP[2][0] +
			kP[1][1] * kP[2][2] - kP[1][2] * kP[2][1];
		afCoeff[2] = -(kP[0][0] + kP[1][1] + kP[2][2]);

		mm_fix32 fRoot = max_cubic_root(afCoeff);
		mm_fix32 fNorm = sqrt(fPmax*fRoot);
		return fNorm;
	}
	void mm_fix32_matrix3x3::to_angle_axis(mm_fix32_vector3& rkAxis, mm_fix32& rfRadians) const
	{
		// Let (x,y,z) be the unit-length axis and let A be an angle of rotation.
		// The rotation matrix is R = I + sin(A)*P + (1-cos(A))*P^2 where
		// I is the identity and
		//
		//       +-        -+
		//   P = |  0 -z +y |
		//       | +z  0 -x |
		//       | -y +x  0 |
		//       +-        -+
		//
		// If A > 0, R represents a counterclockwise rotation about the axis in
		// the sense of looking from the tip of the axis vector towards the
		// origin.  Some algebra will show that
		//
		//   cos(A) = (trace(R)-1)/2  and  R - R^t = 2*sin(A)*P
		//
		// In the event that A = pi, R-R^t = 0 which prevents us from extracting
		// the axis through P.  Instead note that R = I+2*P^2 when A = pi, so
		// P^2 = (R-I)/2.  The diagonal entries of P^2 are x^2-1, y^2-1, and
		// z^2-1.  We can solve these for axis (x,y,z).  Because the angle is pi,
		// it does not matter which sign you choose on the square roots.

		mm_fix32 fTrace = m[0][0] + m[1][1] + m[2][2];
		mm_fix32 fCos = 0.5f*(fTrace - 1.0f);
		rfRadians = acos(fCos);  // in [0,PI]

		if (rfRadians > mm_fix32(0.0))
		{
			if (rfRadians < mm_fix32::MM_PI)
			{
				rkAxis.x = m[2][1] - m[1][2];
				rkAxis.y = m[0][2] - m[2][0];
				rkAxis.z = m[1][0] - m[0][1];
				rkAxis.normalise();
			}
			else
			{
				// angle is PI
				float fHalfInverse;
				if (m[0][0] >= m[1][1])
				{
					// r00 >= r11
					if (m[0][0] >= m[2][2])
					{
						// r00 is maximum diagonal term
						rkAxis.x = 0.5f*sqrt(m[0][0] -
							m[1][1] - m[2][2] + 1.0f);
						fHalfInverse = 0.5f / rkAxis.x;
						rkAxis.y = fHalfInverse * m[0][1];
						rkAxis.z = fHalfInverse * m[0][2];
					}
					else
					{
						// r22 is maximum diagonal term
						rkAxis.z = 0.5f*sqrt(m[2][2] -
							m[0][0] - m[1][1] + 1.0f);
						fHalfInverse = 0.5f / rkAxis.z;
						rkAxis.x = fHalfInverse * m[0][2];
						rkAxis.y = fHalfInverse * m[1][2];
					}
				}
				else
				{
					// r11 > r00
					if (m[1][1] >= m[2][2])
					{
						// r11 is maximum diagonal term
						rkAxis.y = 0.5f*sqrt(m[1][1] -
							m[0][0] - m[2][2] + 1.0f);
						fHalfInverse = 0.5f / rkAxis.y;
						rkAxis.x = fHalfInverse * m[0][1];
						rkAxis.z = fHalfInverse * m[1][2];
					}
					else
					{
						// r22 is maximum diagonal term
						rkAxis.z = 0.5f*sqrt(m[2][2] -
							m[0][0] - m[1][1] + 1.0f);
						fHalfInverse = 0.5f / rkAxis.z;
						rkAxis.x = fHalfInverse * m[0][2];
						rkAxis.y = fHalfInverse * m[1][2];
					}
				}
			}
		}
		else
		{
			// The angle is 0 and the matrix is the identity.  Any axis will
			// work, so just use the x-axis.
			rkAxis.x = 1.0;
			rkAxis.y = 0.0;
			rkAxis.z = 0.0;
		}
	}
	void mm_fix32_matrix3x3::from_angle_axis(const mm_fix32_vector3& rkAxis, const mm_fix32& fRadians)
	{
		mm_fix32 fCos = cos(fRadians);
		mm_fix32 fSin = sin(fRadians);
		mm_fix32 fOneMinusCos = 1.0f - fCos;
		mm_fix32 fX2 = rkAxis.x*rkAxis.x;
		mm_fix32 fY2 = rkAxis.y*rkAxis.y;
		mm_fix32 fZ2 = rkAxis.z*rkAxis.z;
		mm_fix32 fXYM = rkAxis.x*rkAxis.y*fOneMinusCos;
		mm_fix32 fXZM = rkAxis.x*rkAxis.z*fOneMinusCos;
		mm_fix32 fYZM = rkAxis.y*rkAxis.z*fOneMinusCos;
		mm_fix32 fXSin = rkAxis.x*fSin;
		mm_fix32 fYSin = rkAxis.y*fSin;
		mm_fix32 fZSin = rkAxis.z*fSin;

		m[0][0] = fX2 * fOneMinusCos + fCos;
		m[0][1] = fXYM - fZSin;
		m[0][2] = fXZM + fYSin;
		m[1][0] = fXYM + fZSin;
		m[1][1] = fY2 * fOneMinusCos + fCos;
		m[1][2] = fYZM - fXSin;
		m[2][0] = fXZM - fYSin;
		m[2][1] = fYZM + fXSin;
		m[2][2] = fZ2 * fOneMinusCos + fCos;
	}
	bool mm_fix32_matrix3x3::to_euler_angles_xyz(mm_fix32& rfYAngle, mm_fix32& rfPAngle, mm_fix32& rfRAngle) const
	{
		// rot =  cy*cz          -cy*sz           sy
		//        cz*sx*sy+cx*sz  cx*cz-sx*sy*sz -cy*sx
		//       -cx*cz*sy+sx*sz  cz*sx+cx*sy*sz  cx*cy

		rfPAngle = asin(m[0][2]);
		if (rfPAngle < mm_fix32::MM_PI_DIV_2)
		{
			if (rfPAngle > -mm_fix32::MM_PI_DIV_2)
			{
				rfYAngle = atan2(-m[1][2], m[2][2]);
				rfRAngle = atan2(-m[0][1], m[0][0]);
				return true;
			}
			else
			{
				// WARNING.  Not a unique solution.
				mm_fix32 fRmY = atan2(m[1][0], m[1][1]);
				rfRAngle = mm_fix32(0.0);  // any angle works
				rfYAngle = rfRAngle - fRmY;
				return false;
			}
		}
		else
		{
			// WARNING.  Not a unique solution.
			mm_fix32 fRpY = atan2(m[1][0], m[1][1]);
			rfRAngle = mm_fix32(0.0);  // any angle works
			rfYAngle = fRpY - rfRAngle;
			return false;
		}
	}
	void mm_fix32_matrix3x3::from_euler_angles_xyz(const mm_fix32& fYAngle, const mm_fix32& fPAngle, const mm_fix32& fRAngle)
	{
		mm_fix32 fCos, fSin;

		fCos = cos(fYAngle);
		fSin = sin(fYAngle);
		mm_fix32_matrix3x3 kXMat(1.0, 0.0, 0.0, 0.0, fCos, -fSin, 0.0, fSin, fCos);

		fCos = cos(fPAngle);
		fSin = sin(fPAngle);
		mm_fix32_matrix3x3 kYMat(fCos, 0.0, fSin, 0.0, 1.0, 0.0, -fSin, 0.0, fCos);

		fCos = cos(fRAngle);
		fSin = sin(fRAngle);
		mm_fix32_matrix3x3 kZMat(fCos, -fSin, 0.0, fSin, fCos, 0.0, 0.0, 0.0, 1.0);

		*this = kXMat * (kYMat*kZMat);
	}
	void mm_fix32_matrix3x3::eigen_solve_symmetric(mm_fix32 afEigenvalue[3], mm_fix32_vector3 akEigenvector[3]) const
	{
		mm_fix32_matrix3x3 kMatrix = *this;
		mm_fix32 afSubDiag[3];
		kMatrix.tridiagonal(afEigenvalue, afSubDiag);
		kMatrix.ql_algorithm(afEigenvalue, afSubDiag);

		for (size_t i = 0; i < 3; i++)
		{
			akEigenvector[i][0] = kMatrix[0][i];
			akEigenvector[i][1] = kMatrix[1][i];
			akEigenvector[i][2] = kMatrix[2][i];
		}

		// make eigenvectors form a right--handed system
		mm_fix32_vector3 kCross = akEigenvector[1].cross_product(akEigenvector[2]);
		mm_fix32 fDet = akEigenvector[0].dot_product(kCross);
		if (fDet < 0.0)
		{
			akEigenvector[2][0] = -akEigenvector[2][0];
			akEigenvector[2][1] = -akEigenvector[2][1];
			akEigenvector[2][2] = -akEigenvector[2][2];
		}
	}
	void mm_fix32_matrix3x3::tensor_product(const mm_fix32_vector3& rkU, const mm_fix32_vector3& rkV, mm_fix32_matrix3x3& rkProduct)
	{
		for (size_t iRow = 0; iRow < 3; iRow++)
		{
			for (size_t iCol = 0; iCol < 3; iCol++)
				rkProduct[iRow][iCol] = rkU[iRow] * rkV[iCol];
		}
	}
	//
	std::ostream& operator << (std::ostream& o, const mm_fix32_matrix3x3& mat)
	{
		o << "matrix3(";
		for (size_t i = 0; i < 3; ++i)
		{
			o << " row" << (unsigned)i << "{";
			for (size_t j = 0; j < 3; ++j)
			{
				o << mat[i][j] << " ";
			}
			o << "}";
		}
		o << ")";
		return o;
	}
	//
	void mm_fix32_matrix3x3::bidiagonalize(mm_fix32_matrix3x3& kA, mm_fix32_matrix3x3& kL, mm_fix32_matrix3x3& kR)
	{
		mm_fix32 afV[3], afW[3];
		mm_fix32 fLength, fSign, fT1, fInvT1, fT2;
		bool bIdentity;

		// map first column to (*,0,0)
		fLength = sqrt(kA[0][0] * kA[0][0] + kA[1][0] * kA[1][0] + kA[2][0] * kA[2][0]);
		if (fLength > 0.0)
		{
			fSign = (kA[0][0] > 0.0f ? 1.0f : -1.0f);
			fT1 = kA[0][0] + fSign * fLength;
			fInvT1 = 1.0f / fT1;
			afV[1] = kA[1][0] * fInvT1;
			afV[2] = kA[2][0] * fInvT1;

			fT2 = -2.0f / (1.0f + afV[1] * afV[1] + afV[2] * afV[2]);
			afW[0] = fT2 * (kA[0][0] + kA[1][0] * afV[1] + kA[2][0] * afV[2]);
			afW[1] = fT2 * (kA[0][1] + kA[1][1] * afV[1] + kA[2][1] * afV[2]);
			afW[2] = fT2 * (kA[0][2] + kA[1][2] * afV[1] + kA[2][2] * afV[2]);
			kA[0][0] += afW[0];
			kA[0][1] += afW[1];
			kA[0][2] += afW[2];
			kA[1][1] += afV[1] * afW[1];
			kA[1][2] += afV[1] * afW[2];
			kA[2][1] += afV[2] * afW[1];
			kA[2][2] += afV[2] * afW[2];

			kL[0][0] = 1.0f + fT2;
			kL[0][1] = kL[1][0] = fT2 * afV[1];
			kL[0][2] = kL[2][0] = fT2 * afV[2];
			kL[1][1] = 1.0f + fT2 * afV[1] * afV[1];
			kL[1][2] = kL[2][1] = fT2 * afV[1] * afV[2];
			kL[2][2] = 1.0f + fT2 * afV[2] * afV[2];
			bIdentity = false;
		}
		else
		{
			kL = mm_fix32_matrix3x3::IDENTITY;
			bIdentity = true;
		}

		// map first row to (*,*,0)
		fLength = sqrt(kA[0][1] * kA[0][1] + kA[0][2] * kA[0][2]);
		if (fLength > 0.0)
		{
			fSign = (kA[0][1] > 0.0f ? 1.0f : -1.0f);
			fT1 = kA[0][1] + fSign * fLength;
			afV[2] = kA[0][2] / fT1;

			fT2 = -2.0f / (1.0f + afV[2] * afV[2]);
			afW[0] = fT2 * (kA[0][1] + kA[0][2] * afV[2]);
			afW[1] = fT2 * (kA[1][1] + kA[1][2] * afV[2]);
			afW[2] = fT2 * (kA[2][1] + kA[2][2] * afV[2]);
			kA[0][1] += afW[0];
			kA[1][1] += afW[1];
			kA[1][2] += afW[1] * afV[2];
			kA[2][1] += afW[2];
			kA[2][2] += afW[2] * afV[2];

			kR[0][0] = 1.0;
			kR[0][1] = kR[1][0] = 0.0;
			kR[0][2] = kR[2][0] = 0.0;
			kR[1][1] = 1.0f + fT2;
			kR[1][2] = kR[2][1] = fT2 * afV[2];
			kR[2][2] = 1.0f + fT2 * afV[2] * afV[2];
		}
		else
		{
			kR = mm_fix32_matrix3x3::IDENTITY;
		}

		// map second column to (*,*,0)
		fLength = sqrt(kA[1][1] * kA[1][1] + kA[2][1] * kA[2][1]);
		if (fLength > 0.0)
		{
			fSign = (kA[1][1] > 0.0f ? 1.0f : -1.0f);
			fT1 = kA[1][1] + fSign * fLength;
			afV[2] = kA[2][1] / fT1;

			fT2 = -2.0f / (1.0f + afV[2] * afV[2]);
			afW[1] = fT2 * (kA[1][1] + kA[2][1] * afV[2]);
			afW[2] = fT2 * (kA[1][2] + kA[2][2] * afV[2]);
			kA[1][1] += afW[1];
			kA[1][2] += afW[2];
			kA[2][2] += afV[2] * afW[2];

			mm_fix32 fA = 1.0f + fT2;
			mm_fix32 fB = fT2 * afV[2];
			mm_fix32 fC = 1.0f + fB * afV[2];

			if (bIdentity)
			{
				kL[0][0] = 1.0;
				kL[0][1] = kL[1][0] = 0.0;
				kL[0][2] = kL[2][0] = 0.0;
				kL[1][1] = fA;
				kL[1][2] = kL[2][1] = fB;
				kL[2][2] = fC;
			}
			else
			{
				for (int iRow = 0; iRow < 3; iRow++)
				{
					mm_fix32 fTmp0 = kL[iRow][1];
					mm_fix32 fTmp1 = kL[iRow][2];
					kL[iRow][1] = fA * fTmp0 + fB * fTmp1;
					kL[iRow][2] = fB * fTmp0 + fC * fTmp1;
				}
			}
		}
	}
	void mm_fix32_matrix3x3::golub_kahan_step(mm_fix32_matrix3x3& kA, mm_fix32_matrix3x3& kL, mm_fix32_matrix3x3& kR)
	{
		mm_fix32 fT11 = kA[0][1] * kA[0][1] + kA[1][1] * kA[1][1];
		mm_fix32 fT22 = kA[1][2] * kA[1][2] + kA[2][2] * kA[2][2];
		mm_fix32 fT12 = kA[1][1] * kA[1][2];
		mm_fix32 fTrace = fT11 + fT22;
		mm_fix32 fDiff = fT11 - fT22;
		mm_fix32 fDiscr = sqrt(fDiff*fDiff + 4.0f*fT12*fT12);
		mm_fix32 fRoot1 = 0.5f*(fTrace + fDiscr);
		mm_fix32 fRoot2 = 0.5f*(fTrace - fDiscr);

		// adjust right
		mm_fix32 fY = kA[0][0] - (fabs(fRoot1 - fT22) <= fabs(fRoot2 - fT22) ? fRoot1 : fRoot2);
		mm_fix32 fZ = kA[0][1];
		mm_fix32 fInvLength = inv_sqrt(fY*fY + fZ * fZ);
		mm_fix32 fSin = fZ * fInvLength;
		mm_fix32 fCos = -fY * fInvLength;

		mm_fix32 fTmp0 = kA[0][0];
		mm_fix32 fTmp1 = kA[0][1];
		kA[0][0] = fCos * fTmp0 - fSin * fTmp1;
		kA[0][1] = fSin * fTmp0 + fCos * fTmp1;
		kA[1][0] = -fSin * kA[1][1];
		kA[1][1] *= fCos;

		size_t iRow;
		for (iRow = 0; iRow < 3; iRow++)
		{
			fTmp0 = kR[0][iRow];
			fTmp1 = kR[1][iRow];
			kR[0][iRow] = fCos * fTmp0 - fSin * fTmp1;
			kR[1][iRow] = fSin * fTmp0 + fCos * fTmp1;
		}

		// adjust left
		fY = kA[0][0];
		fZ = kA[1][0];
		fInvLength = inv_sqrt(fY*fY + fZ * fZ);
		fSin = fZ * fInvLength;
		fCos = -fY * fInvLength;

		kA[0][0] = fCos * kA[0][0] - fSin * kA[1][0];
		fTmp0 = kA[0][1];
		fTmp1 = kA[1][1];
		kA[0][1] = fCos * fTmp0 - fSin * fTmp1;
		kA[1][1] = fSin * fTmp0 + fCos * fTmp1;
		kA[0][2] = -fSin * kA[1][2];
		kA[1][2] *= fCos;

		size_t iCol;
		for (iCol = 0; iCol < 3; iCol++)
		{
			fTmp0 = kL[iCol][0];
			fTmp1 = kL[iCol][1];
			kL[iCol][0] = fCos * fTmp0 - fSin * fTmp1;
			kL[iCol][1] = fSin * fTmp0 + fCos * fTmp1;
		}

		// adjust right
		fY = kA[0][1];
		fZ = kA[0][2];
		fInvLength = inv_sqrt(fY*fY + fZ * fZ);
		fSin = fZ * fInvLength;
		fCos = -fY * fInvLength;

		kA[0][1] = fCos * kA[0][1] - fSin * kA[0][2];
		fTmp0 = kA[1][1];
		fTmp1 = kA[1][2];
		kA[1][1] = fCos * fTmp0 - fSin * fTmp1;
		kA[1][2] = fSin * fTmp0 + fCos * fTmp1;
		kA[2][1] = -fSin * kA[2][2];
		kA[2][2] *= fCos;

		for (iRow = 0; iRow < 3; iRow++)
		{
			fTmp0 = kR[1][iRow];
			fTmp1 = kR[2][iRow];
			kR[1][iRow] = fCos * fTmp0 - fSin * fTmp1;
			kR[2][iRow] = fSin * fTmp0 + fCos * fTmp1;
		}

		// adjust left
		fY = kA[1][1];
		fZ = kA[2][1];
		fInvLength = inv_sqrt(fY*fY + fZ * fZ);
		fSin = fZ * fInvLength;
		fCos = -fY * fInvLength;

		kA[1][1] = fCos * kA[1][1] - fSin * kA[2][1];
		fTmp0 = kA[1][2];
		fTmp1 = kA[2][2];
		kA[1][2] = fCos * fTmp0 - fSin * fTmp1;
		kA[2][2] = fSin * fTmp0 + fCos * fTmp1;

		for (iCol = 0; iCol < 3; iCol++)
		{
			fTmp0 = kL[iCol][1];
			fTmp1 = kL[iCol][2];
			kL[iCol][1] = fCos * fTmp0 - fSin * fTmp1;
			kL[iCol][2] = fSin * fTmp0 + fCos * fTmp1;
		}
	}
	mm_fix32 mm_fix32_matrix3x3::max_cubic_root(mm_fix32 afCoeff[3])
	{
		// Spectral norm is for A^T*A, so characteristic polynomial
		// P(x) = c[0]+c[1]*x+c[2]*x^2+x^3 has three positive real roots.
		// This yields the assertions c[0] < 0 and c[2]*c[2] >= 3*c[1].

		// quick out for uniform scale (triple root)
		const mm_fix32 fOneThird = 1.0 / 3.0;
		const mm_fix32 fEpsilon = 1e-06;
		mm_fix32 fDiscr = afCoeff[2] * afCoeff[2] - 3.0f*afCoeff[1];
		if (fDiscr <= fEpsilon)
			return -fOneThird * afCoeff[2];

		// Compute an upper bound on roots of P(x).  This assumes that A^T*A
		// has been scaled by its largest entry.
		mm_fix32 fX = 1.0;
		mm_fix32 fPoly = afCoeff[0] + fX * (afCoeff[1] + fX * (afCoeff[2] + fX));
		if (fPoly < 0.0)
		{
			// uses a matrix norm to find an upper bound on maximum root
			fX = fabs(afCoeff[0]);
			mm_fix32 fTmp = 1.0f + fabs(afCoeff[1]);
			if (fTmp > fX)
				fX = fTmp;
			fTmp = 1.0f + fabs(afCoeff[2]);
			if (fTmp > fX)
				fX = fTmp;
		}

		// Newton's method to find root
		mm_fix32 fTwoC2 = 2.0f*afCoeff[2];
		for (int i = 0; i < 16; i++)
		{
			fPoly = afCoeff[0] + fX * (afCoeff[1] + fX * (afCoeff[2] + fX));
			if (fabs(fPoly) <= fEpsilon)
				return fX;

			mm_fix32 fDeriv = afCoeff[1] + fX * (fTwoC2 + 3.0f*fX);
			fX -= fPoly / fDeriv;
		}

		return fX;
	}
	void mm_fix32_matrix3x3::tridiagonal(mm_fix32 afDiag[3], mm_fix32 afSubDiag[3])
	{
		// Householder reduction T = Q^t M Q
		//   Input:
		//     mat, symmetric 3x3 matrix M
		//   Output:
		//     mat, orthogonal matrix Q
		//     diag, diagonal entries of T
		//     subd, subdiagonal entries of T (T is symmetric)

		mm_fix32 fA = m[0][0];
		mm_fix32 fB = m[0][1];
		mm_fix32 fC = m[0][2];
		mm_fix32 fD = m[1][1];
		mm_fix32 fE = m[1][2];
		mm_fix32 fF = m[2][2];

		afDiag[0] = fA;
		afSubDiag[2] = 0.0;
		if (fabs(fC) >= EPSILON)
		{
			mm_fix32 fLength = sqrt(fB*fB + fC * fC);
			mm_fix32 fInvLength = 1.0f / fLength;
			fB *= fInvLength;
			fC *= fInvLength;
			mm_fix32 fQ = 2.0f*fB*fE + fC * (fF - fD);
			afDiag[1] = fD + fC * fQ;
			afDiag[2] = fF - fC * fQ;
			afSubDiag[0] = fLength;
			afSubDiag[1] = fE - fB * fQ;
			m[0][0] = 1.0;
			m[0][1] = 0.0;
			m[0][2] = 0.0;
			m[1][0] = 0.0;
			m[1][1] = fB;
			m[1][2] = fC;
			m[2][0] = 0.0;
			m[2][1] = fC;
			m[2][2] = -fB;
		}
		else
		{
			afDiag[1] = fD;
			afDiag[2] = fF;
			afSubDiag[0] = fB;
			afSubDiag[1] = fE;
			m[0][0] = 1.0;
			m[0][1] = 0.0;
			m[0][2] = 0.0;
			m[1][0] = 0.0;
			m[1][1] = 1.0;
			m[1][2] = 0.0;
			m[2][0] = 0.0;
			m[2][1] = 0.0;
			m[2][2] = 1.0;
		}
	}
	//-----------------------------------------------------------------------
	bool mm_fix32_matrix3x3::ql_algorithm(mm_fix32 afDiag[3], mm_fix32 afSubDiag[3])
	{
		// QL iteration with implicit shifting to reduce matrix from tridiagonal
		// to diagonal

		for (int i0 = 0; i0 < 3; i0++)
		{
			const unsigned int iMaxIter = 32;
			unsigned int iIter;
			for (iIter = 0; iIter < iMaxIter; iIter++)
			{
				int i1;
				for (i1 = i0; i1 <= 1; i1++)
				{
					mm_fix32 fSum = fabs(afDiag[i1]) +
						fabs(afDiag[i1 + 1]);
					if (fabs(afSubDiag[i1]) + fSum == fSum)
						break;
				}
				if (i1 == i0)
					break;

				mm_fix32 fTmp0 = (afDiag[i0 + 1] - afDiag[i0]) / (2.0f*afSubDiag[i0]);
				mm_fix32 fTmp1 = sqrt(fTmp0*fTmp0 + 1.0f);
				if (fTmp0 < 0.0)
					fTmp0 = afDiag[i1] - afDiag[i0] + afSubDiag[i0] / (fTmp0 - fTmp1);
				else
					fTmp0 = afDiag[i1] - afDiag[i0] + afSubDiag[i0] / (fTmp0 + fTmp1);
				mm_fix32 fSin = 1.0;
				mm_fix32 fCos = 1.0;
				mm_fix32 fTmp2 = 0.0;
				for (int i2 = i1 - 1; i2 >= i0; i2--)
				{
					mm_fix32 fTmp3 = fSin * afSubDiag[i2];
					mm_fix32 fTmp4 = fCos * afSubDiag[i2];
					if (fabs(fTmp3) >= fabs(fTmp0))
					{
						fCos = fTmp0 / fTmp3;
						fTmp1 = sqrt(fCos*fCos + 1.0f);
						afSubDiag[i2 + 1] = fTmp3 * fTmp1;
						fSin = 1.0f / fTmp1;
						fCos *= fSin;
					}
					else
					{
						fSin = fTmp3 / fTmp0;
						fTmp1 = sqrt(fSin*fSin + 1.0f);
						afSubDiag[i2 + 1] = fTmp0 * fTmp1;
						fCos = 1.0f / fTmp1;
						fSin *= fCos;
					}
					fTmp0 = afDiag[i2 + 1] - fTmp2;
					fTmp1 = (afDiag[i2] - fTmp0)*fSin + 2.0f*fTmp4*fCos;
					fTmp2 = fSin * fTmp1;
					afDiag[i2 + 1] = fTmp0 + fTmp2;
					fTmp0 = fCos * fTmp1 - fTmp4;

					for (int iRow = 0; iRow < 3; iRow++)
					{
						fTmp3 = m[iRow][i2 + 1];
						m[iRow][i2 + 1] = fSin * m[iRow][i2] +
							fCos * fTmp3;
						m[iRow][i2] = fCos * m[iRow][i2] -
							fSin * fTmp3;
					}
				}
				afDiag[i0] -= fTmp2;
				afSubDiag[i0] = fTmp0;
				afSubDiag[i1] = 0.0;
			}

			if (iIter == iMaxIter)
			{
				// should not get here under normal circumstances
				return false;
			}
		}

		return true;
	}
}