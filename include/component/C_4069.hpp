
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4069.hpp
*/

#ifndef C_4069_HPP
#define C_4069_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_4069 : public AComponent {
        public:
            C_4069();
            ~C_4069() override = default;

            void simulateComponent() override;
            void _not(int in, int out);
    };
}

#endif // C_4069_HPP
