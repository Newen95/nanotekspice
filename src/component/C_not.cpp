
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_not.cpp
*/

#include "../../include/component/C_not.hpp"

nts::C_not::C_not(const std::string &name) : AComponent("not", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeOutput);
}
