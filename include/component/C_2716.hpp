
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_2716.hpp
*/

#ifndef C_2716_HPP
#define C_2716_HPP

#include "../main.hpp"

namespace nts {

class C_2716 : public AComponent {
    public:
        C_2716();
        C_2716(const std::string &name);
        ~C_2716() override = default;

        void simulate(Circuit &circuit);
        void adder_(Circuit &Circuit, int in1, int in2, int out);
        void assignValue(Circuit &Circuit, int out, Tristate sate);
        Tristate getRealPinStatus(int nbr, Circuit &Circuit);
    };
}

#endif // C_2716_HPP
