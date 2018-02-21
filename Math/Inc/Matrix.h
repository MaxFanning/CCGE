#ifndef INCLUDED_MATH_MATRIX_HEADER_H
#define INCLUDED_MATH_MATRIX_HEADER_H

class Vector3;
class Quaternion;

namespace CCGE {
namespace CMath {

struct Matrix
{
	float _11, _12, _13, _14;
	float _21, _22, _23, _24;
	float _31, _32, _33, _34;
	float _41, _42, _43, _44;

	Matrix()
		: _11(1.0f), _12(0.0f), _13(0.0f), _14(0.0f)
		, _21(0.0f), _22(1.0f), _23(0.0f), _24(0.0f)
		, _31(0.0f), _32(0.0f), _33(1.0f), _34(0.0f)
		, _41(0.0f), _42(0.0f), _43(0.0f), _44(1.0f)
	{}

	Matrix(float _11, float _12, float _13, float _14,
		   float _21, float _22, float _23, float _24,
		   float _31, float _32, float _33, float _34,
		   float _41, float _42, float _43, float _44)
		   : _11(_11), _12(_12), _13(_13), _14(_14)
		   , _21(_21), _22(_22), _23(_23), _24(_24)
		   , _31(_31), _32(_32), _33(_33), _34(_34)
		   , _41(_41), _42(_42), _43(_43), _44(_44)
	{}

	inline Matrix operator-() const;
	inline Matrix operator+(const Matrix& mat) const;
	inline Matrix operator-(const Matrix& mat) const;
	inline Matrix operator*(const Matrix& mat) const
	{
		return Matrix
		(
			(_11 * mat._11) + (_12 * mat._21) + (_13 * mat._31) + (_14 * mat._41),
			(_11 * mat._12) + (_12 * mat._22) + (_13 * mat._32) + (_14 * mat._42),
			(_11 * mat._13) + (_12 * mat._23) + (_13 * mat._33) + (_14 * mat._43),
			(_11 * mat._14) + (_12 * mat._24) + (_13 * mat._34) + (_14 * mat._44),

			(_21 * mat._11) + (_22 * mat._21) + (_23 * mat._31) + (_24 * mat._41),
			(_21 * mat._12) + (_22 * mat._22) + (_23 * mat._32) + (_24 * mat._42),
			(_21 * mat._13) + (_22 * mat._23) + (_23 * mat._33) + (_24 * mat._43),
			(_21 * mat._14) + (_22 * mat._24) + (_23 * mat._34) + (_24 * mat._44),

			(_31 * mat._11) + (_32 * mat._21) + (_33 * mat._31) + (_34 * mat._41),
			(_31 * mat._12) + (_32 * mat._22) + (_33 * mat._32) + (_34 * mat._42),
			(_31 * mat._13) + (_32 * mat._23) + (_33 * mat._33) + (_34 * mat._43),
			(_31 * mat._14) + (_32 * mat._24) + (_33 * mat._34) + (_34 * mat._44),

			(_41 * mat._11) + (_42 * mat._21) + (_43 * mat._31) + (_44 * mat._41),
			(_41 * mat._12) + (_42 * mat._22) + (_43 * mat._32) + (_44 * mat._42),
			(_41 * mat._13) + (_42 * mat._23) + (_43 * mat._33) + (_44 * mat._43),
			(_41 * mat._14) + (_42 * mat._24) + (_43 * mat._34) + (_44 * mat._44)
		);
	}
	inline Matrix operator+=(const Matrix& rhs);
	inline Matrix operator*(float s) const
	{
		return Matrix
		(
			_11 * s, _12 * s, _13 * s, _14 * s,
			_21 * s, _22 * s, _23 * s, _24 * s,
			_31 * s, _32 * s, _33 * s, _34 * s,
			_41 * s, _42 * s, _43 * s, _44 * s
		);
	}
	inline Matrix operator/(float s) const;

	static Matrix Zero();
	static Matrix Identity();
	static Matrix Translation(float x, float y, float z);
	static Matrix RotationX(float rad);
	static Matrix RotationY(float rad);
	static Matrix RotationZ(float rad);
	static Matrix Scaling(float sX, float sY, float sZ);
	static Matrix Scaling(float s);

};

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

}
}

#endif // !INCLUDED_MATH_MATRIX_HEADER_H
