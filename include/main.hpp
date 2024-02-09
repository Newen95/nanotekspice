/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** main.hpp
*/

#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <deque>
#include <string>

struct Links {
    std::string pin;
    std::string link_component_name;
    std::string link_component_pin;
};

struct Component {
    std::string name;
    std::string type;
    std::deque<Links> links;
};

#endif // MAIN_HPP
