
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_output.hpp
*/

#ifndef C_OUTPUT_HPP
#define C_OUTPUT_HPP

#include "../AComponent.hpp"

namespace nts {

class C_output : public AComponent {
    protected:
        nts::Tristate _state;
    public:
        C_output(const std::string &name);
        ~C_output() override = default;
    };

}

#endif // C_OUTPUT_HPP
