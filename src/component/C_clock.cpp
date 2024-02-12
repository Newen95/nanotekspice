
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_clock.cpp
*/

#include "../../include/component/C_clock.hpp"

nts::C_clock::C_clock() : AComponent("clock")
{
    addPin(1, PinType::typeInput);
}

nts::C_clock::C_clock(const std::string &name) : AComponent("clock", name)
{
    addPin(1, PinType::typeInput);
}

void nts::C_clock::simulate(Circuit &Circuit)
{
    const auto &map = Circuit.getComponentMap();
    Tristate in_1 = (*getPin(1)).getState();

    const auto &f = (*getPin(1)).getConnectedTo();

    for (const auto &tmp : f) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;

        if (in_1 == False) {
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(False);
            (*getPin(1)).setNextState(True);
        } if (in_1 == True) {
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(True);
            (*getPin(1)).setNextState(False);
        }
    }
}
