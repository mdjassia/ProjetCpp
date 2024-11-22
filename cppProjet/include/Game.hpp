#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "controllers/GameController.hpp"
#include "models/GameModel.hpp"
#include "views/GameView.hpp"

class Game {
public:
    void run();

private:
    sf::RenderWindow window;
    GameModel model;
    GameView* view;
    GameController* controller;
};

#endif // GAME_HPP
