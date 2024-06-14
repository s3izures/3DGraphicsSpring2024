#include "CmdVarInt.h"
#include "VariableCache.h"

bool CmdVarInt::Execute(const std::vector<std::string>& params)
{
	// Need at leaset 3 params for name, =, value
	if (params.size() < 3)
		return false;

	auto vc = VariableCache::Get();
	if (!vc->IsVarName(params[0]) || params[1] != "=")
		return false;

	const int value = std::stof(params[2]);
	const int speed = params.size() > 3 ? std::stof(params[3]) : 1;
	const int min = params.size() > 4 ? std::stof(params[4]) : INT32_MIN;
	const int max = params.size() > 5 ? std::stof(params[5]) : INT32_MAX;

	// Register variable
	vc->AddInt(params[0], value, speed, min, max);
	return true;
}
