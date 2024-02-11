
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4081.hpp
*/

#ifndef C_4081_HPP
#define C_4081_HPP

#include "../AComponent.hpp"

namespace nts {

class C_4081 : public AComponent {
    public:
        C_4081();
        C_4081(const std::string &name);
        ~C_4081() override = default;
    };
}

#endif // C_4081_HPP
