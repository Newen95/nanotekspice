
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_clock.cpp
*/

#include "../../include/component/C_clock.hpp"

nts::C_clock::C_clock() : AComponent("clock")
{
    addPin(1, PinType::typeOutput);
}

void nts::C_clock::simulateComponent()
{
    Tristate in_1 = (*getPin(1)).getState();

    for (const auto &tmp : (*getPin(1)).getConnectedTo()) {
        IComponent *component = tmp->component;
        std::size_t piNbr = tmp->pin;

        if (in_1 == False) {
            component->assignPinValue(piNbr, False, component);
            (*getPin(1)).setNextState(True);
        } else if (in_1 == True) {
            component->assignPinValue(piNbr, True, component);
            (*getPin(1)).setNextState(False);
        } else {
            component->assignPinValue(piNbr, Undefined, component);
            (*getPin(1)).setNextState(Undefined);
        }

        in_1 = component->getPin(piNbr)->getState();
        break;
    }
}
