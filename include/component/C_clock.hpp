
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_clock.hpp
*/

#ifndef C_CLOCK_HPP
#define C_CLOCK_HPP

#include "../main.hpp"

namespace nts {

class C_clock : public AComponent {
    public:
        C_clock();
        C_clock(const std::string &name);
        ~C_clock() override = default;

        void simulate(Circuit &Circuit);
    };
}

#endif // C_CLOCK_HPP
