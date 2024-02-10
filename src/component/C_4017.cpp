
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4017.cpp
*/

#include "../../include/component/C_4017.hpp"

nts::C_4017::C_4017(const std::string &name) : AComponent("4017", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeOutput);
    addPin(6, PinType::typeOutput);
    addPin(7, PinType::typeOutput);
    addPin(8, PinType::typeOutput);
    addPin(9, PinType::typeOutput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeOutput);
    addPin(14, PinType::typeOutput);
}
