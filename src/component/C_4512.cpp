/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4512.cpp
*/

#include "../../include/component/C_4512.hpp"

nts::C_4512::C_4512() : AComponent("4512")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeInput);
    addPin(11, PinType::typeInput);
    addPin(12, PinType::typeInput);
    addPin(13, PinType::typeInput);
    addPin(14, PinType::typeOutput);
    addPin(15, PinType::typeInput);
}

nts::Tristate nts::C_4512::getIndex(Tristate in_a, Tristate in_b, Tristate in_c)
{
    std::string str = std::to_string(in_c) + std::to_string(in_b) + std::to_string(in_a);
    int index = std::stoi(str, nullptr, 2);
    index++;
    if (index == 8)
        index++;
    return getPin(index)->getState();
}

void nts::C_4512::compute(std::size_t pin)
{
    getPin(pin)->setLock(true);
    getPin(14)->setLock(true);

    auto &_pin1 = getPin(1);
    if (_pin1->getLock() != true) {
        _pin1->setLock(true);
        for (auto& linkPtr : _pin1->getConnectedTo()) {
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

    auto &_pin3 = getPin(3);
    if (_pin3->getLock() != true) {
        _pin3->setLock(true);
        for (auto& linkPtr : _pin3->getConnectedTo()) {
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

    auto &_pin7 = getPin(7);
    if (_pin7->getLock() != true) {
        _pin7->setLock(true);
        for (auto& linkPtr : _pin7->getConnectedTo()) {
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

    auto &_pin10 = getPin(10);
    if (_pin10->getLock() != true) {
        _pin10->setLock(true);
        for (auto& linkPtr : _pin10->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin11 = getPin(11);
    if (_pin11->getLock() != true) {
        _pin11->setLock(true);
        for (auto& linkPtr : _pin11->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin12 = getPin(12);
    if (_pin12->getLock() != true) {
        _pin12->setLock(true);
        for (auto& linkPtr : _pin12->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin13 = getPin(13);
    if (_pin13->getLock() != true) {
        _pin13->setLock(true);
        for (auto& linkPtr : _pin13->getConnectedTo()) {
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

    Tristate in_a = this->getPin(11)->getState();
    Tristate in_b = this->getPin(12)->getState();
    Tristate in_c = this->getPin(13)->getState();
    Tristate inhibit = this->getPin(10)->getState();
    Tristate enable = this->getPin(15)->getState();

    if (enable == True) {
        assignPinValue(14, Undefined, this);
    } else if (inhibit == False && in_a != Undefined && in_b != Undefined && in_c != Undefined) {
        assignPinValue(14, getIndex(in_a, in_b, in_c), this);
    } else if (inhibit == True)
        assignPinValue(14, False, this);
}
