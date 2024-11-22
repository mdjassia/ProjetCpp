#include "../../include/models/CaseMobileEnRotation.hpp"

CaseMobileEnRotation::CaseMobileEnRotation(int row, int col) : CaseMobile(row, col) {}

void CaseMobileEnRotation::rotate(float angle) {
    shape.rotate(angle); // Rotation par rapport à son centre
}

void CaseMobileEnRotation::move(float dx, float dy) {
    // Les cases en rotation ne bougent pas (mais vous pouvez adapter si besoin)
}
