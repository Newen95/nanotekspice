/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** pin.hpp
*/

#ifndef PIN_HPP
#define PIN_HPP

#include <string>
#include <list>
#include <memory>

namespace nts
{
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    enum PinType {
        typeInput,
        typeOutput,
        typeInOut,
        typeFalse,
        typeTrue,
        typeClock,
        typeIgnored,
        typeOther
    };

    struct Link
    {
        std::string component;
        std::size_t pin;
    };

    class Pin {
        protected:
            PinType _type;
            std::list<std::unique_ptr<Link>> _connectedTo;
            Tristate _state = Undefined;
            Tristate _nexState = Undefined;

        public:
            Pin(PinType type);
            ~Pin() = default;

            const PinType &getPinType() const;
            const Tristate &getState() const;
            const Tristate &getNextState() const;
            std::list<std::unique_ptr<Link>> &getConnectedTo();

            void setState(const Tristate state);
            void setNextState(const Tristate state);
    };
}

#endif // PIN_HPP
