#include "Graphics.h"

#include "Viewport.h"
#include "Clipper.h"
#include "Camera.h"
#include "MatrixStack.h"

void Graphics::NewFrame()
{
	Viewport::Get()->OnNewFrame();
	Clipper::Get()->OnNewFrame();
	Camera::Get()->OnNewFrame();
	MatrixStack::Get()->OnNewFrame();
}