/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** nanotekspice.cpp
*/

#include "../include/nanotekspice.hpp"

int nanotekspice(std::deque<Component> &components __attribute_maybe_unused__)
{
    std::string input;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "exit")
            return 0;
    }
    return 0;
}