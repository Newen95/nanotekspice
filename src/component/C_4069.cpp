
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

nts::C_4069::C_4069(const std::string &name) : AComponent("4069", name)
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

void nts::C_4069::not_(Circuit &Circuit, int in, int out)
{
    const auto &map = Circuit.getComponentMap();
    Tristate in_1 = (*getPin(in)).getState();

    const auto &pin1_connected = (*getPin(in)).getConnectedTo();
    for (const auto &tmp : pin1_connected) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        in_1 = map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->getState();
        break;
    }

    const auto &f = (*getPin(out)).getConnectedTo();

    for (const auto &tmp : f) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;

        if (in_1 == False)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(True);
        if (in_1 == True)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(False);
        if (in_1 == Undefined)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(Undefined);
    }
}

void nts::C_4069::simulate(Circuit &Circuit)
{
    not_(Circuit, 1, 2);
    not_(Circuit, 3, 4);
    not_(Circuit, 5, 6);
    not_(Circuit, 9, 8);
    not_(Circuit, 11, 10);
    not_(Circuit, 13, 12);
}
