#include "../../include/models/GameModel.hpp"
#include "../../include/models/Level.hpp"


GameModel::GameModel() : currentLevelIndex(0) {
    // Initialisation des niveaux
    levels.push_back(Level(1));
    levels.push_back(Level(2));
    // Ajoutez d'autres niveaux si nécessaire
}

Level* GameModel::getCurrentLevel() {
    if (currentLevelIndex < levels.size()) {
        return &levels[currentLevelIndex];
    }
    return nullptr;
}

void GameModel::nextLevel() {
    if (currentLevelIndex + 1 < levels.size()) {
        currentLevelIndex++;
    }
}

bool GameModel::isGameOver() const {
    return currentLevelIndex >= levels.size();
}
