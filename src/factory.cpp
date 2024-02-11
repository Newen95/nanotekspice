/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** factory.cpp
*/

#include "../include/factory.hpp"

std::unique_ptr<nts::IComponent> createComponent(const std::string& type) {
    if (type == "xor") {
        return std::make_unique<nts::C_xor>();
    } else if (type == "true") {
        return std::make_unique<nts::C_true>();
    } else if (type == "output") {
        return std::make_unique<nts::C_output>();
    } else if (type == "or") {
        return std::make_unique<nts::C_or>();
    } else if (type == "not") {
        return std::make_unique<nts::C_not>();
    } else if (type == "nor") {
        return std::make_unique<nts::C_nor>();
    } else if (type == "nand") {
        return std::make_unique<nts::C_nand>();
    } else if (type == "logger") {
        return std::make_unique<nts::C_logger>();
    } else if (type == "input") {
        return std::make_unique<nts::C_input>();
    } else if (type == "false") {
        return std::make_unique<nts::C_false>();
    } else if (type == "clock") {
        return std::make_unique<nts::C_clock>();
    } else if (type == "and") {
        return std::make_unique<nts::C_and>();
    } else if (type == "4801") {
        return std::make_unique<nts::C_4801>();
    } else if (type == "4514") {
        return std::make_unique<nts::C_4514>();
    } else if (type == "4512") {
        return std::make_unique<nts::C_4512>();
    } else if (type == "4094") {
        return std::make_unique<nts::C_4094>();
    } else if (type == "4081") {
        return std::make_unique<nts::C_4081>();
    } else if (type == "4071") {
        return std::make_unique<nts::C_4071>();
    } else if (type == "4069") {
        return std::make_unique<nts::C_4069>();
    } else if (type == "4040") {
        return std::make_unique<nts::C_4040>();
    } else if (type == "4030") {
        return std::make_unique<nts::C_4030>();
    } else if (type == "4017") {
        return std::make_unique<nts::C_4017>();
    } else if (type == "4013") {
        return std::make_unique<nts::C_4013>();
    } else if (type == "4011") {
        return std::make_unique<nts::C_4011>();
    } else if (type == "4008") {
        return std::make_unique<nts::C_4008>();
    } else if (type == "4001") {
        return std::make_unique<nts::C_4001>();
    } else if (type == "2716") {
        return std::make_unique<nts::C_2716>();
    } else {
        throw std::invalid_argument("Erreur: Type inconnu: " + type);
    }
}
