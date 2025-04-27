#include "utils.hpp"         // Inclusion du fichier d�en-t�te correspondant (d�claration de la fonction)
#include <fstream>           // Pour manipuler les fichiers (ifstream)
#include <sstream>           // Pour utiliser les flux de cha�nes (istringstream)
#include <iostream>          // Pour afficher des messages si besoin (std::cout, std::cerr)

// Fonction qui lit un fichier de configuration et extrait les param�tres nbBilles et mode
bool lireFichierConfig(const std::string& filename, int& nbBilles, std::string& mode) {
    std::ifstream file(filename);  // Ouvre le fichier en lecture

    if (!file.is_open()) return false; // Si le fichier ne s'ouvre pas, on renvoie false (�chec)

    std::string line;
    nbBilles = 15;           // Valeur par d�faut si non pr�cis�e dans le fichier
    mode = "default";        // Mode par d�faut

    // Lecture ligne par ligne du fichier
    while (std::getline(file, line)) {
        std::istringstream iss(line);  // Cr�e un flux � partir de la ligne
        std::string key, val;

        // Tente de s�parer chaque ligne selon le format "cl�=valeur"
        if (std::getline(iss, key, '=') && std::getline(iss, val)) {
            // Si la cl� est "nb_billes", on convertit la valeur en int
            if (key == "nb_billes") nbBilles = std::stoi(val);
            // Si la cl� est "mode", on utilise la cha�ne telle quelle
            else if (key == "mode") mode = val;
        }
    }

    return true; // Lecture r�ussie
}
