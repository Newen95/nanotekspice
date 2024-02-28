
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_and.hpp
*/

#ifndef C_AND_HPP
#define C_AND_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_and : public AComponent {
        public:
            C_and();
            ~C_and() override = default;

            void compute(std::size_t pin) override;
    };
}

#endif // C_AND_HPP
