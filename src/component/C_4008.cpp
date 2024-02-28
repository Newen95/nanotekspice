
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

void nts::C_4008::compute(std::size_t pin)
{
    getPin(pin)->setLock(true);

    getPin(10)->setLock(true);
    getPin(11)->setLock(true);
    getPin(12)->setLock(true);
    getPin(13)->setLock(true);
    getPin(14)->setLock(true);

    auto &_pin9 = getPin(9);
    if (_pin9->getLock() != true) {
        _pin9->setLock(true);
        for (auto& linkPtr : _pin9->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin7 = getPin(7);
    if (_pin7->getLock() != true) {
        _pin7->setLock(true);
        for (auto& linkPtr : _pin7->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin6 = getPin(6);
    if (_pin6->getLock() != true) {
        _pin6->setLock(true);
        for (auto& linkPtr : _pin6->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin5 = getPin(5);
    if (_pin5->getLock() != true) {
        _pin5->setLock(true);
        for (auto& linkPtr : _pin5->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin4 = getPin(4);
    if (_pin4->getLock() != true) {
        _pin4->setLock(true);
        for (auto& linkPtr : _pin4->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin3 = getPin(3);
    if (_pin3->getLock() != true) {
        _pin3->setLock(true);
        for (auto& linkPtr : _pin3->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin2 = getPin(2);
    if (_pin2->getLock() != true) {
        _pin2->setLock(true);
        for (auto& linkPtr : _pin2->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin1 = getPin(1);
    if (_pin1->getLock() != true) {
        _pin1->setLock(true);
        for (auto& linkPtr : _pin1->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin15 = getPin(15);
    if (_pin15->getLock() != true) {
        _pin15->setLock(true);
        for (auto& linkPtr : _pin15->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    Tristate in_c = this->getPin(9)->getState();
    Tristate _1, _2, _3, _4;

    _1 = _adder(6, 7, 10, in_c);
    _2 = _adder(4, 5, 11, _1);
    _3 = _adder(2, 3, 12, _2);
    _4 = _adder(15, 1, 13, _3);

    assignPinValue(14, _4, this);
}