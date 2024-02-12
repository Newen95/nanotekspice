
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_nor.cpp
*/

#include "../../include/component/C_nor.hpp"

nts::C_nor::C_nor() : AComponent("nor")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeOutput);
}

nts::C_nor::C_nor(const std::string &name) : AComponent("nor", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeOutput);
}

void nts::C_nor::simulate(Circuit &Circuit)
{
    const auto &map = Circuit.getComponentMap();
    Tristate in_1 = (*getPin(1)).getState();
    Tristate in_2 = (*getPin(2)).getState();

    const auto &pin1_connected = (*getPin(1)).getConnectedTo();
    for (const auto &tmp : pin1_connected) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        in_1 = map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->getState();
        break;
    }

    const auto &pin2_connected = (*getPin(2)).getConnectedTo();
    for (const auto &tmp : pin2_connected) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        in_2 = map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->getState();
        break;
    }

    const auto &f = (*getPin(3)).getConnectedTo();

    for (const auto &tmp : f) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;

        if (in_1 == False && in_2 == False)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(True);
        if (in_1 == False && in_2 == True)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(False);
        if (in_1 == False && in_2 == Undefined)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(Undefined);
        if (in_1 == True && in_2 == False)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(False);
        if (in_1 == True && in_2 == True)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(False);
        if (in_1 == True && in_2 == Undefined)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(False);
        if (in_1 == Undefined && in_2 == False)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(Undefined);
        if (in_1 == Undefined && in_2 == True)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(False);
        if (in_1 == Undefined && in_2 == Undefined)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(Undefined);

    }
}