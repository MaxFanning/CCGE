#ifndef INCLUDED_MATH_H
#define INCLUDED_MATH_H

// ---------- INCLUDES ----------
#include "Common.h"

#include "Vector4.h"
#include "Vector3.h"
#include "Vector2.h"
#include "Quaternion.h"
#include "Matrix.h"

namespace CCGE {
namespace CMath {

// ---------- FUNCTION DECLARATIONS ----------

template <typename T> 
inline T Min(T a, T b) { return (a > b) ? b : a; }
template <typename T> 
inline T Max(T a, T b) { return (a < b) ? b : a; }
template <typename T>
inline T Clamp(T value, T min, T max) { return Max(min, Min(max, value)); }

bool Compare(float a, float b/*, float epsilon = 0.000001f*/);
bool IsZero(float flt);
bool IsZero(Vector3 v);

inline float Abs(float flt);
inline float Sign(float flt);
inline float Sqr(float flt);
inline float Sqrt(float flt);

float MagnitudeSqr(const Vector3& v);
float Magnitude(const Vector3& v);
float MagnitudeXZSqr(const Vector3& v);
float MagnitudeZX(const Vector3& v);

Vector3 Normalize(const Vector3& v);
Quaternion Normalize(const Quaternion& q);

float DistanceSqr(const Vector3& a, const Vector3& b);
float Distance(const Vector3& a, const Vector3& b);

float Dot(const Vector3& a, const Vector3& b);
float Determinant(const Matrix& m);
Vector3 Cross(const Vector3& a, const Vector3& b);
Vector3 Project(const Vector3& v, const Vector3& n);

Matrix Adjoint(const Matrix& m);
Matrix Inverse(const Matrix& m);
Matrix Transpose(const Matrix& m);

Vector3 TransformCoord(const Vector3& v, const Matrix& m);
Vector3 TransformNormal(const Vector3& v, const Matrix& m);

Vector3 Lerp(const Vector3& v0, const Vector3& v1, float t);
Quaternion Lerp(const Quaternion& q0, const Quaternion& q1, float t);
Quaternion Slerp(Quaternion q0, Quaternion q1, float t);

static Matrix Translation(const Vector3& v);
static Matrix RotationAxis(const Vector3& axis, float rad);
static Matrix RotationQuaternion(const Quaternion& q);

static Quaternion RotationAxisQuaternion(const Vector3& axis, float rad);

}
}

#endif // !INCLUDED_MATH_H
