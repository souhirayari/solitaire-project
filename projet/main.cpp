#include "board.hpp"
#include "utils.hpp"
#include <iostream>

int main() {
    int nbBilles;
    std::string mode;

    std::cout << "Entrez le nombre de billes (max 36): ";
    std::cin >> nbBilles;
    std::cout << "Entrez le mode (default ou random): ";
    std::cin >> mode;

    Board b;
    b.initialiser(nbBilles, mode);

    int sourceLigne, sourceCol, destLigne, destCol;
    bool continuer = true;

    while (continuer) {
        b.afficher();
        std::cout << "Entrez ligne source, colonne source, ligne destination, colonne destination (ou -1 pour quitter) : ";
        std::cin >> sourceLigne;
        if (sourceLigne == -1) {
            continuer = false;
            break;
        }
        std::cin >> sourceCol >> destLigne >> destCol;

        if (b.mouvementValide(sourceLigne, sourceCol, destLigne, destCol)) {
            b.deplacer(sourceLigne, sourceCol, destLigne, destCol);
            std::cout << "D�placement effectu�.\n";
        } else {
            std::cout << "D�placement invalide. R�essayez.\n";
        }
    }

    std::cout << "Fin du jeu.\n";
    return 0;
}
