
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

void nts::C_4017::simulate(Circuit &Circuit)
{
    Tristate in_0_state = getRealPinStatus(13, Circuit);
    Tristate in_1_state = getRealPinStatus(14, Circuit);
    Tristate in_r_state = getRealPinStatus(15, Circuit);

    bool all_undefined = true;
    for (int i = 1; i <= 12; ++i) {
        if (getRealPinStatus(i, Circuit) != Undefined) {
            all_undefined = false;
            break;
        }
    } for (int i = 13; i <= 15; ++i) {
        if (getRealPinStatus(i, Circuit) != Undefined) {
            all_undefined = true;
            break;
        }
        all_undefined = false;
    }

    if (in_r_state == True || all_undefined) {
        for (int i = 1; i <= 11; ++i)
            assignValue(Circuit, i, False);
        assignValue(Circuit, 3, True);
    }

    else if (in_0_state == True || in_1_state == True) {
        for (int i = 1; i <= 11; ++i) {
            if (getRealPinStatus(i, Circuit) == True) {
                assignValue(Circuit, i, False);
                if (i == 11)
                    assignValue(Circuit, 3, True);
                else
                    assignValue(Circuit, i + 1, True);
                break;
            }
        }
    }
}



