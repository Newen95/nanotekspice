/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** nanotekspice.cpp
*/

#include "../include/nanotekspice.hpp"

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

static nts::Tristate accessPinValue(const std::map<std::string, std::unique_ptr<nts::IComponent>> &components, const std::string &componentName)
{
    auto it = components.find(componentName);
    if (it != components.end()) {
        nts::IComponent *component = it->second.get();
        if (component) {
            const std::map<int, std::unique_ptr<nts::Pin>> &pinsMap = component->getPins();
            auto pinIt = pinsMap.find(1);
            if (pinIt != pinsMap.end()) {
                nts::Pin *pin1 = pinIt->second.get();
                if (pin1) {
                    return pin1->getState();
                }
            }
        }
    }
    return nts::Undefined;
}

static void display(nts::Circuit &circuit)
{
    const auto &components = circuit.getComponentMap();

    std::cout << "tick: " << circuit.getTick() << std::endl;

    std::vector<std::string> inputList;
    std::vector<std::string> outputList;

    for (const auto &componentPair : components) {
        const std::string &componentName = componentPair.first;
        const std::string &componentType = componentPair.second->getType();

        if (componentType == "input" || componentType == "clock") {
            inputList.push_back(componentName);
        } else if (componentType == "output") {
                outputList.push_back(componentName);
        }
    }

    std::sort(inputList.begin(), inputList.end());
    std::sort(outputList.begin(), outputList.end());

    nts::Tristate state;
    std::string value;
    std::cout << "input(s):" << std::endl;
    for (const auto &name : inputList) {
        state = accessPinValue(components, name);
        if (state == nts::Undefined)
            value = "U";
        else if (state == nts::True)
            value = "1";
        else
            value = "0";
        std::cout << "  " << name << ": " << value << std::endl;
    }

    std::cout << "output(s):" << std::endl;
    for (const auto &name : outputList) {
        state = accessPinValue(components, name);
        if (state == nts::Undefined)
            value = "U";
        else if (state == nts::True)
            value = "1";
        else
            value = "0";
        std::cout << "  " << name << ": " << value << std::endl;
    }
}

static void attributeValue(std::string input, nts::Circuit &circuit)
{
    const auto &components = circuit.getComponentMap();

    size_t equalPos = input.find('=');
    if (equalPos == std::string::npos)
        return;

    const std::string name = input.substr(0, equalPos);
    const std::string valueStr = input.substr(equalPos + 1);

    if (valueStr != "1" && valueStr != "0" && valueStr != "U") {
        std::cerr << "Erreur : mauvaise valeur. (0, 1 ou U)" << valueStr << std::endl;
        return;
    }

    accessPinValue(components, name);

    auto it = components.find(name);
    if (it != components.end()) {
        nts::IComponent *component = it->second.get();
        if (!component) {
            std::cerr << "Erreur : attributeValue() : composant inacessible." << std::endl;
            return;
        } if (component->getType() != "input" && component->getType() != "clock") {
            std::cerr << "Erreur : Assignation possible uniquement sur les input." << std::endl;
            return;
        }
        const std::map<int, std::unique_ptr<nts::Pin>> &pinsMap = component->getPins();
        auto pinIt = pinsMap.find(1);
        if (pinIt != pinsMap.end()) {
            nts::Pin *pin1 = pinIt->second.get();
            if (pin1) {
                if (valueStr == "1") {
                    pin1->setNextState(nts::True);
                    pin1->setOutNextState(nts::True);
                } if (valueStr == "0") {
                    pin1->setNextState(nts::False);
                    pin1->setOutNextState(nts::False);
                } if (valueStr == "U") {
                    pin1->setNextState(nts::Undefined);
                    pin1->setOutNextState(nts::Undefined);
                }
            }
        }
    }
}

void simulateTick(nts::Circuit &circuit)
{
    const auto &components = circuit.getComponentMap();
    circuit.setTick(circuit.getTick() + 1);

    for (const auto &componentPair : components) {
        nts::IComponent *component = componentPair.second.get();
        component->setIsLock(false);
        for (const auto &pin : component->getPins()) {
            const auto &_pin = pin.second.get();
            _pin->setIsLock(false);
        }
    }

    for (const auto &componentPair : components) {
        nts::IComponent *component = componentPair.second.get();
        if (component) {
            const std::map<int, std::unique_ptr<nts::Pin>> &pinsMap = component->getPins();
            for (const auto &pinPair : pinsMap) {
                nts::Pin *pin = pinPair.second.get();
                if (pin->getPinType() == nts::typeOutput) {
                    pin->setState(pin->getNextState());
                }
            }
        }
    }

    for (const auto &componentPair : components) {
        nts::IComponent *component = componentPair.second.get();
        component->simulate(1);
    }
}

int nanotekspice(std::deque<Component> &components)
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

    while (true) {
        std::cout << "> ";
        if (input == "exit" || !std::getline(std::cin, input) || std::cin.eof())
            return 0;
        if (input == "display")
            display(circuit);
        if (input == "simulate")
            simulateTick(circuit);
        if (input == "loop") {
            while (true) {
                simulateTick(circuit);
                display(circuit);
                attributeValue(input, circuit);
            }
        }
        attributeValue(input, circuit);
    }

    return 0;
}
