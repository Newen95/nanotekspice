
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4094.cpp
*/

#include "../../include/component/C_4094.hpp"

nts::C_4094::C_4094(const std::string &name) : AComponent("4094", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::True);
    addPin(3, PinType::True);
    addPin(4, PinType::Output);
    addPin(5, PinType::Output);
    addPin(6, PinType::Output);
    addPin(7, PinType::Output);
    addPin(8, PinType::Output);
    addPin(9, PinType::Output);
    addPin(10, PinType::Output);
    addPin(11, PinType::Output);
    addPin(12, PinType::Output);
    addPin(13, PinType::Output);
}
