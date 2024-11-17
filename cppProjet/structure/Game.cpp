#include "Game.hpp"
#include <iostream>

Game::Game() 
    : window(sf::VideoMode(800, 600), "Piece Out Game"), currentLevel(0) // Initialisation de la fenêtre directement dans la liste
{
    loadResources();  // Appel de la méthode loadResources après l'initialisation
}

void Game::loadResources() {
    // Charger l'image de fond
    if (!backgroundTexture.loadFromFile("backround.jpg")) {
        std::cerr << "Erreur de chargement de l'image de fond." << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture, true);
    backgroundSprite.setScale(
    1.34, // Largeur
    1.75// Hauteur
);
    // Charger la police
    if (!font.loadFromFile("ressources/PressStart2P-Regular.ttf")) {
        std::cerr << "Erreur de chargement de la police." << std::endl;
    }

    // Créer le bouton "Start Game"
    button.setSize(sf::Vector2f(300, 60)); // Taille du bouton
    button.setFillColor(sf::Color(175, 219, 235)); // Bleu clair
    button.setPosition((window.getSize().x - button.getSize().x) / 2, (window.getSize().y - button.getSize().y) / 2); // Centrer le bouton

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

        // Vérifier si un clic gauche de la souris a eu lieu
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {  // Clic gauche
                // Vérifier si le clic est à l'intérieur du bouton
                sf::FloatRect buttonBounds = button.getGlobalBounds();
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (buttonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    std::cout << "Bouton 'Start Game' cliqué!" << std::endl;
                    // Ici, tu peux démarrer le jeu ou effectuer une autre action
                    // Par exemple, on pourrait appeler une fonction startGame() ici.
                }
            }
        }

        // Vérifier si la souris survole le bouton
        if (event.type == sf::Event::MouseMoved) {
            sf::FloatRect buttonBounds = button.getGlobalBounds();
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (buttonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                // Modifier la couleur du bouton lorsque la souris le survole
                button.setFillColor(sf::Color(135, 206, 235)); // Un bleu plus clair pour l'effet de survol
            } else {
                // Rétablir la couleur d'origine du bouton
                button.setFillColor(sf::Color(173, 216, 230)); // Bleu clair
            }
        }
    }
}
void Game::update() {
    // Pour l'instant, rien à mettre ici, mais si tu as de la logique de jeu, c'est ici que tu l'ajoutes
}

void Game::render() {
    window.clear();

    // Dessiner l'image de fond
    window.draw(backgroundSprite);

    // Dessiner le bouton et le texte
    window.draw(button);
    window.draw(startGameText);

    window.display();
}
