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
    enum PinType {
        Input,
        Output,
        True,
        False,
        Other
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

        public:
            Pin(PinType type);
            ~Pin() = default;

            const PinType &getPinType() const;

            std::list<std::unique_ptr<Link>> &getConnectedTo();
    };
}

#endif // PIN_HPP
