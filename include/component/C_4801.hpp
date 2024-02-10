
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4801.hpp
*/

#ifndef C_4801_HPP
#define C_4801_HPP

#include "../AComponent.hpp"

namespace nts {

class C_4801 : public AComponent {
    public:
        C_4801(const std::string &name);
        ~C_4801() override = default;
    };
}

#endif // C_4801_HPP
