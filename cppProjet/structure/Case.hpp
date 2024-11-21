#ifndef CASE_HPP
#define CASE_HPP

class Case {
public:
    Case(int row, int col);  // Constructeur avec ligne et colonne
    int getRow() const;      // Retourner la ligne
    int getCol() const;      // Retourner la colonne

protected:
    int row;  // Ligne de la case
    int col;  // Colonne de la case
};

#endif // CASE_HPP
