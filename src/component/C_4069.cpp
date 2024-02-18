
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

void nts::C_4069::simulateComponent()
{
    _not(1, 2);
    _not(3, 4);
    _not(5, 6);
    _not(9, 8);
    _not(11, 10);
    _not(13, 12);
}