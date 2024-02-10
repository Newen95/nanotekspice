
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4081.cpp
*/

#include "../../include/component/C_4081.hpp"

nts::C_4081::C_4081(const std::string &name) : AComponent("4081", name)
{
    addPin(1, PinType::Other);

    addPin(1, PinType::Input);
    addPin(1, PinType::Input);
    addPin(1, PinType::Output);
    addPin(1, PinType::Output);
    addPin(1, PinType::Input);
    addPin(1, PinType::Input);
    addPin(1, PinType::Input);
    addPin(1, PinType::Input);
    addPin(1, PinType::Output);
    addPin(1, PinType::Output);
    addPin(1, PinType::Input);
    addPin(1, PinType::Input);
}
