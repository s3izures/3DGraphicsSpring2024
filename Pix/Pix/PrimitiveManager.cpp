#include "PrimitiveManager.h"
#include "Rasterizer.h"
#include "Clipper.h"

PrimitiveManager::PrimitiveManager()
{

}

PrimitiveManager::~PrimitiveManager()
{
	
}

PrimitiveManager* PrimitiveManager::Get()
{
	static PrimitiveManager sInstance;
	return &sInstance;
}

bool PrimitiveManager::BeginDraw(Topology topology)
{
	mTopology = topology;
	mDrawBegin = true;
	mVertexBuffer.clear();
	return true;
}

void PrimitiveManager::AddVertex(const Vertex& vertex)
{
	if (mDrawBegin)
	{
		mVertexBuffer.push_back(vertex);
	}
}

bool PrimitiveManager::EndDraw()
{
	if (!mDrawBegin)
	{
		return false;
	}

	switch (mTopology)
	{
	case Topology::Point:
		for (size_t i = 0; i < mVertexBuffer.size(); ++i)
		{
			if (!Clipper::Get()->ClipPoint(mVertexBuffer[i]))
			{
				Rasterizer::Get()->DrawPoint(mVertexBuffer[i]);
			}
		}
		break;

	case Topology::Line:
		for (size_t i = 1; i < mVertexBuffer.size(); i+=2)
		{
			if (!Clipper::Get()->ClipLine(mVertexBuffer[i-1], mVertexBuffer[i]))
			{
				Rasterizer::Get()->DrawLine(mVertexBuffer[i - 1], mVertexBuffer[i]);
			}
		}
		break;

	case Topology::Triangle:
		for (size_t i = 2; i < mVertexBuffer.size(); i+=3)
		{
			std::vector<Vertex> triangle = { mVertexBuffer[i - 2],mVertexBuffer[i - 1],mVertexBuffer[i] };
			if (!Clipper::Get()->ClipTriangle(triangle))
			{
				for (size_t t = 2; t < triangle.size(); ++t)
				{
					Rasterizer::Get()->DrawTriangle(triangle[0], triangle[t - 1], triangle[t]);
				}
			}
		}
		break;

	default:
		break;
	}

	mDrawBegin = false;
	return true;
}
