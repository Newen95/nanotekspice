
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4017.hpp
*/

#ifndef C_4017_HPP
#define C_4017_HPP

#include "../main.hpp"

namespace nts {

class C_4017 : public AComponent {
    public:
        C_4017();
        C_4017(const std::string &name);
        ~C_4017() override = default;

        void simulate(Circuit &circuit);
        Tristate getRealPinStatus(int nbr, Circuit &Circuit);
        void assignValue(Circuit &Circuit, int out, Tristate sate);
    };
}

#endif // C_4017_HPP
