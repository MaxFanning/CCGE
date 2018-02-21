#include "Precompiled.h"
#include "Vector4.h"

namespace CCGE {
namespace CMath {

Vector4 Vector4::Red()
{
	return { 1.0f, 0.0f, 0.0f, 1.0f };
}

Vector4 Vector4::Green()
{
	return { 0.0f, 1.0f, 0.0f, 1.0f };
}

Vector4 Vector4::Blue()
{
	return { 0.0f, 0.0f, 1.0f, 1.0f };
}

Vector4 Vector4::XAxis()
{
	return { 0.0f, 0.0f, 0.0f, 0.0f };
}

Vector4 Vector4::YAxis()
{
	return { 0.0f, 0.0f, 0.0f, 0.0f };
}

Vector4 Vector4::ZAxis()
{
	return { 0.0f, 0.0f, 0.0f, 0.0f };
}

Vector4 Vector4::Zero()
{
	return { 0.0f, 0.0f, 0.0f, 0.0f };
}

Vector4 Vector4::One()
{
	return { 0.0f, 0.0f, 0.0f, 0.0f };
}

Vector4 Vector4::operator/(float s) const
{
	return { 0.0f, 0.0f, 0.0f, 0.0f };
}

Vector4& Vector4::operator+=(const Vector4& v)
{

}

Vector4& Vector4::operator-=(const Vector4& v)
{

}

Vector4& Vector4::operator*=(float s)
{

}

Vector4& Vector4::operator/=(float s)
{

}

}
}