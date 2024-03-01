
    /*
    ** EPITECH PROJECT, 2023
    ** Some Project
    ** File description:
    ** C_4017.cpp
    */

    #include "../../include/component/C_4017.hpp"

    nts::C_4017::C_4017() : AComponent("4017")
    {
        addPin(1, PinType::typeOutput);
        addPin(2, PinType::typeOutput);
        addPin(3, PinType::typeOutput);
        addPin(4, PinType::typeOutput);
        addPin(5, PinType::typeOutput);
        addPin(6, PinType::typeOutput);
        addPin(7, PinType::typeOutput);
        addPin(8, PinType::typeIgnored);
        addPin(9, PinType::typeOutput);
        addPin(10, PinType::typeOutput);
        addPin(11, PinType::typeOutput);
        addPin(12, PinType::typeOutput);
        addPin(13, PinType::typeInput);
        addPin(14, PinType::typeInput);
        addPin(15, PinType::typeInput);
    }

    void nts::C_4017::getNextIndex(int index)
    {
        if (index == 1)
            _index = 5;
        else if (index == 2)
            _index = 4;
        else if (index == 3)
            _index = 2;
        else if (index == 4)
            _index = 7;
        else if (index == 5)
            _index = 6;
        else if (index == 6)
            _index = 9;
        else if (index == 7)
            _index = 10;
        else if (index == 9)
            _index = 11;
        else if (index == 10)
            _index = 1;
        else if (index == 11 || index == -1)
            _index = 3;
    }

    void nts::C_4017::compute(std::size_t pin)
    {
        bool _goAhead = false;

        getPin(pin)->setLock(true);
        getPin(3)->setLock(true);
        getPin(2)->setLock(true);
        getPin(4)->setLock(true);
        getPin(7)->setLock(true);
        getPin(10)->setLock(true);
        getPin(1)->setLock(true);
        getPin(5)->setLock(true);
        getPin(6)->setLock(true);
        getPin(9)->setLock(true);
        getPin(11)->setLock(true);
        getPin(12)->setLock(true);

        auto &_pin14 = getPin(14);
        if (_pin14->getLock() != true) {
            _pin14->setLock(true);
            for (auto& linkPtr : _pin14->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
        }

        auto &_pin13 = getPin(13);
        if (_pin13->getLock() != true) {
            _pin13->setLock(true);
            for (auto& linkPtr : _pin13->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
        }

        auto &_pin15 = getPin(15);
        if (_pin15->getLock() != true) {
            _pin15->setLock(true);
            for (auto& linkPtr : _pin15->getConnectedTo()) {
                IComponent* component = linkPtr->component;
                std::size_t pinNbr = linkPtr->pin;

                component->compute(pinNbr);
            }
        }

        Tristate in_0_state = this->getPin(14)->getState();
        Tristate in_1_state = this->getPin(13)->getState();
        Tristate in_r_state = this->getPin(15)->getState();

        if (in_0_state == True && in_r_state == True) {
            _goAhead = false;
            _bip = true;
        } else if (in_0_state == False || in_r_state == True) {
            _goAhead = false;
            _bip = false;
        } else if (in_0_state == True && in_1_state == False && _bip == false) {
            _goAhead = true;
            _bip = true;
        } else if (in_0_state == True && in_1_state == True) {
            _goAhead = false;
        }

        if (in_r_state == True) {
            for (int i = 1; i <= 12; i++) {
                if (i == 8)
                    continue;
                assignPinValue(i, False, this);
            }
            assignPinValue(3, True, this);
            assignPinValue(12, True, this);
            _index = 3;
        }

        if (_goAhead == true) {
            assignPinValue(12, True, this);
            getNextIndex(_index);

            if (_index == 1 || _index == 5 || _index == 6 || _index == 9 || _index == 11)
                assignPinValue(12, False, this);

            for (int i = 1; i <= 11; i++) {
                if (i == 8)
                    continue;
                if (i == _index)
                    assignPinValue(i, True, this);
                else
                    assignPinValue(i, False, this);
            }
        }
    }