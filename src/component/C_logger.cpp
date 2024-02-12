
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

void nts::C_logger::simulate()
{
    std::ofstream logfile("log.bin", std::ios::app);
    std::string data;
    nts::Tristate inhibit = (*getPin(10)).getState();
    nts::Tristate state;
    std::cout << "Value of inhibit: " << inhibit << std::endl;

    if (inhibit == nts::False){
        for (size_t i = 0; i < 9; ++i) {
            state = (*getPin(i)).getState();
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
