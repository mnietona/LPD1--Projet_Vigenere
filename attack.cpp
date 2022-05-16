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
        cout << "Utilisation: ./attack <nom_fichier_chiffre> <mot_de_passe> <nom_fichier_dechiffre>" << endl;
        return 1;
    }
    
    string nom_fichier_chiffre = argv[1];
    int longueur_max_clef = stoi(argv[2]);
    string nom_fichier_dechiffre = argv[3];

    string plain,cypher = "";

    lecture_fichier(nom_fichier_chiffre,cypher);

    size_t max_possible = supprime_caractere_non_alphabetique(cypher).length();

    // chnage la valeur de L si elle depasse le nombre de caractere possible 
    if (static_cast<int>(max_possible) < longueur_max_clef)
           attack(cypher,plain,max_possible);
    else
        attack(cypher,plain,static_cast<size_t>(longueur_max_clef));

    ecriture_fichier(nom_fichier_dechiffre,plain);
   

    return 0;
}
