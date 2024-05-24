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
			"SetLightAmbient(r, g, b)\n"
			"\n"
			"- Sets ambient light";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

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
			"SetLightDiffuser(r, g, b)\n"
			"\n"
			"- Set diffuse light color.";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

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
			"SetLightSpecular(r, g, b)\n"
			"\n"
			"- Sets specular light";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

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
			"- Adds a directional ight";
	}

	bool Execute(const std::vector<std::string>& params) override;
};


