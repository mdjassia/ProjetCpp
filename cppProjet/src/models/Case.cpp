#include "../../include/models/Case.hpp"

Case::Case(int row, int col) : row(row), col(col) {}

int Case::getRow() const {
    return row;
}

int Case::getCol() const {
    return col;
}
