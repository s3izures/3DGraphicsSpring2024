#include "CmdSetCorrectUV.h"
#include "PrimitiveManager.h"

bool CmdSetCorrectUV::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 1)
    {
        return false;
    }

    bool useCorrectUV = params[0] == "true";
    PrimitiveManager::Get()->SetCorrectUV(useCorrectUV);
    return true;
}
