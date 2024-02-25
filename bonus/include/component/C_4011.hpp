
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4011.hpp
*/

#ifndef C_4011_HPP
#define C_4011_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_4011 : public AComponent {
        public:
            C_4011();
            ~C_4011() override = default;

            void simulateComponent() override;
            void _nand(int in1, int in2, int out);
    };
}


#endif // C_4011_HPP
