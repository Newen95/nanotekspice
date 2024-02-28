
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4008.hpp
*/

#ifndef C_4008_HPP
#define C_4008_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_4008 : public AComponent {
        public:
            C_4008();
            ~C_4008() override = default;

            void compute(std::size_t pin) override;
            Tristate _adder(int in1, int in2, int out, Tristate in_c);
    };
}

#endif // C_4008_HPP
