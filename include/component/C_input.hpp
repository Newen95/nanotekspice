
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_input.hpp
*/

#ifndef C_INPUT_HPP
#define C_INPUT_HPP

#include "../main.hpp"

namespace nts {

class C_input : public AComponent {
    protected:
        nts::Tristate _state;
    public:
        C_input();
        C_input(const std::string &name);
        ~C_input() override = default;

        void assignValue(Circuit &Circuit, int out, Tristate sate);
        void simulate(Circuit &circuit);
    };
}

#endif // C_INPUT_HPP
