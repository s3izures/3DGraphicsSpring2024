#pragma once
#include "Vertex.h"

class Clipper
{
public:
	static Clipper* Get();

	void OnNewFrame();
	bool ClipPoint(const Vertex& v);
	bool ClipLine(Vertex& v0, Vertex& v1);
	bool ClipTriangle(std::vector<Vertex>& vertices);
	
	bool IsClipping() const { return mClipping; }
	void SetClipping(bool clip) { mClipping = clip; }

private:
	Clipper();
	bool mClipping = false;
};

