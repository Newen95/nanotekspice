/*
** EPITECH PROJECT, 2023
** test-nano
** File description:
** window.hpp
*/

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "main.hpp"
#include "pin.hpp"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

struct Button {
    sf::RectangleShape _button;
    sf::Text _text;
};

struct Tick {
    sf::RectangleShape _button;
    sf::Text _tick;
};

struct TextBox {
    sf::RectangleShape _textBox;
    sf::Text _text;
};

struct ValidButton {
    sf::RectangleShape _button;
    sf::Text _text;
};

struct Pin {
    sf::CircleShape _pin;
    std::string _pinName;
    sf::Text _pinText;
};

struct ComponentGraph {
    sf::RectangleShape _base;
    sf::Text _componentName;
    std::vector<Pin> _pinList;
};

class Textbox {
    public:
        Textbox() {}
        Textbox(int size, sf::Color color, bool sel) {
            textbox.setCharacterSize(size);
            textbox.setFillColor(color);
            isSelected = sel;

            if (sel) {
                textbox.setString("_");
            } else {
                textbox.setString("");
            }
        }

        Textbox& operator=(const Textbox& other) {
        if (this != &other) {
            this->textbox = other.textbox;
            this->text.str(other.text.str());
            this->isSelected = other.isSelected;
            this->hasLimit = other.hasLimit;
            this->limit = other.limit;
        }
        return *this;
    }

        void setFont(sf::Font &font) {
            textbox.setFont(font);
        }

        void setPosition(sf::Vector2f pos) {
            textbox.setPosition(pos);
        }

        void setLimit(bool ToF) {
            hasLimit = ToF;
        }

        void setLimit(bool ToF, int lim) {
            hasLimit = ToF;
            limit = lim;
        }

        void setSelected(bool sel) {
            isSelected = sel;
            if (!sel) {
                std::string t = text.str();
                std::string newT = "";
                for (unsigned int i = 0; i < t.length(); i++) {
                    newT += t[i];
                }
                textbox.setString(newT);
            }
        }

        std::string getText() {
            return text.str();
        }

        bool getIsSelected() {
            return isSelected;
        }

        void drawTo(sf::RenderWindow &window) {
            window.draw(textbox);
        }

        void typedOn(sf::Event input) {
            if (isSelected) {
                int charTyped = input.text.unicode;
                if (charTyped < 128) {
                    if (hasLimit) {
                        if (text.str().length() <= limit) {
                            inputLogic(charTyped);
                        }
                        else if (text.str().length() > limit && charTyped == DELETE_KEY) {
                            deleteLastChar();
                        }
                    }
                    else {
                        inputLogic(charTyped);
                    }
                }
            }
        }

        void clearText() {
            std::string t = text.str();
            std::string newT = "";
            text.str("");
            text << newT;
            textbox.setString(text.str());
        }

    private:
        sf::Text textbox;
        std::ostringstream text;
        bool isSelected;
        bool hasLimit = false;
        unsigned int limit;

        void inputLogic(int charTyped) {
            if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
                text << static_cast<char>(charTyped);
            } else if (charTyped == DELETE_KEY) {
                if (text.str().length() > 0) {
                    deleteLastChar();
                }
            }
            textbox.setString(text.str() + "_");
        }

        void deleteLastChar() {
            std::string t = text.str();
            std::string newT = "";
            for (unsigned int i = 0; i < t.length() - 1; i++) {
                newT += t[i];
            }
            text.str("");
            text << newT;

            textbox.setString(text.str());
        }
};

class MainWindow {
    public:
        MainWindow();

        void run(nts::Circuit &circuit, std::string componentName);
        void processEvents(Textbox &_textBox, nts::Circuit &circuit, std::string componentName);
        void simulate(nts::Circuit &circuit);
        void display(nts::Circuit &circuit);
        void loop(const sf::Vector2f& mousePos, Textbox &_textBox, nts::Circuit &circuit, std::string componentName);
        void render(Textbox &_textBox);
        void handleButtonEvents(const sf::Vector2f& mousePos, Textbox &_textBox, nts::Circuit &circuit, std::string componentName);

        void createTrue();
        void createFalse();
        void create2Gate(nts::Circuit &circuit, std::string name);
        void create1Gate(nts::Circuit &circuit, std::string name);
        void create4040(nts::Circuit &circuit);
        void drawComponent();

    private:
        sf::RenderWindow m_window;
        sf::Font m_font;
        Button _simulateButton;
        Button _displayButton;
        Button _loopButton;
        Button _speedButton;
        Button _slowButton;
        Tick _tickShow;
        TextBox _inputTextBox;
        ValidButton _validButton;
        ComponentGraph _component;

        sf::Int32 _loopTime = 1000;
};

#endif // MAINWINDOW_HPP
