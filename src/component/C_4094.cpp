
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4094.cpp
*/

#include "../../include/component/C_4094.hpp"

nts::C_4094::C_4094() : AComponent("4094")
{
    addPin(1, PinType::typeTrue);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeClock);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeOutput);
    addPin(6, PinType::typeOutput);
    addPin(7, PinType::typeOutput);
    addPin(8, PinType::typeIgnored);
    addPin(9, PinType::typeOutput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeOutput);
    addPin(14, PinType::typeOutput);
    addPin(15, PinType::typeTrue);
}

static int getPos(int pos)
{
    int _pos;

    if (pos == 0)
        _pos = 4;
    else if (pos == 1)
        _pos = 5;
    else if (pos == 2)
        _pos = 6;
    else if (pos == 3)
        _pos = 7;
    else if (pos == 4)
        _pos = 14;
    else if (pos == 5)
        _pos = 13;
    else if (pos == 6)
        _pos = 12;
    else if (pos == 7)
        _pos = 11;

    return _pos;
}

void nts::C_4094::simulateComponent()
{
    Tristate clock = this->getPin(3)->getState();
    Tristate data = this->getPin(2)->getState();
    Tristate strobe = this->getPin(1)->getState();
    Tristate enable = this->getPin(15)->getState();

    if (clock == True) {
        if (strobe == True && enable == True) {
            for (int i = 7; i >= 0; i--) {
                Tristate bit = static_cast<Tristate>((data >> i) & 0x1);
                this->getPin(getPos(i))->setState(bit);
            }
        }

        Tristate lastBit = this->getPin(11)->getState();

        for (int i = 7; i > 0; --i) {
            this->getPin(getPos(i))->setState(this->getPin(getPos(i - 1))->getState());
        }
        this->getPin(4)->setState(lastBit);

        this->getPin(9)->setState(this->getPin(11)->getState());
        this->getPin(10)->setState(this->getPin(15)->getState());
    }
}

