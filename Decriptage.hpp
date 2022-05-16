/**
 * @author Nieto Navarrete Matias
 * matricue : 502920
 */
#include "Texte.hpp"


/**
 * @brief Trouve la lettre la plus utiliser dans un texte
 * 
 * @param texte le texte dans lequel on cherche la lettre la plus utiliser
 * @return char la lettre la plus utiliser
 */
char lettre_plus_utiliser(const string &texte);

/**
 * @brief Trouve la cle possible de taille l non dechiffre de la colonnne
 * 
 * @param colonne colonne pour trouver la clef
 * @param l taille de la clef
 * @return string la clef trouvee non dechiffrer
 */
string trouve_cle_non_dechiffrer(vector<string> colonne, size_t l);

/**
 * @brief dechiffre la clef
 * 
 * @param clef la clef a dechiffrer
 * @return string la clef dechiffrer
 */
string trouve_cle_dechiffrer(const string &clef);

/**
 * @brief Calcul la frequence d'un caractere dans un string
 * 
 * @param texte le texte dans lequel on cherche la frequence
 * @param lettre la lettre a chercher
 * @return float la frequence de la lettre dans le texte
 */
float frequence_lettre(string texte, char lettre);

/**
 * @brief calcul l'erreur de la clef en fesant la moyenne des distances 
 * entre la lettre la plus fréquente et la fréquence attendue de la lettre e en français
 * 
 * @param erreur la frequence de la lettre
 * @param l la taille de la clef
 * @return float l'erreur de la clef
 */
float calcul_erreur(float *erreur, size_t l);

