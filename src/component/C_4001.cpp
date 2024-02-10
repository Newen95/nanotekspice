
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4001.cpp
*/

#include "../../include/component/C_4001.hpp"

nts::C_4001::C_4001(const std::string &name) : AComponent("4001", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeOutput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeOutput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeInput);
    addPin(12, PinType::typeInput);
}
