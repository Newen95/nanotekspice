
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_false.hpp
*/

#ifndef C_FALSE_HPP
#define C_FALSE_HPP

#include "../main.hpp"

namespace nts {

class C_false : public AComponent {
    public:
        C_false();
        C_false(const std::string &name);
        ~C_false() override = default;

        void simulate(Circuit &circuit __attribute_maybe_unused__) { return; }
    };
}

#endif // C_FALSE_HPP
