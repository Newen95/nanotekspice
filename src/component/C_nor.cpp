
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_nor.cpp
*/

#include "../../include/component/C_nor.hpp"

nts::C_nor::C_nor() : AComponent("nor")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeOutput);
}

nts::C_nor::C_nor(const std::string &name) : AComponent("nor", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeOutput);
}
