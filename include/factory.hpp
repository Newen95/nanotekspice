/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** factory.hpp
*/

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <string>
#include <memory>
#include <unordered_set>
#include <stdexcept>

#include "AComponent.hpp"

#include "component/C_true.hpp"
#include "component/C_false.hpp"

#include "component/C_output.hpp"
#include "component/C_input.hpp"

#include "component/C_xor.hpp"
#include "component/C_or.hpp"
#include "component/C_nor.hpp"
#include "component/C_not.hpp"
#include "component/C_nand.hpp"
#include "component/C_and.hpp"

#include "component/C_4001.hpp"
#include "component/C_4011.hpp"
#include "component/C_4030.hpp"
#include "component/C_4069.hpp"
#include "component/C_4071.hpp"
#include "component/C_4081.hpp"

#include "component/C_logger.hpp"
#include "component/C_clock.hpp"

std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

#endif // FACTORY_HPP

