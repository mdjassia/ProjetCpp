#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>
#include "CaseFixe.hpp"
#include <SFML/Graphics.hpp>

class Level {
public:
    Level(int levelNumber);  // Constructeur du niveau
    void draw(sf::RenderWindow& window); // Dessiner toutes les cases fixes du niveau

private:
    int levelNumber;                 // Numéro du niveau
    std::vector<CaseFixe> fixedCases; // Liste des cases fixes
};

#endif // LEVEL_HPP
