#include "Graphics.h"

#include "Viewport.h"
#include "Clipper.h"

void Graphics::NewFrame()
{
	Viewport::Get()->OnNewFrame();
	Clipper::Get()->OnNewFrame();
}