
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_clock.hpp
*/

#ifndef C_CLOCK_HPP
#define C_CLOCK_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_clock : public AComponent {
        public:
            C_clock();
            ~C_clock() override = default;

            void simulateComponent() override;
    };
}

#endif // C_CLOCK_HPP
