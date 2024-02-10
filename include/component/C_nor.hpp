
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_nor.hpp
*/

#ifndef C_NOR_HPP
#define C_NOR_HPP

#include "../AComponent.hpp"

namespace nts {

class C_nor : public AComponent {
    public:
        C_nor(const std::string &name);
        ~C_nor() override = default;
    };

}

#endif // C_NOR_HPP
