#include "CmdSetCameraNear.h"
#include "VariableCache.h"
#include "Camera.h"

bool CmdSetCameraNear::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	auto vc = VariableCache::Get();
	float near = vc->GetFloat(params[0]);
	Camera::Get()->SetNearPlane(near);
	return true;
}
