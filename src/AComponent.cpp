/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** AComponent.cpp
*/

#include "../include/AComponent.hpp"

nts::AComponent::AComponent(const std::string &type, const std::string &name)
    : _type(type), _name(name)
{}

nts::AComponent::~AComponent() {}


const std::string &nts::AComponent::getType() const
{
    return _type;
}

const std::string &nts::AComponent::getName() const
{
    return _name;
}

std::unique_ptr<nts::Pin> &nts::AComponent::getPin(int number)
{
    auto it = _pins.find(number);
    if (it != _pins.end()) {
        return it->second;
    } else {
        throw std::out_of_range("Pin not found");
    }
}

void nts::AComponent::addPin(int number, PinType type)
{
    _pins[number] = std::make_unique<Pin>(type);
}