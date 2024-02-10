
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4801.cpp
*/

#include "../../include/component/C_4801.hpp"

nts::C_4801::C_4801(const std::string &name) : AComponent("4801", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
