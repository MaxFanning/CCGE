#ifndef INCLUDED_MATH_VECTOR3_H
#define INCLUDED_MATH_VECTOR3_H

namespace CCGE {
namespace CMath {

struct Vector3
{
	float x, y, z;

	Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	static Vector3 XAxis();
	static Vector3 YAxis();
	static Vector3 ZAxis();
	static Vector3 Zero();
	static Vector3 One();

	inline Vector3 operator+(const Vector3& v) const { return { x + v.x, y + v.y, z + v.z }; }
	inline Vector3 operator-(const Vector3& v) const { return { x - v.x, y - v.y, z + v.z }; }
	inline Vector3 operator-()                 const { return { -x, -y, -z }; }
	inline Vector3 operator*(float s)          const { return { x * s, y * s, z * s }; }
	inline Vector3 operator/(float s)          const;

	inline Vector3& operator+=(const Vector3& v);
	inline Vector3& operator-=(const Vector3& v);
	inline Vector3& operator*=(float s);
	inline Vector3& operator/=(float s);
};

} // namespace Math
} // namespace CCGE

#endif // !INCLUDED_CORE_VECTOR3_H
