
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_output.hpp
*/

#ifndef C_OUTPUT_HPP
#define C_OUTPUT_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_output : public AComponent {
        public:
            C_output();
            ~C_output() override = default;

            void simulateComponent() override;
    };
}

#endif // C_OUTPUT_HPP
