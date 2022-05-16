/**
 * @author Nieto Navarrete Matias
 * matricue : 502920
 */
#include "Fichier.hpp"

template <typename T>
short unsigned convert(T x) { return static_cast<short unsigned>(x); }

/**
 * @brief Dechiffre un message a l'aide d'une clef
 * 
 * @param message Le message a dechiffrer
 * @param clef La clef pour dechiffrer le message
 * @param plain String qui contiendra le message decrypter

*/
void dechiffrement_de_vigenere(const string &message, string clef,string &plain);

/**
 * Renvoi la meilleur clef pour dechiffrer le texte sous forme de struct 
 * Clef (cfr. l'énoncé pour sa déclaration)
 *
 * @param cypher Le message chiffré
 * @param l la longueur de la clé
 */
struct Clef *trouve_candidat(const string &cypher, size_t l);

/**
 * Dechiffre un message chiffré encodé à l'aide du chiffre de Vigenère et 
 * d'une clé connue.
 *
 * @param cypher Le message à déchiffrer
 * @param clef La clef
 * @param plain String qui contiendra le message déchiffré après l'appel
 */
void decode(const string &cypher, struct Clef *clef, string &plain);

/**
 * Déchiffre un message encodé à l'aide du chiffre de Vigenère sans avoir 
 * connaissance du mot de passe
 *
 * @param cypher Le message à déchiffrer
 * @param plain String qui contiendra le message déchiffré après l'appel
 */
void attack(const string &cypher, string &plain,size_t l);


