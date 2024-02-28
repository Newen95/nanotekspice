
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4040.hpp
*/

#ifndef C_4040_HPP
#define C_4040_HPP

#include "../AComponent.hpp"
#include <bitset>

namespace nts
{
    class C_4040 : public AComponent {
        protected:
            int _nbr = 0;
        public:
            C_4040();
            ~C_4040() override = default;

            void compute(std::size_t pin) override;
    };
}

#endif // C_4040_HPP
