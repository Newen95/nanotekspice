
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_true.hpp
*/

#ifndef C_TRUE_HPP
#define C_TRUE_HPP

#include "../main.hpp"

namespace nts {

class C_true : public AComponent {
    public:
        C_true();
        C_true(const std::string &name);
        ~C_true() override = default;

        void simulate(Circuit &circuit);
        void assignValue(Circuit &Circuit, int out, Tristate sate);
    };
}


#endif // C_TRUE_HPP
