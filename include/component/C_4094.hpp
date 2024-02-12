
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4094.hpp
*/

#ifndef C_4094_HPP
#define C_4094_HPP

#include "../main.hpp"

namespace nts {

class C_4094 : public AComponent {
    public:
        C_4094();
        C_4094(const std::string &name);
        ~C_4094() override = default;

        void simulate(Circuit &circuit __attribute_maybe_unused__) { return; }
    };
}


#endif // C_4094_HPP
