
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4512.hpp
*/

#ifndef C_4512_HPP
#define C_4512_HPP

#include "../main.hpp"

namespace nts {

class C_4512 : public AComponent {
    public:
        C_4512();
        C_4512(const std::string &name);
        ~C_4512() override = default;

        void simulate(Circuit &circuit __attribute_maybe_unused__) { return; }
    };
}


#endif // C_4512_HPP
