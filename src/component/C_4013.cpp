
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4013.cpp
*/

#include "../../include/component/C_4013.hpp"

nts::C_4013::C_4013(const std::string &name) : AComponent("4013", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeOutput);
    addPin(6, PinType::typeClock);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
}
