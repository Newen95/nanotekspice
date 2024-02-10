
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4512.cpp
*/

#include "../../include/component/C_4512.hpp"

nts::C_4512::C_4512(const std::string &name) : AComponent("4512", name)
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
    addPin(10, PinType::Input);
    addPin(11, PinType::Input);
    addPin(12, PinType::Input);
    addPin(13, PinType::Input);
    addPin(14, PinType::Output);
}
