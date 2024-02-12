
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_logger.cpp
*/

#include "../../include/component/C_logger.hpp"

nts::C_logger::C_logger() : AComponent("xor")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeClock);
    addPin(10, PinType::typeInput);
}

nts::C_logger::C_logger(const std::string &name) : AComponent("xor", name)
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeClock);
    addPin(10, PinType::typeInput);
}

void nts::C_logger::simulate()
{
    std::ofstream logfile("log.bin", std::ios::app);
    std::string data;
    nts::Tristate inhibit= (*getPin(10)).getState();

    if (inhibit == Tristate::False){
        for (size_t i = 0; i < 9; ++i) {
            if ((*getPin(i)).getState() == Tristate::True) {
                data += "1";
            } else if ((*getPin(i)).getState() == Tristate::False){
                data += "0";
            } else {
                data += "-1";
            }
        }
        if (logfile.is_open()) {
            logfile << data << std::endl;
            logfile.close();
        } else {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier log.bin" << std::endl;
        }
    }
}


/*void nts::C_logger::simulate(nts::Circuit &Circuit) {
    // Ouvrir le fichier log.bin en mode d'ajout
    std::ofstream logfile("log.bin", std::ios::app);

    // Vérifier si le fichier a été ouvert avec succès
    if (logfile.is_open()) {
        std::string data;

        // Parcourir les 9 premiers pins
        for (size_t i = 0; i < 9; ++i) {
            // Obtenir l'état du pin actuel
            nts::Tristate pinState = (*getPin(i)).getState();

            // Convertir l'état du pin en caractère et l'ajouter à la chaîne de données
            if (pinState == Tristate::True) {
                data += '1';
            } else if (pinState == Tristate::False) {
                data += '0';
            } else {
                data += '-';
            }
        }

        // Écrire les données dans le fichier log.bin
        logfile << data << std::endl;

        // Fermer le fichier
        logfile.close();
    } else {
        // Afficher un message d'erreur si le fichier n'a pas pu être ouvert
        std::cerr << "Erreur : Impossible d'ouvrir le fichier log.bin" << std::endl;
    }
}*/
