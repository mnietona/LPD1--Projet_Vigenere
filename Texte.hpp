/**
 * @author Nieto Navarrete Matias
 * matricue : 502920
 */
#include "common.hpp"


/**
 * @brief transforme le char en majuscule
 * 
 * @param ch le char a transformer en majuscule
 * @return char le char en majuscule
 */
char my_toupper(char ch);

/**
 * @brief Transforme tout les lettre qui sont dans le string en majuscule
 * 
 * @param minuscule le string a transformer en majuscule
 * @return string la chaine de caractere en majuscule 
 */
string majuscule(string minuscule);

/**
 * @brief supprime tout les caractere non alphabetique d'un string
 * 
 * @param message le message a supprimer les caractere non alphabetique
 * @return string le message sans les caractere non alphabetique
 */
string supprime_caractere_non_alphabetique(const string &message);

/**
 * @brief Divise le texte en l colonne
 * 
 * @param texte texte a diviser en colonne
 * @param l nombre de colonne
 * @return vector<string> le texte diviser en colonne
 */
vector<string> divise_en_colonnes(const string &texte, size_t l);

