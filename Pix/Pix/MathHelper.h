#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix4.h"

class MathHelper
{
public:
	static float MagnitudeSquared(const Vector2& v);
	static float MagnitudeSquared(const Vector3& v);
	static float Magnitude(const Vector2& v);
	static float Magnitude(const Vector3& v);
	static Vector2 Normalize(const Vector2& v);
	static Vector3 Normalize(const Vector3& v);
	static float Dot(const Vector2& a, const Vector2& b);
	static float Dot(const Vector3& a, const Vector3& b);
	static Vector3 Cross(const Vector3& a, const Vector3& b);
	static float Lerp(float a, float b, float t);
	static bool CheckEqual(float a, float b);

	static void FlattenVector(Vector3& v);
	static Vector3 TransformCoord(const Vector3& v, const Matrix4& m); //w=1
	static Vector3 TransformNormal(const Vector3& v, const Matrix4& m); //w=0
	static float Determinant(const Matrix4& m);
	static Matrix4 Adjoint(const Matrix4& m);
	static Matrix4 Transpose(const Matrix4& m);
	static Matrix4 Inverse(const Matrix4& m);

};