#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game {
public:
    Game();                  // Constructeur
    void run();              // Méthode pour démarrer le jeu

private:
    sf::RenderWindow window; // Fenêtre du jeu
    sf::Texture backgroundTexture; // Texture pour l'image de fond
    sf::Sprite backgroundSprite;   // Sprite pour l'image de fond
    sf::RectangleShape button;     // Forme du bouton
    sf::Text startGameText;        // Texte pour le bouton
    sf::Font font;                 // Police de caractère pour le texte

    int currentLevel ;     // niveau de jeux 

    void loadResources();   // Méthode pour charger les ressources (fond, police)
    void handleEvents();    // Gérer les événements
    void update();          // Mise à jour de la logique de jeu (si nécessaire)
    void render();          // Rendu des éléments à l'écran
};

#endif
