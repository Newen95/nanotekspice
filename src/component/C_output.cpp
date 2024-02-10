
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_output.cpp
*/

#include "../../include/component/C_output.hpp"

nts::C_output::C_output(const std::string &name) : AComponent("output", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
