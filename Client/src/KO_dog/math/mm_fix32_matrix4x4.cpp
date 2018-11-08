#include "mm_fix32_matrix4x4.h"

namespace mm
{
	const mm_fix32_matrix4x4 mm_fix32_matrix4x4::ZERO
	(
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	);

	const mm_fix32_matrix4x4 mm_fix32_matrix4x4::ZEROAFFINE
	(
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 1
	);

	const mm_fix32_matrix4x4 mm_fix32_matrix4x4::IDENTITY
	(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);

	inline static mm_fix32 MINOR(
		const mm_fix32_matrix4x4& m, 
		const size_t r0, const size_t r1, const size_t r2,
		const size_t c0, const size_t c1, const size_t c2)
	{
		return 
			m[r0][c0] * (m[r1][c1] * m[r2][c2] - m[r2][c1] * m[r1][c2]) -
			m[r0][c1] * (m[r1][c0] * m[r2][c2] - m[r2][c0] * m[r1][c2]) +
			m[r0][c2] * (m[r1][c0] * m[r2][c1] - m[r2][c0] * m[r1][c1]);
	}

	mm_fix32_matrix4x4::mm_fix32_matrix4x4(
		mm_fix32 m00, mm_fix32 m01, mm_fix32 m02, mm_fix32 m03,
		mm_fix32 m10, mm_fix32 m11, mm_fix32 m12, mm_fix32 m13,
		mm_fix32 m20, mm_fix32 m21, mm_fix32 m22, mm_fix32 m23,
		mm_fix32 m30, mm_fix32 m31, mm_fix32 m32, mm_fix32 m33)
	{
		m[0][0] = m00;
		m[0][1] = m01;
		m[0][2] = m02;
		m[0][3] = m03;
		m[1][0] = m10;
		m[1][1] = m11;
		m[1][2] = m12;
		m[1][3] = m13;
		m[2][0] = m20;
		m[2][1] = m21;
		m[2][2] = m22;
		m[2][3] = m23;
		m[3][0] = m30;
		m[3][1] = m31;
		m[3][2] = m32;
		m[3][3] = m33;
	}

	void mm_fix32_matrix4x4::operator = (const mm_fix32_matrix3x3& mat3)
	{
		m[0][0] = mat3.m[0][0]; m[0][1] = mat3.m[0][1]; m[0][2] = mat3.m[0][2];
		m[1][0] = mat3.m[1][0]; m[1][1] = mat3.m[1][1]; m[1][2] = mat3.m[1][2];
		m[2][0] = mat3.m[2][0]; m[2][1] = mat3.m[2][1]; m[2][2] = mat3.m[2][2];
	}

	void mm_fix32_matrix4x4::swap(mm_fix32_matrix4x4& other)
	{
		std::swap(m[0][0], other.m[0][0]);
		std::swap(m[0][1], other.m[0][1]);
		std::swap(m[0][2], other.m[0][2]);
		std::swap(m[0][3], other.m[0][3]);
		std::swap(m[1][0], other.m[1][0]);
		std::swap(m[1][1], other.m[1][1]);
		std::swap(m[1][2], other.m[1][2]);
		std::swap(m[1][3], other.m[1][3]);
		std::swap(m[2][0], other.m[2][0]);
		std::swap(m[2][1], other.m[2][1]);
		std::swap(m[2][2], other.m[2][2]);
		std::swap(m[2][3], other.m[2][3]);
		std::swap(m[3][0], other.m[3][0]);
		std::swap(m[3][1], other.m[3][1]);
		std::swap(m[3][2], other.m[3][2]);
		std::swap(m[3][3], other.m[3][3]);
	}

	mm_fix32_matrix4x4 mm_fix32_matrix4x4::concatenate(const mm_fix32_matrix4x4 &m2) const
	{
		mm_fix32_matrix4x4 r;
		r.m[0][0] = m[0][0] * m2.m[0][0] + m[0][1] * m2.m[1][0] + m[0][2] * m2.m[2][0] + m[0][3] * m2.m[3][0];
		r.m[0][1] = m[0][0] * m2.m[0][1] + m[0][1] * m2.m[1][1] + m[0][2] * m2.m[2][1] + m[0][3] * m2.m[3][1];
		r.m[0][2] = m[0][0] * m2.m[0][2] + m[0][1] * m2.m[1][2] + m[0][2] * m2.m[2][2] + m[0][3] * m2.m[3][2];
		r.m[0][3] = m[0][0] * m2.m[0][3] + m[0][1] * m2.m[1][3] + m[0][2] * m2.m[2][3] + m[0][3] * m2.m[3][3];

		r.m[1][0] = m[1][0] * m2.m[0][0] + m[1][1] * m2.m[1][0] + m[1][2] * m2.m[2][0] + m[1][3] * m2.m[3][0];
		r.m[1][1] = m[1][0] * m2.m[0][1] + m[1][1] * m2.m[1][1] + m[1][2] * m2.m[2][1] + m[1][3] * m2.m[3][1];
		r.m[1][2] = m[1][0] * m2.m[0][2] + m[1][1] * m2.m[1][2] + m[1][2] * m2.m[2][2] + m[1][3] * m2.m[3][2];
		r.m[1][3] = m[1][0] * m2.m[0][3] + m[1][1] * m2.m[1][3] + m[1][2] * m2.m[2][3] + m[1][3] * m2.m[3][3];

		r.m[2][0] = m[2][0] * m2.m[0][0] + m[2][1] * m2.m[1][0] + m[2][2] * m2.m[2][0] + m[2][3] * m2.m[3][0];
		r.m[2][1] = m[2][0] * m2.m[0][1] + m[2][1] * m2.m[1][1] + m[2][2] * m2.m[2][1] + m[2][3] * m2.m[3][1];
		r.m[2][2] = m[2][0] * m2.m[0][2] + m[2][1] * m2.m[1][2] + m[2][2] * m2.m[2][2] + m[2][3] * m2.m[3][2];
		r.m[2][3] = m[2][0] * m2.m[0][3] + m[2][1] * m2.m[1][3] + m[2][2] * m2.m[2][3] + m[2][3] * m2.m[3][3];

		r.m[3][0] = m[3][0] * m2.m[0][0] + m[3][1] * m2.m[1][0] + m[3][2] * m2.m[2][0] + m[3][3] * m2.m[3][0];
		r.m[3][1] = m[3][0] * m2.m[0][1] + m[3][1] * m2.m[1][1] + m[3][2] * m2.m[2][1] + m[3][3] * m2.m[3][1];
		r.m[3][2] = m[3][0] * m2.m[0][2] + m[3][1] * m2.m[1][2] + m[3][2] * m2.m[2][2] + m[3][3] * m2.m[3][2];
		r.m[3][3] = m[3][0] * m2.m[0][3] + m[3][1] * m2.m[1][3] + m[3][2] * m2.m[2][3] + m[3][3] * m2.m[3][3];

		return r;
	}

	mm_fix32_matrix4x4 mm_fix32_matrix4x4::operator * (mm_fix32 scalar) const
	{
		return mm_fix32_matrix4x4(
			scalar*m[0][0], scalar*m[0][1], scalar*m[0][2], scalar*m[0][3],
			scalar*m[1][0], scalar*m[1][1], scalar*m[1][2], scalar*m[1][3],
			scalar*m[2][0], scalar*m[2][1], scalar*m[2][2], scalar*m[2][3],
			scalar*m[3][0], scalar*m[3][1], scalar*m[3][2], scalar*m[3][3]);
	}

	mm_fix32_vector4 operator * (const mm_fix32_vector4& v, const mm_fix32_matrix4x4& mat)
	{
		return mm_fix32_vector4(
			v.x*mat[0][0] + v.y*mat[1][0] + v.z*mat[2][0] + v.w*mat[3][0],
			v.x*mat[0][1] + v.y*mat[1][1] + v.z*mat[2][1] + v.w*mat[3][1],
			v.x*mat[0][2] + v.y*mat[1][2] + v.z*mat[2][2] + v.w*mat[3][2],
			v.x*mat[0][3] + v.y*mat[1][3] + v.z*mat[2][3] + v.w*mat[3][3]
		);
	}

	mm_fix32_matrix4x4 mm_fix32_matrix4x4::operator + (const mm_fix32_matrix4x4 &m2) const
	{
		mm_fix32_matrix4x4 r;

		r.m[0][0] = m[0][0] + m2.m[0][0];
		r.m[0][1] = m[0][1] + m2.m[0][1];
		r.m[0][2] = m[0][2] + m2.m[0][2];
		r.m[0][3] = m[0][3] + m2.m[0][3];

		r.m[1][0] = m[1][0] + m2.m[1][0];
		r.m[1][1] = m[1][1] + m2.m[1][1];
		r.m[1][2] = m[1][2] + m2.m[1][2];
		r.m[1][3] = m[1][3] + m2.m[1][3];

		r.m[2][0] = m[2][0] + m2.m[2][0];
		r.m[2][1] = m[2][1] + m2.m[2][1];
		r.m[2][2] = m[2][2] + m2.m[2][2];
		r.m[2][3] = m[2][3] + m2.m[2][3];

		r.m[3][0] = m[3][0] + m2.m[3][0];
		r.m[3][1] = m[3][1] + m2.m[3][1];
		r.m[3][2] = m[3][2] + m2.m[3][2];
		r.m[3][3] = m[3][3] + m2.m[3][3];

		return r;
	}

	mm_fix32_matrix4x4 mm_fix32_matrix4x4::operator - (const mm_fix32_matrix4x4 &m2) const
	{
		mm_fix32_matrix4x4 r;

		r.m[0][0] = m[0][0] - m2.m[0][0];
		r.m[0][1] = m[0][1] - m2.m[0][1];
		r.m[0][2] = m[0][2] - m2.m[0][2];
		r.m[0][3] = m[0][3] - m2.m[0][3];

		r.m[1][0] = m[1][0] - m2.m[1][0];
		r.m[1][1] = m[1][1] - m2.m[1][1];
		r.m[1][2] = m[1][2] - m2.m[1][2];
		r.m[1][3] = m[1][3] - m2.m[1][3];

		r.m[2][0] = m[2][0] - m2.m[2][0];
		r.m[2][1] = m[2][1] - m2.m[2][1];
		r.m[2][2] = m[2][2] - m2.m[2][2];
		r.m[2][3] = m[2][3] - m2.m[2][3];

		r.m[3][0] = m[3][0] - m2.m[3][0];
		r.m[3][1] = m[3][1] - m2.m[3][1];
		r.m[3][2] = m[3][2] - m2.m[3][2];
		r.m[3][3] = m[3][3] - m2.m[3][3];

		return r;
	}

	bool mm_fix32_matrix4x4::operator == (const mm_fix32_matrix4x4& m2) const
	{
		return
			m[0][0] != m2.m[0][0] || m[0][1] != m2.m[0][1] || m[0][2] != m2.m[0][2] || m[0][3] != m2.m[0][3] ||
			m[1][0] != m2.m[1][0] || m[1][1] != m2.m[1][1] || m[1][2] != m2.m[1][2] || m[1][3] != m2.m[1][3] ||
			m[2][0] != m2.m[2][0] || m[2][1] != m2.m[2][1] || m[2][2] != m2.m[2][2] || m[2][3] != m2.m[2][3] ||
			m[3][0] != m2.m[3][0] || m[3][1] != m2.m[3][1] || m[3][2] != m2.m[3][2] || m[3][3] != m2.m[3][3];
	}

	mm_fix32_matrix4x4 mm_fix32_matrix4x4::transpose(void) const
	{
		return mm_fix32_matrix4x4(
			m[0][0], m[1][0], m[2][0], m[3][0],
			m[0][1], m[1][1], m[2][1], m[3][1],
			m[0][2], m[1][2], m[2][2], m[3][2],
			m[0][3], m[1][3], m[2][3], m[3][3]);
	}

	mm_fix32_matrix4x4 mm_fix32_matrix4x4::adjoint() const
	{
		return mm_fix32_matrix4x4(
			 MINOR(*this, 1, 2, 3, 1, 2, 3),
			-MINOR(*this, 0, 2, 3, 1, 2, 3),
			 MINOR(*this, 0, 1, 3, 1, 2, 3),
			-MINOR(*this, 0, 1, 2, 1, 2, 3),

			-MINOR(*this, 1, 2, 3, 0, 2, 3),
			 MINOR(*this, 0, 2, 3, 0, 2, 3),
			-MINOR(*this, 0, 1, 3, 0, 2, 3),
			 MINOR(*this, 0, 1, 2, 0, 2, 3),

			 MINOR(*this, 1, 2, 3, 0, 1, 3),
			-MINOR(*this, 0, 2, 3, 0, 1, 3),
			 MINOR(*this, 0, 1, 3, 0, 1, 3),
			-MINOR(*this, 0, 1, 2, 0, 1, 3),

			-MINOR(*this, 1, 2, 3, 0, 1, 2),
			 MINOR(*this, 0, 2, 3, 0, 1, 2),
			-MINOR(*this, 0, 1, 3, 0, 1, 2),
			 MINOR(*this, 0, 1, 2, 0, 1, 2));
	}
	mm_fix32 mm_fix32_matrix4x4::determinant() const
	{
		return
			m[0][0] * MINOR(*this, 1, 2, 3, 1, 2, 3) -
			m[0][1] * MINOR(*this, 1, 2, 3, 0, 2, 3) +
			m[0][2] * MINOR(*this, 1, 2, 3, 0, 1, 3) -
			m[0][3] * MINOR(*this, 1, 2, 3, 0, 1, 2);
	}
	mm_fix32_matrix4x4 mm_fix32_matrix4x4::inverse() const
	{
		mm_fix32 m00 = m[0][0], m01 = m[0][1], m02 = m[0][2], m03 = m[0][3];
		mm_fix32 m10 = m[1][0], m11 = m[1][1], m12 = m[1][2], m13 = m[1][3];
		mm_fix32 m20 = m[2][0], m21 = m[2][1], m22 = m[2][2], m23 = m[2][3];
		mm_fix32 m30 = m[3][0], m31 = m[3][1], m32 = m[3][2], m33 = m[3][3];

		mm_fix32 v0 = m20 * m31 - m21 * m30;
		mm_fix32 v1 = m20 * m32 - m22 * m30;
		mm_fix32 v2 = m20 * m33 - m23 * m30;
		mm_fix32 v3 = m21 * m32 - m22 * m31;
		mm_fix32 v4 = m21 * m33 - m23 * m31;
		mm_fix32 v5 = m22 * m33 - m23 * m32;

		mm_fix32 t00 = +(v5 * m11 - v4 * m12 + v3 * m13);
		mm_fix32 t10 = -(v5 * m10 - v2 * m12 + v1 * m13);
		mm_fix32 t20 = +(v4 * m10 - v2 * m11 + v0 * m13);
		mm_fix32 t30 = -(v3 * m10 - v1 * m11 + v0 * m12);

		mm_fix32 invDet = 1 / (t00 * m00 + t10 * m01 + t20 * m02 + t30 * m03);

		mm_fix32 d00 = t00 * invDet;
		mm_fix32 d10 = t10 * invDet;
		mm_fix32 d20 = t20 * invDet;
		mm_fix32 d30 = t30 * invDet;

		mm_fix32 d01 = -(v5 * m01 - v4 * m02 + v3 * m03) * invDet;
		mm_fix32 d11 = +(v5 * m00 - v2 * m02 + v1 * m03) * invDet;
		mm_fix32 d21 = -(v4 * m00 - v2 * m01 + v0 * m03) * invDet;
		mm_fix32 d31 = +(v3 * m00 - v1 * m01 + v0 * m02) * invDet;

		v0 = m10 * m31 - m11 * m30;
		v1 = m10 * m32 - m12 * m30;
		v2 = m10 * m33 - m13 * m30;
		v3 = m11 * m32 - m12 * m31;
		v4 = m11 * m33 - m13 * m31;
		v5 = m12 * m33 - m13 * m32;

		mm_fix32 d02 = +(v5 * m01 - v4 * m02 + v3 * m03) * invDet;
		mm_fix32 d12 = -(v5 * m00 - v2 * m02 + v1 * m03) * invDet;
		mm_fix32 d22 = +(v4 * m00 - v2 * m01 + v0 * m03) * invDet;
		mm_fix32 d32 = -(v3 * m00 - v1 * m01 + v0 * m02) * invDet;

		v0 = m21 * m10 - m20 * m11;
		v1 = m22 * m10 - m20 * m12;
		v2 = m23 * m10 - m20 * m13;
		v3 = m22 * m11 - m21 * m12;
		v4 = m23 * m11 - m21 * m13;
		v5 = m23 * m12 - m22 * m13;

		mm_fix32 d03 = -(v5 * m01 - v4 * m02 + v3 * m03) * invDet;
		mm_fix32 d13 = +(v5 * m00 - v2 * m02 + v1 * m03) * invDet;
		mm_fix32 d23 = -(v4 * m00 - v2 * m01 + v0 * m03) * invDet;
		mm_fix32 d33 = +(v3 * m00 - v1 * m01 + v0 * m02) * invDet;

		return mm_fix32_matrix4x4(
			d00, d01, d02, d03,
			d10, d11, d12, d13,
			d20, d21, d22, d23,
			d30, d31, d32, d33);
	}

	void mm_fix32_matrix4x4::make_translation(const mm_fix32_vector3& v)
	{
		m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = v.x;
		m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = v.y;
		m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = v.z;
		m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
	}

	void mm_fix32_matrix4x4::make_translation(mm_fix32 tx, mm_fix32 ty, mm_fix32 tz)
	{
		m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = tx;
		m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = ty;
		m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = tz;
		m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
	}

	mm_fix32_matrix4x4 mm_fix32_matrix4x4::get_translation(const mm_fix32_vector3& v)
	{
		mm_fix32_matrix4x4 r;

		r.m[0][0] = 1.0; r.m[0][1] = 0.0; r.m[0][2] = 0.0; r.m[0][3] = v.x;
		r.m[1][0] = 0.0; r.m[1][1] = 1.0; r.m[1][2] = 0.0; r.m[1][3] = v.y;
		r.m[2][0] = 0.0; r.m[2][1] = 0.0; r.m[2][2] = 1.0; r.m[2][3] = v.z;
		r.m[3][0] = 0.0; r.m[3][1] = 0.0; r.m[3][2] = 0.0; r.m[3][3] = 1.0;

		return r;
	}

	mm_fix32_matrix4x4 mm_fix32_matrix4x4::get_translation(mm_fix32 t_x, mm_fix32 t_y, mm_fix32 t_z)
	{
		mm_fix32_matrix4x4 r;

		r.m[0][0] = 1.0; r.m[0][1] = 0.0; r.m[0][2] = 0.0; r.m[0][3] = t_x;
		r.m[1][0] = 0.0; r.m[1][1] = 1.0; r.m[1][2] = 0.0; r.m[1][3] = t_y;
		r.m[2][0] = 0.0; r.m[2][1] = 0.0; r.m[2][2] = 1.0; r.m[2][3] = t_z;
		r.m[3][0] = 0.0; r.m[3][1] = 0.0; r.m[3][2] = 0.0; r.m[3][3] = 1.0;

		return r;
	}

	mm_fix32_matrix4x4 mm_fix32_matrix4x4::get_scale(const mm_fix32_vector3& v)
	{
		mm_fix32_matrix4x4 r;
		r.m[0][0] = v.x; r.m[0][1] = 0.0; r.m[0][2] = 0.0; r.m[0][3] = 0.0;
		r.m[1][0] = 0.0; r.m[1][1] = v.y; r.m[1][2] = 0.0; r.m[1][3] = 0.0;
		r.m[2][0] = 0.0; r.m[2][1] = 0.0; r.m[2][2] = v.z; r.m[2][3] = 0.0;
		r.m[3][0] = 0.0; r.m[3][1] = 0.0; r.m[3][2] = 0.0; r.m[3][3] = 1.0;

		return r;
	}

	mm_fix32_matrix4x4 mm_fix32_matrix4x4::get_scale(mm_fix32 s_x, mm_fix32 s_y, mm_fix32 s_z)
	{
		mm_fix32_matrix4x4 r;
		r.m[0][0] = s_x; r.m[0][1] = 0.0; r.m[0][2] = 0.0; r.m[0][3] = 0.0;
		r.m[1][0] = 0.0; r.m[1][1] = s_y; r.m[1][2] = 0.0; r.m[1][3] = 0.0;
		r.m[2][0] = 0.0; r.m[2][1] = 0.0; r.m[2][2] = s_z; r.m[2][3] = 0.0;
		r.m[3][0] = 0.0; r.m[3][1] = 0.0; r.m[3][2] = 0.0; r.m[3][3] = 1.0;

		return r;
	}

	void mm_fix32_matrix4x4::extract_3x3_matrix(mm_fix32_matrix3x3& m3x3) const
	{
		m3x3.m[0][0] = m[0][0];
		m3x3.m[0][1] = m[0][1];
		m3x3.m[0][2] = m[0][2];
		m3x3.m[1][0] = m[1][0];
		m3x3.m[1][1] = m[1][1];
		m3x3.m[1][2] = m[1][2];
		m3x3.m[2][0] = m[2][0];
		m3x3.m[2][1] = m[2][1];
		m3x3.m[2][2] = m[2][2];
	}

	void mm_fix32_matrix4x4::make_transform(const mm_fix32_vector3& position, const mm_fix32_vector3& scale, const mm_fix32_quaternion& orientation)
	{
		// Ordering:
		//    1. Scale
		//    2. Rotate
		//    3. Translate

		mm_fix32_matrix3x3 rot3x3;
		orientation.to_rotation_matrix(rot3x3);

		// Set up final matrix with scale, rotation and translation
		m[0][0] = scale.x * rot3x3[0][0]; m[0][1] = scale.y * rot3x3[0][1]; m[0][2] = scale.z * rot3x3[0][2]; m[0][3] = position.x;
		m[1][0] = scale.x * rot3x3[1][0]; m[1][1] = scale.y * rot3x3[1][1]; m[1][2] = scale.z * rot3x3[1][2]; m[1][3] = position.y;
		m[2][0] = scale.x * rot3x3[2][0]; m[2][1] = scale.y * rot3x3[2][1]; m[2][2] = scale.z * rot3x3[2][2]; m[2][3] = position.z;

		// No projection term
		m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
	}

	void mm_fix32_matrix4x4::make_inverse_transform(const mm_fix32_vector3& position, const mm_fix32_vector3& scale, const mm_fix32_quaternion& orientation)
	{
		// Invert the parameters
		mm_fix32_vector3 invTranslate = -position;
		mm_fix32_vector3 invScale(1 / scale.x, 1 / scale.y, 1 / scale.z);
		mm_fix32_quaternion invRot = orientation.inverse();

		// Because we're inverting, order is translation, rotation, scale
		// So make translation relative to scale & rotation
		invTranslate = invRot * invTranslate; // rotate
		invTranslate *= invScale; // scale

								  // Next, make a 3x3 rotation matrix
		mm_fix32_matrix3x3 rot3x3;
		invRot.to_rotation_matrix(rot3x3);

		// Set up final matrix with scale, rotation and translation
		m[0][0] = invScale.x * rot3x3[0][0]; m[0][1] = invScale.x * rot3x3[0][1]; m[0][2] = invScale.x * rot3x3[0][2]; m[0][3] = invTranslate.x;
		m[1][0] = invScale.y * rot3x3[1][0]; m[1][1] = invScale.y * rot3x3[1][1]; m[1][2] = invScale.y * rot3x3[1][2]; m[1][3] = invTranslate.y;
		m[2][0] = invScale.z * rot3x3[2][0]; m[2][1] = invScale.z * rot3x3[2][1]; m[2][2] = invScale.z * rot3x3[2][2]; m[2][3] = invTranslate.z;

		// No projection term
		m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
	}

	void mm_fix32_matrix4x4::decomposition(mm_fix32_vector3& position, mm_fix32_vector3& scale, mm_fix32_quaternion& orientation) const
	{
		assert(is_affine());

		mm_fix32_matrix3x3 m3x3;
		this->extract_3x3_matrix(m3x3);

		mm_fix32_matrix3x3 matQ;
		mm_fix32_vector3 vecU;
		m3x3.qdu_decomposition(matQ, scale, vecU);

		orientation = mm_fix32_quaternion(matQ);
		position = mm_fix32_vector3(m[0][3], m[1][3], m[2][3]);
	}

	mm_fix32_matrix4x4 mm_fix32_matrix4x4::inverse_affine(void) const
	{
		assert(this->is_affine());

		mm_fix32 m10 = m[1][0], m11 = m[1][1], m12 = m[1][2];
		mm_fix32 m20 = m[2][0], m21 = m[2][1], m22 = m[2][2];

		mm_fix32 t00 = m22 * m11 - m21 * m12;
		mm_fix32 t10 = m20 * m12 - m22 * m10;
		mm_fix32 t20 = m21 * m10 - m20 * m11;

		mm_fix32 m00 = m[0][0], m01 = m[0][1], m02 = m[0][2];

		mm_fix32 invDet = 1 / (m00 * t00 + m01 * t10 + m02 * t20);

		t00 *= invDet; t10 *= invDet; t20 *= invDet;

		m00 *= invDet; m01 *= invDet; m02 *= invDet;

		mm_fix32 r00 = t00;
		mm_fix32 r01 = m02 * m21 - m01 * m22;
		mm_fix32 r02 = m01 * m12 - m02 * m11;

		mm_fix32 r10 = t10;
		mm_fix32 r11 = m00 * m22 - m02 * m20;
		mm_fix32 r12 = m02 * m10 - m00 * m12;

		mm_fix32 r20 = t20;
		mm_fix32 r21 = m01 * m20 - m00 * m21;
		mm_fix32 r22 = m00 * m11 - m01 * m10;

		mm_fix32 m03 = m[0][3], m13 = m[1][3], m23 = m[2][3];

		mm_fix32 r03 = -(r00 * m03 + r01 * m13 + r02 * m23);
		mm_fix32 r13 = -(r10 * m03 + r11 * m13 + r12 * m23);
		mm_fix32 r23 = -(r20 * m03 + r21 * m13 + r22 * m23);

		return mm_fix32_matrix4x4(
			r00, r01, r02, r03,
			r10, r11, r12, r13,
			r20, r21, r22, r23,
			0, 0, 0, 1);
	}

	mm_fix32_matrix4x4 mm_fix32_matrix4x4::concatenate_affine(const mm_fix32_matrix4x4 &m2) const
	{
		assert(this->is_affine() && m2.is_affine());

		return mm_fix32_matrix4x4(
			m[0][0] * m2.m[0][0] + m[0][1] * m2.m[1][0] + m[0][2] * m2.m[2][0],
			m[0][0] * m2.m[0][1] + m[0][1] * m2.m[1][1] + m[0][2] * m2.m[2][1],
			m[0][0] * m2.m[0][2] + m[0][1] * m2.m[1][2] + m[0][2] * m2.m[2][2],
			m[0][0] * m2.m[0][3] + m[0][1] * m2.m[1][3] + m[0][2] * m2.m[2][3] + m[0][3],

			m[1][0] * m2.m[0][0] + m[1][1] * m2.m[1][0] + m[1][2] * m2.m[2][0],
			m[1][0] * m2.m[0][1] + m[1][1] * m2.m[1][1] + m[1][2] * m2.m[2][1],
			m[1][0] * m2.m[0][2] + m[1][1] * m2.m[1][2] + m[1][2] * m2.m[2][2],
			m[1][0] * m2.m[0][3] + m[1][1] * m2.m[1][3] + m[1][2] * m2.m[2][3] + m[1][3],

			m[2][0] * m2.m[0][0] + m[2][1] * m2.m[1][0] + m[2][2] * m2.m[2][0],
			m[2][0] * m2.m[0][1] + m[2][1] * m2.m[1][1] + m[2][2] * m2.m[2][1],
			m[2][0] * m2.m[0][2] + m[2][1] * m2.m[1][2] + m[2][2] * m2.m[2][2],
			m[2][0] * m2.m[0][3] + m[2][1] * m2.m[1][3] + m[2][2] * m2.m[2][3] + m[2][3],

			0, 0, 0, 1);
	}

	mm_fix32_vector3 mm_fix32_matrix4x4::transform_direction_affine(const mm_fix32_vector3& v) const
	{
		assert(this->is_affine());

		return mm_fix32_vector3(
			m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z,
			m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z,
			m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z);
	}

	mm_fix32_vector3 mm_fix32_matrix4x4::transform_affine(const mm_fix32_vector3& v) const
	{
		assert(this->is_affine());

		return mm_fix32_vector3(
			m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3],
			m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3],
			m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3]);
	}

	mm_fix32_vector4 mm_fix32_matrix4x4::transform_affine(const mm_fix32_vector4& v) const
	{
		assert(this->is_affine());

		return mm_fix32_vector4(
			m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w,
			m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w,
			m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w,
			v.w);
	}

	std::ostream& operator << (std::ostream& o, const mm_fix32_matrix4x4& mat)
	{
		o << "matrix4(";
		for (size_t i = 0; i < 4; ++i)
		{
			o << " row" << (unsigned)i << "{";
			for (size_t j = 0; j < 4; ++j)
			{
				o << mat[i][j] << " ";
			}
			o << "}";
		}
		o << ")";
		return o;
	}

}