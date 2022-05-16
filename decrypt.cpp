/**
 *
 * @file decrypt.cpp
 * @author Nieto Navarrete Matias
 * matricule : 502920
 * @brief Déchiffrement du chiffre de vigenere
 *
 */

#include "Vigenere.hpp"

int main(int argc, char *argv[]) {
    if (argc < 4) {
        cout << "Utilisation: ./decrypt <nom_fichier_chiffre> <mot_de_passe> <nom_fichier_dechiffre>" << endl;
        return 1;
    }

    string nom_fichier_chiffre = argv[1];
    string mot_de_passe = argv[2];
    string nom_fichier_dechiffre = argv[3];
    
    
    string plain,message = "";

    lecture_fichier(nom_fichier_chiffre,message);
    
    dechiffrement_de_vigenere(message,majuscule(mot_de_passe),plain);

    ecriture_fichier(nom_fichier_dechiffre,plain);

    return 0;
}
