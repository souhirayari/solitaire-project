
#ifndef UTILS_HPP           // Si UTILS_HPP n'est pas encore d�fini,
#define UTILS_HPP           // on le d�finit pour �viter les inclusions multiples (protection d'en-t�te)

#include <string>           // Inclusion de la biblioth�que string pour utiliser std::string

// D�claration de la fonction lireFichierConfig.
// Elle prend en param�tre :
// - le nom du fichier � lire (filename)
// - une r�f�rence vers un entier (nbBilles) pour r�cup�rer le nombre de billes
// - une r�f�rence vers une cha�ne de caract�res (mode) pour r�cup�rer le mode de jeu
// Elle retourne true si la lecture a r�ussi, false sinon.
bool lireFichierConfig(const std::string& filename, int& nbBilles, std::string& mode);

#endif                      // Fin de la protection d'en-t�te
