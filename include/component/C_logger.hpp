/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_logger.hpp
*/

#ifndef C_LOGGER_HPP
#define C_LOGGER_HPP

#include "../main.hpp"

namespace nts {

class C_logger : public AComponent {
    public:
        C_logger();
        C_logger(const std::string &name);
        ~C_logger() override = default;

        void simulate(Circuit &circuit __attribute_maybe_unused__) { return; }
    };

}


#endif // C_LOGGER_HPP

