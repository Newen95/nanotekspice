
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_or.hpp
*/

#ifndef C_OR_HPP
#define C_OR_HPP

#include "../AComponent.hpp"

namespace nts {

class C_or : public AComponent {
    public:
        C_or();
        C_or(const std::string &name);
        ~C_or() override = default;
    };

}

#endif // C_OR_HPP
