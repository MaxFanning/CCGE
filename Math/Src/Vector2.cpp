#include "Precompiled.h"
#include "Vector2.h"

namespace CCGE {
namespace CMath {

Vector2 Vector2::XAxis()
{
	return { 1.0f, 0.0f };
}

Vector2 Vector2::YAxis()
{
	return { 0.0f, 1.0f };
}

Vector2 Vector2::Zero()
{
	return { 0.0f, 0.0f };
}

Vector2 Vector2::One()
{
	return { 0.0f, 0.0f };
}

Vector2 Vector2::operator/(float s) const
{
	return { 0.0f, 0.0f };
}

Vector2& Vector2::operator+=(const Vector2& v)
{
	//return { 0.0f, 0.0f };
}

Vector2& Vector2::operator-=(const Vector2& v)
{
	//return { 0.0f, 0.0f };
}

Vector2& Vector2::operator*=(float s)
{
	//return { 0.0f, 0.0f };
}

Vector2& Vector2::operator/=(float s)
{
	//return { 0.0f, 0.0f };
}

}
}