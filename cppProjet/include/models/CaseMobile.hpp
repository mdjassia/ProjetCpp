#ifndef CASE_MOBILE_HPP
#define CASE_MOBILE_HPP

#include "Case.hpp"
#include <SFML/Graphics.hpp>

class CaseMobile : public Case {
public:
    CaseMobile(int row, int col);   // Constructeur de base
    virtual void move(float dx, float dy) = 0; // Méthode abstraite pour le déplacement
    virtual void draw(sf::RenderWindow& window); // Dessiner la case

protected:
    sf::RectangleShape shape; // Forme graphique commune
};

#endif // CASE_MOBILE_HPP

