# Projet Vigenère - Langage de Programmation 1

## Description

Ce projet a été développé dans le cadre du cours de Langage de Programmation 1. Il implémente l'algorithme de chiffrement Vigenère, permettant de chiffrer et de déchiffrer des messages à l'aide d'un mot de passe. De plus, il inclut une fonctionnalité d'attaque pour tenter de retrouver le mot de passe utilisé dans le chiffrement d'un message.

## Compilation

Pour compiler le projet, utilisez la commande suivante dans le terminal :

```bash
make
```

Cette commande va compiler les scripts nécessaires et les programmes C pour l'encryption, la décryption, et l'attaque de Vigenère.

## Utilisation

### Chiffrement

Pour chiffrer un message, exécutez :

```bash
python3 encrypt.py <fichier_clair> <mdp> <fichier_chiffrer>
```

- `<fichier_clair>` : le chemin vers le fichier contenant le message en clair à chiffrer.
- `<mdp>` : le mot de passe utilisé pour le chiffrement.
- `<fichier_chiffrer>` : le chemin où sera sauvegardé le message chiffré.

### Déchiffrement

Pour déchiffrer un message, utilisez :

```bash
./decrypt <fichier_chiffrer> <mdp> <fichier_clair>
```

### Attaque de Vigenère

Pour lancer une attaque afin de tenter de retrouver le mot de passe d'un message chiffré, exécutez :

```bash
./attack <fichier_chiffrer> <L> <fichier_clair>
```

- `<L>` : la longueur supposée du mot de passe. Cette valeur doit être déterminée par l'utilisateur basée sur une analyse ou une hypothèse.

## Objectifs du Projet

Le but de ce projet était double : 
1. Implémenter le chiffrement et le déchiffrement de messages à l'aide de l'algorithme de Vigenère, en se servant d'un mot de passe.
2. Explorer les techniques d'analyse cryptographique en développant une attaque permettant de retrouver le mot de passe utilisé pour chiffrer un message.
