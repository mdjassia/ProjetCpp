#include "CaseFixe.hpp"

CaseFixe::CaseFixe(int row, int col) : Case(row, col) {
    shape.setSize({64.0f, 64.0f});  // Taille fixe
    shape.setFillColor(sf::Color(175, 219, 235));  // Couleur spécifique aux cases fixes
}

void CaseFixe::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

void CaseFixe::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
