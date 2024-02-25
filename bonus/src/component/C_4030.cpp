
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4030.cpp
*/

#include "../../include/component/C_4030.hpp"

nts::C_4030::C_4030() : AComponent("4030")
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

void nts::C_4030::_xor(int in1, int in2, int out)
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
            component->assignPinValue(piNbr, False, component);
        if (in_1 == False && in_2 == True)
            component->assignPinValue(piNbr, True, component);
        if (in_1 == False && in_2 == Undefined)
            component->assignPinValue(piNbr, Undefined, component);
        if (in_1 == True && in_2 == False)
            component->assignPinValue(piNbr, True, component);
        if (in_1 == True && in_2 == True)
            component->assignPinValue(piNbr, False, component);
        if (in_1 == True && in_2 == Undefined)
            component->assignPinValue(piNbr, Undefined, component);
        if (in_1 == Undefined && in_2 == False)
            component->assignPinValue(piNbr, Undefined, component);
        if (in_1 == Undefined && in_2 == True)
            component->assignPinValue(piNbr, Undefined, component);
        if (in_1 == Undefined && in_2 == Undefined)
            component->assignPinValue(piNbr, Undefined, component);
    }
}

void nts::C_4030::simulateComponent()
{
    _xor(1, 2, 3);
    _xor(5, 6, 4);
    _xor(8, 9, 10);
    _xor(12, 13, 11);
}