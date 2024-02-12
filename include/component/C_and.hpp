
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_and.hpp
*/

#ifndef C_AND_HPP
#define C_AND_HPP

#include "../main.hpp"

namespace nts {

class C_and : public AComponent {
    public:
        C_and();
        C_and(const std::string &name);
        ~C_and() override = default;

        void simulate(Circuit &circuit);
    };
}

#endif // C_AND_HPP

