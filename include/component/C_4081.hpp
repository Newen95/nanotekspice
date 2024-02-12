
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4081.hpp
*/

#ifndef C_4081_HPP
#define C_4081_HPP

#include "../main.hpp"

namespace nts {

class C_4081 : public AComponent {
    public:
        C_4081();
        C_4081(const std::string &name);
        ~C_4081() override = default;

        void and_(Circuit &Circuit, int in1, int in2, int out);
        void simulate(Circuit &circuit);
    };
}

#endif // C_4081_HPP
