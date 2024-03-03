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

int nts::C_4514::getIndex(Tristate in_0, Tristate in_1, Tristate in_2, Tristate in_3)
{
    std::string str = std::to_string(in_3) + std::to_string(in_2) + std::to_string(in_1) + std::to_string(in_0);
    int index = std::stoi(str, nullptr, 2);

    if (index == 0)
        return 11;
    if (index == 1)
        return 9;
    if (index == 2)
        return 10;
    if (index == 3)
        return 8;
    if (index == 4)
        return 7;
    if (index == 5)
        return 6;
    if (index == 6)
        return 5;
    if (index == 7)
        return 4;
    if (index == 8)
        return 18;
    if (index == 9)
        return 17;
    if (index == 10)
        return 20;
    if (index == 11)
        return 19;
    if (index == 12)
        return 14;
    if (index == 13)
        return 13;
    if (index == 14)
        return 16;
    if (index == 15)
        return 15;
    else
        return 11;
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
    Tristate strobe = this->getPin(1)->getState();
    int index = 0;

    if (strobe == 0) {
        if (inhibit == 1) {
            for (int i = 4; i <= 20; i++)
                assignPinValue(i, False, this);
        } else if (in_0 != Undefined && in_1 != Undefined && in_2 != Undefined && in_3 != Undefined) {
            index = getIndex(in_0, in_1, in_2, in_3);

            for (int i = 4; i <= 20; i++) {
                if (i == 12)
                    continue;
                if (i == index)
                    assignPinValue(index, True, this);
                else
                    assignPinValue(i, False, this);
            }
        } else {
            for (int i = 4; i <= 20; i++)
                assignPinValue(i, Undefined, this);
        }
    }
}
