
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4081.hpp
*/

#ifndef C_4081_HPP
#define C_4081_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_4081 : public AComponent {
        public:
            C_4081();
            ~C_4081() override = default;

            void compute(std::size_t pin) override;
            void _and(int in1, int in2, int out);
    };
}

#endif // C_4081_HPP
