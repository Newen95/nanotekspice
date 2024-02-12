/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** error_handling.cpp
*/

#include "../include/main.hpp"
#include "../include/error_handling.hpp"

static int check_type(std::string type)
{
    if (type != "input" && type != "output" && type != "true" && type != "false" && type != "clock" && type != "and" && type != "or" && type != "xor" && type != "not" && type != "4001" && type != "4011" && type != "4030" && type != "4069" && type != "4071" && type != "4081" && type != "4008" && type != "4013" && type != "4017" && type != "4040" && type != "4094" && type != "4512" && type != "4514" && type != "4801" && type != "2716" && type != "logger") {
        std::cerr << "Erreur: Mauvais type de composant." << std::endl;
        return 84;
    }
    return 0;
}

static int check_name(std::string name, std::deque<std::string> &all_component_name)
{
    auto it = std::find(all_component_name.begin(), all_component_name.end(), name);
    if (it != all_component_name.end()) {
        std::cerr << "Erreur: Des composants ont le meme nom: '" << *it << "'." << std::endl;
        return 84;
    }
    return 0;
}

static int check_link_name(std::string name, std::deque<std::string> &all_component_name)
{
    auto it = std::find(all_component_name.begin(), all_component_name.end(), name);
    if (it == all_component_name.end()) {
        std::cerr << "Erreur: Mauvais nom de composant." << std::endl;
        return 84;
    }
    return 0;
}

static int check_link_pin(std::string pin)
{
    if (pin == "") {
        std::cerr << "Erreur: Pin manquant." << std::endl;
        return 84;
    }
    return 0;
}

static void add_component_to_list(std::deque<std::string> &all_component_name, std::string name)
{
    auto it = std::find(all_component_name.begin(), all_component_name.end(), name);
    if (it != all_component_name.end())
        return;
    else
        all_component_name.push_back(name);
    return;
}

static int parse_content(std::deque<std::string> &lines, std::deque<Component> &components, std::deque<std::string> &all_component_name)
{
    bool is_chipsets = false;
    bool is_links_section = false;

    for (const auto &line : lines) {
        if (line == ".chipsets:") {
            is_chipsets = true;
            continue;
        } if (!is_chipsets) {
            continue;
        } if (line == ".links:") {
            is_links_section = true;
            continue;
        }

        if (!is_links_section && !line.empty()) {
            Component new_component;
            size_t pos = line.find_first_of(" \t");
            if (pos != std::string::npos) {
                new_component.type = line.substr(0, pos);
                new_component.name = line.substr(pos + 1);
                new_component.links.clear();

                if (check_type(new_component.type) == 84 || check_name(new_component.name, all_component_name) == 84)
                    return 84;

                components.push_back(new_component);
                add_component_to_list(all_component_name, new_component.name);
            }
        } else if (is_links_section && !line.empty()) {
            std::istringstream iss(line);
            std::string component1, component2, component1_pin, component2_pin, component1_name, component2_name;
            while (iss >> component1 >> component2) {
                std::istringstream cmp1(component1);
                std::istringstream cmp2(component2);
                std::getline(cmp1, component1_name, ':');
                std::getline(cmp1, component1_pin);
                std::getline(cmp2, component2_name, ':');
                std::getline(cmp2, component2_pin);

                if (check_link_name(component1_name, all_component_name) == 84 || check_link_name(component2_name, all_component_name) == 84)
                    return 84;
                if (check_link_pin(component1_pin) == 84 || check_link_pin(component2_pin) == 84)
                    return 84;

                Links link1 {component1_pin, component2_name, component2_pin};
                Links link2 {component2_pin, component1_name, component1_pin};
                for (auto &comp : components) {
                    if (comp.name == component1_name)
                        comp.links.push_back(link1);
                    if (comp.name == component2_name)
                        comp.links.push_back(link2);
                }
            }
        }

        if (line.empty())
            break;
    }

    if (!is_chipsets) {
        std::cerr << "Erreur: Le parametre suivant n'est pas fournis '.chipsets'." << std::endl;
        return 84;
    }

    return 0;
}

static std::string remove_comments(const std::string &line)
{
    size_t pos_comment = line.find('#');
    std::string cleaned_line = (pos_comment != std::string::npos) ? line.substr(0, pos_comment) : line;

    size_t pos_last_non_space = cleaned_line.find_last_not_of(" \t");
    if (pos_last_non_space != std::string::npos) {
        cleaned_line.erase(pos_last_non_space + 1);
    } else {
        cleaned_line.clear();
    }

    return cleaned_line;
}

int error_handling(int ac, char **av, std::deque<Component> &components)
{
    std::deque<std::string> lines;
    std::deque<std::string> all_component_name;

    if (ac != 2) {
        std::cerr << "Erreur: Nombre d'arguments incorrect." << std::endl;
        return 84;
    }

    std::ifstream file(av[1]);
    if (!file.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier." << std::endl;
        return 84;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string cleaned_line = remove_comments(line);
        if (!cleaned_line.empty()) {
            lines.push_back(cleaned_line);
        }
    }

    file.close();

    return parse_content(lines, components, all_component_name);
}
