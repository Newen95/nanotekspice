
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_output.cpp
*/

#include "../../include/component/C_output.hpp"

nts::C_output::C_output() : AComponent("output")
{
    addPin(1, PinType::typeInput);
}

void nts::C_output::simulateComponent()
{}