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

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    try {
        std::cout << "Linking pin " << pin << " of component " << _name
                    << " to pin " << otherPin << " of component " << other.getName() << std::endl;
    } catch (const std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void nts::AComponent::simulate(std::size_t tick __attribute_maybe_unused__)
{
    return;
}

nts::Tristate nts::AComponent::compute(std::size_t pin __attribute_maybe_unused__)
{
    return nts::Tristate::Undefined;
}