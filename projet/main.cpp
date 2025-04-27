#include "board.hpp"
#include "utils.hpp"
#include <iostream>

int main() {
    Board b;

    int nbBilles = b.demanderNombre("Entrez le nombre de billes (max 36): ");
    std::string mode;
    std::cout << "Entrez le mode (default ou random): ";
    std::cin >> mode;

    b.initialiser(nbBilles, mode);

    int sourceLigne, sourceCol, destLigne, destCol;
    bool continuer = true;

    while (continuer) {
        b.afficher();
        std::cout << "Entrez ligne source, colonne source, ligne destination, colonne destination (ou -1 pour quitter) :\n";

        sourceLigne = b.demanderNombre("Ligne source : ");
        if (sourceLigne == -1) {
            continuer = false;
            break;
        }
        sourceCol = b.demanderNombre("Colonne source : ");
        destLigne = b.demanderNombre("Ligne destination : ");
        destCol = b.demanderNombre("Colonne destination : ");

        if (b.mouvementValide(sourceLigne, sourceCol, destLigne, destCol)) {
            b.deplacer(sourceLigne, sourceCol, destLigne, destCol);
            std::cout << "Déplacement effectué.\n";
        } else {
            std::cout << "Déplacement invalide. Réessayez.\n";
        }
    }

    std::cout << "Fin du jeu.\n";
    return 0;
}
