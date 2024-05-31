#pragma once
#include "Command.h"
class CmdSetShadeMode :
    public Command
{
public:
	const char* GetName() override
	{
		return "SetShadeMode";
	}

	const char* GetDescription() override
	{
		return
			"SetShadeMode(shadeMode)\n"
			"\n"
			"- flat\n"
			"- gouraud\n"
			"- phong\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

