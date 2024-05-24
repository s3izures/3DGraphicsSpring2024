#include "Graphics.h"

#include "Viewport.h"
#include "Clipper.h"
#include "Camera.h"
#include "MatrixStack.h"
#include "PrimitiveManager.h"
#include "DepthBuffer.h"
#include "LightManager.h"
#include "MaterialManager.h"

void Graphics::NewFrame()
{
	Viewport::Get()->OnNewFrame();
	Clipper::Get()->OnNewFrame();
	Camera::Get()->OnNewFrame();
	MatrixStack::Get()->OnNewFrame();
	PrimitiveManager::Get()->OnNewFrame();
	DepthBuffer::Get()->OnNewFrame();
	LightManager::Get()->OnNewFrame();
	MaterialManager::Get()->OnNewFrame();
}