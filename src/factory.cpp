/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** factory.cpp
*/

#include "../include/factory.hpp"

std::unique_ptr<nts::AComponent> createComponent(const std::string& type, const std::string& name) {
    if (type == "xor") {
        return std::make_unique<nts::C_xor>(name);
    } else if (type == "true") {
        return std::make_unique<nts::C_true>(name);
    } else if (type == "output") {
        return std::make_unique<nts::C_output>(name);
    } else if (type == "or") {
        return std::make_unique<nts::C_or>(name);
    } else if (type == "not") {
        return std::make_unique<nts::C_not>(name);
    } else if (type == "nor") {
        return std::make_unique<nts::C_nor>(name);
    } else if (type == "nand") {
        return std::make_unique<nts::C_nand>(name);
    } else if (type == "logger") {
        return std::make_unique<nts::C_logger>(name);
    } else if (type == "input") {
        return std::make_unique<nts::C_input>(name);
    } else if (type == "false") {
        return std::make_unique<nts::C_false>(name);
    } else if (type == "clock") {
        return std::make_unique<nts::C_clock>(name);
    } else if (type == "and") {
        return std::make_unique<nts::C_and>(name);
    } else if (type == "4801") {
        return std::make_unique<nts::C_4801>(name);
    } else if (type == "4514") {
        return std::make_unique<nts::C_4514>(name);
    } else if (type == "4512") {
        return std::make_unique<nts::C_4512>(name);
    } else if (type == "4094") {
        return std::make_unique<nts::C_4094>(name);
    } else if (type == "4081") {
        return std::make_unique<nts::C_4081>(name);
    } else if (type == "4071") {
        return std::make_unique<nts::C_4071>(name);
    } else if (type == "4069") {
        return std::make_unique<nts::C_4069>(name);
    } else if (type == "4040") {
        return std::make_unique<nts::C_4040>(name);
    } else if (type == "4030") {
        return std::make_unique<nts::C_4030>(name);
    } else if (type == "4017") {
        return std::make_unique<nts::C_4017>(name);
    } else if (type == "4013") {
        return std::make_unique<nts::C_4013>(name);
    } else if (type == "4011") {
        return std::make_unique<nts::C_4011>(name);
    } else if (type == "4008") {
        return std::make_unique<nts::C_4008>(name);
    } else if (type == "4001") {
        return std::make_unique<nts::C_4001>(name);
    } else if (type == "2716") {
        return std::make_unique<nts::C_2716>(name);
    } else {
        throw std::invalid_argument("Erreur: Type inconnu: " + type);
    }
}
