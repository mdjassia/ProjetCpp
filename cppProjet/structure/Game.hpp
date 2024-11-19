#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Level.hpp"
#include <vector>

class Game {
public:
    Game(); // Constructeur
    void run(); // Fonction principale de boucle du jeu

private:
    void loadResources(); // Charger les ressources
    void handleEvents(); // Gérer les événements
    void update(); // Mettre à jour l'état du jeu
    void render(); // Rendu du jeu
    void renderMenu(); // Rendu du menu
    void renderGame(); // Rendu du jeu (niveau actuel)

    sf::RenderWindow window; // Fenêtre du jeu
    bool inGame; // Flag pour savoir si on est en jeu
    int level; // Numéro du niveau actuel
    sf::RectangleShape button; // Bouton "Start Game"
    sf::Text startGameText; // Texte du bouton
    sf::Font font; // Police de caractère
    sf::Sprite backgroundSprite; // Sprite d'arrière-plan
    sf::Texture backgroundTexture; // Texture de l'arrière-plan

    std::vector<Level> levels; // Liste des niveaux
    Level* currentLevel; // Niveau actuel
};

#endif // GAME_HPP
