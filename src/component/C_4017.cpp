
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4017.cpp
*/

#include "../../include/component/C_4017.hpp"

nts::C_4017::C_4017(const std::string &name) : AComponent("4017", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Input);
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
    addPin(14, PinType::Output);
}
