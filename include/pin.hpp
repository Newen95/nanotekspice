/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** pin.hpp
*/

#ifndef PIN_HPP
#define PIN_HPP

#include <string>
#include "IComponent.hpp"

namespace nts {

    enum PinType {
        Input,
        Output,
        Other
    };

    class Pin {
        protected:
            PinType _type;
            Tristate _state;

        public:
            Pin(PinType type);
            ~Pin() = default;

            PinType getType() const;
    };

}

#endif // PIN_HPP
