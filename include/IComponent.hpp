/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** IComponent.hpp
*/

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

#include <iostream>
#include <memory>
#include <map>
#include "pin.hpp"

namespace nts
{
    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;

            virtual const std::string &getType() const = 0;
            virtual const std::string &getName() const = 0;
            virtual const std::map<int, std::unique_ptr<Pin>> &getPins() const = 0;
            virtual std::unique_ptr<Pin> &getPin(int number) = 0;
    };
}

#endif // ICOMPONENT_HPP