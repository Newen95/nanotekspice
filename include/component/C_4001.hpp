
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4001.hpp
*/

#ifndef C_4001_HPP
#define C_4001_HPP

#include "../AComponent.hpp"

namespace nts {

class C_4001 : public AComponent {
    public:
        C_4001(const std::string &name);
        ~C_4001() override = default;
    };
}


#endif // C_4001_HPP
