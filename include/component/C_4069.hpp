
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4069.hpp
*/

#ifndef C_4069_HPP
#define C_4069_HPP

#include "../main.hpp"

namespace nts {

class C_4069 : public AComponent {
    public:
        C_4069();
        C_4069(const std::string &name);
        ~C_4069() override = default;

        void not_(Circuit &Circuit, int in, int out);
        void simulate(Circuit &circuit);
    };
}
#endif // C_4069_HPP
