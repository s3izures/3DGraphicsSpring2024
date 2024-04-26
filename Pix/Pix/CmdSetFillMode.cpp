#include "CmdSetFillMode.h"
#include "Rasterizer.h"

bool CmdSetFillMode::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 1)
        return false;

    FillMode fillMode = FillMode::Wireframe;
    if (params[0] == "Wireframe")
        fillMode = FillMode::Wireframe;
    if (params[0] == "Solid")
        fillMode = FillMode::Solid;
    else
        return false;

    Rasterizer::Get()->SetFillMode(fillMode);
    return true;
}
