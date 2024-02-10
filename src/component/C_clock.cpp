
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_clock.cpp
*/

#include "../../include/component/C_clock.hpp"

nts::C_clock::C_clock(const std::string &name) : AComponent("clock", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeOutput);
}
