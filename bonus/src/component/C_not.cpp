
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

void nts::C_not::simulateComponent()
{
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
