#pragma once
#include "Vertex.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

enum class CullMode
{
	None, //No culling
	Back, //Back facing
	Front //Front facing
};

class PrimitiveManager
{
public:
	static PrimitiveManager* Get();
	~PrimitiveManager();

	void OnNewFrame();
	void SetCullMode(CullMode mode);
	void SetCorrectUV(bool correctUV);

	bool BeginDraw(Topology topology, bool applyTransform);
	void AddVertex(const Vertex& vertex);
	bool EndDraw();

private:
	PrimitiveManager();
	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Triangle;
	CullMode mCullMode = CullMode::None;
	bool mCorrectUV = false;
	bool mDrawBegin = false;
	bool mApplyTransform = false;
};

