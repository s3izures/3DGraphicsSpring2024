#pragma once
#include "Command.h"
class CmdSetCorrectUV :
    public Command
{
public:
	const char* GetName() override
	{
		return "SetCorrectUV";
	}

	const char* GetDescription() override
	{
		return
			"SetCorrectUV(bool)\n"
			"\n"
			"- Sets uv.";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

