#ifndef GAME_MODEL_HPP
#define GAME_MODEL_HPP

#include "Level.hpp"
#include <vector>

class GameModel {
public:
    GameModel();
    Level* getCurrentLevel();
    void nextLevel();
    bool isGameOver() const;

private:
    std::vector<Level> levels; // Liste des niveaux
    int currentLevelIndex;     // Index du niveau actuel
};

#endif // GAME_MODEL_HPP