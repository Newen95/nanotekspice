
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4008.cpp
*/

#include "../../include/component/C_4008.hpp"

nts::C_4008::C_4008() : AComponent("4008")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeIgnored);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeOutput);
    addPin(14, PinType::typeOutput);
    addPin(15, PinType::typeInput);
    addPin(16, PinType::typeIgnored);
}

nts::C_4008::C_4008(const std::string &name) : AComponent("4008", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeIgnored);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeOutput);
    addPin(13, PinType::typeOutput);
    addPin(14, PinType::typeOutput);
    addPin(15, PinType::typeInput);
    addPin(16, PinType::typeIgnored);
}


nts::Tristate nts::C_4008::adder_(Circuit &Circuit, int in1, int in2, int out)
{
    const auto &map = Circuit.getComponentMap();
    Tristate in_1 = (*getPin(in1)).getState();
    Tristate in_2 = (*getPin(in2)).getState();
    Tristate _out;

    const auto &pin1_connected = (*getPin(in1)).getConnectedTo();
    for (const auto &tmp : pin1_connected) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        in_1 = map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->getState();
        break;
    }

    const auto &pin2_connected = (*getPin(in2)).getConnectedTo();
    for (const auto &tmp : pin2_connected) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        in_2 = map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->getState();
        break;
    }

    const auto &f = (*getPin(out)).getConnectedTo();

    for (const auto &tmp : f) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;

        if (in_1 == True && in_2 == True) {
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(True);
            _out = True;
        } else if (in_1 == True && in_2 == False) {
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(True);
            _out = True;
        } else if (in_1 == False && in_2 == True) {
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(True);
            _out = True;
        } else if (in_1 == Undefined && in_2 == Undefined) {
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(Undefined);
            _out = Undefined;
        } else if (in_1 == True && in_2 == Undefined) {
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(Undefined);
            _out = Undefined;
        } else if (in_1 == Undefined && in_2 == True) {
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(Undefined);
            _out = Undefined;
        } else {
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(False);
            _out = False;
        }
    }
    return _out;
}

void nts::C_4008::assignValue(Circuit &Circuit, int out, Tristate sate)
{
    const auto &map = Circuit.getComponentMap();
    const auto &f = (*getPin(out)).getConnectedTo();

    for (const auto &tmp : f) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(sate);
    }
}

nts::Tristate nts::C_4008::getRealPinStatus(int nbr, Circuit &Circuit)
{
    const auto &pin_connected = (*getPin(nbr)).getConnectedTo();
    for (const auto &tmp : pin_connected) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        return Circuit.getComponentMap().find(component_name)->second.get()->getPins().find(component_pin)->second.get()->getState();
    }
    return Undefined;
}

void nts::C_4008::simulate(Circuit &Circuit)
{
    Tristate _1 = adder_(Circuit, 1, 15, 13);
    Tristate _2 = adder_(Circuit, 2, 3, 12);
    Tristate _3 = adder_(Circuit, 4, 5, 11);
    Tristate _4 = adder_(Circuit, 6, 7, 10);
    Tristate in_9 = getRealPinStatus(9, Circuit);

    if (_1 == True && _2 == True && _3 == True && _4 == True && in_9 == True)
        assignValue(Circuit, 14, True);
    else if (_1 == False && _2 == False && _3 == False && _4 == False && in_9 == False)
        assignValue(Circuit, 14, False);
    else
        assignValue(Circuit, 14, Undefined);
}