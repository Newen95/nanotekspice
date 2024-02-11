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
#include "pin.hpp"
#include "AComponent.hpp"
#include <map>

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

namespace nts {
    class Circuit {
        protected:
            std::map<std::string, std::unique_ptr<AComponent>> _componentMap;
            std::size_t _tick;
        public:
            Circuit() : _tick(0) {}
            ~Circuit() = default;

            void setComponentMap(std::map<std::string, std::unique_ptr<AComponent>> map)
            {
                _componentMap = std::move(map);
            }

            void setTick(std::size_t tick)
            {
                _tick = tick;
            }

            std::size_t getTick() const
            {
                return _tick;
            }

            const std::map<std::string, std::unique_ptr<AComponent>> &getComponentMap() const
            {
                return _componentMap;
            }

    };
}

#endif // MAIN_HPP
