
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4071.hpp
*/

#ifndef C_4071_HPP
#define C_4071_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_4071 : public AComponent {
        public:
            C_4071();
            ~C_4071() override = default;

            void compute(std::size_t pin) override;
            void _or(int in1, int in2, int out);
    };
}

#endif // C_4071_HPP
