
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4013.cpp
*/

#include "../../include/component/C_4013.hpp"

nts::C_4013::C_4013() : AComponent("4013")
{
    addPin(1, PinType::typeOutput);
    addPin(2, PinType::typeOutput);
    addPin(3, PinType::typeClock);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeIgnored);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeInput);
    addPin(11, PinType::typeClock);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeOutput);
}


void nts::C_4013::simulateComponent()
{
    Tristate clk1 = this->getPin(3)->getState();
    Tristate clk2 = this->getPin(11)->getState();

    Tristate data1 = this->getPin(5)->getState();
    Tristate data2 = this->getPin(9)->getState();

    Tristate reset1 = this->getPin(4)->getState();
    Tristate reset2 = this->getPin(10)->getState();

    Tristate set1 = this->getPin(6)->getState();
    Tristate set2 = this->getPin(8)->getState();

    if (clk1 == True) {
        if (reset1 == True)
            _state1 = False;
        else if (set1 == True)
            _state1 = True;
        else
            _state1 = data1;
    }
    assignPinValue(1, _state1, this);
    assignPinValue(2, _state1 == True ? False : (_state1 == Undefined ? Undefined : True), this);

    if (clk2 == True) {
        if (reset2 == True)
            _state2 = False;
        else if (set2 == True)
            _state2 = True;
        else
            _state2 = data2;
    }
    assignPinValue(13, _state2, this);
    assignPinValue(12, _state1 == True ? False : (_state2 == Undefined ? Undefined : True), this);
}
