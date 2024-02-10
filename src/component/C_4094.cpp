
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4094.cpp
*/

#include "../../include/component/C_4094.hpp"

nts::C_4094::C_4094(const std::string &name) : AComponent("4094", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
