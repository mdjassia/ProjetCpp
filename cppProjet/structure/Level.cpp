#include "Level.hpp"

Level::Level(int levelNumber) : levelNumber(levelNumber) {
    // Initialisation des cases fixes en fonction du niveau
    if (levelNumber == 1) {
        fixedCases.push_back(CaseFixe(0, 0));
        fixedCases.push_back(CaseFixe(0, 1));
        fixedCases.push_back(CaseFixe(0, 2));
        fixedCases.push_back(CaseFixe(0, 3));
        fixedCases.push_back(CaseFixe(0, 4));
        fixedCases.push_back(CaseFixe(0, 5));
        fixedCases.push_back(CaseFixe(0, 6));
        fixedCases.push_back(CaseFixe(0, 7));
    } else if (levelNumber == 2) {
        fixedCases.push_back(CaseFixe(0, 0));
        fixedCases.push_back(CaseFixe(0, 1));
        fixedCases.push_back(CaseFixe(0, 2));
        fixedCases.push_back(CaseFixe(0, 3));
        fixedCases.push_back(CaseFixe(0, 4));
        fixedCases.push_back(CaseFixe(0, 5));
        fixedCases.push_back(CaseFixe(0, 6));
        fixedCases.push_back(CaseFixe(1, 2));
        fixedCases.push_back(CaseFixe(0, 7));
        fixedCases.push_back(CaseFixe(0, 7));
        fixedCases.push_back(CaseFixe(0, 7));
        fixedCases.push_back(CaseFixe(0, 7));
        fixedCases.push_back(CaseFixe(0, 7));
        fixedCases.push_back(CaseFixe(0, 7));
        fixedCases.push_back(CaseFixe(0, 7));
    }
}

void Level::draw(sf::RenderWindow& window) {
    const int TILE_SIZE = 64;
    const int X_MARGIN = 1;
    const int Y_MARGIN = 1;

    // Centrer la grille
    int maxRow = 0, maxCol = 0;
    for (const auto& fixedCase : fixedCases) {
        if (fixedCase.getRow() > maxRow) maxRow = fixedCase.getRow();
        if (fixedCase.getCol() > maxCol) maxCol = fixedCase.getCol();
    }

    int gridWidth = maxCol * TILE_SIZE + (maxCol - 1) * X_MARGIN;
    int gridHeight = maxRow * TILE_SIZE + (maxRow - 1) * Y_MARGIN;

    int windowWidth = window.getSize().x;
    int windowHeight = window.getSize().y;

    int offsetX = (windowWidth - gridWidth) / 2;
    int offsetY = (windowHeight - gridHeight) / 2;

    for (auto& fixedCase : fixedCases) {
        float x = offsetX + fixedCase.getCol() * (TILE_SIZE + X_MARGIN);
        float y = offsetY + fixedCase.getRow() * (TILE_SIZE + Y_MARGIN);
        fixedCase.setPosition(x, y);
        fixedCase.draw(window);
    }
}
