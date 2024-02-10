
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4071.hpp
*/

#ifndef C_4071_HPP
#define C_4071_HPP

#include "../AComponent.hpp"

namespace nts {

class C_4071 : public AComponent {
    public:
        C_4071(const std::string &name);
        ~C_4071() override = default;
    };
}

#endif // C_4071_HPP
