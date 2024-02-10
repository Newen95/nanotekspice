
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_or.cpp
*/

#include "../../include/component/C_or.hpp"

nts::C_or::C_or(const std::string &name) : AComponent("or", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}