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

const std::map<int, std::unique_ptr<nts::Pin>>& nts::AComponent::getPins() const
{
    return _pins;
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
    if (_pins.find(pin) == _pins.end()) {
        throw std::out_of_range("Le pin spécifié n'existe pas dans ce composant.");
    }

    std::unique_ptr<Pin> &currentPin = _pins[pin];

    std::unique_ptr<Link> link = std::make_unique<Link>();
    link->component = other.getName();
    link->pin = otherPin;

    currentPin->getConnectedTo().push_back(std::move(link));
}

void nts::AComponent::simulate(std::size_t tick __attribute_maybe_unused__)
{
    return;
}

nts::Tristate nts::AComponent::compute(std::size_t pin __attribute_maybe_unused__)
{
    return nts::Tristate::Undefined;
}