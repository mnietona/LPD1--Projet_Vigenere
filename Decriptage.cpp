/**
 * @author Nieto Navarrete Matias
 * matricue : 502920
 */
#include "Decriptage.hpp"

char lettre_plus_utiliser(const string &texte){
    int frequences[LEN_ALPHABET] = {0};
    for (unsigned long i=0; i<texte.length(); ++i)
        frequences[ static_cast<int>(texte[i]) - ASCII_A] += 1;
    int max = 0;
    char lettre = ' ';
    for (int i = 0; i<LEN_ALPHABET ; i++ ){
        if (frequences[i] > max){
            max = frequences[i];
            lettre = static_cast<char>(i + ASCII_A);
        }
    }
    return lettre;
}

string trouve_cle_non_dechiffrer(vector<string> colonne, size_t l){
    
    string clef = "";
    unsigned short j = 0;

    do{
        string lettres_colonne = "";
        for (unsigned long i = 0; i < colonne.size() ; ++i){
            lettres_colonne += colonne[i][j];
        }
        j++;
        clef += lettre_plus_utiliser(lettres_colonne);
    }while (clef.length() < l);

    return clef;
}

string trouve_cle_dechiffrer(const string &clef){
    
    string cle_dechiffrer = "";

    for (unsigned short i=0; i < clef.length() ; ++i){
        double bonne_lettre = int(clef[i]) - ASCII_E;
        if (bonne_lettre < 0)
            bonne_lettre = LEN_ALPHABET + bonne_lettre;
        cle_dechiffrer += static_cast<char>(bonne_lettre + ASCII_A);
    }
    return cle_dechiffrer;
}

float frequence_lettre(string texte, char lettre){

    float nb_lettre = 0;
    for (long unsigned int i=0; i<texte.length(); ++i){
        if (texte[i] == lettre)
            nb_lettre ++;
    }
    return static_cast<float>(nb_lettre/ static_cast<float>(texte.length()));
}

float calcul_erreur(float erreur[], size_t l){
    double erreur_total = 0;
    for (unsigned short i=0; i<l; ++i)
        erreur_total += abs(erreur[i]-FREQUENCE_E);
    return static_cast<float>(erreur_total/static_cast<float>(l));
}
