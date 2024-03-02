
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4512.hpp
*/

#ifndef C_4512_HPP
#define C_4512_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_4512 : public AComponent {
        public:
            C_4512();
            ~C_4512() override = default;

            Tristate getIndex(Tristate in_a, Tristate in_b, Tristate in_c);
            void compute(std::size_t pin) override;
    };
}

#endif // C_4512_HPP
