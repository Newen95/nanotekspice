
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_2716.cpp
*/

#include "../../include/component/C_2716.hpp"

nts::C_2716::C_2716() : AComponent("2716")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeOutput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeIgnored);
    addPin(13, PinType::typeOutput);
    addPin(14, PinType::typeOutput);
    addPin(15, PinType::typeOutput);
    addPin(16, PinType::typeOutput);
    addPin(17, PinType::typeOutput);
    addPin(18, PinType::typeInput);
    addPin(19, PinType::typeIgnored);
    addPin(20, PinType::typeInput);
    addPin(21, PinType::typeIgnored);
    addPin(22, PinType::typeInput);
    addPin(23, PinType::typeInput);
    addPin(24, PinType::typeIgnored);
}

void nts::C_2716::simulateComponent()
{
    Tristate enable = this->getPin(18)->getState();
    Tristate read = this->getPin(20)->getState();

    if (enable == True && read == True) {
        for (int i = 9; i <= 17 ; i++) {
            assignPinValue(i, True, this);
        }
    } else {
        for (int i = 9; i <= 17 ; i++) {
            assignPinValue(i, Undefined, this);
        }
    }

}
