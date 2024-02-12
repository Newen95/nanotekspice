
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4008.hpp
*/

#ifndef C_4008_HPP
#define C_4008_HPP

#include "../main.hpp"

namespace nts {

class C_4008 : public AComponent {
    public:
        C_4008();
        C_4008(const std::string &name);
        ~C_4008() override = default;

        void simulate(Circuit &circuit);
        Tristate adder_(Circuit &Circuit, int in1, int in2, int out);
        void assignValue(Circuit &Circuit, int out, Tristate sate);
        Tristate getRealPinStatus(int nbr, Circuit &Circuit);
    };
}

#endif // C_4008_HPP
