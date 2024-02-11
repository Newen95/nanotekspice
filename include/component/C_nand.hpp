
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_nand.hpp
*/

#ifndef C_NAND_HPP
#define C_NAND_HPP

#include "../AComponent.hpp"

namespace nts {

class C_nand : public AComponent {
    public:
        C_nand();
        C_nand(const std::string &name);
        ~C_nand() override = default;
    };

}

#endif // C_NAND_HPP
