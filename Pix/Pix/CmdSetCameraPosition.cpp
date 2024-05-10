#include "CmdSetCameraPosition.h"
#include "VariableCache.h"
#include "Camera.h"

bool CmdSetCameraPosition::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}
	
	auto vc = VariableCache::Get();
	float x = vc->GetFloat(params[0]);
	float y = vc->GetFloat(params[1]);
	float z = vc->GetFloat(params[2]);
	Camera::Get()->SetPosition({ x, y, z });
	return true;
}
