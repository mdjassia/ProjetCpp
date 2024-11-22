#include "../../include/controllers/GameController.hpp"
#include "../../include/models/GameModel.hpp"
#include "../../include/views/GameView.hpp"


GameController::GameController(sf::RenderWindow& window, GameModel& model, GameView& view)
    : window(window), model(model), view(view), inGame(false) {}

void GameController::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void GameController::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (!inGame && event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (view.isButtonClicked(mousePos)) {
                inGame = true;
            }
        }
    }
}

void GameController::update() {
    if (inGame && model.isGameOver()) {
        inGame = false; // Retour au menu principal
    }
}

void GameController::render() {
    window.clear();
    if (!inGame) {
        view.renderMenu(inGame);
    } else {
        view.renderGame(model.getCurrentLevel());
    }
    window.display();
}
