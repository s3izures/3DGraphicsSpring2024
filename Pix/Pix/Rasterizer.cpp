#include "Rasterizer.h"

Rasterizer* Rasterizer::Get()
{
	static Rasterizer sInstance;
	return &sInstance;
}

void Rasterizer::SetColor(X::Color color)
{
	mColor = color;
}

void Rasterizer::SetFillMode(FillMode fillMode)
{
	mFillMode = fillMode;
}

void Rasterizer::DrawPoint(int x, int y)
{
	X::DrawPixel(x, y, mColor);
}

void Rasterizer::DrawPoint(const Vertex& v)
{
	mColor = v.color;
	DrawPoint(static_cast<int>(v.pos.x + 0.5f), static_cast<int>(v.pos.y + 0.5f));
}

void Rasterizer::DrawLine(const Vertex& v0, const Vertex& v1)
{
	float dx = v0.pos.x - v1.pos.x;
	float dy = v0.pos.y - v1.pos.y;
	if (std::abs(dx) < 0.01f || std::abs(dx) < std::abs(dy)) //Slope goes up
	{
		float startY, endY;
		if (v0.pos.y < v1.pos.y)
		{
			startY = v0.pos.y;
			endY = v1.pos.y;
		}
		else
		{
			endY = v0.pos.y;
			startY = v1.pos.y;
		}

		for (float y = startY; y <= endY; ++y)
		{
			float t = (y - startY) / (endY - startY);
			Vertex v = LerpVertex(v0, v1, t);
			DrawPoint(v);
		}
	}
	else
	{
		float startX, endX;
		if (v0.pos.x < v1.pos.x)
		{
			startX = v0.pos.x;
			endX = v1.pos.x;
		}
		else
		{
			endX = v0.pos.x;
			startX = v1.pos.x;
		}

		for (float x = startX; x <= endX; ++x)
		{
			float t = (x - startX) / (endX - startX);
			Vertex v = LerpVertex(v0, v1, t);
			DrawPoint(v);
		}
	}
}

void Rasterizer::DrawTriangle(const Vertex& v0, const Vertex& v1, const Vertex& v2)
{

}
