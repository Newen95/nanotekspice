
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4011.cpp
*/

#include "../../include/component/C_4011.hpp"

nts::C_4011::C_4011(const std::string &name) : AComponent("4011", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
