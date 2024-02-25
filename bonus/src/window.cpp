/*
** EPITECH PROJECT, 2023
** test-nano
** File description:
** window.cpp
*/

#include "../include/window.hpp"
#include <unistd.h>
#include <chrono>
#include <thread>

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


// WINDOW


MainWindow::MainWindow() : m_window(sf::VideoMode(1000, 600), "NanoTekSpice")
{
    m_window.setFramerateLimit(30);

    // SET FONT
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::string fontPath = std::string(cwd) + "/utils/DMSans.ttf";
        m_font.loadFromFile(fontPath);
    }

    // SIMULATE BUTTON
    _simulateButton._text.setFont(m_font);
    _simulateButton._text.setCharacterSize(30);
    _simulateButton._text.setFillColor(sf::Color::White);
    _simulateButton._text.setString("Simulate");
    _simulateButton._text.setStyle(sf::Text::Bold);
    sf::FloatRect textBounds = _simulateButton._text.getLocalBounds();
    _simulateButton._text.setPosition(50 + (250 - textBounds.width) / 2, 100 + (35 - textBounds.height) / 2);

    _simulateButton._button.setSize(sf::Vector2f(250, 50));
    _simulateButton._button.setFillColor(sf::Color(180, 50, 50));
    _simulateButton._button.setPosition(50, 100);

    // DISPLAY BUTTON
    _displayButton._text.setFont(m_font);
    _displayButton._text.setCharacterSize(30);
    _displayButton._text.setFillColor(sf::Color::White);
    _displayButton._text.setString("Display");
    _displayButton._text.setStyle(sf::Text::Bold);
    textBounds = _displayButton._text.getLocalBounds();
    _displayButton._text.setPosition(50 + (250 - textBounds.width) / 2, 170 + (35 - textBounds.height) / 2);

    _displayButton._button.setSize(sf::Vector2f(250, 50));
    _displayButton._button.setFillColor(sf::Color(50, 50, 50));
    _displayButton._button.setPosition(50, 170);

    // LOOP BUTTON
    _loopButton._text.setFont(m_font);
    _loopButton._text.setCharacterSize(30);
    _loopButton._text.setFillColor(sf::Color::White);
    _loopButton._text.setString("Loop");
    _loopButton._text.setStyle(sf::Text::Bold);
    textBounds = _loopButton._text.getLocalBounds();
    _loopButton._text.setPosition(50 + (250 - textBounds.width) / 2, 240 + (35 - textBounds.height) / 2);

    _loopButton._button.setSize(sf::Vector2f(250, 50));
    _loopButton._button.setFillColor(sf::Color(50, 50, 50));
    _loopButton._button.setPosition(50, 240);

    // SPEED BUTTON
    _speedButton._text.setFont(m_font);
    _speedButton._text.setCharacterSize(30);
    _speedButton._text.setFillColor(sf::Color::White);
    _speedButton._text.setString("speed");
    _speedButton._text.setStyle(sf::Text::Bold);
    textBounds = _speedButton._text.getLocalBounds();
    _speedButton._text.setPosition(50 + (100 - textBounds.width) / 2, 310 + (35 - textBounds.height) / 2);

    _speedButton._button.setSize(sf::Vector2f(100, 50));
    _speedButton._button.setFillColor(sf::Color(50, 50, 50));
    _speedButton._button.setPosition(50, 310);

    // SLOW BUTTON
    _slowButton._text.setFont(m_font);
    _slowButton._text.setCharacterSize(30);
    _slowButton._text.setFillColor(sf::Color::White);
    _slowButton._text.setString("slow");
    _slowButton._text.setStyle(sf::Text::Bold);
    textBounds = _slowButton._text.getLocalBounds();
    _slowButton._text.setPosition(200 + (100 - textBounds.width) / 2, 310 + (35 - textBounds.height) / 2);

    _slowButton._button.setSize(sf::Vector2f(100, 50));
    _slowButton._button.setFillColor(sf::Color(50, 50, 50));
    _slowButton._button.setPosition(200, 310);

    // TICK BUTTON
    _tickShow._tick.setFont(m_font);
    _tickShow._tick.setCharacterSize(30);
    _tickShow._tick.setFillColor(sf::Color::White);
    _tickShow._tick.setString("0");
    float textLength = _tickShow._tick.getGlobalBounds().width;
    textBounds = _tickShow._tick.getLocalBounds();
    _tickShow._tick.setPosition((100 + 250 - textLength) / 2, 380 + (32 - textBounds.height) / 2);

    _tickShow._button.setSize(sf::Vector2f(250, 50));
    _tickShow._button.setFillColor(sf::Color(50, 50, 50));
    _tickShow._button.setPosition(50, 380);

    // INPUT BUTTON
    _inputTextBox._text.setFont(m_font);
    _inputTextBox._text.setCharacterSize(30);
    _inputTextBox._text.setFillColor(sf::Color::Black);
    _inputTextBox._text.setString("");
    _inputTextBox._text.setStyle(sf::Text::Regular);
    _inputTextBox._text.setPosition((100 + 250 - textLength) / 2, 450 + (32 - textBounds.height) / 2);

    _inputTextBox._textBox.setSize(sf::Vector2f(185, 50));
    _inputTextBox._textBox.setFillColor(sf::Color(50, 50, 50));
    _inputTextBox._textBox.setPosition(50, 450);

    // VALIDBUTTON
    _validButton._button.setSize(sf::Vector2f(50, 50));
    _validButton._button.setFillColor(sf::Color(50, 50, 50));
    _validButton._button.setPosition(250, 450);
}

void MainWindow::processEvents(Textbox &_textBox, nts::Circuit &circuit, std::string componentName)
{
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_window.close();
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left)
                handleButtonEvents(sf::Vector2f(event.mouseButton.x, event.mouseButton.y), _textBox, circuit, componentName);
        } else if (event.type == sf::Event::TextEntered) {
            _textBox.typedOn(event);
        }
    }
}

void MainWindow::simulate(nts::Circuit &circuit)
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

void MainWindow::display(nts::Circuit &circuit)
{
    for (const auto &cmp : circuit.getComponentMap()) {
        nts::IComponent *component = cmp.second.get();
        std::string name = cmp.first;

        for (const auto &compPin : component->getPins()) {
            nts::Tristate state = compPin.second->getState();
            for (Pin& pin : _component._pinList) {
                if (pin._pinName == name) {
                    if (state == nts::True)
                        pin._pin.setFillColor(sf::Color::Blue);
                    else if (state == nts::False)
                        pin._pin.setFillColor(sf::Color::White);
                    else
                        pin._pin.setFillColor(sf::Color::Magenta);
                }
            }
        }
    }
}

void MainWindow::render(Textbox &_textBox)
{
    // Couleur de fond
    m_window.clear(sf::Color(80, 80, 80));

    // Affichage des bouttons
    m_window.draw(_simulateButton._button);
    m_window.draw(_displayButton._button);
    m_window.draw(_loopButton._button);
    m_window.draw(_slowButton._button);
    m_window.draw(_speedButton._button);
    m_window.draw(_simulateButton._text);
    m_window.draw(_displayButton._text);
    m_window.draw(_loopButton._text);
    m_window.draw(_slowButton._text);
    m_window.draw(_speedButton._text);

    m_window.draw(_tickShow._button);
    m_window.draw(_tickShow._tick);

    m_window.draw(_inputTextBox._textBox);
    m_window.draw(_inputTextBox._text);

    m_window.draw(_validButton._button);
    m_window.draw(_validButton._text);

    _textBox.drawTo(m_window);

    // Affichage de la séparation
    sf::RectangleShape rectangle(sf::Vector2f(5, 600));
    rectangle.setFillColor(sf::Color(255, 255, 255));
    rectangle.setPosition(350, 0);
    m_window.draw(rectangle);

    drawComponent();
    m_window.display();
}

void MainWindow::loop(const sf::Vector2f& mousePos, Textbox &_textBox, nts::Circuit &circuit, std::string componentName)
{
    while (true) {
        simulate(circuit);
        int tickValue = std::stoi(_tickShow._tick.getString().toAnsiString());
        tickValue++;
        _tickShow._tick.setString(std::to_string(tickValue));
        display(circuit);
        sf::Clock clock;
        sf::Time startTime = clock.getElapsedTime();

        while (clock.getElapsedTime() - startTime < sf::milliseconds(_loopTime) &&
            _loopButton._button.getGlobalBounds().contains(mousePos)) {
            processEvents(_textBox, circuit, componentName);
            render(_textBox);
        }
    }
}

void MainWindow::handleButtonEvents(const sf::Vector2f& mousePos, Textbox &_textBox, nts::Circuit &circuit, std::string componentName)
{
    if (_simulateButton._button.getGlobalBounds().contains(mousePos)) {
        std::cout << "Simulate button clicked!" << std::endl;
        simulate(circuit);

        int tickValue = std::stoi(_tickShow._tick.getString().toAnsiString());
        tickValue++;
        _tickShow._tick.setString(std::to_string(tickValue));

        // Surbrillance
        _simulateButton._button.setFillColor(sf::Color(220, 50, 50));
        sf::Clock clock;
        sf::Time startTime = clock.getElapsedTime();

        while (clock.getElapsedTime() - startTime < sf::milliseconds(300) &&
            _simulateButton._button.getGlobalBounds().contains(mousePos)) {
            processEvents(_textBox, circuit, componentName);
            render(_textBox);
        }
        _simulateButton._button.setFillColor(sf::Color(180, 50, 50));
    } else if (_displayButton._button.getGlobalBounds().contains(mousePos)) {
        std::cout << "Display button clicked!" << std::endl;
        display(circuit);

        // Surbrillance
        _displayButton._button.setFillColor(sf::Color(60, 60, 60));
        sf::Clock clock;
        sf::Time startTime = clock.getElapsedTime();

        while (clock.getElapsedTime() - startTime < sf::milliseconds(300) &&
            _displayButton._button.getGlobalBounds().contains(mousePos)) {
            processEvents(_textBox, circuit, componentName);
            render(_textBox);
        }
        _displayButton._button.setFillColor(sf::Color(50, 50, 50));

    } else if (_loopButton._button.getGlobalBounds().contains(mousePos)) {
        std::cout << "Loop button clicked!" << std::endl;
        loop(mousePos, _textBox, circuit, componentName);
        // Surbrillance
        _loopButton._button.setFillColor(sf::Color(60, 60, 60));
        sf::Clock clock;
        sf::Time startTime = clock.getElapsedTime();

        while (clock.getElapsedTime() - startTime < sf::milliseconds(300) &&
            _loopButton._button.getGlobalBounds().contains(mousePos)) {
            processEvents(_textBox, circuit, componentName);
            render(_textBox);
        }
        _loopButton._button.setFillColor(sf::Color(50, 50, 50));

    } else if (_speedButton._button.getGlobalBounds().contains(mousePos)) {
        std::cout << "Speed button clicked!" << std::endl;
        _loopTime = _loopTime / 2;
        // Surbrillance
        _speedButton._button.setFillColor(sf::Color(60, 60, 60));
        sf::Clock clock;
        sf::Time startTime = clock.getElapsedTime();

        while (clock.getElapsedTime() - startTime < sf::milliseconds(300) &&
            _speedButton._button.getGlobalBounds().contains(mousePos)) {
            processEvents(_textBox, circuit, componentName);
            render(_textBox);
        }
        _speedButton._button.setFillColor(sf::Color(50, 50, 50));

    } else if (_slowButton._button.getGlobalBounds().contains(mousePos)) {
        std::cout << "Slow button clicked!" << std::endl;
        _loopTime = _loopTime * 2;
        // Surbrillance
        _slowButton._button.setFillColor(sf::Color(60, 60, 60));
        sf::Clock clock;
        sf::Time startTime = clock.getElapsedTime();

        while (clock.getElapsedTime() - startTime < sf::milliseconds(300) &&
            _slowButton._button.getGlobalBounds().contains(mousePos)) {
            processEvents(_textBox, circuit, componentName);
            render(_textBox);
        }
        _slowButton._button.setFillColor(sf::Color(50, 50, 50));

    } else if (_inputTextBox._textBox.getGlobalBounds().contains(mousePos)) {
        std::cout << "Textbox button clicked!" << std::endl;
        _textBox.setSelected(true);

    } else if (_validButton._button.getGlobalBounds().contains(mousePos)) {
        std::cout << "Validate button clicked: " << _textBox.getText() << std::endl;
        attributeValue(_textBox.getText(), circuit);
        _textBox.clearText();

        // Surbrillance
        _validButton._button.setFillColor(sf::Color(60, 60, 60));
        sf::Clock clock;
        sf::Time startTime = clock.getElapsedTime();

        while (clock.getElapsedTime() - startTime < sf::milliseconds(300) &&
            _validButton._button.getGlobalBounds().contains(mousePos)) {
            processEvents(_textBox, circuit, componentName);
            render(_textBox);
        }
        _validButton._button.setFillColor(sf::Color(50, 50, 50));

    }

    if (!_inputTextBox._textBox.getGlobalBounds().contains(mousePos) && _textBox.getIsSelected() == true) {
        _textBox.setSelected(false);
    }
}

void MainWindow::run(nts::Circuit &circuit, std::string componentName)
{
    // TEXTBOX
    Textbox _textBox(24, sf::Color::White, false);
    _textBox.setPosition({60, 460});
    _textBox.setFont(m_font);

    if (componentName == "true.nts") {
        createTrue();
    } if (componentName == "false.nts") {
        createFalse();
    } if (componentName == "xor.nts") {
        create2Gate(circuit, "xor");
    } if (componentName == "or.nts") {
        create2Gate(circuit, "or");
    } if (componentName == "nor.nts") {
        create2Gate(circuit, "nor");
    } if (componentName == "nand.nts") {
        create2Gate(circuit, "nand");
    } if (componentName == "and.nts") {
        create2Gate(circuit, "and");
    } if (componentName == "not.nts") {
        create1Gate(circuit, "not");
    } if (componentName == "clock.nts") {
        create1Gate(circuit, "clock");
    } if (componentName == "4040_counter.nts") {
        create4040(circuit);
    }

    while (m_window.isOpen()) {
        processEvents(_textBox, circuit, componentName);
        render(_textBox);
    }
}

void MainWindow::createTrue()
{
    _component._componentName.setFont(m_font);
    _component._componentName.setCharacterSize(25);
    _component._componentName.setFillColor(sf::Color::White);
    _component._componentName.setString("true");
    _component._componentName.setStyle(sf::Text::Bold);
    sf::FloatRect textBounds = _component._componentName.getLocalBounds();
    _component._componentName.setPosition(645, 285);

    _component._base.setSize(sf::Vector2f(300, 150));
    _component._base.setFillColor(sf::Color(50, 50, 50));
    _component._base.setPosition(522, 225);

    sf::CircleShape out;
    out.setRadius(20);
    out.setFillColor(sf::Color::Blue);
    out.setPosition(802, 280);
    Pin _out;
    _out._pinName = "";
    _out._pin = out;
    _component._pinList.push_back(_out);
}

void MainWindow::createFalse()
{
    _component._componentName.setFont(m_font);
    _component._componentName.setCharacterSize(25);
    _component._componentName.setFillColor(sf::Color::White);
    _component._componentName.setString("false");
    _component._componentName.setStyle(sf::Text::Bold);
    sf::FloatRect textBounds = _component._componentName.getLocalBounds();
    _component._componentName.setPosition(645, 285);

    _component._base.setSize(sf::Vector2f(300, 150));
    _component._base.setFillColor(sf::Color(50, 50, 50));
    _component._base.setPosition(522, 225);

    sf::CircleShape out;
    out.setRadius(20);
    out.setFillColor(sf::Color::White);
    out.setPosition(802, 280);
    Pin _out;
    _out._pinName = "";
    _out._pin = out;
    _component._pinList.push_back(_out);
}

void MainWindow::create2Gate(nts::Circuit &circuit, std::string name)
{
    int in = 0;
    int out = 0;

    _component._componentName.setFont(m_font);
    _component._componentName.setCharacterSize(25);
    _component._componentName.setFillColor(sf::Color::White);
    _component._componentName.setString(name);
    _component._componentName.setStyle(sf::Text::Bold);
    sf::FloatRect textBounds = _component._componentName.getLocalBounds();
    _component._componentName.setPosition(645, 285);

    _component._base.setSize(sf::Vector2f(300, 150));
    _component._base.setFillColor(sf::Color(50, 50, 50));
    _component._base.setPosition(522, 225);

    sf::CircleShape out1;
    out1.setRadius(20);
    out1.setFillColor(sf::Color::Magenta);
    out1.setPosition(802, 280);
    Pin _out1;
    _out1._pin = out1;

    sf::CircleShape in1;
    in1.setRadius(20);
    in1.setFillColor(sf::Color::Magenta);
    in1.setPosition(502, 240);
    Pin _in1;
    _in1._pin = in1;

    sf::CircleShape in2;
    in2.setRadius(20);
    in2.setFillColor(sf::Color::Magenta);
    in2.setPosition(502, 320);
    Pin _in2;
    _in2._pin = in2;

    for (const auto &cmp : circuit.getComponentMap()) {
        nts::IComponent *component = cmp.second.get();
        std::string name = cmp.first;

        if (component && component->getType() == "input" && in == 0) {
            _in1._pinName = name;
            _in1._pinText.setFont(m_font);
            _in1._pinText.setCharacterSize(20);
            _in1._pinText.setFillColor(sf::Color::White);
            _in1._pinText.setString(name);
            _in1._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _in1._pinText.getLocalBounds();
            float textWidth = textBounds.width;
            float xPos = std::min(textWidth, 500.f);
            _in1._pinText.setPosition(490 - xPos, 245);
            in++;
        } else if (component && component->getType() == "input" && in == 1) {
            _in2._pinName = name;
            _in2._pinText.setFont(m_font);
            _in2._pinText.setCharacterSize(20);
            _in2._pinText.setFillColor(sf::Color::White);
            _in2._pinText.setString(name);
            _in2._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _in2._pinText.getLocalBounds();
            float textWidth = textBounds.width;
            float xPos = std::min(textWidth, 500.f);
            _in2._pinText.setPosition(490 - xPos, 325);
            in++;
        } else if (component && component->getType() == "output" && out == 0) {
            _out1._pinName = name;
            _out1._pinText.setFont(m_font);
            _out1._pinText.setCharacterSize(20);
            _out1._pinText.setFillColor(sf::Color::White);
            _out1._pinText.setString(name);
            _out1._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _out1._pinText.getLocalBounds();
            _out1._pinText.setPosition(850, 285);
            out++;
        }
    }

    _component._pinList.push_back(_out1);
    _component._pinList.push_back(_in1);
    _component._pinList.push_back(_in2);
}

void MainWindow::create1Gate(nts::Circuit &circuit, std::string name)
{
    int in = 0;
    int out = 0;

    _component._componentName.setFont(m_font);
    _component._componentName.setCharacterSize(25);
    _component._componentName.setFillColor(sf::Color::White);
    _component._componentName.setString(name);
    _component._componentName.setStyle(sf::Text::Bold);
    sf::FloatRect textBounds = _component._componentName.getLocalBounds();
    _component._componentName.setPosition(645, 285);

    _component._base.setSize(sf::Vector2f(300, 150));
    _component._base.setFillColor(sf::Color(50, 50, 50));
    _component._base.setPosition(522, 225);

    sf::CircleShape out1;
    out1.setRadius(20);
    out1.setFillColor(sf::Color::Magenta);
    out1.setPosition(802, 280);
    Pin _out1;
    _out1._pin = out1;

    sf::CircleShape in1;
    in1.setRadius(20);
    in1.setFillColor(sf::Color::Magenta);
    in1.setPosition(502, 280);
    Pin _in1;
    _in1._pin = in1;

    for (const auto &cmp : circuit.getComponentMap()) {
        nts::IComponent *component = cmp.second.get();
        std::string name = cmp.first;

        if (component && (component->getType() == "input" || component->getType() == "clock") && in == 0) {
            _in1._pinName = name;
            _in1._pinText.setFont(m_font);
            _in1._pinText.setCharacterSize(20);
            _in1._pinText.setFillColor(sf::Color::White);
            _in1._pinText.setString(name);
            _in1._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _in1._pinText.getLocalBounds();
            float textWidth = textBounds.width;
            float xPos = std::min(textWidth, 500.f);
            _in1._pinText.setPosition(490 - xPos, 285);
            in++;
        } else if (component && component->getType() == "output" && out == 0) {
            _out1._pinName = name;
            _out1._pinText.setFont(m_font);
            _out1._pinText.setCharacterSize(20);
            _out1._pinText.setFillColor(sf::Color::White);
            _out1._pinText.setString(name);
            _out1._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _out1._pinText.getLocalBounds();
            _out1._pinText.setPosition(850, 285);
            out++;
        }
    }

    _component._pinList.push_back(_out1);
    _component._pinList.push_back(_in1);
}

void MainWindow::create4040(nts::Circuit &circuit)
{
    int out = 0;

    _component._componentName.setFont(m_font);
    _component._componentName.setCharacterSize(25);
    _component._componentName.setFillColor(sf::Color::White);
    _component._componentName.setString("4040_counter");
    _component._componentName.setStyle(sf::Text::Bold);
    sf::FloatRect textBounds = _component._componentName.getLocalBounds();
    _component._componentName.setPosition(585, 285);

    _component._base.setSize(sf::Vector2f(300, 500));
    _component._base.setFillColor(sf::Color(50, 50, 50));
    _component._base.setPosition(522, 50);

    sf::CircleShape in_reset;
    in_reset.setRadius(20);
    in_reset.setFillColor(sf::Color::Magenta);
    in_reset.setPosition(502, 450);
    Pin _in_reset;
    _in_reset._pin = in_reset;

    sf::CircleShape clock;
    clock.setRadius(20);
    clock.setFillColor(sf::Color::Magenta);
    clock.setPosition(502, 150);
    Pin _clock;
    _clock._pin = clock;

    sf::CircleShape out00;
    out00.setRadius(16);
    out00.setFillColor(sf::Color::Magenta);
    out00.setPosition(806, 59);
    Pin _out00;
    _out00._pin = out00;

    sf::CircleShape out01;
    out01.setRadius(16);
    out01.setFillColor(sf::Color::Magenta);
    out01.setPosition(806, 100);
    Pin _out01;
    _out01._pin = out01;

    sf::CircleShape out02;
    out02.setRadius(16);
    out02.setFillColor(sf::Color::Magenta);
    out02.setPosition(806, 141);
    Pin _out02;
    _out02._pin = out02;

    sf::CircleShape out03;
    out03.setRadius(16);
    out03.setFillColor(sf::Color::Magenta);
    out03.setPosition(806, 182);
    Pin _out03;
    _out03._pin = out03;

    sf::CircleShape out04;
    out04.setRadius(16);
    out04.setFillColor(sf::Color::Magenta);
    out04.setPosition(806, 223);
    Pin _out04;
    _out04._pin = out04;

    sf::CircleShape out05;
    out05.setRadius(16);
    out05.setFillColor(sf::Color::Magenta);
    out05.setPosition(806, 264);
    Pin _out05;
    _out05._pin = out05;

    sf::CircleShape out06;
    out06.setRadius(16);
    out06.setFillColor(sf::Color::Magenta);
    out06.setPosition(806, 305);
    Pin _out06;
    _out06._pin = out06;

    sf::CircleShape out07;
    out07.setRadius(16);
    out07.setFillColor(sf::Color::Magenta);
    out07.setPosition(806, 346);
    Pin _out07;
    _out07._pin = out07;

    sf::CircleShape out08;
    out08.setRadius(16);
    out08.setFillColor(sf::Color::Magenta);
    out08.setPosition(806, 387);
    Pin _out08;
    _out08._pin = out08;

    sf::CircleShape out09;
    out09.setRadius(16);
    out09.setFillColor(sf::Color::Magenta);
    out09.setPosition(806, 428);
    Pin _out09;
    _out09._pin = out09;

    sf::CircleShape out10;
    out10.setRadius(16);
    out10.setFillColor(sf::Color::Magenta);
    out10.setPosition(806, 469);
    Pin _out10;
    _out10._pin = out10;

    sf::CircleShape out11;
    out11.setRadius(16);
    out11.setFillColor(sf::Color::Magenta);
    out11.setPosition(806, 510);
    Pin _out11;
    _out11._pin = out11;

    for (const auto &cmp : circuit.getComponentMap()) {
        nts::IComponent *component = cmp.second.get();
        std::string name = cmp.first;

        if (component && component->getType() == "clock") {
            _clock._pinName = name;
            _clock._pinText.setFont(m_font);
            _clock._pinText.setCharacterSize(20);
            _clock._pinText.setFillColor(sf::Color::White);
            _clock._pinText.setString(name);
            _clock._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _clock._pinText.getLocalBounds();
            float textWidth = textBounds.width;
            float xPos = std::min(textWidth, 500.f);
            _clock._pinText.setPosition(490 - xPos, 155);
        } if (component && component->getType() == "input") {
            _in_reset._pinName = name;
            _in_reset._pinText.setFont(m_font);
            _in_reset._pinText.setCharacterSize(20);
            _in_reset._pinText.setFillColor(sf::Color::White);
            _in_reset._pinText.setString(name);
            _in_reset._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _in_reset._pinText.getLocalBounds();
            float textWidth = textBounds.width;
            float xPos = std::min(textWidth, 500.f);
            _in_reset._pinText.setPosition(490 - xPos, 455);
        } else if (component && component->getType() == "output" && out == 0) {
            _out00._pinName = name;
            _out00._pinText.setFont(m_font);
            _out00._pinText.setCharacterSize(15);
            _out00._pinText.setFillColor(sf::Color::White);
            _out00._pinText.setString(name);
            _out00._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _out00._pinText.getLocalBounds();
            _out00._pinText.setPosition(850, 64);
            out++;
        } else if (component && component->getType() == "output" && out == 1) {
            _out01._pinName = name;
            _out01._pinText.setFont(m_font);
            _out01._pinText.setCharacterSize(15);
            _out01._pinText.setFillColor(sf::Color::White);
            _out01._pinText.setString(name);
            _out01._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _out01._pinText.getLocalBounds();
            _out01._pinText.setPosition(850, 105);
            out++;
        } else if (component && component->getType() == "output" && out == 2) {
            _out02._pinName = name;
            _out02._pinText.setFont(m_font);
            _out02._pinText.setCharacterSize(15);
            _out02._pinText.setFillColor(sf::Color::White);
            _out02._pinText.setString(name);
            _out02._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _out02._pinText.getLocalBounds();
            _out02._pinText.setPosition(850, 146);
            out++;
        } else if (component && component->getType() == "output" && out == 3) {
            _out03._pinName = name;
            _out03._pinText.setFont(m_font);
            _out03._pinText.setCharacterSize(15);
            _out03._pinText.setFillColor(sf::Color::White);
            _out03._pinText.setString(name);
            _out03._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _out03._pinText.getLocalBounds();
            _out03._pinText.setPosition(850, 187);
            out++;
        } else if (component && component->getType() == "output" && out == 4) {
            _out04._pinName = name;
            _out04._pinText.setFont(m_font);
            _out04._pinText.setCharacterSize(15);
            _out04._pinText.setFillColor(sf::Color::White);
            _out04._pinText.setString(name);
            _out04._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _out04._pinText.getLocalBounds();
            _out04._pinText.setPosition(850, 228);
            out++;
        } else if (component && component->getType() == "output" && out == 5) {
            _out05._pinName = name;
            _out05._pinText.setFont(m_font);
            _out05._pinText.setCharacterSize(15);
            _out05._pinText.setFillColor(sf::Color::White);
            _out05._pinText.setString(name);
            _out05._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _out05._pinText.getLocalBounds();
            _out05._pinText.setPosition(850, 269);
            out++;
        } else if (component && component->getType() == "output" && out == 6) {
            _out06._pinName = name;
            _out06._pinText.setFont(m_font);
            _out06._pinText.setCharacterSize(15);
            _out06._pinText.setFillColor(sf::Color::White);
            _out06._pinText.setString(name);
            _out06._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _out06._pinText.getLocalBounds();
            _out06._pinText.setPosition(850, 310);
            out++;
        } else if (component && component->getType() == "output" && out == 7) {
            _out07._pinName = name;
            _out07._pinText.setFont(m_font);
            _out07._pinText.setCharacterSize(15);
            _out07._pinText.setFillColor(sf::Color::White);
            _out07._pinText.setString(name);
            _out07._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _out07._pinText.getLocalBounds();
            _out07._pinText.setPosition(850, 351);
            out++;
        } else if (component && component->getType() == "output" && out == 8) {
            _out08._pinName = name;
            _out08._pinText.setFont(m_font);
            _out08._pinText.setCharacterSize(15);
            _out08._pinText.setFillColor(sf::Color::White);
            _out08._pinText.setString(name);
            _out08._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _out08._pinText.getLocalBounds();
            _out08._pinText.setPosition(850, 392);
            out++;
        } else if (component && component->getType() == "output" && out == 9) {
            _out09._pinName = name;
            _out09._pinText.setFont(m_font);
            _out09._pinText.setCharacterSize(15);
            _out09._pinText.setFillColor(sf::Color::White);
            _out09._pinText.setString(name);
            _out09._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _out09._pinText.getLocalBounds();
            _out09._pinText.setPosition(850, 433);
            out++;
        } else if (component && component->getType() == "output" && out == 10) {
            _out10._pinName = name;
            _out10._pinText.setFont(m_font);
            _out10._pinText.setCharacterSize(15);
            _out10._pinText.setFillColor(sf::Color::White);
            _out10._pinText.setString(name);
            _out10._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _out10._pinText.getLocalBounds();
            _out10._pinText.setPosition(850, 474);
            out++;
        } else if (component && component->getType() == "output" && out == 11) {
            _out11._pinName = name;
            _out11._pinText.setFont(m_font);
            _out11._pinText.setCharacterSize(15);
            _out11._pinText.setFillColor(sf::Color::White);
            _out11._pinText.setString(name);
            _out11._pinText.setStyle(sf::Text::Bold);
            sf::FloatRect textBounds = _out11._pinText.getLocalBounds();
            _out11._pinText.setPosition(850, 515);
            out++;
        }
    }

    _component._pinList.push_back(_clock);
    _component._pinList.push_back(_in_reset);
    _component._pinList.push_back(_out00);
    _component._pinList.push_back(_out01);
    _component._pinList.push_back(_out02);
    _component._pinList.push_back(_out03);
    _component._pinList.push_back(_out04);
    _component._pinList.push_back(_out05);
    _component._pinList.push_back(_out06);
    _component._pinList.push_back(_out07);
    _component._pinList.push_back(_out08);
    _component._pinList.push_back(_out09);
    _component._pinList.push_back(_out10);
    _component._pinList.push_back(_out11);
}

void MainWindow::drawComponent()
{
    m_window.draw(_component._base);
    m_window.draw(_component._componentName);
    for (const Pin& pin : _component._pinList) {
        m_window.draw(pin._pin);
        m_window.draw(pin._pinText);
    }
}
