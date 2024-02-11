
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_input.cpp
*/

#include "../../include/component/C_input.hpp"

nts::C_input::C_input() : AComponent("input")
{
    addPin(1, PinType::typeOutput);
}


nts::C_input::C_input(const std::string &name) : AComponent("input", name)
{
    addPin(1, PinType::typeOutput);
}
