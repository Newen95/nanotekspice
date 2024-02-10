
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
    addPin(3, PinType::Output);
}
