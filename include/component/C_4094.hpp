
/*
** EPITECH PROJECT, 2023
** Some Project
** File description:
** C_4094.hpp
*/

#ifndef C_4094_HPP
#define C_4094_HPP

#include "../AComponent.hpp"

namespace nts
{
    class C_4094 : public AComponent {
        protected:
            std::string _data = "";
        public:
            C_4094();
            ~C_4094() override = default;

            void simulateComponent() override;
    };
}

#endif // C_4094_HPP
