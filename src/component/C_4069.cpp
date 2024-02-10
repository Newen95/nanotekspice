
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
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
