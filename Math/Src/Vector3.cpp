#include "Precompiled.h"
#include "Vector3.h"

namespace CCGE {
namespace CMath {

Vector3 Vector3::XAxis()
{
	return { 1.0f, 0.0f, 0.0f };
}

Vector3 Vector3::YAxis()
{
	return { 0.0f, 1.0f, 0.0f };
}

Vector3 Vector3::ZAxis()
{
	return { 0.0f, 0.0f, 1.0f };
}

Vector3 Vector3::Zero()
{
	return Vector3();
}

Vector3 Vector3::One()
{
	return { 1.0f, 1.0f, 1.0f };
}

Vector3 Vector3::operator/(float s) const
{
	ASSERT(s != 0.0f, "[CMath::Vector3] Cannot divide by zero!");
	const float div = 1.0f / s;
	return { x * div, y * div, z * div };
}

Vector3& Vector3::operator+=(const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vector3& Vector3::operator*=(float s)
{
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

Vector3& Vector3::operator/=(float s)
{
	ASSERT(s != 0.0f, "[CMath] Cannot divide by zero!");
	const float inv = 1.0f / s;
	x *= inv;
	y *= inv;
	z *= inv;
	return *this;
}

}
}