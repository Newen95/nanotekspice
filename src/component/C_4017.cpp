
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
    addPin(3, PinType::Output);
}
