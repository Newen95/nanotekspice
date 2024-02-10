
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4069.cpp
*/

#include "../../include/component/C_4069.hpp"

nts::C_4069::C_4069(const std::string &name) : AComponent("4069", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Output);
    addPin(3, PinType::Input);
    addPin(4, PinType::Output);
    addPin(5, PinType::Input);
    addPin(6, PinType::Output);
    addPin(7, PinType::Output);
    addPin(8, PinType::Input);
    addPin(9, PinType::Output);
    addPin(10, PinType::Input);
    addPin(11, PinType::Output);
    addPin(12, PinType::Input);
}
