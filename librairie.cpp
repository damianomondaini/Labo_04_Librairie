/*
  ---------------------------------------------------------------------------
  Fichier     : librairie.cpp
  Auteur(s)   : Anthony Jost, Damiano Mondaini
  Date        : 05.11.2020
  But         : Mettre à disposition les fonctions suivantes et expliquées
  					 dans le fichier "librairie.h"

  Remarque(s) : La source du code de la fonction random a été ajoutée en
  					 commentaire dans le fichier "librairie.h"
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
	int compteur 	 = 0;

	// La variable i va parcourir les valeurs entières entre 1 et la racine carrée de la valeur passée en paramètre.
	// Un nombre non-premier ayant de toute façon un diviseur inférieur ou égal à sa racine,
	// il n'y a aucune raison d'aller au delà de cette racine.
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
	int sommeCube = 0,
		 temp 	  = valeur;

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

int random(int borneInf, int borneSup){
	int valeurMaxRand = borneSup - borneInf + 1,
		 reste 			= RAND_MAX % valeurMaxRand,
		 valeurAleatoire;

	do
	{
		valeurAleatoire = rand();
	} while (valeurAleatoire >= RAND_MAX - reste);
	return borneInf + valeurAleatoire % valeurMaxRand;
}

unsigned int buffer(const std::string& contenuBuffer, char& lettreMin, char& lettreMaj) {
   lettreMin = std::numeric_limits<char>::max();
   lettreMaj = std::numeric_limits<char>::min();
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

void trigo(double angleDegres, double& sinus, double& cosinus, double& tangente){
	double angleRadians = angleDegres * M_PI / 180;  // Transforme les degrés en radians

	sinus 	= sin(angleRadians);
	cosinus  = cos(angleRadians);
	tangente = tan(angleRadians);
}

bool repondOui(const std::string& question, unsigned char reponseOui, unsigned char reponseNon){
   unsigned char reponse,
   				  reponseOuiMaj,
   				  reponseOuiMin,
   				  reponseNonMaj,
   				  reponseNonMin;

   // Détermination du caractère minuscule et majuscule pour répondre oui
   if (islower(reponseOui)) {
      reponseOuiMin = reponseOui;
      reponseOuiMaj = toupper(reponseOui);
   } else {
      reponseOuiMin = tolower(reponseOui);
      reponseOuiMaj = reponseOui;
   }

   // Détermination du caractère minuscule et majuscule pour répondre non
   if (islower(reponseNon)) {
      reponseNonMin = reponseNon;
      reponseNonMaj = toupper(reponseNon);
   } else {
      reponseNonMin = tolower(reponseNon);
      reponseNonMaj = reponseNon;
   }

   // Boucle faite tant que l'utilisateur ne répond ni le caractère pour répondre oui ni le caractère pour répondre non
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