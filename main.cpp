/*
  ---------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Labo 04 Librairie
  Auteur(s)   : Anthony Jost, Damiano Mondaini
  Date        : 05.11.200
  But         : -
  Remarque(s) : -
  Compilateur : Mingw-w64 g++ 8.1.0
  ---------------------------------------------------------------------------
*/

#include <iostream>                 // Gestion du flux
#include <cstdlib>                  // EXIT_SUCCESS et EXIT_FAILURE
#include <cmath>                    // Formules mathématiques
#include <ctime>                    // Gestion du temps
#include <cctype>                   // Opérations sur le buffer
#include <cassert>                  // TODO


#include "librairie.h"              // Librairie personnalisée

using namespace std;

enum class Fonction {EST_PAIR = 1, SOMME_CHIFFRES, NBRE1ER, NBRE_ARMSTRONG, RANDOM, BUFFER, TRIGO, REPOND_OUI = 0};

void verifSaisie(const string& texte, int& valeur, int borneInf, int borneSup);

int main() {

	int choixOptions;
	do{
		cout << "Options" 						  << endl
			  << "    1   est pair" 			  << endl
			  << "    2   somme chiffres" 	  << endl
			  << "    3   nombre 1er" 			  << endl
			  << "    4   nombre de Armstrong" << endl
			  << "    5   nombre aleatoire" 	  << endl
			  << "    6   buffer" 				  << endl
			  << "    7   trigo" 				  << endl
			  << "    0   quitter" 				  << endl
			  											  << endl;
		const string choixTexte = "votre choix [0 - 7] : ";
		int choixMin = 0,
			 choixMax = 7;

		verifSaisie(choixTexte, choixOptions, choixMin, choixMax);

		switch(Fonction (choixOptions)){
			case Fonction::EST_PAIR :
				break;
			case Fonction::SOMME_CHIFFRES :
				break;
			case Fonction::NBRE1ER :
				break;
			case Fonction::NBRE_ARMSTRONG :
				break;
			case Fonction::RANDOM :
				break;
			case Fonction::BUFFER :
				break;
			case Fonction::TRIGO :
				break;
			case Fonction::REPOND_OUI :
				break;
			default :
				break;
		}

	}while(choixOptions != 0);

   return EXIT_SUCCESS;
}

void verifSaisie(const string& texte, int& valeur, int borneInf, int borneSup) {
	bool saisieOK;

	do{
		cout << texte << endl;
		saisieOK = cin >> valeur && valeur >= borneInf && valeur <= borneSup;
		if(!saisieOK){
			cin.clear();
			cout << "Erreur de saisie" << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}while(!saisieOK);
}