#include "../include/Game.hpp"

void Game::run() {
    window.create(sf::VideoMode(800, 600), "Piece Out Game");

    model = GameModel();
    view = new GameView(window);
    controller = new GameController(window, model, *view);

    controller->run();

    delete view;
    delete controller;
}
