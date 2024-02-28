
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4011.cpp
*/

#include "../../include/component/C_4011.hpp"

nts::C_4011::C_4011() : AComponent("4011")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeOutput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeIgnored);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeInput);
    addPin(13, PinType::typeInput);
    addPin(14, PinType::typeIgnored);
}

void nts::C_4011::_nand(int in1, int in2, int out)
{
    Tristate in_1 = (*getPin(in1)).getState();
    Tristate in_2 = (*getPin(in2)).getState();

    for (const auto &tmp : (*getPin(in1)).getConnectedTo()) {
        IComponent *component = tmp->component;
        std::size_t piNbr = tmp->pin;

        in_1 = component->getPin(piNbr)->getState();
        break;
    }

    for (const auto &tmp : (*getPin(in2)).getConnectedTo()) {
        IComponent *component = tmp->component;
        std::size_t piNbr = tmp->pin;

        in_2 = component->getPin(piNbr)->getState();
        break;
    }

    for (const auto &tmp : (*getPin(out)).getConnectedTo()) {
        IComponent *component = tmp->component;
        std::size_t piNbr = tmp->pin;

        if (in_1 == False && in_2 == False)
            component->assignPinValue(piNbr, True, component);
        if (in_1 == False && in_2 == True)
            component->assignPinValue(piNbr, True, component);
        if (in_1 == False && in_2 == Undefined)
            component->assignPinValue(piNbr, True, component);
        if (in_1 == True && in_2 == False)
            component->assignPinValue(piNbr, True, component);
        if (in_1 == True && in_2 == True)
            component->assignPinValue(piNbr, False, component);
        if (in_1 == True && in_2 == Undefined)
            component->assignPinValue(piNbr, Undefined, component);
        if (in_1 == Undefined && in_2 == False)
            component->assignPinValue(piNbr, True, component);
        if (in_1 == Undefined && in_2 == True)
            component->assignPinValue(piNbr, Undefined, component);
        if (in_1 == Undefined && in_2 == Undefined)
            component->assignPinValue(piNbr, Undefined, component);
    }
}

void nts::C_4011::compute(std::size_t pin)
{
    if (pin == 3) {
        getPin(3)->setLock(true);
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
        _nand(1, 2, 3);
    }

    if (pin == 4) {
        getPin(4)->setLock(true);
        auto &_pin1 = getPin(5);
        if (_pin1->getLock() != true) {
            _pin1->setLock(true);
            for (auto& linkPtr : _pin1->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
        }
        auto &_pin2 = getPin(6);
        if (_pin2->getLock() != true) {
            _pin2->setLock(true);
            for (auto& linkPtr : _pin2->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
        }
        _nand(5, 6, 4);
    }

    if (pin == 10) {
        getPin(10)->setLock(true);
        auto &_pin1 = getPin(8);
        if (_pin1->getLock() != true) {
            _pin1->setLock(true);
            for (auto& linkPtr : _pin1->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
        }
        auto &_pin2 = getPin(9);
        if (_pin2->getLock() != true) {
            _pin2->setLock(true);
            for (auto& linkPtr : _pin2->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
        }
        _nand(8, 9, 10);
    }

    if (pin == 11) {
        getPin(11)->setLock(true);
        auto &_pin1 = getPin(12);
        if (_pin1->getLock() != true) {
            _pin1->setLock(true);
            for (auto& linkPtr : _pin1->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
        }
        auto &_pin2 = getPin(13);
        if (_pin2->getLock() != true) {
            _pin2->setLock(true);
            for (auto& linkPtr : _pin2->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
        }
        _nand(12, 13, 11);
    }
}
