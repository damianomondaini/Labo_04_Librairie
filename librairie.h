//
// Created by damia on 05.11.2020.
//

#ifndef LABO_04_LIBRAIRIE_LIBRAIRIE_H
#define LABO_04_LIBRAIRIE_LIBRAIRIE_H

// Vérifier si un entier est pair ou non
// Retourne si oui ou non par un booléen
bool estPair(int valeur);

// Calcule la somme des chiffres d'une valeur reçue
// Retourne la somme par un entier
int sommeChiffres(int valeur);

// Vérifie si un nombre passé par paramètre est 1er
// Retourne si oui ou non par un booléen
bool nbre1er(int valeur);


// Vérifie si le nombre passé par paramètre est un nombre d'Armstrong
// Retourne si oui ou non par booléen
bool nbreArmstrong(int valeur);

// Calcule le sinus, le cosinus et la tangante d'un angle en degré donné par paramètre
// Ne retourne rien et assigne les valeurs par référence
void trigo(double angle, double& sinus, double& cosinus, double& tangente);

// Détermine la plus petite minuscule et la plus grande majucule d'un string
// Retourne le nombre de caractères traités et assigne la plus petite minuscule et la plus grande majuscule par
// référence
unsigned int buffer(const std::string& contenuBuffer, char& lettreMin, char& lettreMaj);

// Code source: https://stackoverflow.com/a/11766794
// Génère un entier entre deux bornes incluses
// Retourne l'entier généré par un entier
int random(int borneInf, int borneSup);

#endif //LABO_04_LIBRAIRIE_LIBRAIRIE_H
