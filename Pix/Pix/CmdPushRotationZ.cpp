#include "CmdPushRotationZ.h"
#include "VariableCache.h"
#include "MatrixStack.h"

bool CmdPushRotationZ::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}

	auto vc = VariableCache::Get();
	float rad = vc->GetFloat(params[0]) * 3.1459 / 180.0f;
	MatrixStack::Get()->PushRotationX(rad);
	return true;
}
