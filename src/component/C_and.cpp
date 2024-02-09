
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_and.cpp
*/

#include "../../include/component/C_and.hpp"


nts::C_and::C_and(const std::string &name) : AComponent("and", name, 3)
{
    addPin(1, PinType::Input);
    addPin(2, PinType::Input);
    addPin(3, PinType::Output);
}

void nts::C_and::simulate(std::size_t tick __attribute_maybe_unused__)
{}

nts::Tristate nts::C_and::compute(std::size_t pin __attribute_maybe_unused__)
{
    return nts::Tristate::Undefined;
}

void nts::C_and::setLink(std::size_t pin __attribute_maybe_unused__, nts::IComponent &other __attribute_maybe_unused__, std::size_t otherPin __attribute_maybe_unused__)
{}
