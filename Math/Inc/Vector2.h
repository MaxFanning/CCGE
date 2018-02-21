#ifndef INCLUDED_MATH_VECTOR2_H
#define INCLUDED_MATH_VECTOR2_H

namespace CCGE {
namespace CMath {

struct Vector2
{
	float x, y;

	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(float x, float y) : x(x), y(y) {}

	static Vector2 XAxis();
	static Vector2 YAxis();
	static Vector2 Zero();
	static Vector2 One();

	inline Vector2 operator+(const Vector2& v) const { return { x + v.x, y + v.y }; }
	inline Vector2 operator-(const Vector2& v) const { return { x - v.x, y - v.y }; }
	inline Vector2 operator-()                 const { return { -x, -y }; }
	inline Vector2 operator*(float s)          const { return { x * s, y * s }; }
	inline Vector2 operator/(float s)          const;
	  
	inline Vector2& operator+=(const Vector2& v);
	inline Vector2& operator-=(const Vector2& v);
	inline Vector2& operator*=(float s);
	inline Vector2& operator/=(float s);
};

}
}

#endif // !INCLUDED_MATH_VECTOR2_H
