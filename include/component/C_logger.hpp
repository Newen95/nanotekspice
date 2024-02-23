/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_logger.hpp
*/

#ifndef C_LOGGER_HPP
#define C_LOGGER_HPP

#include <fstream>
#include <cmath>
#include "../AComponent.hpp"

namespace nts
{
    class C_logger : public AComponent {
        public:
            C_logger();
            ~C_logger() override = default;

            int convertBoolToDecimal(bool boolArray[8]);
            void simulateComponent() override;
    };
}

#endif // C_LOGGER_HPP
