
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_nand.hpp
*/

#ifndef C_NAND_HPP
#define C_NAND_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_nand : public AComponent {
        public:
            C_nand();
            ~C_nand() override = default;

            void compute(std::size_t pin) override;
    };
}

#endif // C_NAND_HPP
