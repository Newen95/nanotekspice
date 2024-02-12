
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4030.hpp
*/

#ifndef C_4030_HPP
#define C_4030_HPP

#include "../main.hpp"

namespace nts {

class C_4030 : public AComponent {
    public:
        C_4030();
        C_4030(const std::string &name);
        ~C_4030() override = default;

        void xor_(Circuit &Circuit, int in1, int in2, int out);
        void simulate(Circuit &circuit);
    };
}

#endif // C_4030_HPP
