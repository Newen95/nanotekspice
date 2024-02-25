
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

void nts::C_logger::simulateComponent()
{
    std::ofstream logfile("log.bin", std::ios::out | std::ios::binary | std::ios::app);
    char to_write = 0;
    nts::Tristate inhibit = this->getPin(10)->getState();
    nts::Tristate state;

    if (inhibit == nts::False && this->getPin(9)->getState() == nts::True) {
        for (int i = 1; i <= 8; ++i) {
            state = this->getPin(i)->getState();
            if (state != nts::Undefined) {
                to_write |= (1 << (i - 1));
            } else {
                return;
            }
        }
        if (logfile.is_open()) {
            logfile.write(&to_write, 1);
            logfile.close();
        } else {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier log.bin" << std::endl;
        }
    }
}

