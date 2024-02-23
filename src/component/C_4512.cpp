/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4512.cpp
*/

#include "../../include/component/C_4512.hpp"

nts::C_4512::C_4512() : AComponent("4512")
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
    addPin(15, PinType::typeInput);
}

void nts::C_4512::simulateComponent()
{
    Tristate inhibit = this->getPin(10)->getState();
    Tristate enable = this->getPin(15)->getState();

    if (enable == 1) {
        assignPinValue(14, Undefined, this);
    } else {
        if (inhibit == True) {
            assignPinValue(14, False, this);
        } else {
            assignPinValue(14, True, this);
        }
    }
}
