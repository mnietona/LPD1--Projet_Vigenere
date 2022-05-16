/**
 * @author Nieto Navarrete Matias
 * matricue : 502920
 */
#include "Fichier.hpp"

void lecture_fichier(const string &nom_fichier, string &texte){
    ifstream fichier(nom_fichier.c_str());
    if (fichier){
        string ligne;
        while (getline(fichier,ligne)){
            texte += ligne + "\n";
        }
        fichier.close();
    }else
        cout << "Impossible d'ouvrir le fichier !" << endl;
}

void ecriture_fichier(const string &nom_fichier, const string &texte){
    ofstream fichier(nom_fichier.c_str());
    if (fichier){
        fichier << texte;
        fichier.close();
    }else
        cout << "Impossible d'ouvrir le fichier !" << endl;

}
