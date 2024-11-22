#ifndef CASE_MOBILE_EN_ROTATION_HPP
#define CASE_MOBILE_EN_ROTATION_HPP

#include "CaseMobile.hpp"

class CaseMobileEnRotation : public CaseMobile {
public:
    CaseMobileEnRotation(int row, int col);  // Constructeur
    void rotate(float angle);                // Faire tourner la case
    void move(float dx, float dy) override;  // Implémentation inutile ici
};

#endif // CASE_MOBILE_EN_ROTATION_HPP
