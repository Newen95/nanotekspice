
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_true.hpp
*/

#ifndef C_TRUE_HPP
#define C_TRUE_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_true : public AComponent {
        public:
            C_true();
            ~C_true() override = default;

            void simulateComponent() override;
    };
}

#endif // C_TRUE_HPP
