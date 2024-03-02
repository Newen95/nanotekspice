/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** AComponent.hpp
*/

#ifndef ACOMPONENT_HPP
#define ACOMPONENT_HPP

#include "IComponent.hpp"
#include "pin.hpp"
#include <map>
#include <memory>
#include <sstream>
#include <stdexcept>


namespace nts
{
    class AComponent : public IComponent {
    private:
        std::string _type = "";
        std::size_t _currentTick;
        std::map<int, std::unique_ptr<Pin>> _pins;
        bool _isLock;
    public:
        // CTOR
        AComponent() = default;
        AComponent(const std::string &type);

        // ICOMPONENT FUNCTION
        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

        // OTHER
        void addPin(int number, PinType type);
        const std::size_t &getCurrentTick() const override;

        const std::string &getType() const override;
        const std::map<int, std::unique_ptr<Pin>> &getPins() const override;
        std::unique_ptr<Pin> &getPin(int number) override;
        void assignPinValue(int pinNbr, Tristate state, IComponent *Component) override;

        void setIsLock(bool state) override;
    };
}

#endif // ACOMPONENT_HPP
