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

namespace nts {

    class AComponent : public IComponent {
    private:
        std::string _type;
        std::string _name;
        std::map<int, std::unique_ptr<Pin>> _pins;

    public:
        AComponent(const std::string &type, const std::string &name);
        virtual ~AComponent() = default;

        void simulate(std::size_t tick) override = 0;
        nts::Tristate compute(std::size_t pin) override = 0;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override = 0;

        const std::string &getType() const ;
        const std::string &getName() const;
        Pin &getPin(int number);

        void addPin(int number, PinType type);
    };

}

#endif // ACOMPONENT_HPP
