#pragma once
#include "Command.h"

class CmdDrawRectangle : public Command
{
public:
	const char* GetName() override
	{
		return "DrawRectangle";
	}

	const char* GetDescription() override
	{
		return
			"DrawRectangle(x, y, x, y)\n"
			"\n"
			"- Draws a rectangle from first point (x, y) to second point (x, y).";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

