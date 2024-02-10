
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4030.cpp
*/

#include "../../include/component/C_4030.hpp"

nts::C_4030::C_4030(const std::string &name) : AComponent("4030", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
