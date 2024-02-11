
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4011.cpp
*/

#include "../../include/component/C_4011.hpp"

nts::C_4011::C_4011() : AComponent("4011")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeOutput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeIgnored);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeInput);
    addPin(13, PinType::typeInput);
    addPin(14, PinType::typeIgnored);
}

nts::C_4011::C_4011(const std::string &name) : AComponent("4011", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeOutput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeIgnored);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeInput);
    addPin(13, PinType::typeInput);
    addPin(14, PinType::typeIgnored);
}
