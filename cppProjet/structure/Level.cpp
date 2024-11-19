#include "Level.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

// Constructeur : initialise la grille avec les dimensions données
Level::Level(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY) {
    // Initialisation de la grille avec des valeurs par défaut (0)
    grid.resize(sizeX, std::vector<int>(sizeY, 0));
}

// Méthode pour dessiner la grille dans une fenêtre SFML
void Level::draw(sf::RenderWindow &window) {
    for (int x = 0; x < sizeX; ++x) {
        for (int y = 0; y < sizeY; ++y) {
            // Créer un carré représentant une case de la grille
            sf::RectangleShape cell(sf::Vector2f(64, 64)); // Taille d'une case
            cell.setPosition(100 + x * 64, 100 + y * 64);  // Position des cases
            cell.setFillColor(sf::Color::White);           // Couleur des cases
            window.draw(cell);                             // Dessiner la case
        }
    }
}
