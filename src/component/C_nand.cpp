
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_nand.cpp
*/

#include "../../include/component/C_nand.hpp"

nts::C_nand::C_nand(const std::string &name) : AComponent("nand", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}