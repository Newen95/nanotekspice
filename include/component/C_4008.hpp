
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4008.hpp
*/

#ifndef C_4008_HPP
#define C_4008_HPP

#include "../AComponent.hpp"

namespace nts {

class C_4008 : public AComponent {
    public:
        C_4008(const std::string &name);
        ~C_4008() override = default;
    };
}

#endif // C_4008_HPP
