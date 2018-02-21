#ifndef INCLUDED_MATH_QUATERNION_H
#define INCLUDED_MATH_QUATERNION_H

class Vector3;

namespace CCGE {
namespace CMath {
	
struct Quaternion
{
	float x, y, z, w;

	Quaternion() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
	Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	inline Quaternion operator+(const Quaternion& rhs) const;
	inline Quaternion operator*(float s) const;
};

Quaternion Quaternion::operator+(const Quaternion& rhs) const
{
	return Quaternion(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

Quaternion Quaternion::operator*(float s) const
{
	return Quaternion(x * s, y * s, z * s, w * s);
}

}
}

#endif // !INCLUDED_MATH_QUATERNION_H
