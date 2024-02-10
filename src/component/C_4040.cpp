
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4040.cpp
*/

#include "../../include/component/C_4040.hpp"

nts::C_4040::C_4040(const std::string &name) : AComponent("4040", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
