
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_false.cpp
*/

#include "../../include/component/C_false.hpp"

nts::C_false::C_false(const std::string &name) : AComponent("false", name)
{
    addPin(1, PinType::Output);
}
