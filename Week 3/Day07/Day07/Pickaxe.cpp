#include "Pickaxe.h"

std::string Pickaxe::Swing()
{
    return "Player 2";
}

//Pickaxe::Pickaxe()
//{
//    material_ = Material::Wood;
//    label_ = "";
//}

Pickaxe::Pickaxe(ToolMaterial material, std::string label) :
    label_(label),
    material_(material)
{
}

Pickaxe::Pickaxe(ToolMaterial material) :
    material_(material),
    label_("")
{
}
