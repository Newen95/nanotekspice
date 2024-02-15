
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
    Tristate clk1 = getRealPinStatus(3, Circuit);
    Tristate clk2 = getRealPinStatus(11, Circuit);

    Tristate data1 = getRealPinStatus(5, Circuit);
    Tristate data2 = getRealPinStatus(9, Circuit);

    Tristate reset1 = getRealPinStatus(4, Circuit);
    Tristate reset2 = getRealPinStatus(10, Circuit);

    Tristate set1 = getRealPinStatus(6, Circuit);
    Tristate set2 = getRealPinStatus(8, Circuit);

    if (clk1 == True) {
        if (reset1 == True)
            _state1 = False;
        else if (set1 == True)
            _state1 = True;
        else
            _state1 = data1;
    }
    assignValue(Circuit, 1, _state1);
    assignValue(Circuit, 2, _state1 == True ? False : (_state1 == Undefined ? Undefined : True));

    if (clk2 == True) {
        if (reset2 == True)
            _state2 = False;
        else if (set2 == True)
            _state2 = True;
        else
            _state2 = data2;
    }
    assignValue(Circuit, 13, _state2);
    assignValue(Circuit, 12, _state1 == True ? False : (_state2 == Undefined ? Undefined : True));
}
