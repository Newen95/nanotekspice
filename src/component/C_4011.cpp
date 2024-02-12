
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4011.cpp
*/

#include "../../include/component/C_4011.hpp"

nts::C_4011::C_4011() : AComponent("4011")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeOutput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeIgnored);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeInput);
    addPin(13, PinType::typeInput);
    addPin(14, PinType::typeIgnored);
}

nts::C_4011::C_4011(const std::string &name) : AComponent("4011", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeOutput);
    addPin(4, PinType::typeOutput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeIgnored);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeInput);
    addPin(10, PinType::typeOutput);
    addPin(11, PinType::typeOutput);
    addPin(12, PinType::typeInput);
    addPin(13, PinType::typeInput);
    addPin(14, PinType::typeIgnored);
}

void nts::C_4011::nand_(Circuit &Circuit, int in1, int in2, int out)
{
    const auto &map = Circuit.getComponentMap();
    Tristate in_1 = (*getPin(in1)).getState();
    Tristate in_2 = (*getPin(in2)).getState();

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

        if (in_1 == False && in_2 == False)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(True);
        if (in_1 == False && in_2 == True)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(True);
        if (in_1 == False && in_2 == Undefined)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(True);
        if (in_1 == True && in_2 == False)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(True);
        if (in_1 == True && in_2 == True)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(False);
        if (in_1 == True && in_2 == Undefined)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(Undefined);
        if (in_1 == Undefined && in_2 == False)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(True);
        if (in_1 == Undefined && in_2 == True)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(Undefined);
        if (in_1 == Undefined && in_2 == Undefined)
            map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(Undefined);
    }
}

void nts::C_4011::simulate(Circuit &Circuit)
{
    nand_(Circuit, 1, 2, 3);
    nand_(Circuit, 5, 6, 4);
    nand_(Circuit, 8, 9, 10);
    nand_(Circuit, 12, 13, 11);
}