
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4017.cpp
*/

#include "../../include/component/C_4017.hpp"

nts::C_4017::C_4017() : AComponent("4017")
{
    addPin(1, PinType::typeOutput);
    addPin(2, PinType::typeOutput);
    addPin(3, PinType::typeOutput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeOutput);
    addPin(6, PinType::typeOutput);
    addPin(7, PinType::typeOutput);
    addPin(8, PinType::typeIgnored);
    addPin(9, PinType::typeOutput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeInput);
    addPin(14, PinType::typeInput);
    addPin(15, PinType::typeInput);
}

void nts::C_4017::getNextIndex(int index)
{
    if (index == 1)
        index = 5;
    else if (index == 2)
        index = 4;
    else if (index == 3)
        index = 2;
    else if (index == 4)
        index = 7;
    else if (index == 5)
        index = 6;
    else if (index == 6)
        index = 9;
    else if (index == 7)
        index = 10;
    else if (index == 9)
        index = 11;
    else if (index == 10)
        index = 1;
    else if (index == 11 || index == -1)
        index = 3;

    _index = index;
}

void nts::C_4017::compute(std::size_t pin)
{
    getPin(pin)->setLock(true);

    Tristate in_0_state = this->getPin(14)->getState();
    Tristate in_1_state = this->getPin(13)->getState();
    Tristate in_r_state = this->getPin(15)->getState();

    if (in_r_state == True) {
        for (int i = 1; i <= 12; i++) {
            if (i == 8)
                continue;
            assignPinValue(i, False, this);
        }
        assignPinValue(3, True, this);
        assignPinValue(12, True, this);
    }

    else if ((in_0_state == True || in_1_state == False) && in_r_state != Undefined) {
        assignPinValue(12, True, this);
        getNextIndex(_index);

        if (_index == 1 || _index == 5 || _index == 6 || _index == 9 || _index == 11)
            assignPinValue(12, False, this);

        for (int i = 1; i <= 11; i++) {
            if (i == 8)
                continue;
            if (i == _index)
                assignPinValue(i, True, this);
            else
                assignPinValue(i, False, this);
        }
    }
}