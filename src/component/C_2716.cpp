
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
    addPin(3, PinType::Input);
    addPin(4, PinType::Input);
    addPin(5, PinType::Input);
    addPin(6, PinType::Input);
    addPin(7, PinType::Input);
    addPin(8, PinType::Input);
    addPin(9, PinType::Input);
    addPin(10, PinType::Input);
    addPin(11, PinType::Input);
    addPin(12, PinType::Input);
    addPin(13, PinType::Input);
    addPin(14, PinType::Output);
    addPin(15, PinType::Output);
    addPin(16, PinType::Output);
    addPin(17, PinType::Output);
    addPin(18, PinType::Output);
    addPin(19, PinType::Output);
    addPin(20, PinType::Output);
    addPin(21, PinType::Output);
}
