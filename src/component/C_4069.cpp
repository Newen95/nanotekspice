
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4069.cpp
*/

#include "../../include/component/C_4069.hpp"

nts::C_4069::C_4069() : AComponent("4069")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeOutput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeOutput);
    addPin(7, PinType::typeIgnored);
    addPin(8, PinType::typeOutput);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeInput);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeInput);
    addPin(14, PinType::typeIgnored);
}

void nts::C_4069::_not(int in, int out)
{
    Tristate _in = (*getPin(in)).getState();

    for (const auto &tmp : (*getPin(in)).getConnectedTo()) {
        IComponent *component = tmp->component;
        std::size_t piNbr = tmp->pin;

        _in = component->getPin(piNbr)->getState();
        break;
    }

    for (const auto &tmp : (*getPin(out)).getConnectedTo()) {
        IComponent *component = tmp->component;
        std::size_t piNbr = tmp->pin;

        if (_in == False)
            component->assignPinValue(piNbr, True, component);
        else if (_in == True)
            component->assignPinValue(piNbr, False, component);
        else
            component->assignPinValue(piNbr, Undefined, component);

    }
}

void nts::C_4069::compute(std::size_t pin)
{
    if (pin == 2) {
        getPin(2)->setLock(true);
        auto &_pin = getPin(1);
        if (_pin->getLock() != true) {
            _pin->setLock(true);
            for (auto& linkPtr : _pin->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
        }
        _not(1, 2);
    }

    if (pin == 4) {
        getPin(4)->setLock(true);
        auto &_pin = getPin(3);
        if (_pin->getLock() != true) {
            _pin->setLock(true);
            for (auto& linkPtr : _pin->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
            _not(3, 4);
        }
    }

    if (pin == 6) {
        getPin(6)->setLock(true);
        auto &_pin = getPin(5);
        if (_pin->getLock() != true) {
            _pin->setLock(true);
            for (auto& linkPtr : _pin->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
            _not(5, 6);
        }
    }

    if (pin == 8) {
        getPin(8)->setLock(true);
        auto &_pin = getPin(9);
        if (_pin->getLock() != true) {
            _pin->setLock(true);
            for (auto& linkPtr : _pin->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
            _not(9, 8);
        }
    }

    if (pin == 10) {
        getPin(10)->setLock(true);
        auto &_pin = getPin(11);
        if (_pin->getLock() != true) {
            _pin->setLock(true);
            for (auto& linkPtr : _pin->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
            _not(11, 10);
        }
    }

    if (pin == 12) {
        getPin(12)->setLock(true);
        auto &_pin = getPin(13);
        if (_pin->getLock() != true) {
            _pin->setLock(true);
            for (auto& linkPtr : _pin->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
            _not(13, 12);
        }
    }
}