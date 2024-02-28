
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4013.hpp
*/

#ifndef C_4013_HPP
#define C_4013_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_4013 : public AComponent {
        private:
            Tristate _state1 = Undefined;
            Tristate _state2 = Undefined;
        public:
            C_4013();
            ~C_4013() override = default;

            void compute(std::size_t pin) override;
    };
}

#endif // C_4013_HPP
