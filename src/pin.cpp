/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** pin.cpp
*/

#include "../include/pin.hpp"

nts::Pin::Pin(PinType type) : _type(type), _isLock(false)
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

const bool &nts::Pin::getIsLock() const
{
    return _isLock;
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

void nts::Pin::setOutState(const nts::Tristate state)
{
    for (const auto &element : _connectedTo) {
        IComponent &component = *element.get()->component;
        std::size_t &component_pin = element.get()->pin;
        component.getPin(component_pin).get()->setState(state);
        if (!_isLock) {
            _isLock = true;
            component.getPin(component_pin).get()->setOutState(state);
        }
    }
}

void nts::Pin::setOutNextState(const nts::Tristate state)
{
    for (const auto &element : _connectedTo) {
        IComponent &component = *element.get()->component;
        std::size_t &component_pin = element.get()->pin;

        if (component.getPin(component_pin).get()->getPinType() == typeInput)
            component.getPin(component_pin).get()->setNextState(state);
    }
}

void nts::Pin::setIsLock(const bool state)
{
    _isLock = state;
}