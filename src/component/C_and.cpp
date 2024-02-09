
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_and.cpp
*/

#include "../../include/component/C_and.hpp"


nts::C_and::C_and(const std::string &name) : AComponent("and", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
