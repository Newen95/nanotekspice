
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4008.cpp
*/

#include "../../include/component/C_4008.hpp"

nts::C_4008::C_4008() : AComponent("4008")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeIgnored);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeOutput);
    addPin(14, PinType::typeOutput);
    addPin(15, PinType::typeInput);
    addPin(16, PinType::typeIgnored);
}

nts::Tristate nts::C_4008::_adder(int in1, int in2, int out, Tristate in_c)
{
    Tristate in_1 = this->getPin(in1)->getState();
    Tristate in_2 = this->getPin(in2)->getState();
    Tristate _sum, _carry;

    if (in_1 && in_2 && in_c) {
        _sum = True;
        _carry = True;
    } else if ((in_1 ^ in_2 ^ in_c) == True) {
        _sum = True;
        _carry = False;
    } else if (!in_1 && !in_2 && !in_c) {
        _sum = False;
        _carry = False;
    } else {
        _sum = False;
        _carry = True;
    }

    assignPinValue(out, _sum, this);
    return _carry;
}

void nts::C_4008::simulateComponent()
{
    Tristate in_c = this->getPin(9)->getState();
    Tristate _1, _2, _3, _4;

    _1 = _adder(6, 7, 10, in_c);
    _2 = _adder(4, 5, 11, _1);
    _3 = _adder(2, 3, 12, _2);
    _4 = _adder(15, 1, 13, _3);

    assignPinValue(14, _4, this);
}