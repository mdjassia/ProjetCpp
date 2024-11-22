#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include "../models/GameModel.hpp" // Corrige le chemin relatif
#include "../views/GameView.hpp"

class GameController {
public:
   GameController(sf::RenderWindow& window, GameModel& model, GameView& view);

    void run();

private:
    void handleEvents();
    void update();
    void render();

    sf::RenderWindow& window;
    GameModel& model;
    GameView& view;
    bool inGame;
};

#endif // GAME_CONTROLLER_HPP
