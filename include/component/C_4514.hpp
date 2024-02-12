
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4514.hpp
*/

#ifndef C_4514_HPP
#define C_4514_HPP

#include "../main.hpp"

namespace nts {

class C_4514 : public AComponent {
    public:
        C_4514();
        C_4514(const std::string &name);
        ~C_4514() override = default;

        void simulate(Circuit &circuit __attribute_maybe_unused__) { return; }
    };
}


#endif // C_4514_HPP
