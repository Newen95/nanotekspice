
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_false.cpp
*/

#include "../../include/component/C_false.hpp"

nts::C_false::C_false() : AComponent("false")
{
    addPin(1, PinType::typeOutput);
}

nts::C_false::C_false(const std::string &name) : AComponent("false", name)
{
    addPin(1, PinType::typeOutput);
}

void nts::C_false::assignValue(Circuit &Circuit, int out, Tristate sate)
{
    const auto &map = Circuit.getComponentMap();
    const auto &f = (*getPin(out)).getConnectedTo();

    for (const auto &tmp : f) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(sate);
    }
}

void nts::C_false::simulate(Circuit &Circuit)
{
    assignValue(Circuit, 1, False);
}
