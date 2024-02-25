
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4030.hpp
*/

#ifndef C_4030_HPP
#define C_4030_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_4030 : public AComponent {
        public:
            C_4030();
            ~C_4030() override = default;

            void simulateComponent() override;
            void _xor(int in1, int in2, int out);
    };
}

#endif // C_4030_HPP
