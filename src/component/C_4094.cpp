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

void nts::C_4094::compute(std::size_t pin)
{
    getPin(pin)->setLock(true);
    getPin(4)->setLock(true);
    getPin(5)->setLock(true);
    getPin(6)->setLock(true);
    getPin(7)->setLock(true);
    getPin(11)->setLock(true);
    getPin(12)->setLock(true);
    getPin(13)->setLock(true);
    getPin(14)->setLock(true);
    getPin(9)->setLock(true);
    getPin(10)->setLock(true);

    auto &_pin2 = getPin(2);
        if (_pin2->getLock() != true) {
            _pin2->setLock(true);
            for (auto& linkPtr : _pin2->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
        }

    Tristate clock = this->getPin(3)->getState();
    Tristate data = this->getPin(2)->getState();
    Tristate strobe = this->getPin(1)->getState();
    Tristate enable = this->getPin(15)->getState();
    Tristate toAssign;
    int len;

    if (clock == True) {
        if (enable == False) {
            for (int i = 0; i < 8; i++)
                assignPinValue(getPos(i), Undefined, this);
            assignPinValue(9, Undefined, this);
        }

        if (enable == True && strobe == True && data != Undefined) {

            if (data == False)
                _data = '0' + _data;
            else
                _data = '1' + _data;

            len = _data.length();

            if (len > 6) {
                toAssign = _data[6] == '0' ? False : True;
                assignPinValue(9, toAssign, this);
                if (len > 8) {
                    _data.pop_back();
                    len--;
                }
            }

            for (int i = 0; i < len; i++) {
                if (_data[i] == '0')
                    toAssign = False;
                else
                    toAssign = True;
                assignPinValue(getPos(i), toAssign, this);
            }
        }
    }


    else {
        if (enable == False) {
            for (int i = 0; i < 8; i++)
                assignPinValue(getPos(i), Undefined, this);
            assignPinValue(10, Undefined, this);
        } if (enable == True && strobe == True && data != Undefined) {
            len = _data.length();
            if (len > 6) {
                toAssign = _data[6] == '0' ? False : True;
                assignPinValue(10, toAssign, this);
            }
        }
    }
}

