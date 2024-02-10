
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4008.cpp
*/

#include "../../include/component/C_4008.hpp"

nts::C_4008::C_4008(const std::string &name) : AComponent("4008", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
