#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>

class Level {
public:
    Level(int level);             // Constructeur pour initialiser un niveau
    void draw(sf::RenderWindow &window);  // Méthode pour dessiner le niveau

private:
    int level;                    // Niveau actuel
    sf::RectangleShape grid[10][10];  // Matrice 10x10
    void initGrid();              // Initialisation de la grille
    void setLevelCases();         // Définir les cases allumées pour chaque niveau
};

#endif // LEVEL_HPP
