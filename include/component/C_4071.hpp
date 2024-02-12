
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4071.hpp
*/

#ifndef C_4071_HPP
#define C_4071_HPP

#include "../main.hpp"

namespace nts {

class C_4071 : public AComponent {
    public:
        C_4071();
        C_4071(const std::string &name);
        ~C_4071() override = default;

        void or_(Circuit &Circuit, int in1, int in2, int out);
        void simulate(Circuit &circuit);
    };
}

#endif // C_4071_HPP
