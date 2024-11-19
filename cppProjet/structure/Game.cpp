#include "Game.hpp"
#include <iostream>

Game::Game()
    : window(sf::VideoMode(800, 600), "Piece Out Game"),
      inGame(false),                  // Initialisation à false (menu principal)
      currentLevel(nullptr),          // Niveau initial à nullptr
      level(0)                        // Initialisation à 0
{
    loadResources();  // Appel de la méthode loadResources après l'initialisation
    levels.push_back(Level(1)); // Ajouter le niveau 1
    levels.push_back(Level(2)); // Ajouter le niveau 2 (vous pouvez ajouter plus de niveaux ici)

    if (!levels.empty()) {
        currentLevel = &levels[0];  // Définir le premier niveau comme niveau actuel
    }
}

void Game::loadResources() {
    // Charger l'image de fond
    if (!backgroundTexture.loadFromFile("backround.jpg")) {
        std::cerr << "Erreur de chargement de l'image de fond." << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture, true);
    backgroundSprite.setScale(1.34, 1.75); // Scale de l'image de fond

    // Charger la police
    if (!font.loadFromFile("ressources/PressStart2P-Regular.ttf")) {
        std::cerr << "Erreur de chargement de la police." << std::endl;
    }

    // Créer le bouton "Start Game"
    button.setSize(sf::Vector2f(300, 60)); // Taille du bouton
    button.setFillColor(sf::Color(175, 219, 235)); // Bleu clair
    button.setPosition((window.getSize().x - button.getSize().x) / 2, 
                       (window.getSize().y - button.getSize().y) / 2); // Centrer le bouton

    // Ajouter des bordures pour simuler un style pixelisé
    button.setOutlineThickness(2);  // Bordure épaisse pour effet pixelisé
    button.setOutlineColor(sf::Color(0, 0, 0)); // Bordure noire

    // Créer le texte du bouton
    startGameText.setFont(font);
    startGameText.setString("Start Game");
    startGameText.setCharacterSize(24);
    startGameText.setFillColor(sf::Color::White); // Couleur du texte

    // Centrer le texte sur le bouton
    sf::FloatRect textBounds = startGameText.getLocalBounds();
    startGameText.setPosition(button.getPosition().x + (button.getSize().x - textBounds.width) / 2, 
                              button.getPosition().y + (button.getSize().y - textBounds.height) / 2);
}

void Game::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (!inGame) { // Si on est dans le menu principal
            // Vérifier si un clic gauche de la souris a eu lieu
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::FloatRect buttonBounds = button.getGlobalBounds();
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (buttonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    inGame = true; // Passer en mode jeu
                }
            }
        }
    }
}

void Game::update() {
    // Mise à jour de la logique de jeu, si nécessaire
}

void Game::renderGame() {
    // Vérifier si le niveau existe avant de le dessiner
    if (currentLevel != nullptr) {
        window.draw(backgroundSprite);
        currentLevel->draw(window);  // Dessiner le niveau actuel
    }
}

void Game::render() {
    window.clear();

    if (!inGame) {
        renderMenu(); // Afficher le menu principal
    } else {
        renderGame(); // Afficher l'écran de jeu
    }

    window.display();
}

void Game::renderMenu() {
    // Dessiner l'image de fond
    window.draw(backgroundSprite);

    // Dessiner le bouton et le texte
    window.draw(button);
    window.draw(startGameText);
}
