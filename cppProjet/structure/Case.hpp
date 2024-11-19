#ifndef CASE_HPP
#define CASE_HPP

#include <SFML/Graphics.hpp>

class Case {
public:
    Case(int row, int col);  // Constructeur avec ligne et colonne
    void setPosition(float x, float y);  // Définir la position de la case
    void draw(sf::RenderWindow& window);  // Dessiner la case
    int getRow() const;  // Retourner la ligne
    int getCol() const;  // Retourner la colonne

private:
    int row;  // Ligne de la case
    int col;  // Colonne de la case
    sf::RectangleShape shape;  // Forme de la case (Rectangle)
};

#endif // CASE_HPP
