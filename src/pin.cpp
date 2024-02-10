/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** pin.cpp
*/

#include "../include/pin.hpp"

nts::Pin::Pin(PinType type) : _type(type)
{}

std::list<std::unique_ptr<nts::Link>> &nts::Pin::getConnectedTo()
{
    return _connectedTo;
}
