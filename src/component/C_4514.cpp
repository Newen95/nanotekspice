
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4514.cpp
*/

#include "../../include/component/C_4514.hpp"

nts::C_4514::C_4514(const std::string &name) : AComponent("4514", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
