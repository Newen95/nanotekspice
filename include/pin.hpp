/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** pin.hpp
*/

#ifndef PIN_HPP
#define PIN_HPP

#include <string>

namespace nts
{
    enum PinType {
        Input,
        Output,
        Other
    };

    class Pin {
        protected:
            PinType _type;

        public:
            Pin(PinType type);
            ~Pin() = default;
    };

}

#endif // PIN_HPP
