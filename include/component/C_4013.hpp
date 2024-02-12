
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4013.hpp
*/

#ifndef C_4013_HPP
#define C_4013_HPP

#include "../main.hpp"

namespace nts {

class C_4013 : public AComponent {
    private:
        Tristate state_1;
        Tristate state_2;
    public:
        C_4013();
        C_4013(const std::string &name);
        ~C_4013() override = default;

        void simulate(Circuit &circuit);
        void assignValue(Circuit &Circuit, int out, Tristate sate);
        Tristate getRealPinStatus(int nbr, Circuit &Circuit);
    };
}

#endif // C_4013_HPP
