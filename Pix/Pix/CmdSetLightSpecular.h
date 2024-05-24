#pragma once
#include "Command.h"
class CmdSetLightSpecular : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightSpecular";
	}

	const char* GetDescription() override
	{
		return
			"SetLightSpecular()\n"
			"\n"
			"- ";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

