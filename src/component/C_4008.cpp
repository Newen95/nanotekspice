
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4008.cpp
*/

#include "../../include/component/C_4008.hpp"

nts::C_4008::C_4008(const std::string &name) : AComponent("4008", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Input);
    addPin(4, PinType::Input);
    addPin(5, PinType::Input);
    addPin(6, PinType::Input);
    addPin(7, PinType::Input);
    addPin(8, PinType::Input);
    addPin(9, PinType::Input);
    addPin(10, PinType::Output);
    addPin(11, PinType::Output);
    addPin(12, PinType::Output);
    addPin(13, PinType::Output);
    addPin(14, PinType::Output);
}
