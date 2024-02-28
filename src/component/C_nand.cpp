
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_nand.cpp
*/

#include "../../include/component/C_nand.hpp"

nts::C_nand::C_nand() : AComponent("nand")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeOutput);
}

void nts::C_nand::compute(std::size_t pin)
{
    getPin(pin)->setLock(true);
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

    Tristate in_1 = (*getPin(1)).getState();
    Tristate in_2 = (*getPin(2)).getState();

    for (const auto &tmp : (*getPin(1)).getConnectedTo()) {
        IComponent *component = tmp->component;
        std::size_t piNbr = tmp->pin;

        in_1 = component->getPin(piNbr)->getState();
        break;
    }

    for (const auto &tmp : (*getPin(2)).getConnectedTo()) {
        IComponent *component = tmp->component;
        std::size_t piNbr = tmp->pin;

        in_2 = component->getPin(piNbr)->getState();
        break;
    }

    for (const auto &tmp : (*getPin(3)).getConnectedTo()) {
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
