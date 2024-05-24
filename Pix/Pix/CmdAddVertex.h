#pragma once
#include "Command.h"

class CmdAddVertex : public Command
{
public:
	const char* GetName() override
	{
		return "Vertex";
	}

	const char* GetDescription() override
	{
		return
			"Vertex(x, y, z)\n"
			"Vertex(x, y, r, g, b)\n"
			"Vertex(x, y, z, r, g, b)\n"
			"\n"
			"- Adds vertex to primitives manager before render.";
	}

	bool Execute(const std::vector<std::string>& params) override;
};


