/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** nanotekspice.cpp
*/

#include "../include/nanotekspice.hpp"

void printComponentMap(const std::map<std::string, std::unique_ptr<nts::AComponent>> &componentMap)
{
    std::cout << "Component Map:" << std::endl;
    for (const auto &pair : componentMap) {
        const std::string &name = pair.first;
        const nts::AComponent &component = *(pair.second);

        std::cout << "Component name: " << name << std::endl;
        std::cout << "Component type: " << component.getType() << std::endl << std::endl;;
    }
}

static int create_all_component_and_pins(std::deque<Component> &components, std::map<std::string, std::unique_ptr<nts::AComponent>> &componentMap)
{
    for (const auto &component : components) {
        std::string componentName = component.name;
        std::unique_ptr<nts::AComponent> cComponent;

        if (component.type == "and") {
            cComponent = std::make_unique<nts::C_and>(componentName);
        } else if (component.type == "or") {
            cComponent = std::make_unique<nts::C_or>(componentName);
        } else if (component.type == "xor") {
            cComponent = std::make_unique<nts::C_xor>(componentName);
        } else if (component.type == "2716") {
            cComponent = std::make_unique<nts::C_2716>(componentName);
        } else if (component.type == "4011") {
            cComponent = std::make_unique<nts::C_4011>(componentName);
        } else if (component.type == "4030") {
            cComponent = std::make_unique<nts::C_4030>(componentName);
        } else if (component.type == "4071") {
            cComponent = std::make_unique<nts::C_4071>(componentName);
        } else if (component.type == "4512") {
            cComponent = std::make_unique<nts::C_4512>(componentName);
        } else if (component.type == "4001") {
            cComponent = std::make_unique<nts::C_4001>(componentName);
        } else if (component.type == "4013") {
            cComponent = std::make_unique<nts::C_4013>(componentName);
        } else if (component.type == "4040") {
            cComponent = std::make_unique<nts::C_4040>(componentName);
        } else if (component.type == "4081") {
            cComponent = std::make_unique<nts::C_4081>(componentName);
        } else if (component.type == "4514") {
            cComponent = std::make_unique<nts::C_4514>(componentName);
        } else if (component.type == "clock") {
            cComponent = std::make_unique<nts::C_clock>(componentName);
        } else if (component.type == "not") {
            cComponent = std::make_unique<nts::C_not>(componentName);
        } else if (component.type == "true") {
            cComponent = std::make_unique<nts::C_true>(componentName);
        } else if (component.type == "4008") {
            cComponent = std::make_unique<nts::C_4008>(componentName);
        } else if (component.type == "4017") {
            cComponent = std::make_unique<nts::C_4017>(componentName);
        } else if (component.type == "4069") {
            cComponent = std::make_unique<nts::C_4069>(componentName);
        } else if (component.type == "4094") {
            cComponent = std::make_unique<nts::C_4094>(componentName);
        } else if (component.type == "4801") {
            cComponent = std::make_unique<nts::C_4801>(componentName);
        } else if (component.type == "false") {
            cComponent = std::make_unique<nts::C_false>(componentName);
        } else if (component.type == "input") {
            cComponent = std::make_unique<nts::C_input>(componentName);
        } else if (component.type == "output") {
            cComponent = std::make_unique<nts::C_output>(componentName);
        } else {
            std::cerr << "Type de composant non pris en charge : " << component.type << std::endl;
        }
        componentMap[componentName] = std::move(cComponent);
    }
    return 0;
}

int nanotekspice(std::deque<Component> &components)
{
    std::map<std::string, std::unique_ptr<nts::AComponent>> componentMap;

    if (create_all_component_and_pins(components, componentMap) == 84)
        return 84;

    printComponentMap(componentMap);

    return 0;
}
