/**
 * @author Nieto Navarrete Matias
 * matricue : 502920
 */
#include "Texte.hpp"

char my_toupper(char ch){
    return static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
}

string majuscule(string minuscule){
    for (unsigned long i=0; i<minuscule.length(); ++i)
        minuscule[i] = my_toupper(minuscule[i]);
    return minuscule;
}

string supprime_caractere_non_alphabetique(const string &message){

    string message_alphabetique;
    for (unsigned long i=0; i<message.length(); ++i){
        if (isalpha(message[i]))
            message_alphabetique += message[i];
    }
    return message_alphabetique;
}

vector<string> divise_en_colonnes(const string &texte, size_t l){
    
    vector<string> colonnes;
    string partiel = "";

    for (unsigned long i=0; i<texte.length(); ++i){

        partiel += texte[i];
        if (l == 0)
            colonnes.push_back(partiel);
        else if ((i+1) % l == 0){
            colonnes.push_back(partiel);
            partiel = "";
        }  
    }
    
    return colonnes;
}
