
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4801.cpp
*/

#include "../../include/component/C_4801.hpp"

nts::C_4801::C_4801() : AComponent("4801")
{
    addPin(1, PinType::typeInput);
    addPin(2, PinType::typeInput);
    addPin(3, PinType::typeInput);
    addPin(4, PinType::typeInput);
    addPin(5, PinType::typeInput);
    addPin(6, PinType::typeInput);
    addPin(7, PinType::typeInput);
    addPin(8, PinType::typeInput);
    addPin(9, PinType::typeInOut);
    addPin(10, PinType::typeInOut);
    addPin(11, PinType::typeInOut);
    addPin(12, PinType::typeIgnored);
    addPin(13, PinType::typeInOut);
    addPin(14, PinType::typeInOut);
    addPin(15, PinType::typeInOut);
    addPin(16, PinType::typeInOut);
    addPin(17, PinType::typeInOut);
    addPin(18, PinType::typeInput);
    addPin(19, PinType::typeIgnored);
    addPin(20, PinType::typeInput);
    addPin(21, PinType::typeInput);
    addPin(22, PinType::typeInput);
    addPin(23, PinType::typeInput);
    addPin(24, PinType::typeIgnored);
}

void nts::C_4801::compute(std::size_t pin)
{
    getPin(pin)->setLock(true);

    Tristate enableState = this->getPin(18)->getState();
    Tristate writeState = this->getPin(21)->getState();
    Tristate readState = this->getPin(20)->getState();

    std::string address;
    for (int i = 0; i < 10; ++i) {
        address += std::to_string(this->getPin(i + 1)->getState());
    }

    int decimalAddress = std::stoi(address, nullptr, 2);

    if (enableState == True) {
        if (writeState == True) {
            std::string inputData;
            for (int i = 0; i < 8; ++i) {
                Tristate inputState = this->getPin(i + 9)->getState();
                inputData += std::to_string(inputState);
            }
            ram[decimalAddress] = inputData;
        }
        else if (readState == True) {
            std::string outputData = ram[decimalAddress];
            for (int i = 0; i < 8; ++i) {
                Tristate outputState = outputData[i] == '1' ? True : False;
                this->getPin(i + 9)->setState(outputState);
            }
        }
    }
}
