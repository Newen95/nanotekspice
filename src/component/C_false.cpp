
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_false.cpp
*/

#include "../../include/component/C_false.hpp"

nts::C_false::C_false() : AComponent("false")
{
    addPin(1, PinType::typeOutput);
}

void nts::C_false::compute(std::size_t pin)
{
    getPin(pin)->setLock(true);
    assignPinValue(1, False, this);
}
