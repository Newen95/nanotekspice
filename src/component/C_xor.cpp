
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_xor.cpp
*/

#include "../../include/component/C_xor.hpp"

nts::C_xor::C_xor(const std::string &name) : AComponent("xor", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
