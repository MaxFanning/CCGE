#include "Precompiled.h"
#include "Matrix.h"
#include "Vector3.h"
#include "Quaternion.h"

namespace CCGE {
namespace CMath {

Matrix Matrix::operator-() const
{
	return (*this * -1.0f);
}

Matrix Matrix::operator+(const Matrix& mat) const
{
	return Matrix
	(
		_11 + mat._11, _12 + mat._12, _13 + mat._13, _14 + mat._14,
		_21 + mat._21, _22 + mat._22, _23 + mat._23, _24 + mat._24,
		_31 + mat._31, _32 + mat._32, _33 + mat._33, _34 + mat._34,
		_41 + mat._41, _42 + mat._42, _43 + mat._43, _44 + mat._44
	);
}

Matrix Matrix::operator-(const Matrix& mat) const
{
	return Matrix
	(
		_11 - mat._11, _12 - mat._12, _13 - mat._13, _14 - mat._14,
		_21 - mat._21, _22 - mat._22, _23 - mat._23, _24 - mat._24,
		_31 - mat._31, _32 - mat._32, _33 - mat._33, _34 - mat._34,
		_41 - mat._41, _42 - mat._42, _43 - mat._43, _44 - mat._44
	);
}

//Matrix Matrix::operator*(const Matrix& mat) const
//{
//	return Matrix
//	(
//		(_11 * mat._11) + (_12 * mat._21) + (_13 * mat._31) + (_14 * mat._41),
//		(_11 * mat._12) + (_12 * mat._22) + (_13 * mat._32) + (_14 * mat._42),
//		(_11 * mat._13) + (_12 * mat._23) + (_13 * mat._33) + (_14 * mat._43),
//		(_11 * mat._14) + (_12 * mat._24) + (_13 * mat._34) + (_14 * mat._44),
//			   									  					
//		(_21 * mat._11) + (_22 * mat._21) + (_23 * mat._31) + (_24 * mat._41),
//		(_21 * mat._12) + (_22 * mat._22) + (_23 * mat._32) + (_24 * mat._42),
//		(_21 * mat._13) + (_22 * mat._23) + (_23 * mat._33) + (_24 * mat._43),
//		(_21 * mat._14) + (_22 * mat._24) + (_23 * mat._34) + (_24 * mat._44),
//			   					 									
//		(_31 * mat._11) + (_32 * mat._21) + (_33 * mat._31) + (_34 * mat._41),
//		(_31 * mat._12) + (_32 * mat._22) + (_33 * mat._32) + (_34 * mat._42),
//		(_31 * mat._13) + (_32 * mat._23) + (_33 * mat._33) + (_34 * mat._43),
//		(_31 * mat._14) + (_32 * mat._24) + (_33 * mat._34) + (_34 * mat._44),
//			   					 								
//		(_41 * mat._11) + (_42 * mat._21) + (_43 * mat._31) + (_44 * mat._41),
//		(_41 * mat._12) + (_42 * mat._22) + (_43 * mat._32) + (_44 * mat._42),
//		(_41 * mat._13) + (_42 * mat._23) + (_43 * mat._33) + (_44 * mat._43),
//		(_41 * mat._14) + (_42 * mat._24) + (_43 * mat._34) + (_44 * mat._44)
//	);
//}

Matrix Matrix::operator+=(const Matrix& rhs)
{
	_11 += rhs._11; _12 += rhs._12; _13 += rhs._13; _14 += rhs._14;
	_21 += rhs._21; _22 += rhs._22; _23 += rhs._23; _24 += rhs._24;
	_31 += rhs._31; _32 += rhs._32; _33 += rhs._33; _34 += rhs._34;
	_41 += rhs._41; _42 += rhs._42; _43 += rhs._43; _44 += rhs._44;
	return *this;
}

//Matrix Matrix::operator*(float s) const
//{
//	return Matrix
//	(
//		_11 * s, _12 * s, _13 * s, _14 * s,
//		_21 * s, _22 * s, _23 * s, _24 * s,
//		_31 * s, _32 * s, _33 * s, _34 * s,
//		_41 * s, _42 * s, _43 * s, _44 * s
//	);
//}

Matrix Matrix::operator/(float s) const
{
	ASSERT(s != 0.0f, "[CMath::Matrix] Cannot divide by zero!");
	const float inv = 1.0f / s;
	return Matrix
	(
		_11 * inv, _12 * inv, _13 * inv, _14 * inv,
		_21 * inv, _22 * inv, _23 * inv, _24 * inv,
		_31 * inv, _32 * inv, _33 * inv, _34 * inv,
		_41 * inv, _42 * inv, _43 * inv, _44 * inv
	);
}

Matrix Matrix::Zero()
{
	return Matrix
	(
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);
}

Matrix Matrix::Identity()
{
	return Matrix();
}

Matrix Matrix::Translation(float x, float y, float z)
{
	return Matrix
	(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		x,    y,    z,    1.0f
	);
}

Matrix Matrix::RotationX(float rad)
{
	const float c = cos(rad);
	const float s = sin(rad);

	return Matrix
	(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, c,    s,    0.0f,
		0.0f, -s,   c,    0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Matrix Matrix::RotationY(float rad)
{
	const float c = cos(rad);
	const float s = sin(rad);

	return Matrix
	(
		c,    0.0f, -s,   0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		s,    0.0f, c,    0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Matrix Matrix::RotationZ(float rad)
{
	const float c = cos(rad);
	const float s = sin(rad);

	return Matrix
	(
		c,    s,    0.0f, 0.0f,
		-s,   c,    0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Matrix Matrix::Scaling(float sX, float sY, float sZ)
{
	return Matrix
	(
		sX,   0.0f, 0.0f, 0.0f,
		0.0f, sY,   0.0f, 0.0f,
		0.0f, 0.0f, sZ,   0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Matrix Matrix::Scaling(float s)
{
	return Matrix
	(
		s,    0.0f, 0.0f, 0.0f,
		0.0f, s,    0.0f, 0.0f,
		0.0f, 0.0f, s,    0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

}
}