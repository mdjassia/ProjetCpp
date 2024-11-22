#ifndef CASE_MOBILE_EN_LIGNE_HPP
#define CASE_MOBILE_EN_LIGNE_HPP

#include "CaseMobile.hpp"
#include "Direction.hpp" // Inclusion de l'énumération Direction

class CaseMobileEnLigne : public CaseMobile {
public:
    CaseMobileEnLigne(int row, int col, Direction direction); // Constructeur

    // Méthodes de base
    void move(float delta);                  // Déplacer la case selon sa direction
    void setDirection(Direction newDirection); // Changer la direction possible
    Direction getDirection() const;          // Obtenir la direction actuelle

    // Redéfinition du dessin
    void draw(sf::RenderWindow& window) override;

private:
    int row;       // Ligne actuelle
    int col;       // Colonne actuelle
    Direction direction; // Direction possible de déplacement
};

#endif // CASE_MOBILE_EN_LIGNE_HPP
