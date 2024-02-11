
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_2716.hpp
*/

#ifndef C_2716_HPP
#define C_2716_HPP

#include "../AComponent.hpp"

namespace nts {

class C_2716 : public AComponent {
    public:
        C_2716();
        C_2716(const std::string &name);
        ~C_2716() override = default;
    };
}

#endif // C_2716_HPP
