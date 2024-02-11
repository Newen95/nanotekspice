
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4514.cpp
*/

#include "../../include/component/C_4514.hpp"

nts::C_4514::C_4514() : AComponent("4514")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeOutput);
    addPin(6, PinType::typeOutput);
    addPin(7, PinType::typeOutput);
    addPin(8, PinType::typeOutput);
    addPin(9, PinType::typeOutput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeIgnored);
    addPin(13, PinType::typeOutput);
    addPin(14, PinType::typeOutput);
    addPin(15, PinType::typeOutput);
    addPin(16, PinType::typeOutput);
    addPin(17, PinType::typeOutput);
    addPin(18, PinType::typeOutput);
    addPin(19, PinType::typeOutput);
    addPin(20, PinType::typeOutput);
    addPin(21, PinType::typeInput);
    addPin(22, PinType::typeInput);
    addPin(23, PinType::typeInput);
    addPin(24, PinType::typeIgnored);
}

nts::C_4514::C_4514(const std::string &name) : AComponent("4514", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeOutput);
    addPin(6, PinType::typeOutput);
    addPin(7, PinType::typeOutput);
    addPin(8, PinType::typeOutput);
    addPin(9, PinType::typeOutput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeIgnored);
    addPin(13, PinType::typeOutput);
    addPin(14, PinType::typeOutput);
    addPin(15, PinType::typeOutput);
    addPin(16, PinType::typeOutput);
    addPin(17, PinType::typeOutput);
    addPin(18, PinType::typeOutput);
    addPin(19, PinType::typeOutput);
    addPin(20, PinType::typeOutput);
    addPin(21, PinType::typeInput);
    addPin(22, PinType::typeInput);
    addPin(23, PinType::typeInput);
    addPin(24, PinType::typeIgnored);
}
