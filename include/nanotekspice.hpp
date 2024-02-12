/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** nanotekspice.hpp
*/

#ifndef NANOTEKSPICE_HPP
#define NANOTEKSPICE_HPP

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "AComponent.hpp"
#include "main.hpp"
#include "pin.hpp"

#include "component/C_2716.hpp"
#include "component/C_4011.hpp"
#include "component/C_4030.hpp"
#include "component/C_4071.hpp"
#include "component/C_4512.hpp"
#include "component/C_4001.hpp"
#include "component/C_4013.hpp"
#include "component/C_4040.hpp"
#include "component/C_4081.hpp"
#include "component/C_4514.hpp"
#include "component/C_4008.hpp"
#include "component/C_4017.hpp"
#include "component/C_4069.hpp"
#include "component/C_4094.hpp"
#include "component/C_4801.hpp"
#include "component/C_and.hpp"
#include "component/C_input.hpp"
#include "component/C_output.hpp"
#include "component/C_clock.hpp"
#include "component/C_not.hpp"
#include "component/C_true.hpp"
#include "component/C_false.hpp"
#include "component/C_or.hpp"
#include "component/C_xor.hpp"
#include "component/C_nor.hpp"
#include "component/C_nand.hpp"
#include "component/C_logger.hpp"

int nanotekspice(std::deque<Component> &components);

#endif // NANOTEKSPICE_HPP