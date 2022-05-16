"""
file : encrypt.py
author : Nieto Navarrete Matias
matricule : 502920
brief : Chiffrement à l’aide du chiffre de Vigenère
"""

import sys

def chiffre_de_vigenere(message,clef):
    """
    Chiffre le message recu à l'aide d'une cle
    message : le message a chiffrer
    cle : la cle pour chiffre le message
    return : le message chiffrer
    """
    LEN_ALPHABET , ASCII_A = 26 , ord('A')
    message_crypter = ""
    espace = 0
    for i in range(len(message)):
        if message[i].isalpha():
            ascii =  (ord(message[i]) + ord(clef[(i - espace) % len(clef)])) % LEN_ALPHABET
            message_crypter += chr(ascii+ASCII_A)
        else:
            message_crypter += message[i]
            espace += 1

    return message_crypter


def main():
    if len(sys.argv) < 4:
       print("Utilisation: python encrypt.py <nom_fichier_clair> <mot_de_passe> <nom_fichier_chiffre>", file=sys.stderr)
       sys.exit(1)
    
    
    nom_fichier_clair: str = sys.argv[1]
    mot_de_passe: str = sys.argv[2]
    nom_fichier_chiffre: str = sys.argv[3]

    # Lecture et ecriture
    with open(nom_fichier_clair) as f, open(nom_fichier_chiffre,"w") as f2:
       f2.write(chiffre_de_vigenere(f.read().upper(),mot_de_passe.upper()))
    

if __name__ == "__main__":
   main()







