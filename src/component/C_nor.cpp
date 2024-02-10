
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_nor.cpp
*/

#include "../../include/component/C_nor.hpp"

nts::C_nor::C_nor(const std::string &name) : AComponent("nor", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}