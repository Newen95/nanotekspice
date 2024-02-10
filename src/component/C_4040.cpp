
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4040.cpp
*/

#include "../../include/component/C_4040.hpp"

nts::C_4040::C_4040(const std::string &name) : AComponent("4040", name)
{
    addPin(1, PinType::typeOutput);
    addPin(2, PinType::typeOutput);
    addPin(3, PinType::typeOutput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeOutput);
    addPin(6, PinType::typeOutput);
    addPin(7, PinType::typeOutput);
    addPin(8, PinType::typeIgnored);
    addPin(9, PinType::typeOutput);
    addPin(10, PinType::typeClock);
    addPin(11, PinType::typeInput);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeOutput);
    addPin(14, PinType::typeOutput);
    addPin(15, PinType::typeOutput);
    addPin(16, PinType::typeIgnored);
}
