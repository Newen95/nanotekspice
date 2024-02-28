
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_not.cpp
*/

#include "../../include/component/C_not.hpp"

nts::C_not::C_not() : AComponent("not")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeOutput);
}

void nts::C_not::compute(std::size_t pin)
{
    getPin(pin)->setLock(true);
    auto &_pin = getPin(1);
    if (_pin->getLock() != true) {
        _pin->setLock(true);
        for (auto& linkPtr : _pin->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    Tristate in = (*getPin(1)).getState();

    for (const auto &tmp : (*getPin(1)).getConnectedTo()) {
        IComponent *component = tmp->component;
        std::size_t piNbr = tmp->pin;

        in = component->getPin(piNbr)->getState();
        break;
    }

    for (const auto &tmp : (*getPin(2)).getConnectedTo()) {
        IComponent *component = tmp->component;
        std::size_t piNbr = tmp->pin;

        if (in == False)
            component->assignPinValue(piNbr, True, component);
        else if (in == True)
            component->assignPinValue(piNbr, False, component);
        else
            component->assignPinValue(piNbr, Undefined, component);

    }
}
