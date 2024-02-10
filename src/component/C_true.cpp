
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_true.cpp
*/

#include "../../include/component/C_true.hpp"

nts::C_true::C_true(const std::string &name) : AComponent("true", name)
{
    addPin(1, PinType::Output);
}
