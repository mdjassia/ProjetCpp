#include "Level.hpp"
#include <SFML/Graphics.hpp>

Level::Level(int levelNumber) : levelNumber(levelNumber) {
    // Exemple d'ajout de cases fixes spécifiques à chaque niveau
    if (levelNumber == 1) {
        fixedCases.push_back(Case(0, 0));
        fixedCases.push_back(Case(0, 1));
        fixedCases.push_back(Case(0, 2));
        fixedCases.push_back(Case(0, 3));
        fixedCases.push_back(Case(0, 4));
        fixedCases.push_back(Case(0, 5));
        fixedCases.push_back(Case(0, 6));
        fixedCases.push_back(Case(0, 7));
    } else if (levelNumber == 2) {
        fixedCases.push_back(Case(1, 1));
        fixedCases.push_back(Case(1, 2));
        fixedCases.push_back(Case(1, 3));
        fixedCases.push_back(Case(1, 4));
        fixedCases.push_back(Case(1, 5));
    }
}

void Level::draw(sf::RenderWindow &window) {
    const int TILE_SIZE = 64;  // Taille des cases
    const int X_MARGIN = 1;   // Marge horizontale entre les cases
    const int Y_MARGIN = 1;   // Marge verticale entre les cases
    const int WINDOW_WIDTH = window.getSize().x;  // Largeur de la fenêtre
    const int WINDOW_HEIGHT = window.getSize().y;  // Hauteur de la fenêtre

    int maxRow = 0, maxCol = 0;
    for (const auto& fixedCase : fixedCases) {
        if (fixedCase.getRow() > maxRow) {
            maxRow = fixedCase.getRow();
        }
        if (fixedCase.getCol() > maxCol) {
            maxCol = fixedCase.getCol();
        }
    }

    // Calculer la largeur et la hauteur de la grille avec l'espacement
    int gridWidth = (maxCol + 1) * TILE_SIZE + maxCol * X_MARGIN;
    int gridHeight = (maxRow + 1) * TILE_SIZE + maxRow * Y_MARGIN;

    // Centrer la grille dans la fenêtre
    int MARGIN_LEFT = (WINDOW_WIDTH - gridWidth) / 2;
    int MARGIN_TOP = (WINDOW_HEIGHT - gridHeight) / 2;

    // Dessiner les cases
    for (auto& fixedCase : fixedCases) {
        int x = MARGIN_LEFT + fixedCase.getCol() * (TILE_SIZE + X_MARGIN);  // Position X avec marge
        int y = MARGIN_TOP + fixedCase.getRow() * (TILE_SIZE + Y_MARGIN);  // Position Y avec marge
        fixedCase.setPosition(x, y);  // Positionner chaque case
        fixedCase.draw(window);  // Dessiner chaque case
    }
}

int Level::getNumRows() const {
    return fixedCases.empty() ? 0 : fixedCases.back().getRow() + 1;
}

int Level::getNumCols() const {
    return fixedCases.empty() ? 0 : fixedCases.back().getCol() + 1;
}

std::vector<Case> Level::getFixedCases() const {
    return fixedCases;
}
