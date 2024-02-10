
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4040.cpp
*/

#include "../../include/component/C_4040.hpp"

nts::C_4040::C_4040(const std::string &name) : AComponent("4040", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Output);
    addPin(3, PinType::Output);
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
