#pragma once
#include "Command.h"
class CmdAddDirectionalLight : public Command
{
public:
	const char* GetName() override
	{
		return "AddDirectionalLight";
	}

	const char* GetDescription() override
	{
		return
			"AddDirectionalLight()\n"
			"\n"
			"- ";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

