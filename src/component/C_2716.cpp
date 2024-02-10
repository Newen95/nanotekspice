
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_2716.cpp
*/

#include "../../include/component/C_2716.hpp"

nts::C_2716::C_2716(const std::string &name) : AComponent("2716", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeInput);
    addPin(11, PinType::typeInput);
    addPin(12, PinType::typeInput);
    addPin(13, PinType::typeInput);
    addPin(14, PinType::typeOutput);
    addPin(15, PinType::typeOutput);
    addPin(16, PinType::typeOutput);
    addPin(17, PinType::typeOutput);
    addPin(18, PinType::typeOutput);
    addPin(19, PinType::typeOutput);
    addPin(20, PinType::typeOutput);
    addPin(21, PinType::typeOutput);
}
