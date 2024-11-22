#include "../../include/views/GameView.hpp"

#include <SFML/Graphics.hpp>


#include <iostream>

GameView::GameView(sf::RenderWindow& window) : window(window) {
    loadResources();
}

void GameView::loadResources() {
    if (!backgroundTexture.loadFromFile("assets/images/backround.jpg")) {
    std::cerr << "Erreur de chargement de l'image de fond." << std::endl;
}
    backgroundSprite.setTexture(backgroundTexture, true);
    backgroundSprite.setScale(1.34, 1.75);

    if (!font.loadFromFile("assets/fonts/PressStart2P-Regular.ttf")) {
        std::cerr << "Erreur de chargement de la police." << std::endl;
    }

    button.setSize(sf::Vector2f(300, 60));
    button.setFillColor(sf::Color(175, 219, 235));
    button.setPosition((window.getSize().x - button.getSize().x) / 2,
                       (window.getSize().y - button.getSize().y) / 2);

    button.setOutlineThickness(2);
    button.setOutlineColor(sf::Color::Black);

    startGameText.setFont(font);
    startGameText.setString("Start Game");
    startGameText.setCharacterSize(24);
    startGameText.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = startGameText.getLocalBounds();
    startGameText.setPosition(button.getPosition().x + (button.getSize().x - textBounds.width) / 2,
                              button.getPosition().y + (button.getSize().y - textBounds.height) / 2);
}

void GameView::renderMenu(bool inGame) {
    if (!inGame) {
        window.draw(backgroundSprite);
        window.draw(button);
        window.draw(startGameText);
    }
}

void GameView::renderGame(Level* currentLevel) {
    if (currentLevel) {
        window.draw(backgroundSprite);
        currentLevel->draw(window);
    }
}

bool GameView::isButtonClicked(const sf::Vector2i& mousePos) const {
    return button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}
