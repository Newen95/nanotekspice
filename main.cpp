/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** main.cpp
*/

#include "include/main.hpp"
#include "include/error_handling.hpp"

int main(int argc, char **argv)
{
    std::deque<Component> components;

    if (error_handling(argc, argv, components) == 84)
        return 84;

    for (const auto &component : components) {
        std::cout << "NAME: '" << component.name << "' TYPE: '" << component.type << "'" << std::endl;
        std::cout << "LINKS:" << std::endl;
        for (const auto &link : component.links) {
            std::cout << "pin: '" << link.pin << "'\tCMPnom: '" << link.link_component_name << "' CMPpin: '" << link.link_component_pin << "'" << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
