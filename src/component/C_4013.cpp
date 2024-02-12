
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4013.cpp
*/

#include "../../include/component/C_4013.hpp"

nts::C_4013::C_4013() : AComponent("4013")
{
    addPin(1, PinType::typeOutput);
    addPin(2, PinType::typeOutput);
    addPin(3, PinType::typeClock);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeIgnored);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeInput);
    addPin(11, PinType::typeClock);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeOutput);
}

nts::C_4013::C_4013(const std::string &name) : AComponent("4013", name)
{
    addPin(1, PinType::typeOutput);
    addPin(2, PinType::typeOutput);
    addPin(3, PinType::typeClock);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeIgnored);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeInput);
    addPin(11, PinType::typeClock);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeOutput);
}

void nts::C_4013::assignValue(Circuit &Circuit, int out, Tristate sate)
{
    const auto &map = Circuit.getComponentMap();
    const auto &f = (*getPin(out)).getConnectedTo();

    for (const auto &tmp : f) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(sate);
    }
}

nts::Tristate nts::C_4013::getRealPinStatus(int nbr, Circuit &Circuit)
{
    const auto &pin_connected = (*getPin(nbr)).getConnectedTo();
    for (const auto &tmp : pin_connected) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        return Circuit.getComponentMap().find(component_name)->second.get()->getPins().find(component_pin)->second.get()->getState();
    }
    return Undefined;
}


void nts::C_4013::simulate(Circuit &Circuit)
{
    Tristate cl_1_clock_state = getRealPinStatus(1, Circuit);
    Tristate cl_2_clock_state = getRealPinStatus(11, Circuit);

    Tristate in_1_data_state = getRealPinStatus(5, Circuit);
    Tristate in_1_set_state = getRealPinStatus(6, Circuit);
    Tristate in_1_reset_state = getRealPinStatus(4, Circuit);

    Tristate in_2_data_state = getRealPinStatus(9, Circuit);
    Tristate in_2_set_state = getRealPinStatus(8, Circuit);
    Tristate in_2_reset_state = getRealPinStatus(10, Circuit);

    if (cl_1_clock_state == True) {
        if (in_1_reset_state == True)
            state_1 = False; // Réinitialisation
        else if (in_1_set_state == True)
            state_1 = True; // Réglage
        else
            state_1 = in_1_data_state; // Chargement
    }

    if (cl_2_clock_state == True) {
        if (in_2_reset_state == True)
            state_2 = False; // Réinitialisation
        else if (in_2_set_state == True)
            state_2 = True; // Réglage
        else
            state_2 = in_2_data_state; // Chargement
    }

    // Mise à jour des sorties Q et Qb pour chaque flip-flop
    assignValue(Circuit, 1, state_1);
    assignValue(Circuit, 2, state_1 == True ? False : True);
    assignValue(Circuit, 13, state_2);
    assignValue(Circuit, 12, state_2 == True ? False : True);
}