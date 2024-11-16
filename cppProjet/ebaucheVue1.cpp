#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm> // Pour std::max et std::min
#include <cmath> // Pour std::round

using namespace std;
using namespace sf;


int main() {
    // Parametres graphiques
    int MARGIN_LEFT = 100, MARGIN_RIGHT = 100, MARGIN_TOP = 100, MARGIN_BOTTOM = 100;
    int TILE_SIZE = 64;
    int NB_COL = 6, NB_LIGNE = 1; // Niveau 1 : 1 ligne et 6 colonnes
    unsigned int nbPix_x = MARGIN_LEFT + MARGIN_RIGHT + NB_COL * TILE_SIZE;
    unsigned int nbPix_y = MARGIN_TOP + MARGIN_BOTTOM + NB_LIGNE * TILE_SIZE;

    // Définition d'un panneau "central"
    RectangleShape centralPane(Vector2f(NB_COL * TILE_SIZE, NB_LIGNE * TILE_SIZE));
    centralPane.setPosition(MARGIN_LEFT, MARGIN_TOP);
    centralPane.setFillColor(Color::White); 

    // Définition de la grille
    VertexArray trame(Lines, (NB_COL + 1 + NB_LIGNE + 1) * 2);
    int n = 0;
    for (int i = 0; i <= NB_LIGNE; ++i) {
        trame[n++].position = Vector2f(MARGIN_LEFT, MARGIN_TOP + i   * TILE_SIZE);
        trame[n].color = Color::White;
        trame[n++].position = Vector2f(nbPix_x - MARGIN_RIGHT, MARGIN_TOP + i * TILE_SIZE);
    }
    for (int i = 0; i <= NB_COL; ++i) {
        trame[n++].position = Vector2f(MARGIN_LEFT + i * TILE_SIZE, MARGIN_TOP);
        trame[n].color = Color::White;
        trame[n++].position = Vector2f(MARGIN_LEFT + i * TILE_SIZE, nbPix_y - MARGIN_BOTTOM);
    }

    // Création du carré rouge
    RectangleShape redSquare(Vector2f(TILE_SIZE, TILE_SIZE));
    redSquare.setFillColor(Color::Red);
    redSquare.setPosition(MARGIN_LEFT, MARGIN_TOP);

    // Création des triangles
    CircleShape leftTriangle(8.f, 3); // Triangle à gauche
    leftTriangle.setFillColor(Color::White); // Colorie le triangle
    leftTriangle.setOrigin(8.f, 8.f); // Positionner l'origine au centre du triangle
    leftTriangle.setPosition(MARGIN_LEFT + TILE_SIZE / 2 - 20.f, MARGIN_TOP + TILE_SIZE / 2); // Position initiale à gauche du carré
    leftTriangle.rotate(270.f); 

    CircleShape rightTriangle(8.f, 3); // Triangle à droite
    rightTriangle.setFillColor(Color::White); // Colorie le triangle
    rightTriangle.setOrigin(8.f, 8.f); // Positionner l'origine au centre du triangle
    rightTriangle.setPosition(MARGIN_LEFT + TILE_SIZE / 2 + 20.f, MARGIN_TOP + TILE_SIZE / 2);// Position initiale à droite du carré
    rightTriangle.rotate(90.f); 

    // Création du carré rose (objectif)
    RectangleShape pinkSquare(Vector2f(TILE_SIZE, TILE_SIZE));
    pinkSquare.setFillColor(Color::Magenta);
    pinkSquare.setPosition(MARGIN_LEFT + (NB_COL - 1) * TILE_SIZE, MARGIN_TOP);

    // Opérations graphiques générales
    RenderWindow window{ VideoMode{nbPix_x, nbPix_y}, "Piece Out - Niveau 1" };
    bool isDragging = false;
    Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("packGroundGame.png")) { // Remplacez "background.jpg" par le nom de votre image
            cout << "Erreur de chargement de l'image de fond !" << endl;
            return EXIT_FAILURE; // Si l'image ne se charge pas, quitter
        }
    while (window.isOpen()) {
        
        Vector2i mousePos = Mouse::getPosition(window);
        Vector2f mouseWorldPos = window.mapPixelToCoords(mousePos);
        // Chargement de l'image de fond
       
        Sprite backgroundSprite(backgroundTexture); // Crée un sprite à partir de la texture

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed ||
                (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
                window.close();

            // Détection du clic sur le carré rouge pour le déplacer
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                if (redSquare.getGlobalBounds().contains(mouseWorldPos)) {
                    isDragging = true;
                }
            }

            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                isDragging = false;

                // Vérification si le carré rouge atteint le carré rose
                if (redSquare.getGlobalBounds().intersects(pinkSquare.getGlobalBounds())) {
                    cout << "Bravo !" << endl;
                }
            }
        }

        // Déplacement du carré rouge avec la souris
        if (isDragging) {
            // Calcul de la nouvelle position en X
            float newX = mouseWorldPos.x - TILE_SIZE / 2;

            // Assurez-vous que le carré reste dans les limites des colonnes
            newX = std::max(static_cast<float>(MARGIN_LEFT), std::min(newX, static_cast<float>(MARGIN_LEFT + (NB_COL - 1) * TILE_SIZE)));


            // Aligner le mouvement case par case (arrondir à la taille de la case)
            newX = MARGIN_LEFT + std::round((newX - MARGIN_LEFT) / TILE_SIZE) * TILE_SIZE;

            // Mettre à jour la position du carré rouge
            redSquare.setPosition(newX, MARGIN_TOP);

            // Mettre à jour la position des triangles pour qu'ils suivent le carré
            leftTriangle.setPosition(newX + TILE_SIZE / 2 - 20.f, MARGIN_TOP + TILE_SIZE / 2);
            rightTriangle.setPosition(newX + TILE_SIZE / 2 + 20.f, MARGIN_TOP + TILE_SIZE / 2);
        }

        window.clear(); // Nettoie la fenêtre avant d'afficher de nouveaux éléments

        // Dessiner l'arrière-plan
        window.draw(backgroundSprite); // Affiche l'image de fond

        window.setView(window.getDefaultView());

        // Affichage
        window.draw(centralPane);
        window.draw(trame);
        window.draw(pinkSquare);
        window.draw(redSquare);
        window.draw(leftTriangle); // Dessine le triangle gauche
        window.draw(rightTriangle); // Dessine le triangle droit

        window.display();
    }

    return EXIT_SUCCESS;
}
