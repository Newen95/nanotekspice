
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4801.hpp
*/

#ifndef C_4801_HPP
#define C_4801_HPP

#include "../main.hpp"

namespace nts {

class C_4801 : public AComponent {
    public:
        C_4801();
        C_4801(const std::string &name);
        ~C_4801() override = default;

        void simulate(Circuit &circuit __attribute_maybe_unused__) { return; }
    };
}

#endif // C_4801_HPP
