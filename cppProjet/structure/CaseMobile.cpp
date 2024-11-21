#include "CaseMobile.hpp"

CaseMobile::CaseMobile(int row, int col) : Case(row, col) {
    shape.setSize({64.0f, 64.0f});  // Taille par défaut
    shape.setFillColor(sf::Color::Green); // Couleur par défaut pour les cases mobiles
}

void CaseMobile::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
