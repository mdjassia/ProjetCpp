#include "Level.hpp"
#include <SFML/Graphics.hpp>

Level::Level(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY) {
    grid.resize(sizeX, std::vector<int>(sizeY, 0)); // Initialisation d'une grille vide
}

void Level::draw(sf::RenderWindow &window) {
    // Dessiner la grille
    for (int x = 0; x < sizeX; ++x) {
        for (int y = 0; y < sizeY; ++y) {
            sf::RectangleShape cell(sf::Vector2f(64, 64));
            cell.setPosition(100 + x * 64, 100 + y * 64); // Position des cases
            cell.setFillColor(sf::Color::White); // Couleur des cases
            window.draw(cell);
        }
    }
}
