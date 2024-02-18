
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_true.cpp
*/

#include "../../include/component/C_true.hpp"

nts::C_true::C_true() : AComponent("true")
{
    addPin(1, PinType::typeOutput);
}

void nts::C_true::simulateComponent()
{
    assignPinValue(1, True, this);
}
