/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** nanotekspice.cpp
*/

#include "../include/nanotekspice.hpp"
#include "../include/window.hpp"

static int create_all_component(std::deque<Component> &components, std::map<std::string, std::unique_ptr<nts::IComponent>> &componentMap)
{
    for (const auto &component : components) {
        std::string componentName = component.name;
        std::unique_ptr<nts::IComponent> new_component;

        new_component = createComponent(component.type);
        componentMap[componentName] = std::move(new_component);
    }
    return 0;
}

static int create_all_link(std::deque<Component> &components, std::map<std::string, std::unique_ptr<nts::IComponent>> &componentMap)
{
    for (const auto &component : components) {
        std::string current_component_name = component.name;
        auto at = componentMap.find(current_component_name);

        for (const auto &link : component.links) {
            auto it = componentMap.find(link.link_component_name);

            if (it != componentMap.end() && at != componentMap.end()) {
                nts::IComponent &component_to_link = *(it->second);
                nts::IComponent &component_actual = *(at->second);
                std::size_t pin_to_link = std::stoul(link.link_component_pin);
                std::size_t pin_actual = std::stoul(link.pin);

                component_actual.setLink(pin_actual, component_to_link, pin_to_link);
            }
        }
    }
    return 0;
}

int nanotekspice(std::deque<Component> &components, char *name)
{
    std::string input;
    nts::Circuit circuit;
    std::map<std::string, std::unique_ptr<nts::IComponent>> componentMap;

    if (create_all_component(components, componentMap) == 84 || create_all_link(components, componentMap) == 84)
        return 84;

    circuit.setComponentMap(std::move(componentMap));

    for (const auto &cmp : circuit.getComponentMap()) {
        if (cmp.second.get()->getType() == "false") {
            cmp.second.get()->assignPinValue(1, nts::False, cmp.second.get());
        } if (cmp.second.get()->getType() == "true") {
            cmp.second.get()->assignPinValue(1, nts::True, cmp.second.get());
        }
    }

    MainWindow mainWindow;
    mainWindow.run(circuit, name);
    return 0;
}
