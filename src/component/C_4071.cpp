
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4071.cpp
*/

#include "../../include/component/C_4071.hpp"

nts::C_4071::C_4071(const std::string &name) : AComponent("4071", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
    addPin(4, PinType::Output);
    addPin(5, PinType::Input);
    addPin(6, PinType::Input);
    addPin(7, PinType::Input);
    addPin(8, PinType::Input);
    addPin(9, PinType::Output);
    addPin(10, PinType::Output);
    addPin(11, PinType::Input);
    addPin(12, PinType::Input);
}
