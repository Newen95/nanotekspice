
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4514.hpp
*/

#ifndef C_4514_HPP
#define C_4514_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_4514 : public AComponent {
        public:
            C_4514();
            ~C_4514() override = default;

            int getIndex(Tristate in_0, Tristate in_1, Tristate in_2, Tristate in_3);
            void compute(std::size_t pin) override;
    };
}

#endif // C_4514_HPP
