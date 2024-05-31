#pragma once
#include "MathHelper.h"
#include "XEngine.h"

struct Vertex
{
	Vector3 pos;
	Vector3 posWorld;
	Vector3 norm;
	X::Color color;
};

inline static Vector3 LerpPosition(const Vector3& a, const Vector3& b, const float t, bool toPixel = true)
{
	Vector3 pos;
	pos.x = MathHelper::Lerp(a.x, b.x, t);
	pos.y = MathHelper::Lerp(a.y, b.y, t);
	pos.z = MathHelper::Lerp(a.z, b.z, t);
	if (toPixel)
	{
		pos.x = floorf((a.x, b.x, t) + 0.5f);
		pos.y = floorf((a.y, b.y, t) + 0.5f);
	}
	return pos;
}
inline static Vector3 LerpNorm(const Vector3& a, const Vector3& b, const float t)
{
	Vector3 norm;
	norm.x = MathHelper::Lerp(a.x, b.x, t);
	norm.y = MathHelper::Lerp(a.y, b.y, t);
	norm.z = MathHelper::Lerp(a.z, b.z, t);

	return MathHelper::Normalize(norm);
}
inline static X::Color LerpColor(const X::Color& a, const X::Color& b, const float t)
{
	X::Color col;
	col.x = MathHelper::Lerp(a.r, b.r, t);
	col.y = MathHelper::Lerp(a.g, b.g, t);
	col.z = MathHelper::Lerp(a.b, b.b, t);
	col.a = MathHelper::Lerp(a.a, b.a, t);

	return col;
}
inline static Vertex LerpVertex(const Vertex& a, const Vertex& b, const float t, bool lerpNorm = false)
{
	Vertex vertex;
	vertex.pos = LerpPosition(a.pos, b.pos, t, false);
	vertex.color = LerpColor(a.color, b.color, t);
	if (lerpNorm)
	{
		vertex.posWorld = LerpPosition(a.posWorld, b.posWorld, t);
		vertex.norm = LerpNorm(a.norm, b.norm, t);
	}
	return vertex;
}