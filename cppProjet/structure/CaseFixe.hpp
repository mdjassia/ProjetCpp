#ifndef CASE_FIXE_HPP
#define CASE_FIXE_HPP

#include "Case.hpp"
#include <SFML/Graphics.hpp>

class CaseFixe : public Case {
public:
    CaseFixe(int row, int col);  // Constructeur
    void setPosition(float x, float y);  // Positionner la case
    void draw(sf::RenderWindow& window); // Dessiner la case

private:
    sf::RectangleShape shape;  // Forme graphique de la case
};

#endif // CASE_FIXE_HPP
