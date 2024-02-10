
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4013.hpp
*/

#ifndef C_4013_HPP
#define C_4013_HPP

#include "../AComponent.hpp"

namespace nts {

class C_4013 : public AComponent {
    public:
        C_4013(const std::string &name);
        ~C_4013() override = default;
    };
}

#endif // C_4013_HPP
