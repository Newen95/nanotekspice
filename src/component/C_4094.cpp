
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4094.cpp
*/

#include "../../include/component/C_4094.hpp"

nts::C_4094::C_4094() : AComponent("4094")
{
    addPin(1, PinType::typeTrue);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeClock);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeOutput);
    addPin(6, PinType::typeOutput);
    addPin(7, PinType::typeOutput);
    addPin(8, PinType::typeIgnored);
    addPin(9, PinType::typeOutput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeOutput);
    addPin(14, PinType::typeOutput);
    addPin(15, PinType::typeTrue);
}

nts::C_4094::C_4094(const std::string &name) : AComponent("4094", name)
{
    addPin(1, PinType::typeTrue);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeClock);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeOutput);
    addPin(6, PinType::typeOutput);
    addPin(7, PinType::typeOutput);
    addPin(8, PinType::typeIgnored);
    addPin(9, PinType::typeOutput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeOutput);
    addPin(14, PinType::typeOutput);
    addPin(15, PinType::typeTrue);
}
