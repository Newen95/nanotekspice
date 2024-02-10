
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4071.cpp
*/

#include "../../include/component/C_4071.hpp"

nts::C_4071::C_4071(const std::string &name) : AComponent("4071", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
