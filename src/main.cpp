/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** main.cpp
*/

#include "../include/main.hpp"
#include "../include/error_handling.hpp"
#include "../include/nanotekspice.hpp"

int main(int argc, char **argv)
{
    std::deque<Component> components;

    if (error_handling(argc, argv, components) == 84)
        return 84;

    int res = nanotekspice(components);
    return res;
}
