#pragma once
#include "Vertex.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

class PrimitiveManager
{
public:
	static PrimitiveManager* Get();
	~PrimitiveManager();
	bool BeginDraw(Topology topology);
	void AddVertex(const Vertex& vertex);
	bool EndDraw();

private:
	PrimitiveManager();
	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Triangle;
	bool mDrawBegin = false;
};

