
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
    addPin(3, PinType::Input);
    addPin(4, PinType::Input);
    addPin(5, PinType::Input);
    addPin(6, PinType::Input);
    addPin(7, PinType::Output);
    addPin(8, PinType::Output);
    addPin(9, PinType::Output);
    addPin(10, PinType::Output);
    addPin(11, PinType::Output);
    addPin(12, PinType::Output);
    addPin(13, PinType::Output);
    addPin(14, PinType::Output);
    addPin(15, PinType::Output);
    addPin(16, PinType::Output);
    addPin(17, PinType::Output);
    addPin(18, PinType::Output);
    addPin(19, PinType::Output);
    addPin(20, PinType::Output);
    addPin(21, PinType::Output);
    addPin(22, PinType::Output);
}
