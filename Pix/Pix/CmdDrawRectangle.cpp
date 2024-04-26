#include "CmdDrawRectangle.h"
#include "Rasterizer.h"

bool CmdDrawRectangle::Execute(const std::vector<std::string>& params)
{
	// Need at least 4 params for x, y
	if (params.size() < 4)
	{
		return false;
	}

	int positionX1 = stoi(params[0]);
	int positionY1 = stoi(params[1]);

	int positionX2 = stoi(params[2]);
	int positionY2 = stoi(params[3]);

	if (positionX1 > positionX2 || positionY1 > positionY2)
	{
		return false;
	}

	// Draw the pixel
	for (int y = positionY1; y <= positionY2; y++)
	{
		for (int x = positionX1; x <= positionX2; x++)
		{
			Rasterizer::Get()->DrawPoint(x, y);
		}
	}
	return true;
}