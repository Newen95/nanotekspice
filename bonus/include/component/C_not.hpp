
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_not.hpp
*/

#ifndef C_NOT_HPP
#define C_NOT_HPP


#include "../AComponent.hpp"

namespace nts
{
    class C_not : public AComponent {
        public:
            C_not();
            ~C_not() override = default;

            void simulateComponent() override;
    };

}

#endif // C_NOT_HPP
