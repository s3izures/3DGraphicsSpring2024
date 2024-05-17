#include "DepthBuffer.h"

DepthBuffer* DepthBuffer::Get()
{
	static DepthBuffer sInstance;
	return &sInstance;
}

void DepthBuffer::OnNewFrame()
{
	mEnabled = false;
	for (int i = 0; i < mWidth * mHeight; ++i)
	{
		mDepthBuffer[i] = 1.0f;
	}
}

void DepthBuffer::Initialize(int width, int height)
{
	if (width != mWidth || height != mHeight)
	{
		mDepthBuffer = std::make_unique<float[]>(width * height);
		mWidth = width;
		mHeight = height;
		OnNewFrame();
	}
}

void DepthBuffer::SetEnabled(bool enabled)
{
	mEnabled = enabled;
}

bool DepthBuffer::CheckDepthBuffer(int x, int y, int z)
{
	if (!mEnabled)
	{
		return true;
	}
}
