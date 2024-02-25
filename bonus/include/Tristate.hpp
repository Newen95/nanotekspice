/*
** EPITECH PROJECT, 2023
** mdr
** File description:
** Tristate.hpp
*/

#ifndef TRISTATE_HPP
#define TRISTATE_HPP

namespace nts
{
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };
}

#endif // TRISTATE_HPP