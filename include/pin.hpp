/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-tom.blancheton
** File description:
** pin.hpp
*/

#ifndef PIN_HPP
#define PIN_HPP

#include <string>
#include <list>
#include <memory>

#include "IComponent.hpp"
#include "Tristate.hpp"
#include "main.hpp"

namespace nts
{
    enum PinType {
        typeInput,
        typeOutput,
        typeInOut,
        typeFalse,
        typeTrue,
        typeClock,
        typeIgnored,
        typeOther
    };

    struct Link
    {
        IComponent *component;
        std::size_t pin;
    };

    class Pin {
        protected:
            PinType _type;
            std::list<std::unique_ptr<Link>> _connectedTo;
            Tristate _state = Undefined;
            Tristate _nexState = Undefined;
            bool _isLock;
            bool _Lock = false;
            bool _ScdLock = false;

        public:
            Pin(PinType type);
            ~Pin() = default;

            const PinType &getPinType() const;
            const Tristate &getState() const;
            const Tristate &getNextState() const;
            std::list<std::unique_ptr<Link>> &getConnectedTo();
            const bool &getIsLock() const;
            const bool &getLock() const;
            const bool &getScdLock() const;

            void setState(const Tristate state);
            void setNextState(const Tristate state);
            void setOutState(const Tristate state);
            void setOutNextState(const Tristate state);
            void setIsLock(const bool state);
            void setLock(const bool state);
            void setScdLock(const bool state);
    };
}

#endif // PIN_HPP
