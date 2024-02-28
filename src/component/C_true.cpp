
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

void nts::C_true::compute(std::size_t pin)
{
    getPin(pin)->setLock(true);
    assignPinValue(1, True, this);
}
