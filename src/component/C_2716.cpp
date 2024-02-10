
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_2716.cpp
*/

#include "../../include/component/C_2716.hpp"

nts::C_2716::C_2716(const std::string &name) : AComponent("2716", name)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}
