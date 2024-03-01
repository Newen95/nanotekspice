
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_logger.cpp
*/

#include "../../include/component/C_logger.hpp"

nts::C_logger::C_logger() : AComponent("logger")
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

void nts::C_logger::compute(std::size_t pin)
{
    getPin(pin)->setLock(true);

    auto &_pin1 = getPin(1);
    if (_pin1->getLock() != true) {
        _pin1->setLock(true);
        for (auto& linkPtr : _pin1->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin2 = getPin(2);
    if (_pin2->getLock() != true) {
        _pin2->setLock(true);
        for (auto& linkPtr : _pin2->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin3 = getPin(3);
    if (_pin3->getLock() != true) {
        _pin3->setLock(true);
        for (auto& linkPtr : _pin3->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin4 = getPin(4);
    if (_pin4->getLock() != true) {
        _pin4->setLock(true);
        for (auto& linkPtr : _pin4->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin5 = getPin(5);
    if (_pin5->getLock() != true) {
        _pin5->setLock(true);
        for (auto& linkPtr : _pin5->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin6 = getPin(6);
    if (_pin6->getLock() != true) {
        _pin6->setLock(true);
        for (auto& linkPtr : _pin6->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin7 = getPin(7);
    if (_pin7->getLock() != true) {
        _pin7->setLock(true);
        for (auto& linkPtr : _pin7->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin8 = getPin(8);
    if (_pin8->getLock() != true) {
        _pin8->setLock(true);
        for (auto& linkPtr : _pin8->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }

    auto &_pin10 = getPin(10);
    if (_pin10->getLock() != true) {
        _pin10->setLock(true);
        for (auto& linkPtr : _pin10->getConnectedTo()) {
            IComponent* component = linkPtr->component;
            std::size_t pinNbr = linkPtr->pin;

            component->compute(pinNbr);
        }
    }



    std::ofstream logfile("log.bin", std::ios::out | std::ios::binary | std::ios::app);
    char to_write = 0; // Modifier le type de to_write en char pour stocker un caractère ASCII
    nts::Tristate inhibit = this->getPin(10)->getState();
    nts::Tristate state;

    if (inhibit == nts::False && this->getPin(9)->getState() == nts::True) {
        for (int i = 1; i <= 8; ++i) {
            state = this->getPin(i)->getState();
            if (state == nts::True) { // Modifier pour vérifier si l'état est True
                to_write += pow(2, (i - 1)); // Inverser l'ordre des bits
            } else if (state == nts::Undefined) {
                return; // Sortir de la fonction si un état est Undefined
            }
        }
        if (logfile.is_open()) {
            logfile.write(&to_write, 1); // Écrire le caractère dans le fichier binaire
            logfile.close();
        } else {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier log.bin" << std::endl;
        }
    }
}
