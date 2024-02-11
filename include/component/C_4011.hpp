
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4011.hpp
*/

#ifndef C_4011_HPP
#define C_4011_HPP

#include "../AComponent.hpp"

namespace nts {

class C_4011 : public AComponent {
    public:
        C_4011();
        C_4011(const std::string &name);
        ~C_4011() override = default;
    };
}


#endif // C_4011_HPP
