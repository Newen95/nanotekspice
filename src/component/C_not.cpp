
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

nts::C_not::C_not(const std::string &name) : AComponent("not", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeOutput);
}

void nts::C_not::simulate(Circuit &Circuit)
{
    const auto &map = Circuit.getComponentMap();
    Tristate in_1 = (*getPin(1)).getState();

    const auto &pin1_connected = (*getPin(1)).getConnectedTo();
    for (const auto &tmp : pin1_connected) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        in_1 = map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->getState();
        break;
    }

    const auto &f = (*getPin(2)).getConnectedTo();

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
