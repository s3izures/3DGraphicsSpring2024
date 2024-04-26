#pragma once

#include <XEngine.h>
#include "Vertex.h"

enum class FillMode
{
	Wireframe,
	Solid
};

class Rasterizer
{
public:
	static Rasterizer* Get();

public:
	void SetColor(X::Color color);
	void SetFillMode(FillMode fillMode);

	void DrawPoint(int x, int y);

	void DrawPoint(const Vertex& v);
	void DrawLine(const Vertex& v0, const Vertex& v1);
	void DrawTriangle(const Vertex& v0, const Vertex& v1, const Vertex& v2);

private:
	X::Color mColor = X::Colors::White;
	FillMode mFillMode = FillMode::Wireframe;

	void DrawFilledTriangle(const Vertex& v0, const Vertex& v1, const Vertex& v2);
};