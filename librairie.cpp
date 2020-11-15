/*
  ---------------------------------------------------------------------------
  Fichier     : librairie.cpp
  Auteur(s)   : Anthony Jost, Damiano Mondaini
  Date        : 05.11.200
  But         : -
  Remarque(s) : -
  Compilateur : Mingw-w64 g++ 8.1.0
  ---------------------------------------------------------------------------
*/

#include <cmath>
#include <cstdlib>
#include <string>
#include <cctype>
#include <iostream>
#include <limits>
#include "librairie.h"

bool estPair(int valeur){
   bool estPair = valeur % 2 == 0;
   return estPair;
}

void trigo(double angleDeg, double& sinus, double& cosinus, double& tangente){
   double angleRad = angleDeg * M_PI / 180;  // Transforme les degrés en radians
   sinus = sin(angleRad);
   cosinus = cos(angleRad);
   tangente = tan(angleRad);
}

int random(int borneInf, int borneSup){
   int valeurMaxRand = borneSup - borneInf + 1;
   int reste = RAND_MAX % valeurMaxRand;
   int valeurAleatoire;
   do
   {
      valeurAleatoire = rand();
   } while (valeurAleatoire >= RAND_MAX - reste);
   return borneInf + valeurAleatoire % valeurMaxRand;
}

int sommeChiffres(int valeur){
	int sommeChiffres = 0;
	while(valeur != 0){
		sommeChiffres += valeur % 10;
		valeur /= 10;
	}
	return sommeChiffres;
}

bool nbre1er(int valeur){
	bool estPremier = true;
	int compteur = 0;
	for(int i = 1; i <= (int)sqrt((double)valeur); ++i){
		if(valeur % i == 0){
			++compteur;
		}
	}
	if(compteur > 1){
		estPremier = false;
	}
	return estPremier;
}

bool nbreArmstrong(int valeur) {
	bool nbreArmstrong;
	int sommeCube = 0;
	int temp = valeur;
	while(temp != 0){
		sommeCube += (int)pow((double)(temp % 10),3);
		temp /= 10;
	}
	if(sommeCube == valeur){
		nbreArmstrong = true;
	} else {
		nbreArmstrong = false;
	}
	return nbreArmstrong;
}

unsigned int buffer(const std::string& contenuBuffer, char& lettreMin, char& lettreMaj) {
   lettreMin = 127;
   lettreMaj = 0;
   // Boucle sur chaque caractère
   for (char charPos : contenuBuffer) { // Condition suggérée par CLion
      // Test si le caractère est alphabètique
      if (isalpha(charPos)) {
         // Test si le caractère est minuscule
         if (islower(charPos)) {
            if (charPos < lettreMin) {
               lettreMin = charPos;
            }
         } else { // Sinon le caractère est majuscule
            if (charPos > lettreMaj) {
               lettreMaj = charPos;
            }
         }
      }
   }
   return contenuBuffer.length();
}

bool repondOui(const std::string& question, unsigned char reponseOui, unsigned char reponseNon){
   // Déclaration des variables
   unsigned char reponse;
   unsigned char reponseOuiMaj;
   unsigned char reponseOuiMin;
   unsigned char reponseNonMaj;
   unsigned char reponseNonMin;

   // Détermination du caractère minuscule et majuscule pour répondre oui
   if (islower(reponseOui)) {
      reponseOuiMin = reponseOui;
      reponseOuiMaj = reponseOui - 32;
   } else {
      reponseOuiMin = reponseOui + 32;
      reponseOuiMaj = reponseOui;
   }

   // Détermination du caractère minuscule et majuscule pour répondre non
   if (islower(reponseNon)) {
      reponseNonMin = reponseNon;
      reponseNonMaj = reponseNon - 32;
   } else {
      reponseNonMin = reponseNon + 32;
      reponseNonMaj = reponseNon;
   }

   // Boucle faite tant que l'utilisateur ne répond ni le caractère pour répondre oui nile caractère pour répondre non
   // qu'il soit majuscule ou minuscule
   do {
      std::cout << question << std::endl;
      std::cin >> reponse;

      if (std::cin.fail()) {
         std::cin.clear();
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      if (reponse == reponseOuiMin || reponse == reponseOuiMaj) {
         return true;
      }

      if (reponse == reponseNonMin || reponse == reponseNonMaj) {
         return false;
      }
   } while (true);
}