
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_or.cpp
*/

#include "../../include/component/C_or.hpp"

nts::C_or::C_or() : AComponent("or")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeOutput);
}

nts::C_or::C_or(const std::string &name) : AComponent("or", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeOutput);
}
