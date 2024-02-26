/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** factory.cpp
*/

#include "../include/factory.hpp"

std::unique_ptr<nts::IComponent> createComponent(const std::string &type)
{
    std::unordered_set<std::string> allTypes = {
        "input", "output", "true", "false", "clock",
        "and", "or", "xor", "not", "4001", "4011",
        "4030", "4069", "4071", "4081", "4008", "4013",
        "4017", "4040", "4094", "4512", "4514", "4801",
        "2716", "logger"
    };

    bool checkType = allTypes.find(type) != allTypes.end();

    if (checkType) {
        if (type == "false")
            return std::make_unique<nts::C_false>();
        if (type == "true")
            return std::make_unique<nts::C_true>();
        if (type == "input")
            return std::make_unique<nts::C_input>();
        if (type == "output")
            return std::make_unique<nts::C_output>();
        if (type == "xor")
            return std::make_unique<nts::C_xor>();
        if (type == "or")
            return std::make_unique<nts::C_or>();
        if (type == "nor")
            return std::make_unique<nts::C_nor>();
        if (type == "not")
            return std::make_unique<nts::C_not>();
        if (type == "nand")
            return std::make_unique<nts::C_nand>();
        if (type == "4001")
            return std::make_unique<nts::C_4001>();
        if (type == "4011")
            return std::make_unique<nts::C_4011>();
        if (type == "4030")
            return std::make_unique<nts::C_4030>();
        if (type == "4069")
            return std::make_unique<nts::C_4069>();
        if (type == "4071")
            return std::make_unique<nts::C_4071>();
        if (type == "4081")
            return std::make_unique<nts::C_4081>();
        if (type == "4008")
            return std::make_unique<nts::C_4008>();
        if (type == "4013")
            return std::make_unique<nts::C_4013>();
        if (type == "and")
            return std::make_unique<nts::C_and>();
        if (type == "logger")
            return std::make_unique<nts::C_logger>();
        if (type == "clock")
            return std::make_unique<nts::C_clock>();
        if (type == "4017")
            return std::make_unique<nts::C_4017>();
        if (type == "4040")
            return std::make_unique<nts::C_4040>();
        if (type == "4094")
            return std::make_unique<nts::C_4094>();
        if (type == "4512")
            return std::make_unique<nts::C_4512>();
        if (type == "4514")
            return std::make_unique<nts::C_4514>();
        if (type == "2716")
            return std::make_unique<nts::C_2716>();
        if (type == "4801")
            return std::make_unique<nts::C_4801>();
    } else {
        throw std::invalid_argument("Erreur: factory.cpp: Type inconnu: " + type);
    }
    throw std::invalid_argument("Erreur: factory.cpp: IM BATMAN. I LIVE IN THE SHADOW.");
}
