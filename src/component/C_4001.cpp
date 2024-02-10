
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4001.cpp
*/

#include "../../include/component/C_4001.hpp"

nts::C_4001::C_4001(const std::string &name) : AComponent("4001", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
