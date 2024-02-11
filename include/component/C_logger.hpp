
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_logger.hpp
*/

#ifndef C_LOGGER_HPP
#define C_LOGGER_HPP

#include "../AComponent.hpp"

namespace nts {

class C_logger : public AComponent {
    public:
        C_logger(const std::string &name);
        ~C_logger() override = default;
    };

}


#endif // C_LOGGER_HPP

