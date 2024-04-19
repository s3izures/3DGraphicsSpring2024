#pragma once
#include "Command.h"

class CmdSetFillMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetFillMode";
	}

	const char* GetDescription() override
	{
		return
			"SetFillMode(fillMode)\n"
			"\n"
			"- Wireframe: outline only.\n"
			"- Solid: fill in shape.\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

