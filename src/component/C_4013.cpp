
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


void nts::C_4013::compute(std::size_t pin)
{
    getPin(pin)->setLock(true);

    getPin(12)->setLock(true);
    getPin(13)->setLock(true);
    getPin(1)->setLock(true);
    getPin(2)->setLock(true);

    auto &_pin5 = getPin(5);
    if (_pin5->getLock() != true) {
        _pin5->setLock(true);
        for (auto& linkPtr : _pin5->getConnectedTo()) {
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

    auto &_pin4 = getPin(4);
    if (_pin4->getLock() != true) {
        _pin4->setLock(true);
        for (auto& linkPtr : _pin4->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin9 = getPin(9);
    if (_pin9->getLock() != true) {
        _pin9->setLock(true);
        for (auto& linkPtr : _pin9->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin8 = getPin(8);
    if (_pin8->getLock() != true) {
        _pin8->setLock(true);
        for (auto& linkPtr : _pin8->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin10 = getPin(10);
    if (_pin10->getLock() != true) {
        _pin10->setLock(true);
        for (auto& linkPtr : _pin10->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    Tristate clk1 = this->getPin(3)->getState();
    Tristate clk2 = this->getPin(11)->getState();

    Tristate data1 = this->getPin(5)->getState();
    Tristate data2 = this->getPin(9)->getState();

    Tristate reset1 = this->getPin(4)->getState();
    Tristate reset2 = this->getPin(10)->getState();

    Tristate set1 = this->getPin(6)->getState();
    Tristate set2 = this->getPin(8)->getState();

    Tristate _qstate1, _qstate2;

    if (clk1 == True) {
        _state1 = data1;
    } if (set1 == True) {
        _state1 = True;
    } else if (reset1 == True) {
        _state1 = False;
    } else if (data1 == Undefined)
        _state1 = Undefined;

    if (reset1 == True && set1 == True)
        _qstate1 = True;
    else if (_state1 == True && reset1 != Undefined)
        _qstate1 = False;
    else if (_state1 == False && set1 != Undefined)
        _qstate1 = True;
    else
        _qstate1 = Undefined;

    assignPinValue(1, _state1, this);
    assignPinValue(2, _qstate1, this);

    if (clk2 == True) {
        _state2 = data2;
    } if (set2 == True) {
        _state2 = True;
    } else if (reset2 == True) {
        _state2 = False;
    } else if (data2 == Undefined)
        _state2 = Undefined;

    if (reset2 == True && set2 == True)
        _qstate2 = True;
    else if (_state2 == True && reset2 != Undefined)
        _qstate2 = False;
    else if (_state2 == False && set2 != Undefined)
        _qstate2 = True;
    else
        _qstate2 = Undefined;

    assignPinValue(13, _state2, this);
    assignPinValue(12, _qstate2, this);
}
