
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4069.cpp
*/

#include "../../include/component/C_4069.hpp"

nts::C_4069::C_4069(const std::string &name) : AComponent("4069", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeOutput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeOutput);
    addPin(7, PinType::typeOutput);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeOutput);
    addPin(10, PinType::typeInput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeInput);
}
