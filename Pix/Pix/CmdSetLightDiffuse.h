#pragma once
#include "Command.h"
class CmdSetLightDiffuse : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightDiffuse";
	}

	const char* GetDescription() override
	{
		return
			"SetLightDiffuse()\n"
			"\n"
			"- ";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

