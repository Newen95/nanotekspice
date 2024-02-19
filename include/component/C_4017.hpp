
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4017.hpp
*/

#ifndef C_4017_HPP
#define C_4017_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_4017 : public AComponent {
        protected:
            int _index = -1;
        public:
            C_4017();
            ~C_4017() override = default;

            void simulateComponent() override;
            void getNextIndex(int index);
    };
}

#endif // C_4017_HPP
