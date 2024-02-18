
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_false.hpp
*/

#ifndef C_FALSE_HPP
#define C_FALSE_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_false : public AComponent {
        public:
            C_false();
            ~C_false() override = default;

            void simulateComponent() override;
    };
}

#endif // C_FALSE_HPP
