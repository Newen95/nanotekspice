
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
    std::cerr << "IM BATMAN. I LIVE IN THE SHADOW." << std::endl;
}
