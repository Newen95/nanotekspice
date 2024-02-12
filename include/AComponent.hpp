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

namespace nts
{
    class AComponent : public IComponent {
    private:
        std::string _type;
        std::string _name;
        std::map<int, std::unique_ptr<Pin>> _pins;

    public:
        AComponent() = default;
        AComponent(const std::string &type);
        AComponent(const std::string &type, const std::string &name);

        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

        const std::string &getType() const override;
        const std::string &getName() const override;
        const std::map<int, std::unique_ptr<Pin>> &getPins() const override;
        std::unique_ptr<Pin> &getPin(int number) override;

        void addPin(int number, PinType type);
    };
}

#endif // ACOMPONENT_HPP
