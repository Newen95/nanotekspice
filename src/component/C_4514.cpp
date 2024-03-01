/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4514.cpp
*/

#include "../../include/component/C_4514.hpp"

nts::C_4514::C_4514() : AComponent("4514")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeOutput);
    addPin(6, PinType::typeOutput);
    addPin(7, PinType::typeOutput);
    addPin(8, PinType::typeOutput);
    addPin(9, PinType::typeOutput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeIgnored);
    addPin(13, PinType::typeOutput);
    addPin(14, PinType::typeOutput);
    addPin(15, PinType::typeOutput);
    addPin(16, PinType::typeOutput);
    addPin(17, PinType::typeOutput);
    addPin(18, PinType::typeOutput);
    addPin(19, PinType::typeOutput);
    addPin(20, PinType::typeOutput);
    addPin(21, PinType::typeInput);
    addPin(22, PinType::typeInput);
    addPin(23, PinType::typeInput);
    addPin(24, PinType::typeIgnored);
}

void nts::C_4514::allUndefined()
{
    for (int i = 4; i <= 20; i++) {
        assignPinValue(i, Undefined, this);
    }
}

int nts::C_4514::isUndefined(Tristate in_0, Tristate in_1, Tristate in_2, Tristate in_3)
{
    if (in_0 == Undefined || in_1 == Undefined || in_2 == Undefined || in_3 == Undefined) {
        return 1;
    }
    return 0;
}

int nts::C_4514::getTotalValue(Tristate in_0, Tristate in_1, Tristate in_2, Tristate in_3)
{
    int val_0 = (in_0 == True) ? 1 : 0;
    int val_1 = (in_1 == True) ? 1 : 0;
    int val_2 = (in_2 == True) ? 1 : 0;
    int val_3 = (in_3 == True) ? 1 : 0;

    return val_0 + (val_1 << 1) + (val_2 << 2) + (val_3 << 3);
}

void nts::C_4514::compute(std::size_t pin)
{
    getPin(pin)->setLock(true);
    getPin(11)->setLock(true);
    getPin(9)->setLock(true);
    getPin(10)->setLock(true);
    getPin(8)->setLock(true);
    getPin(7)->setLock(true);
    getPin(6)->setLock(true);
    getPin(5)->setLock(true);
    getPin(4)->setLock(true);
    getPin(18)->setLock(true);
    getPin(17)->setLock(true);
    getPin(20)->setLock(true);
    getPin(19)->setLock(true);
    getPin(14)->setLock(true);
    getPin(13)->setLock(true);
    getPin(16)->setLock(true);
    getPin(15)->setLock(true);

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

    auto &_pin21 = getPin(21);
    if (_pin21->getLock() != true) {
        _pin21->setLock(true);
        for (auto& linkPtr : _pin21->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin22 = getPin(22);
    if (_pin22->getLock() != true) {
        _pin22->setLock(true);
        for (auto& linkPtr : _pin22->getConnectedTo()) {
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

    auto &_pin23 = getPin(23);
    if (_pin23->getLock() != true) {
        _pin23->setLock(true);
        for (auto& linkPtr : _pin23->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }


    Tristate in_0 = this->getPin(2)->getState();
    Tristate in_1 = this->getPin(3)->getState();
    Tristate in_2 = this->getPin(21)->getState();
    Tristate in_3 = this->getPin(22)->getState();
    Tristate inhibit = this->getPin(23)->getState();
    int total_value = 0;

    if (inhibit == 1) {
        for (int i = 4; i <= 20; i++) {
            assignPinValue(i, False, this);
        }
    } else {
        if (isUndefined(in_0, in_1, in_2, in_3) == 1)
            return;
        total_value = getTotalValue(in_0, in_1, in_2, in_3);
        if (total_value == 84) {
            allUndefined();
            return;
        }
        for (int i = 4; i <= 20; i++) {
            if (i == total_value + 4) {
                assignPinValue(total_value + 4, True, this);
            } else {
                assignPinValue(i, False, this);
            }
        }
        assignPinValue(total_value + 4, True, this);
    }
}
