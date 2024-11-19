#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>
#include "Case.hpp"
#include <vector>

class Level {
public:
    Level(int levelNumber); // Constructeur avec le numéro de niveau
    void draw(sf::RenderWindow& window); // Méthode pour dessiner le niveau
    int getNumRows() const; // Nombre de lignes du niveau
    int getNumCols() const; // Nombre de colonnes du niveau
    std::vector<Case> getFixedCases() const; // Obtenir les cases fixes

private:
    int levelNumber; // Numéro du niveau
    std::vector<Case> fixedCases; // Cases fixes pour ce niveau
};

#endif // LEVEL_HPP
