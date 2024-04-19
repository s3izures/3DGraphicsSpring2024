#pragma once
#include "MathHelper.h"
#include "XEngine.h"

struct Vertex
{
	Vector3 pos;
	X::Color color;
};

inline static Vector3 LerpPosition(const Vector3& a, const Vector3& b, const float t)
{
	Vector3 pos;
	pos.x = MathHelper::Lerp(a.x, b.x, t);
	pos.y = MathHelper::Lerp(a.y, b.y, t);
	pos.z = MathHelper::Lerp(a.z, b.z, t);

	return pos;
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
inline static Vertex LerpVertex(const Vertex& a, const Vertex& b, const float t)
{
	Vertex vertex;
	vertex.pos = LerpPosition(a.pos, b.pos, t);
	vertex.color = LerpColor(a.color, b.color, t);
	return vertex;
}