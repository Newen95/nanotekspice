
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4801.cpp
*/

#include "../../include/component/C_4801.hpp"

nts::C_4801::C_4801() : AComponent("4801")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeInOut);
    addPin(10, PinType::typeInOut);
    addPin(11, PinType::typeInOut);
    addPin(12, PinType::typeIgnored);
    addPin(13, PinType::typeInOut);
    addPin(14, PinType::typeInOut);
    addPin(15, PinType::typeInOut);
    addPin(16, PinType::typeInOut);
    addPin(17, PinType::typeInOut);
    addPin(18, PinType::typeInput);
    addPin(19, PinType::typeIgnored);
    addPin(20, PinType::typeInput);
    addPin(21, PinType::typeInput);
    addPin(22, PinType::typeInput);
    addPin(23, PinType::typeInput);
    addPin(24, PinType::typeIgnored);
}

nts::C_4801::C_4801(const std::string &name) : AComponent("4801", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeInOut);
    addPin(10, PinType::typeInOut);
    addPin(11, PinType::typeInOut);
    addPin(12, PinType::typeIgnored);
    addPin(13, PinType::typeInOut);
    addPin(14, PinType::typeInOut);
    addPin(15, PinType::typeInOut);
    addPin(16, PinType::typeInOut);
    addPin(17, PinType::typeInOut);
    addPin(18, PinType::typeInput);
    addPin(19, PinType::typeIgnored);
    addPin(20, PinType::typeInput);
    addPin(21, PinType::typeInput);
    addPin(22, PinType::typeInput);
    addPin(23, PinType::typeInput);
    addPin(24, PinType::typeIgnored);
}
