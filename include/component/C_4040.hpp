
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4040.hpp
*/

#ifndef C_4040_HPP
#define C_4040_HPP

#include "../AComponent.hpp"

namespace nts {

class C_4040 : public AComponent {
    public:
        C_4040();
        C_4040(const std::string &name);
        ~C_4040() override = default;
    };
}

#endif // C_4040_HPP
