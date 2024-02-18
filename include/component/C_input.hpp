
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_input.hpp
*/

#ifndef C_INPUT_HPP
#define C_INPUT_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_input : public AComponent {
        public:
            C_input();
            ~C_input() override = default;

            void simulateComponent() override;
    };
}

#endif // C_INPUT_HPP
