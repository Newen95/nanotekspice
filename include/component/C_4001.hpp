
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4001.hpp
*/

#ifndef C_4001_HPP
#define C_4001_HPP

#include "../main.hpp"

namespace nts {

class C_4001 : public AComponent {
    public:
        C_4001();
        C_4001(const std::string &name);
        ~C_4001() override = default;

        void simulate(Circuit &circuit);
        void nor_(Circuit &Circuit, int in_1, int in_2, int out);
    };
}


#endif // C_4001_HPP
