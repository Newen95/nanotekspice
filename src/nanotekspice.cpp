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
        std::cout << "Component type: " << component.getType() << std::endl;

        for (const auto &pinPair : component.getPins()) {
            int pinNumber = pinPair.first;
            const auto &pinPtr = *pinPair.second;
            const auto &pinPtr_ = pinPair.second;

            std::cout << "Pin: " << pinNumber << " Type: " << pinPtr.getPinType() << std::endl;
            const auto &connectedTo = pinPtr_->getConnectedTo();
            for (const auto &link : connectedTo) {
                std::cout << "  Linked to component: " << link->component << ", pin: " << link->pin << std::endl;
            }
        }

        std::cout << std::endl;
    }
}

static int create_all_component(std::deque<Component> &components, std::map<std::string, std::unique_ptr<nts::AComponent>> &componentMap)
{
    for (const auto &component : components) {
        std::string componentName = component.name;
        std::unique_ptr<nts::AComponent> cComponent;

        cComponent = createComponent(component.type, component.name);
        componentMap[componentName] = std::move(cComponent);
    }
    return 0;
}

static int create_all_link(std::deque<Component> &components, std::map<std::string, std::unique_ptr<nts::AComponent>> &componentMap)
{
    for (const auto &component : components) {
        std::string Name = component.name;

        for (const auto &link : component.links) {
            auto it = componentMap.find(link.link_component_name);
            auto at = componentMap.find(Name);

            if (it != componentMap.end() && at != componentMap.end()) {
                nts::AComponent &component_to_link = *(it->second);
                nts::AComponent &component_actual = *(at->second);
                std::size_t pin_to_link = std::stoul(link.link_component_pin);
                std::size_t pin_actual = std::stoul(link.pin);

                component_actual.setLink(pin_actual, component_to_link, pin_to_link);
            }
        }
    }
    return 0;
}

static nts::Tristate accessPinValue(const std::map<std::string, std::unique_ptr<nts::AComponent>> &components, const std::string &componentName)
{
    auto it = components.find(componentName);
    if (it != components.end()) {
        nts::AComponent *component = it->second.get();
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
        const nts::AComponent &component = *(componentPair.second);

        if (component.getType() == "input" || component.getType() == "clock") {
            inputList.push_back(component.getName());
        } else if (component.getType() == "output") {
            outputList.push_back(component.getName());
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
        nts::AComponent *component = it->second.get();
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
                if (valueStr == "1")
                    pin1->setNextState(nts::True);
                if (valueStr == "0")
                    pin1->setNextState(nts::False);
                if (valueStr == "U")
                    pin1->setNextState(nts::Undefined);
            }
        }
    }
}

static void simulate(nts::Circuit &circuit)
{
    const auto &components = circuit.getComponentMap();
    circuit.setTick(circuit.getTick() + 1);

    for (const auto &componentPair : components) {
        nts::AComponent *component = componentPair.second.get();
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
        nts::AComponent *component = componentPair.second.get();
        if (component) {
            if (component->getType() == "or") {
                nts::C_or *comp = dynamic_cast<nts::C_or*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "xor") {
                nts::C_xor *comp = dynamic_cast<nts::C_xor*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "and") {
                nts::C_and *comp = dynamic_cast<nts::C_and*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "not") {
                nts::C_not *comp = dynamic_cast<nts::C_not*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "nor") {
                nts::C_nor *comp = dynamic_cast<nts::C_nor*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "nand") {
                nts::C_nand *comp = dynamic_cast<nts::C_nand*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "4001") {
                nts::C_4001 *comp = dynamic_cast<nts::C_4001*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "4011") {
                nts::C_4011 *comp = dynamic_cast<nts::C_4011*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "4069") {
                nts::C_4069 *comp = dynamic_cast<nts::C_4069*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "4071") {
                nts::C_4071 *comp = dynamic_cast<nts::C_4071*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "4081") {
                nts::C_4081 *comp = dynamic_cast<nts::C_4081*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "clock") {
                nts::C_clock *comp = dynamic_cast<nts::C_clock*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "logger") {
                nts::C_logger *comp = dynamic_cast<nts::C_logger*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "4008") {
                nts::C_4008 *comp = dynamic_cast<nts::C_4008*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "4013") {
                nts::C_4013 *comp = dynamic_cast<nts::C_4013*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "4017") {
                nts::C_4017 *comp = dynamic_cast<nts::C_4017*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "input") {
                nts::C_input *comp = dynamic_cast<nts::C_input*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "true") {
                nts::C_true *comp = dynamic_cast<nts::C_true*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "false") {
                nts::C_false *comp = dynamic_cast<nts::C_false*>(component);
                comp->simulate(circuit);
            } else if (component->getType() == "4030") {
                nts::C_4030 *comp = dynamic_cast<nts::C_4030*>(component);
                comp->simulate(circuit);
            }
        }
    }

}

int nanotekspice(std::deque<Component> &components)
{
    std::map<std::string, std::unique_ptr<nts::AComponent>> componentMap;

    if (create_all_component(components, componentMap) == 84 || create_all_link(components, componentMap) == 84)
        return 84;

    nts::Circuit circuit;
    circuit.setComponentMap(std::move(componentMap));
    std::string input;

    const auto &map = circuit.getComponentMap();
    for (const auto &cmp : map) {
        if (cmp.second.get()->getType() == "false") {
            const auto &f = cmp.second.get()->getPin(1).get()->getConnectedTo();
            for (const auto &tmp : f) {
                std::string component_name = tmp.get()->component;
                std::size_t component_pin = tmp.get()->pin;
                map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(nts::False);
            }
        } if (cmp.second.get()->getType() == "true") {
            const auto &f = cmp.second.get()->getPin(1).get()->getConnectedTo();
            for (const auto &tmp : f) {
                std::string component_name = tmp.get()->component;
                std::size_t component_pin = tmp.get()->pin;
                map.find(component_name)->second.get()->getPins().find(component_pin)->second.get()->setState(nts::True);
            }
        }
    }

    while (true) {
        std::cout << "> ";
        if (input == "exit" || !std::getline(std::cin, input) || std::cin.eof())
            return 0;
        if (input == "display")
            display(circuit);
        if (input == "simulate")
            simulate(circuit);
        if (input == "loop") {
            while (true) {
                simulate(circuit);
                display(circuit);
                attributeValue(input, circuit);
            }
        }
        attributeValue(input, circuit);
    }

    return 0;
}
