/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** AComponent.cpp
*/

#include "../include/AComponent.hpp"

// CTOR


nts::AComponent::AComponent(const std::string &type) : _type(type), _currentTick(0), _isLock(false)
{}

// ICOMPONENT FUNCTION


void nts::AComponent::simulate(std::size_t tick)
{
    if (_isLock == false)
        _currentTick += tick;
    _isLock = true;

    if (getType() == "logger")
        compute(0);
    else {
        for (auto& pinPair : _pins) {
            std::size_t pinNbr = pinPair.first;
            Pin* pin = pinPair.second.get();

            if (pin->getPinType() == typeOutput && pin->getLock() != true) {
                pin->setLock(true);
                compute(pinNbr);
            }
        }
    }
}

void nts::AComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    if (_pins.find(pin) == _pins.end()) {
        throw std::out_of_range("Erreur: AComponent.cpp: Le pin spécifié n'existe pas dans ce composant.");
    }

    std::unique_ptr<Pin> &currentPin = _pins[pin];
    std::unique_ptr<Link> link = std::make_unique<Link>();

    link->component = &other;
    link->pin = otherPin;

    currentPin->getConnectedTo().push_back(std::move(link));
}


// OTHER


void nts::AComponent::addPin(int number, PinType type)
{
    _pins[number] = std::make_unique<Pin>(type);
}

const std::size_t &nts::AComponent::getCurrentTick() const
{
    return _currentTick;
}

const std::string &nts::AComponent::getType() const
{
    return _type;
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
        std::ostringstream oss;
        oss << "Pin " << number << " not found";
        throw std::out_of_range(oss.str());
    }
}

void nts::AComponent::setIsLock(bool state)
{
    _isLock = state;
}

void nts::AComponent::assignPinValue(int pinNbr, Tristate state, IComponent *Component)
{
    std::unique_ptr<Pin> &pin = Component->getPin(pinNbr);
    if (pin) {
        pin->setState(state);
        pin->setOutState(state);
    }
}
