#pragma once
#include "Command.h"
class CmdModel :
    public Command
{
public:
	const char* GetName() override
	{
		return "Model";
	}

	const char* GetDescription() override
	{
		return
			"Model(filename)\n"
			"\n"
			"- Load model as vertices.";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

