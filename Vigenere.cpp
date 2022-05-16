/**
 * @author Nieto Navarrete Matias
 * matricue : 502920
 */
#include "Vigenere.hpp"

void dechiffrement_de_vigenere(const string &message, string clef, string &plain){
    short unsigned ascii = 0;
    unsigned int espace = 0;
    
    for (unsigned i=0; i < message.length(); ++i){
        if (isalpha(message[i])){
            if ( ( convert(message[i]) - convert(clef[(i - espace) % clef.length()]) ) < 0){
                ascii = convert(( LEN_ALPHABET + convert(message[i]) - convert(clef[(i - espace) % clef.length()]) ) % LEN_ALPHABET);
            }else
                ascii = convert(( convert(message[i]) - convert(clef[(i - espace) % clef.length()]) ) % LEN_ALPHABET);
            plain += static_cast<char>(ascii + ASCII_A);
        }else{
            plain += message[i];
            espace++;
        }
    }
}

struct Clef *trouve_candidat(const string &cypher, size_t l){
    struct Clef *candidat = new struct Clef;
    string texte = supprime_caractere_non_alphabetique(cypher);
    size_t longueur_clef = 1;

    float *erreur = new float[l+1];
    string *tab_clef = new string[l+1];

    for (size_t i = 1; i < l+1 ; ++i){
        vector<string> colonne = divise_en_colonnes(texte,i);
        string cle_non_dechiffrer = trouve_cle_non_dechiffrer(colonne,i);
        tab_clef[i] = cle_non_dechiffrer;

        float *error = new float [i];
        for (unsigned long a=0; a < i; ++a){
            string chaine_erreur = "";
            for (unsigned long j=0; j < colonne.size(); ++j)
                chaine_erreur += colonne[j][a];
            error[a] = frequence_lettre(chaine_erreur,cle_non_dechiffrer[a]);
        }
        erreur[i] = calcul_erreur(error,i);
        delete[] error;

        // permet de s'arreter une fois qu'il a remaquer qu'on doublais la bonne clef
        if ( (i > 5) and (i % longueur_clef == 0) and (candidat->erreur < 0.1) ){  
            string clef = trouve_cle_dechiffrer(tab_clef[longueur_clef]);
            if ( clef+clef == trouve_cle_dechiffrer(tab_clef[i]) )
                break;
        }

        if (abs(erreur[i]) < abs(erreur[longueur_clef])){
            longueur_clef = i;
            candidat->erreur = erreur[longueur_clef];
        }
        
    }
    
    candidat->longueur = longueur_clef;    
    candidat->clef = new char[longueur_clef];
    string cle = trouve_cle_dechiffrer(tab_clef[longueur_clef]);
    for (unsigned long i=0; i < longueur_clef; ++i)
        candidat->clef[i] = cle[i];
    candidat->clef[longueur_clef] = '\0';

    delete [] erreur;
    delete [] tab_clef;

    return candidat;

}

void decode(const string &cypher, struct Clef *clef, string &plain){
    dechiffrement_de_vigenere(cypher,clef->clef,plain);
}

void attack(const string &cypher, string &plain,size_t l){
        
        struct Clef *candidat = trouve_candidat(cypher,l);
        
        //cout << "clef : " << candidat->clef << endl;
        //cout << "longueur de la clef : " << candidat->longueur << endl;
        //cout << "erreur : " << candidat->erreur << endl;
        
        decode(cypher,candidat,plain);
        delete candidat;
    
}
