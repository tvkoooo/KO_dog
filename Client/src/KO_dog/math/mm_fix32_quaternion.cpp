#include "mm_fix32_quaternion.h"

namespace mm
{
	const mm_fix32 mm_fix32_quaternion::EPSILON = 1e-03;
	const mm_fix32_quaternion mm_fix32_quaternion::ZERO(0, 0, 0, 0);
	const mm_fix32_quaternion mm_fix32_quaternion::IDENTITY(1, 0, 0, 0);

	const mm_fix32 mm_fix32_quaternion::msEpsilon = 1e-03;

	mm_fix32_quaternion mm_fix32_quaternion::operator + (const mm_fix32_quaternion& rkQ) const
	{
		return mm_fix32_quaternion(
			this->x + rkQ.x,
			this->y + rkQ.y,
			this->z + rkQ.z,
			this->w + rkQ.w);
	}
	mm_fix32_quaternion mm_fix32_quaternion::operator - (const mm_fix32_quaternion& rkQ) const
	{
		return mm_fix32_quaternion(
			this->z - rkQ.z,
			this->w - rkQ.w,
			this->x - rkQ.x,
			this->y - rkQ.y);
	}
	mm_fix32_quaternion mm_fix32_quaternion::operator * (const mm_fix32_quaternion& rkQ) const
	{
		// NOTE:  Multiplication is not generally commutative, so in most
		// cases p*q != q*p.
		return mm_fix32_quaternion
		(
			w * rkQ.x + x * rkQ.w + y * rkQ.z - z * rkQ.y,
			w * rkQ.y + y * rkQ.w + z * rkQ.x - x * rkQ.z,
			w * rkQ.z + z * rkQ.w + x * rkQ.y - y * rkQ.x,
			w * rkQ.w - x * rkQ.x - y * rkQ.y - z * rkQ.z
		);
	}

	mm_fix32_vector3 mm_fix32_quaternion::operator * (const mm_fix32_vector3& v) const
	{
		// nVidia SDK implementation
		mm_fix32_vector3 uv, uuv;
		mm_fix32_vector3 qvec(x, y, z);
		uv = qvec.cross_product(v);
		uuv = qvec.cross_product(uv);
		uv *= (2.0f * w);
		uuv *= 2.0f;

		return v + uv + uuv;
	}

	mm_fix32_quaternion operator * (mm_fix32 fScalar, const mm_fix32_quaternion& rkQ)
	{
		return mm_fix32_quaternion(
			fScalar * rkQ.x,
			fScalar * rkQ.y,
			fScalar * rkQ.z,
			fScalar * rkQ.w);
	}
	mm_fix32_quaternion operator * (const mm_fix32_quaternion& rkQ, mm_fix32 fScalar)
	{
		return mm_fix32_quaternion(
			fScalar * rkQ.x,
			fScalar * rkQ.y,
			fScalar * rkQ.z,
			fScalar * rkQ.w);
	}

	mm_fix32 mm_fix32_quaternion::normalise()
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
			this->w *= fInvLength;
		}

		return fLength;
	}

	mm_fix32_quaternion mm_fix32_quaternion::inverse() const
	{
		mm_fix32 fNorm = w * w + x * x + y * y + z * z;
		if (fNorm > 0.0)
		{
			mm_fix32 fInvNorm = 1.0f / fNorm;
			return mm_fix32_quaternion(-x * fInvNorm, -y * fInvNorm, -z * fInvNorm, w*fInvNorm);
		}
		else
		{
			// return an invalid result to flag the error
			return ZERO;
		}
	}

	mm_fix32_quaternion mm_fix32_quaternion::unit_inverse() const
	{
		// assert:  'this' is unit length
		return mm_fix32_quaternion(w, -x, -y, -z);
	}

	mm_fix32_quaternion mm_fix32_quaternion::quaternion_exp() const
	{
		// If q = A*(x*i+y*j+z*k) where (x,y,z) is unit length, then
		// exp(q) = e^w(cos(A)+sin(A)*(x*i+y*j+z*k)).  If sin(A) is near zero,
		// use exp(q) = e^w(cos(A)+(x*i+y*j+z*k)) since sin(A)/A has limit 1.

		mm_fix32 fAngle(sqrt(x*x + y * y + z * z));
		mm_fix32 fSin = sin(fAngle);
		mm_fix32 fExpW = exp(w);

		mm_fix32_quaternion kResult;
		kResult.w = fExpW * cos(fAngle);

		if (fabs(fAngle) >= msEpsilon)
		{
			mm_fix32 fCoeff = fExpW * (fSin / (fAngle));
			kResult.x = fCoeff * x;
			kResult.y = fCoeff * y;
			kResult.z = fCoeff * z;
		}
		else
		{
			kResult.x = fExpW * x;
			kResult.y = fExpW * y;
			kResult.z = fExpW * z;
		}

		return kResult;
	}

	mm_fix32_quaternion mm_fix32_quaternion::quaternion_log() const
	{
		// If q = cos(A)+sin(A)*(x*i+y*j+z*k) where (x,y,z) is unit length, then
		// log(q) = (A/sin(A))*(x*i+y*j+z*k).  If sin(A) is near zero, use
		// log(q) = (x*i+y*j+z*k) since A/sin(A) has limit 1.

		mm_fix32_quaternion kResult;
		kResult.w = 0.0;

		if (fabs(w) < 1.0)
		{
			// According to Neil Dantam, atan2 has the best stability.
			// http://www.neil.dantam.name/note/dantam-quaternion.pdf
			mm_fix32 fNormV = sqrt(x*x + y * y + z * z);
			mm_fix32 fAngle(atan2(fNormV, w));

			mm_fix32 fSin = sin(fAngle);
			if (fabs(fSin) >= msEpsilon)
			{
				mm_fix32 fCoeff = fAngle / fSin;
				kResult.x = fCoeff * x;
				kResult.y = fCoeff * y;
				kResult.z = fCoeff * z;
				return kResult;
			}
		}

		kResult.x = x;
		kResult.y = y;
		kResult.z = z;

		return kResult;
	}

	void mm_fix32_quaternion::from_rotation_matrix(const mm_fix32_matrix3x3& kRot)
	{
		// Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
		// article "Quaternion Calculus and Fast Animation".

		mm_fix32 fTrace = kRot[0][0] + kRot[1][1] + kRot[2][2];
		mm_fix32 fRoot;

		if (fTrace > 0.0)
		{
			// |w| > 1/2, may as well choose w > 1/2
			fRoot = sqrt(fTrace + 1.0f);  // 2w
			w = 0.5f*fRoot;
			fRoot = 0.5f / fRoot;  // 1/(4w)
			x = (kRot[2][1] - kRot[1][2])*fRoot;
			y = (kRot[0][2] - kRot[2][0])*fRoot;
			z = (kRot[1][0] - kRot[0][1])*fRoot;
		}
		else
		{
			// |w| <= 1/2
			static size_t s_iNext[3] = { 1, 2, 0 };
			size_t i = 0;
			if (kRot[1][1] > kRot[0][0])
				i = 1;
			if (kRot[2][2] > kRot[i][i])
				i = 2;
			size_t j = s_iNext[i];
			size_t k = s_iNext[j];

			fRoot = sqrt(kRot[i][i] - kRot[j][j] - kRot[k][k] + 1.0f);
			mm_fix32* apkQuat[3] = { &x, &y, &z };
			*apkQuat[i] = 0.5f*fRoot;
			fRoot = 0.5f / fRoot;
			w = (kRot[k][j] - kRot[j][k])*fRoot;
			*apkQuat[j] = (kRot[j][i] + kRot[i][j])*fRoot;
			*apkQuat[k] = (kRot[k][i] + kRot[i][k])*fRoot;
		}
	}

	void mm_fix32_quaternion::to_rotation_matrix(mm_fix32_matrix3x3& kRot) const
	{
		mm_fix32 fTx = x + x;
		mm_fix32 fTy = y + y;
		mm_fix32 fTz = z + z;
		mm_fix32 fTwx = fTx * w;
		mm_fix32 fTwy = fTy * w;
		mm_fix32 fTwz = fTz * w;
		mm_fix32 fTxx = fTx * x;
		mm_fix32 fTxy = fTy * x;
		mm_fix32 fTxz = fTz * x;
		mm_fix32 fTyy = fTy * y;
		mm_fix32 fTyz = fTz * y;
		mm_fix32 fTzz = fTz * z;

		kRot[0][0] = 1.0f - (fTyy + fTzz);
		kRot[0][1] = fTxy - fTwz;
		kRot[0][2] = fTxz + fTwy;
		kRot[1][0] = fTxy + fTwz;
		kRot[1][1] = 1.0f - (fTxx + fTzz);
		kRot[1][2] = fTyz - fTwx;
		kRot[2][0] = fTxz - fTwy;
		kRot[2][1] = fTyz + fTwx;
		kRot[2][2] = 1.0f - (fTxx + fTyy);
	}

	void mm_fix32_quaternion::from_angle_axis(const mm_fix32& rfAngle, const mm_fix32_vector3& rkAxis)
	{
		// assert:  axis[] is unit length
		//
		// The quaternion representing the rotation is
		//   q = cos(A/2)+sin(A/2)*(x*i+y*j+z*k)

		mm_fix32 fHalfAngle(0.5*rfAngle);
		mm_fix32 fSin = sin(fHalfAngle);
		w = cos(fHalfAngle);
		x = fSin * rkAxis.x;
		y = fSin * rkAxis.y;
		z = fSin * rkAxis.z;
	}

	void mm_fix32_quaternion::to_angle_axis(mm_fix32& rfAngle, mm_fix32_vector3& rkAxis) const
	{
		// The quaternion representing the rotation is
		//   q = cos(A/2)+sin(A/2)*(x*i+y*j+z*k)

		mm_fix32 fSqrLength = x * x + y * y + z * z;
		if (fSqrLength > 0.0)
		{
			rfAngle = 2.0*acos(w);
			mm_fix32 fInvLength = inv_sqrt(fSqrLength);
			rkAxis.x = x * fInvLength;
			rkAxis.y = y * fInvLength;
			rkAxis.z = z * fInvLength;
		}
		else
		{
			// angle is 0 (mod 2*pi), so any axis will do
			rfAngle = mm_fix32(0.0);
			rkAxis.x = 1.0;
			rkAxis.y = 0.0;
			rkAxis.z = 0.0;
		}
	}

	void mm_fix32_quaternion::from_axes(const mm_fix32_vector3* akAxis)
	{
		mm_fix32_matrix3x3 kRot;

		for (size_t iCol = 0; iCol < 3; iCol++)
		{
			kRot[0][iCol] = akAxis[iCol].x;
			kRot[1][iCol] = akAxis[iCol].y;
			kRot[2][iCol] = akAxis[iCol].z;
		}

		this->from_rotation_matrix(kRot);
	}

	void mm_fix32_quaternion::from_axes(const mm_fix32_vector3& xaxis, const mm_fix32_vector3& yaxis, const mm_fix32_vector3& zaxis)
	{
		mm_fix32_matrix3x3 kRot;

		kRot[0][0] = xaxis.x;
		kRot[1][0] = xaxis.y;
		kRot[2][0] = xaxis.z;

		kRot[0][1] = yaxis.x;
		kRot[1][1] = yaxis.y;
		kRot[2][1] = yaxis.z;

		kRot[0][2] = zaxis.x;
		kRot[1][2] = zaxis.y;
		kRot[2][2] = zaxis.z;

		this->from_rotation_matrix(kRot);
	}

	void mm_fix32_quaternion::to_axes(mm_fix32_vector3* akAxis) const
	{
		mm_fix32_matrix3x3 kRot;

		this->to_rotation_matrix(kRot);

		for (size_t iCol = 0; iCol < 3; iCol++)
		{
			akAxis[iCol].x = kRot[0][iCol];
			akAxis[iCol].y = kRot[1][iCol];
			akAxis[iCol].z = kRot[2][iCol];
		}
	}

	void mm_fix32_quaternion::to_axes(mm_fix32_vector3& xaxis, mm_fix32_vector3& yaxis, mm_fix32_vector3& zaxis) const
	{
		mm_fix32_matrix3x3 kRot;

		this->to_rotation_matrix(kRot);

		xaxis.x = kRot[0][0];
		xaxis.y = kRot[1][0];
		xaxis.z = kRot[2][0];

		yaxis.x = kRot[0][1];
		yaxis.y = kRot[1][1];
		yaxis.z = kRot[2][1];

		zaxis.x = kRot[0][2];
		zaxis.y = kRot[1][2];
		zaxis.z = kRot[2][2];
	}

	mm_fix32_vector3 mm_fix32_quaternion::x_axis(void) const
	{
		//Real fTx  = 2.0*x;
		mm_fix32 fTy = 2.0f*y;
		mm_fix32 fTz = 2.0f*z;
		mm_fix32 fTwy = fTy * w;
		mm_fix32 fTwz = fTz * w;
		mm_fix32 fTxy = fTy * x;
		mm_fix32 fTxz = fTz * x;
		mm_fix32 fTyy = fTy * y;
		mm_fix32 fTzz = fTz * z;

		return mm_fix32_vector3(1.0f - (fTyy + fTzz), fTxy + fTwz, fTxz - fTwy);
	}

	mm_fix32_vector3 mm_fix32_quaternion::y_axis(void) const
	{
		mm_fix32 fTx = 2.0f*x;
		mm_fix32 fTy = 2.0f*y;
		mm_fix32 fTz = 2.0f*z;
		mm_fix32 fTwx = fTx * w;
		mm_fix32 fTwz = fTz * w;
		mm_fix32 fTxx = fTx * x;
		mm_fix32 fTxy = fTy * x;
		mm_fix32 fTyz = fTz * y;
		mm_fix32 fTzz = fTz * z;

		return mm_fix32_vector3(fTxy - fTwz, 1.0f - (fTxx + fTzz), fTyz + fTwx);
	}

	mm_fix32_vector3 mm_fix32_quaternion::z_axis(void) const
	{
		mm_fix32 fTx = 2.0f*x;
		mm_fix32 fTy = 2.0f*y;
		mm_fix32 fTz = 2.0f*z;
		mm_fix32 fTwx = fTx * w;
		mm_fix32 fTwy = fTy * w;
		mm_fix32 fTxx = fTx * x;
		mm_fix32 fTxz = fTz * x;
		mm_fix32 fTyy = fTy * y;
		mm_fix32 fTyz = fTz * y;

		return mm_fix32_vector3(fTxz + fTwy, fTyz - fTwx, 1.0f - (fTxx + fTyy));
	}

	mm_fix32 mm_fix32_quaternion::get_rotate_x(bool reprojectAxis) const
	{
		if (reprojectAxis)
		{
			// roll = atan2(localx.y, localx.x)
			// pick parts of xAxis() implementation that we need
			//			Real fTx  = 2.0*x;
			mm_fix32 fTy = 2.0f*y;
			mm_fix32 fTz = 2.0f*z;
			mm_fix32 fTwz = fTz * w;
			mm_fix32 fTxy = fTy * x;
			mm_fix32 fTyy = fTy * y;
			mm_fix32 fTzz = fTz * z;

			// Vector3(1.0-(fTyy+fTzz), fTxy+fTwz, fTxz-fTwy);

			return mm_fix32(atan2(fTxy + fTwz, 1.0f - (fTyy + fTzz)));

		}
		else
		{
			return mm_fix32(atan2(2 * (x*y + w * z), w*w + x * x - y * y - z * z));
		}
	}

	mm_fix32 mm_fix32_quaternion::get_rotate_y(bool reprojectAxis) const
	{
		if (reprojectAxis)
		{
			// pitch = atan2(localy.z, localy.y)
			// pick parts of yAxis() implementation that we need
			mm_fix32 fTx = 2.0f*x;
			//			Real fTy  = 2.0f*y;
			mm_fix32 fTz = 2.0f*z;
			mm_fix32 fTwx = fTx * w;
			mm_fix32 fTxx = fTx * x;
			mm_fix32 fTyz = fTz * y;
			mm_fix32 fTzz = fTz * z;

			// Vector3(fTxy-fTwz, 1.0-(fTxx+fTzz), fTyz+fTwx);
			return mm_fix32(atan2(fTyz + fTwx, 1.0f - (fTxx + fTzz)));
		}
		else
		{
			// internal version
			return mm_fix32(atan2(2 * (y*z + w * x), w*w - x * x - y * y + z * z));
		}
	}

	mm_fix32 mm_fix32_quaternion::get_rotate_z(bool reprojectAxis) const
	{
		if (reprojectAxis)
		{
			// yaw = atan2(localz.x, localz.z)
			// pick parts of zAxis() implementation that we need
			mm_fix32 fTx = 2.0f*x;
			mm_fix32 fTy = 2.0f*y;
			mm_fix32 fTz = 2.0f*z;
			mm_fix32 fTwy = fTy * w;
			mm_fix32 fTxx = fTx * x;
			mm_fix32 fTxz = fTz * x;
			mm_fix32 fTyy = fTy * y;

			// Vector3(fTxz+fTwy, fTyz-fTwx, 1.0-(fTxx+fTyy));

			return mm_fix32(atan2(fTxz + fTwy, 1.0f - (fTxx + fTyy)));

		}
		else
		{
			// internal version
			return mm_fix32(asin(-2 * (x*z - w * y)));
		}
	}

	bool mm_fix32_quaternion::equals(const mm_fix32_quaternion& rhs, const mm_fix32& tolerance) const
	{
		mm_fix32 d = this->dot_product(rhs);
		mm_fix32 angle = acos(2.0f * d*d - 1.0f);

		return fabs(angle) <= tolerance;
	}

	mm_fix32_quaternion mm_fix32_quaternion::get_rotation_to(const mm_fix32_vector3& rkVector, const mm_fix32_vector3& dest, const mm_fix32_vector3& fallbackAxis /*= mm_fix32_vector3::ZERO*/)
	{
		// From Sam Hocevar's article "Quaternion from two vectors:
		// the final version"
		mm_fix32 a = sqrt(rkVector.squared_length() * dest.squared_length());
		mm_fix32 b = a + rkVector.dot_product(dest);
		mm_fix32_vector3 axis;

		if (b < (mm_fix32)1e-06 * a)
		{
			b = (mm_fix32)0.0;
			axis = fallbackAxis != mm_fix32_vector3::ZERO ? fallbackAxis
				: fabs(rkVector.x) > fabs(rkVector.z) ? mm_fix32_vector3(-rkVector.y, rkVector.x, (mm_fix32)0.0)
				: mm_fix32_vector3((mm_fix32)0.0, -rkVector.z, rkVector.y);
		}
		else
		{
			axis = rkVector.cross_product(dest);
		}

		mm_fix32_quaternion q(b, axis.x, axis.y, axis.z);
		q.normalise();
		return q;
	}

	mm_fix32_quaternion mm_fix32_quaternion::slerp(
		mm_fix32 fT, 
		const mm_fix32_quaternion& rkP, 
		const mm_fix32_quaternion& rkQ, 
		bool shortestPath/*= false*/)
	{
		mm_fix32 fCos = rkP.dot_product(rkQ);
		mm_fix32_quaternion rkT;

		// Do we need to invert rotation?
		if (fCos < 0.0f && shortestPath)
		{
			fCos = -fCos;
			rkT = -rkQ;
		}
		else
		{
			rkT = rkQ;
		}

		if (fabs(fCos) < 1 - EPSILON)
		{
			// Standard case (slerp)
			mm_fix32 fSin = sqrt(1 - squared(fCos));
			mm_fix32 fAngle = atan2(fSin, fCos);
			mm_fix32 fInvSin = 1.0f / fSin;
			mm_fix32 fCoeff0 = sin((1.0f - fT) * fAngle) * fInvSin;
			mm_fix32 fCoeff1 = sin(fT * fAngle) * fInvSin;
			return fCoeff0 * rkP + fCoeff1 * rkT;
		}
		else
		{
			// There are two situations:
			// 1. "rkP" and "rkQ" are very close (fCos ~= +1), so we can do a linear
			//    interpolation safely.
			// 2. "rkP" and "rkQ" are almost inverse of each other (fCos ~= -1), there
			//    are an infinite number of possibilities interpolation. but we haven't
			//    have method to fix this case, so just use linear interpolation here.
			mm_fix32_quaternion t = (1.0f - fT) * rkP + fT * rkT;
			// taking the complement requires renormalisation
			t.normalise();
			return t;
		}
	}

	mm_fix32_quaternion mm_fix32_quaternion::slerp_extra_spins(
		mm_fix32 fT, 
		const mm_fix32_quaternion& rkP, 
		const mm_fix32_quaternion& rkQ, 
		int iExtraSpins)
	{
		mm_fix32 fCos = rkP.dot_product(rkQ);
		mm_fix32 fAngle(acos(fCos));

		if (fabs(fAngle) < msEpsilon)
			return rkP;

		mm_fix32 fSin = sin(fAngle);
		mm_fix32 fPhase(mm_fix32::MM_PI*iExtraSpins*fT);
		mm_fix32 fInvSin = 1.0f / fSin;
		mm_fix32 fCoeff0 = sin((1.0f - fT)*fAngle - fPhase)*fInvSin;
		mm_fix32 fCoeff1 = sin(fT*fAngle + fPhase)*fInvSin;
		return fCoeff0 * rkP + fCoeff1 * rkQ;
	}

	void mm_fix32_quaternion::intermediate(
		const mm_fix32_quaternion& rkQ0, 
		const mm_fix32_quaternion& rkQ1, 
		const mm_fix32_quaternion& rkQ2, 
		mm_fix32_quaternion& rkA, 
		mm_fix32_quaternion& rkB)
	{
		// assert:  q0, q1, q2 are unit quaternions

		mm_fix32_quaternion kQ0inv = rkQ0.unit_inverse();
		mm_fix32_quaternion kQ1inv = rkQ1.unit_inverse();
		mm_fix32_quaternion rkP0 = kQ0inv * rkQ1;
		mm_fix32_quaternion rkP1 = kQ1inv * rkQ2;
		mm_fix32_quaternion kArg = 0.25*(rkP0.quaternion_log() - rkP1.quaternion_log());
		mm_fix32_quaternion kMinusArg = -kArg;

		rkA = rkQ1 * kArg.quaternion_exp();
		rkB = rkQ1 * kMinusArg.quaternion_exp();
	}

	mm_fix32_quaternion mm_fix32_quaternion::squad(
		mm_fix32 fT, 
		const mm_fix32_quaternion& rkP, 
		const mm_fix32_quaternion& rkA, 
		const mm_fix32_quaternion& rkB, 
		const mm_fix32_quaternion& rkQ, 
		bool shortestPath/*= false*/)
	{
		mm_fix32 fSlerpT = 2.0f*fT*(1.0f - fT);
		mm_fix32_quaternion kSlerpP = slerp(fT, rkP, rkQ, shortestPath);
		mm_fix32_quaternion kSlerpQ = slerp(fT, rkA, rkB);
		return slerp(fSlerpT, kSlerpP, kSlerpQ);
	}

	mm_fix32_quaternion mm_fix32_quaternion::nlerp(
		mm_fix32 fT, 
		const mm_fix32_quaternion& rkP, 
		const mm_fix32_quaternion& rkQ, 
		bool shortestPath /*= false*/)
	{
		mm_fix32_quaternion result;
		mm_fix32 fCos = rkP.dot_product(rkQ);
		if (fCos < 0.0f && shortestPath)
		{
			result = rkP + fT * ((-rkQ) - rkP);
		}
		else
		{
			result = rkP + fT * (rkQ - rkP);
		}
		result.normalise();
		return result;
	}

	std::ostream& operator << (std::ostream& o, const mm_fix32_quaternion& q)
	{
		o << "quaternion(" << q.w << ", " << q.x << ", " << q.y << ", " << q.z << ")";
		return o;
	}
}