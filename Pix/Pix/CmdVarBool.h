#pragma once
#include "Command.h"

class CmdVarBool : public Command
{
public:
	const char* GetName() override
	{
		return "bool";
	}

	const char* GetDescription() override
	{
		return
			"Declares a bool variable. Can optionally specify a drag speed, min, and max.\n"
			"\n"
			"syntax: int $<name> = <value>, =, <max>\n"
			"\n"
			"e.g.\n"
			"  \n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

