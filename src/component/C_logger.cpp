
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_logger.cpp
*/

#include "../../include/component/C_logger.hpp"

nts::C_logger::C_logger() : AComponent("logger")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeClock);
    addPin(10, PinType::typeInput);
}

nts::C_logger::C_logger(const std::string &name) : AComponent("logger", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeClock);
    addPin(10, PinType::typeInput);
}

nts::Tristate nts::C_logger::getRealPinStatus(int nbr, Circuit &Circuit)
{
    const auto &pin_connected = (*getPin(nbr)).getConnectedTo();
    for (const auto &tmp : pin_connected) {
        std::string component_name = tmp.get()->component;
        std::size_t component_pin = tmp.get()->pin;
        return Circuit.getComponentMap().find(component_name)->second.get()->getPins().find(component_pin)->second.get()->getState();
    }
    return Undefined;
}

void nts::C_logger::simulate(Circuit &Circuit)
{
    std::ofstream logfile("log.bin", std::ios::trunc);
    std::string data;
    nts::Tristate inhibit = getRealPinStatus(10, Circuit);
    nts::Tristate state;

    if (inhibit == nts::False){
        for (int i = 1; i < 9; i++) {
            state = getRealPinStatus(i, Circuit);
            if (state == nts::True) {
                data += "1";
            } else if (state == nts::False){
                data += "0";
            } else {
                data += "-1";
            }
        }
        if (logfile.is_open()) {
            logfile << data << std::endl;
            logfile.close();
        } else {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier log.bin" << std::endl;
        }
    }
}
