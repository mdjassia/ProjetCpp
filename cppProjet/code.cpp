// Structure des classes et définitions pour un jeu de type "Piece Out" en C++
// Fichiers header (.hpp) et implémentations de base

// Game.hpp
#ifndef GAME_HPP
#define GAME_HPP


#include <vector>
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    std::vector<Level> levels;
    int currentLevel;

    void processEvents();
    void render();
    void startGame();
};

#endif // GAME_HPP

// Level.hpp
#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>


class Level {
public:
    Level(int size); // Constructeur pour initialiser un niveau avec une matrice N x N
    void draw(sf::RenderWindow &window);
    void setPlayableShape(const std::vector<std::pair<int, int>> &shape);

private:
    int size;
    std::vector<std::vector<int>> grid;
    std::vector<Piece> pieces;
};

#endif // LEVEL_HPP

// Piece.hpp
#ifndef PIECE_HPP
#define PIECE_HPP

enum class MoveType {
    ROTATE,
    SLIDE,
    FIXED
};

class Piece {
public:
    Piece(int x, int y, MoveType moveType);
    void move();
    void draw(sf::RenderWindow &window);

private:
    int x, y;
    MoveType moveType;
};

#endif // PIECE_HPP

// Game.cpp

#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game() : window(sf::VideoMode(800, 600), "Piece Out Game"), currentLevel(0) {
    levels.emplace_back(3); // Ajout de niveaux (exemple: matrice 3x3)
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            startGame(); // Si le bouton start est cliqué, commence le jeu
        }
    }
}

void Game::render() {
    window.clear();
    // Afficher le bouton Start ou l'état actuel du jeu
    if (currentLevel == 0) {
        // Code pour dessiner le bouton "Start Game"
        sf::RectangleShape button(sf::Vector2f(200, 50));
        button.setPosition(300, 275);
        button.setFillColor(sf::Color::Green);
        window.draw(button);
    } else {
        levels[currentLevel - 1].draw(window);
    }
    window.display();
}

void Game::startGame() {
    if (currentLevel == 0) {
        currentLevel = 1; // Passe au niveau 1
    }
}

// Level.cpp

#include <SFML/Graphics.hpp>

Level::Level(int size) : size(size) {
    grid.resize(size, std::vector<int>(size, 0)); // Initialisation de la grille
}

void Level::draw(sf::RenderWindow &window) {
    // Code pour dessiner le niveau
}

void Level::setPlayableShape(const std::vector<std::pair<int, int>> &shape) {
    // Code pour définir la forme jouable dans la matrice
}

// Piece.cpp

#include <SFML/Graphics.hpp>

Piece::Piece(int x, int y, MoveType moveType) : x(x), y(y), moveType(moveType) {}

void Piece::move() {
    // Code pour déplacer la pièce selon moveType
}

void Piece::draw(sf::RenderWindow &window) {
    // Code pour dessiner la pièce
}
