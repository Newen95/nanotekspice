
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
        if (data1 == False && set1 == False && reset1 == False) {
            assignValue(Circuit, 1, False);
            assignValue(Circuit, 2, True);
            _state1 = False;
        } else if (data1 == True && set1 == False && reset1 == False) {
            assignValue(Circuit, 1, True);
            assignValue(Circuit, 2, False);
            _state1 = True;
        }
    } if (reset1 == True && set1 == False) {
        assignValue(Circuit, 1, False);
        assignValue(Circuit, 2, True);
        _state1 = False;
    } else if (reset1 == False && set1 == True) {
        assignValue(Circuit, 1, True);
        assignValue(Circuit, 2, False);
        _state1 = True;
    } else if (reset1 == True && set1 == True) {
        assignValue(Circuit, 1, True);
        assignValue(Circuit, 2, True);
        _state1 = True;
    } else {
        assignValue(Circuit, 1, _state1);
        assignValue(Circuit, 2, _state1 == True ? False : True);
    }

    if (clk2 == True) {
        if (data2 == False && set2 == False && reset2 == False) {
            assignValue(Circuit, 1, False);
            assignValue(Circuit, 2, True);
            _state2 = False;
        } else if (data2 == True && set2 == False && reset2 == False) {
            assignValue(Circuit, 1, True);
            assignValue(Circuit, 2, False);
            _state2 = True;
        }
    } if (reset2 == True && set2 == False) {
        assignValue(Circuit, 1, False);
        assignValue(Circuit, 2, True);
        _state2 = False;
    } else if (reset2 == False && set2 == True) {
        assignValue(Circuit, 1, True);
        assignValue(Circuit, 2, False);
        _state2 = True;
    } else if (reset2 == True && set2 == True) {
        assignValue(Circuit, 1, True);
        assignValue(Circuit, 2, True);
        _state2 = True;
    } else {
        assignValue(Circuit, 1, _state2);
        assignValue(Circuit, 2, _state2 == True ? False : True);
    }
}
