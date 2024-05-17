#include "CmdSetCullMode.h"
#include "PrimitiveManager.h"

bool CmdSetCullMode::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 1)
    {
        return false;
    }

    CullMode cullmode = CullMode::None;
    if (params[0] == "None")
    {
        cullmode = CullMode::None;
    }
    else if (params[0] == "Back")
    {
        cullmode = CullMode::Back;
    }
    else if (params[0] == "Front")
    {
        cullmode = CullMode::Front;
    }
    else
    {
        return false;
    }


    PrimitiveManager::Get()->SetCullMode(cullmode);
    return true;
}
