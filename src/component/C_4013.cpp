
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4013.cpp
*/

#include "../../include/component/C_4013.hpp"

nts::C_4013::C_4013(const std::string &name) : AComponent("4013", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Input);
    addPin(4, PinType::Output);
    addPin(5, PinType::Output);
    addPin(6, PinType::Clock);
    addPin(7, PinType::Input);
    addPin(8, PinType::Input);
    addPin(9, PinType::Input);
    addPin(10, PinType::Output);
    addPin(11, PinType::Output);
}
