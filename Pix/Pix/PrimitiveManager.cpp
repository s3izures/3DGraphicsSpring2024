#include "PrimitiveManager.h"
#include "Rasterizer.h"
#include "Clipper.h"
#include "Camera.h"
#include "Matrix4.h"

extern float gResolutionX;
extern float gResolutionY;

namespace
{
	Matrix4 GetScreenMatrix()
	{
		float hw = gResolutionX * 0.5f;
		float hh = gResolutionY * 0.5f;

		return Matrix4
		(
			hw, 0.0f, 0.0f, 0.0f,
			0.0f, -hh, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			hw, hh, 0.0f, 1.0f
		);
	}
}

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

bool PrimitiveManager::BeginDraw(Topology topology, bool applyTransform)
{
	mTopology = topology;
	mDrawBegin = true;
	mApplyTransform = applyTransform;
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

	if (mApplyTransform)
	{
		Matrix4 matWorld = Identity();
		Matrix4 matView = Camera::Get()->GetViewMatrix();
		Matrix4 matProj = Camera::Get()->GetProjectionMatrix();
		Matrix4 matScreen = GetScreenMatrix();
		Matrix4 matNDC = matWorld * matView * matProj;
		Matrix4	matFinal = matNDC * matScreen;

		for (size_t i = 0; i < mVertexBuffer.size(); ++i)
		{
			Vector3 finalPos = MathHelper::TransformCoord(mVertexBuffer[i].pos, matFinal);
			mVertexBuffer[i].pos = finalPos;
		}
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
