#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Level {
public:
    // Constructeur pour initialiser un niveau avec les dimensions spécifiées
    Level(int sizeX, int sizeY);

    // Méthode pour dessiner le niveau dans une fenêtre SFML
    void draw(sf::RenderWindow &window);

private:
    int sizeX; // Taille de la grille en X
    int sizeY; // Taille de la grille en Y
    std::vector<std::vector<int>> grid; // Grille représentant les données du niveau
};

#endif // LEVEL_HPP
