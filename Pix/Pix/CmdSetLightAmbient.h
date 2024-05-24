#pragma once
#include "Command.h"
class CmdSetLightAmbient : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightAmbient";
	}

	const char* GetDescription() override
	{
		return
			"SetLightAmbient()\n"
			"\n"
			"- ";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

