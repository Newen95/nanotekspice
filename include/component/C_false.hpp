
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_false.hpp
*/

#ifndef C_FALSE_HPP
#define C_FALSE_HPP

#include "../AComponent.hpp"

namespace nts {

class C_false : public AComponent {
    public:
        C_false(const std::string &name);
        ~C_false() override = default;
    };
}

#endif // C_FALSE_HPP
