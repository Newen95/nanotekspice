
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4001.hpp
*/

#ifndef C_4001_HPP
#define C_4001_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_4001 : public AComponent {
        public:
            C_4001();
            ~C_4001() override = default;

            void compute(std::size_t pin) override;
            void _nor(int in1, int in2, int out);
    };
}

#endif // C_4001_HPP
