#ifndef INCLUDED_MATH_VECTOR4_H
#define INCLUDED_MATH_VECTOR4_H

namespace CCGE {
namespace CMath {

struct Vector4
{
float x, y, z, w;

Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

static Vector4 Red();
static Vector4 Green();
static Vector4 Blue();

static Vector4 XAxis();
static Vector4 YAxis();
static Vector4 ZAxis();
static Vector4 Zero();
static Vector4 One();
			 
inline Vector4 operator+(const Vector4& v) const { return { x + v.x, y + v.y, z + v.z, w + v.w }; }
inline Vector4 operator-(const Vector4& v) const { return { x - v.x, y - v.y, z - v.z, w - v.w }; }
inline Vector4 operator-()                 const { return { -x, -y, -z, -w }; }
inline Vector4 operator*(float s)          const { return { x * s, y * s, z * s, w * s }; }
inline Vector4 operator/(float s)          const;

inline Vector4& operator+=(const Vector4& v);
inline Vector4& operator-=(const Vector4& v);
inline Vector4& operator*=(float s);
inline Vector4& operator/=(float s);
};

} // namespace Math
} // namespace CCGE

#endif // !INCLUDED_CORE_VECTOR4_H
