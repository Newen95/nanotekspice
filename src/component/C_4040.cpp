
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4013.cpp
*/

#include "../../include/component/C_4040.hpp"

nts::C_4040::C_4040() : AComponent("4040")
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
    addPin(10, PinType::typeClock);
    addPin(11, PinType::typeInput);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeOutput);
    addPin(14, PinType::typeOutput);
    addPin(15, PinType::typeOutput);
    addPin(16, PinType::typeIgnored);
}

static int getPos(int pos)
{
    int _pos;

    if (pos == 1)
        _pos = 9;
    else if (pos == 2)
        _pos = 7;
    else if (pos == 3)
        _pos = 6;
    else if (pos == 4)
        _pos = 5;
    else if (pos == 5)
        _pos = 3;
    else if (pos == 6)
        _pos = 2;
    else if (pos == 7)
        _pos = 4;
    else if (pos == 9)
        _pos = 13;
    else if (pos == 12)
        _pos = 12;
    else if (pos == 13)
        _pos = 14;
    else if (pos == 14)
        _pos = 15;
    else if (pos == 15)
        _pos = 1;

    return _pos;
}

void nts::C_4040::simulateComponent()
{
    Tristate reset = this->getPin(11)->getState();
    Tristate clock = this->getPin(10)->getState();
    Tristate toAssign = Undefined;
    bool first = false;
    int index = 0;

    if (reset == True) {
        _nbr = 0;
        for (int i = 1; i <= 15; i++) {
            if (i == 8 || i == 10 || i == 11)
                continue;
            assignPinValue(i, False, this);
        }
    }

    else if (clock == False) {
        _nbr += 1;
        if (_nbr > 4095)
            _nbr = 0;
        std::string binaryString = std::bitset<12>(_nbr).to_string();
        for (int i = 15; i > 0; i--) {
            if (i == 8 || i == 10 || i == 11)
                continue;
            if (binaryString[index] == '0' && first == false) {
                index++;
                continue;
            } if (binaryString[index] == '1') {
                toAssign = True;
                first = true;
            } else
                toAssign = False;
            assignPinValue(getPos(i), toAssign, this);
            index++;
        }
    }
}
