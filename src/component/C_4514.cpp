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

void nts::C_4514::allUndefined()
{
    for (int i = 4; i <= 20; i++) {
        assignPinValue(i, Undefined, this);
    }
}

int nts::C_4514::getTotalValue(Tristate in_0, Tristate in_1, Tristate in_2, Tristate in_3)
{
    int val_0 = 0;
    int val_1 = 0;
    int val_2 = 0;
    int val_3 = 0;

    if (in_0 == False) {
        val_0 = 0;
    } else if (in_0 == True){
        val_0 = 1;
    } else {
        return 84;
    }

    if (in_1 == False) {
        val_1 = 0;
    } else if (in_1 == True){
        val_1 = 1;
    } else {
        return 84;
    }

    if (in_2 == False) {
        val_2 = 0;
    } else if (in_2 == True){
        val_2 = 1;
    } else {
        return 84;
    }

    if (in_3 == False) {
        val_3 = 0;
    } else if (in_3 == True){
        val_3 = 1;
    } else {
        return 84;
    }

    return ((val_0 * 1) + (val_1 * 2) + (val_2 * 4) + (val_3 * 8));
}

void nts::C_4514::simulateComponent()
{
    Tristate in_0 = this->getPin(2)->getState();
    Tristate in_1 = this->getPin(3)->getState();
    Tristate in_2 = this->getPin(21)->getState();
    Tristate in_3 = this->getPin(22)->getState();
    Tristate inhibit = this->getPin(23)->getState();
    int total_value = 0;

    if (inhibit == 1) {
        for (int i = 4; i <= 20; i++) {
            assignPinValue(i, False, this);
        }
    } else {
        printf("Total value: %d\n", total_value);
        total_value = getTotalValue(in_0, in_1, in_2, in_3);
        if (total_value == 84) {
            allUndefined();
        }
        assignPinValue(total_value + 4, False, this);
    }
}
