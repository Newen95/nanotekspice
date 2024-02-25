
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

void nts::C_input::simulateComponent()
{
    Tristate state = (*getPin(1)).getState();
    assignPinValue(1, state, this);
}
