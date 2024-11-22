#ifndef GAME_VIEW_HPP
#define GAME_VIEW_HPP

#include <SFML/Graphics.hpp>
#include "../models/GameModel.hpp"

class GameView {
public:
    GameView(sf::RenderWindow& window);
    void renderMenu(bool inGame);
    void renderGame(Level* currentLevel);
    bool isButtonClicked(const sf::Vector2i& mousePos) const;


private:
    sf::RenderWindow& window;         // Référence à la fenêtre SFML
    sf::RectangleShape button;        // Bouton "Start Game"
    sf::Text startGameText;           // Texte du bouton
    sf::Sprite backgroundSprite;      // Sprite d'arrière-plan
    sf::Texture backgroundTexture;    // Texture d'arrière-plan
    sf::Font font;                    // Police

    void loadResources();
};

#endif // GAME_VIEW_HPP
