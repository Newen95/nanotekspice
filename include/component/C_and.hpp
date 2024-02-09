
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_and.hpp
*/

#ifndef C_AND_HPP
#define C_AND_HPP

#include <iostream>
#include <string>

#include "../IComponent.hpp"

class C_and : nts::IComponent {
    private:
        nts::Tristate _in1;
        nts::Tristate _in2;
        nts::Tristate _output;

    public:
        C_and();
        ~C_and();

        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
};

#endif // C_AND_HPP
