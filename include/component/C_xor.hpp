
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_xor.hpp
*/

#ifndef C_XOR_HPP
#define C_XOR_HPP

#include "../main.hpp"

namespace nts {

class C_xor : public AComponent {
    public:
        C_xor();
        C_xor(const std::string &name);
        ~C_xor() override = default;

        void simulate(Circuit &circuit);
    };

}


#endif // C_XOR_HPP

