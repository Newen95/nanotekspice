
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4017.cpp
*/

#include "../../include/component/C_4017.hpp"

nts::C_4017::C_4017() : AComponent("4017")
{
    addPin(1, PinType::typeOutput);
    addPin(2, PinType::typeOutput);
    addPin(3, PinType::typeOutput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeOutput);
    addPin(6, PinType::typeOutput);
    addPin(7, PinType::typeOutput);
    addPin(8, PinType::typeIgnored);
    addPin(9, PinType::typeOutput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeInput);
    addPin(14, PinType::typeInput);
    addPin(15, PinType::typeInput);
}

nts::C_4017::C_4017(const std::string &name) : AComponent("4017", name)
{
    addPin(1, PinType::typeOutput);
    addPin(2, PinType::typeOutput);
    addPin(3, PinType::typeOutput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeOutput);
    addPin(6, PinType::typeOutput);
    addPin(7, PinType::typeOutput);
    addPin(8, PinType::typeIgnored);
    addPin(9, PinType::typeOutput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeInput);
    addPin(14, PinType::typeInput);
    addPin(15, PinType::typeInput);
}

void nts::C_4017::assignValue(Circuit &Circuit, int out, Tristate sate)
{
    const auto &map = Circuit.getComponentMap();
    const auto &f = (*getPin(out)).getConnectedTo();

    for (const auto &tmp : f) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(sate);
    }
}

nts::Tristate nts::C_4017::getRealPinStatus(int nbr, Circuit &Circuit)
{
    const auto &pin_connected = (*getPin(nbr)).getConnectedTo();
    for (const auto &tmp : pin_connected) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        return Circuit.getComponentMap().find(component_name)->second.get()->getPins().find(component_pin)->second.get()->getState();
    }
    return Undefined;
}

static int getNextIndex(int index)
{
    if (index == 1)
        index = 5;
    else if (index == 2)
        index = 4;
    else if (index == 3)
        index = 2;
    else if (index == 4)
        index = 7;
    else if (index == 5)
        index = 6;
    else if (index == 6)
        index = 9;
    else if (index == 7)
        index = 10;
    else if (index == 9)
        index = 11;
    else if (index == 10)
        index = 1;
    else if (index == 11 || index == 12)
        index = 3;

    return index;
}

void nts::C_4017::simulate(Circuit &Circuit)
{
    Tristate in_0_state = getRealPinStatus(14, Circuit);
    Tristate in_1_state = getRealPinStatus(13, Circuit);
    Tristate in_r_state = getRealPinStatus(15, Circuit);
    int index = 1;

    if (in_r_state == True) {
        for (int i = 1; i <= 11; ++i) {
            if (i == 8)
                continue;
            assignValue(Circuit, i, False);
        }
        assignValue(Circuit, 3, True);
    }

    else if ((in_0_state == True || in_1_state == True) && in_r_state != Undefined) {
        for (; index <= 11; index++)
            if (getRealPinStatus(index, Circuit) == True)
        index = getNextIndex(index);
        for (int i = 1; i <= 11; i++) {
            if (i == 8)
                continue;
            if (i == index)
                assignValue(Circuit, i, True);
            else
                assignValue(Circuit, i, False);
        }
    }
}