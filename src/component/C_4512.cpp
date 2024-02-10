
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4512.cpp
*/

#include "../../include/component/C_4512.hpp"

nts::C_4512::C_4512(const std::string &name) : AComponent("4512", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
