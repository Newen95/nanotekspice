/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** pin.cpp
*/

#include "../include/pin.hpp"

nts::Pin::Pin(PinType type) : _type(type)
{}

std::list<std::unique_ptr<nts::Link>> &nts::Pin::getConnectedTo()
{
    return _connectedTo;
}

const nts::PinType &nts::Pin::getPinType() const
{
    return _type;
}

const nts::Tristate &nts::Pin::getState() const
{
    return _state;
}

void nts::Pin::setState(const nts::Tristate state)
{
    _state = state;
}

const nts::Tristate &nts::Pin::getNextState() const
{
    return _nexState;
}

void nts::Pin::setNextState(const nts::Tristate state)
{
    _nexState = state;
}
