
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

void nts::C_4008::_adder(int in1, int in2, int out)
{
    Tristate in_1 = this->getPin(in1)->getState();
    Tristate in_2 = this->getPin(in2)->getState();
    Tristate in_c = this->getPin(9)->getState();
    Tristate _out, _sum, _carry;

    const auto &f = (*getPin(out)).getConnectedTo();

    for (const auto &tmp : f) {
        IComponent *component = tmp->component;
        std::size_t piNbr = tmp->pin;

        if (in_1 == True && in_2 == True) {
            component->assignPinValue(piNbr, True, component);
            _out = True;
        } else if (in_1 == True && in_c == True) {
            component->assignPinValue(piNbr, True, component);
            _out = True;
        } else if (in_2 == True && in_c == True) {
            component->assignPinValue(piNbr, True, component);
            _out = True;
        } else if (in_1 == True && in_2 == True && in_c == Undefined) {
            component->assignPinValue(piNbr, True, component);
            _out = True;
        } else if (in_1 == False && in_2 == False && in_c == Undefined) {
            component->assignPinValue(piNbr, True, component);
            _out = True;
        } else if (in_1 == Undefined && in_2 == Undefined && in_c == Undefined) {
            component->assignPinValue(piNbr, Undefined, component);
            _out = Undefined;
        } else if (in_1 == Undefined && in_2 == Undefined) {
            component->assignPinValue(piNbr, Undefined, component);
            _out = Undefined;
        } else if (in_1 == Undefined && in_c == Undefined) {
            component->assignPinValue(piNbr, Undefined, component);
            _out = Undefined;
        } else if (in_2 == Undefined && in_c == Undefined) {
            component->assignPinValue(piNbr, Undefined, component);
            _out = Undefined;
        } else {
            component->assignPinValue(piNbr, False, component);
            _out = False;
        }

        if (in_1 == True && in_2 == True && in_c == True)
            _sum = True;
        else if (in_1 == True && in_2 == False && in_c == False)
            _sum = True;
        else if (in_1 == False && in_2 == True && in_c == False)
            _sum = True;
        else if (in_1 == False && in_2 == False && in_c == True)
            _sum = True;
        else if (in_1 == Undefined || in_2 == Undefined || in_c == Undefined)
            _sum = Undefined;
        else
            _sum = False;

        if (in_1 == True && in_2 == True)
            _carry = True;
        else if (in_1 == True && in_c == True)
            _carry = True;
        else if (in_2 == True && in_c == True)
            _carry = True;
        else if ((in_1 == Undefined && in_2 == Undefined && in_c != False)
                || (in_1 == Undefined && in_c == Undefined && in_2 != False)
                || (in_2 == Undefined && in_c == Undefined && in_1 != False))
            _carry = Undefined;
        else
            _carry = False;
    }

    if (out != 13)
        assignPinValue(9, _carry, this);
    assignPinValue(14, _out, this);
    assignPinValue(out, _sum, this);
}

void nts::C_4008::simulateComponent()
{
    _adder(6, 7, 10);
    _adder(4, 5, 11);
    _adder(2, 3, 12);
    _adder(1, 15, 13);
}