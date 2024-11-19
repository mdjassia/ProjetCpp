#include "Case.hpp"

Case::Case(int row, int col) : row(row), col(col) {
    shape.setSize(sf::Vector2f(64, 64));  // Taille de chaque case
    shape.setFillColor(sf::Color(175, 219, 235));  // Couleur de remplissage par défaut (bleu)
}

void Case::setPosition(float x, float y) {
    shape.setPosition(x, y);  // Définir la position de la case
}

void Case::draw(sf::RenderWindow& window) {
    window.draw(shape);  // Dessiner la case sur la fenêtre
}

int Case::getRow() const {
    return row;  // Retourner la ligne de la case
}

int Case::getCol() const {
    return col;  // Retourner la colonne de la case
}
