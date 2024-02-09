
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_and.cpp
*/

#include "../../include/component/C_and.hpp"


C_and::C_and() {}

C_and::~C_and() {}

void C_and::simulate(std::size_t tick __attribute_maybe_unused__)
{}

nts::Tristate C_and::compute(std::size_t pin __attribute_maybe_unused__)
{
    if (_in1 == nts::Tristate::True && _in2 == nts::Tristate::True)
        _output = nts::Tristate::True;
    else
        _output = nts::Tristate::False;
    return _output;
}

void C_and::setLink(std::size_t pin __attribute_maybe_unused__, nts::IComponent &other __attribute_maybe_unused__, std::size_t otherPin __attribute_maybe_unused__)
{}
