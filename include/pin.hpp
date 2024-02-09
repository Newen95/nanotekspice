/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** pin.hpp
*/

#ifndef PIN_HPP
#define PIN_HPP

#include <string>

namespace nts {

    enum PinType {
        Input,
        Output,
        Other
    };

    class Pin {
        private:
            int _number;
            PinType _type;
        public:
            Pin(int number, PinType type) : _number(number), _type(type) {};
            ~Pin() = default;

            int getNumber() const {
                return _number;
            }

            PinType getType() const {
                return _type;
            }
    };

}

#endif // PIN_HPP
