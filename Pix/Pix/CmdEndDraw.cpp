#include "CmdEndDraw.h"
#include"PrimitiveManager.h"

bool CmdEndDraw::Execute(const std::vector<std::string>& params)
{
    return PrimitiveManager::Get()->EndDraw();
}
