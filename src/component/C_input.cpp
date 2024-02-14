
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_input.cpp
*/

#include "../../include/component/C_input.hpp"

nts::C_input::C_input() : AComponent("input")
{
    addPin(1, PinType::typeOutput);
}


nts::C_input::C_input(const std::string &name) : AComponent("input", name)
{
    addPin(1, PinType::typeOutput);
}

void nts::C_input::assignValue(Circuit &Circuit, int out, Tristate sate)
{
    const auto &map = Circuit.getComponentMap();
    const auto &f = (*getPin(out)).getConnectedTo();

    for (const auto &tmp : f) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(sate);
    }
}

void nts::C_input::simulate(Circuit &Circuit)
{
    Tristate state = (*getPin(1)).getState();
    assignValue(Circuit, 1, state);
}
