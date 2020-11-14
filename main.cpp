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
#include <string>


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

		int choixMin = 0,
			 choixMax = 7;
		string choixTexte = "votre choix [" + to_string(choixMin) + " - " + to_string(choixMax) + "] : ";
		verifSaisie(choixTexte, choixOptions, choixMin, choixMax);

		switch((Fonction) choixOptions){
			case Fonction::EST_PAIR :{
				int valeur,
					 valeurMin = 0,
					 valeurMax = 1000;
				string texteFonction1 = "entrer une valeur [" + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
				verifSaisie(texteFonction1, valeur, valeurMin, valeurMax);
				cout << valeur << " est une valeur ";
				if(!estPair(valeur)) {
					cout << "im";
				}
				cout << "pair" << endl << endl;
				break;
			}
			case Fonction::SOMME_CHIFFRES :{
				int valeur,
					 valeurMin = 0,
					 valeurMax = 1000;
				string texteFonction2 = "entrer une valeur [" + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
				verifSaisie(texteFonction2, valeur, valeurMin, valeurMax);
				cout << "La somme des chiffres de " << valeur << " = " << sommeChiffres(valeur) << endl << endl;
				break;
			}
			case Fonction::NBRE1ER :{
				int valeur,
					 valeurMin = 0,
					 valeurMax = 1000;
				string texteFonction3 = "     - debut : [" + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
				cout << "Determiner les nombres premiers compris dans un intervalle" << endl;
				verifSaisie(texteFonction3, valeur, valeurMin, valeurMax);
				valeurMin = valeur;
				texteFonction3 = "     - fin   : [" + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
				verifSaisie(texteFonction3, valeur, valeurMin, valeurMax);
				valeurMax = valeur;
				for(int i = valeurMin; i <= valeurMax; ++i){
					if(nbre1er(i)){
						cout << "Le nombre " << i << " est un nombre premier" << endl;
					}
				}
			}
			case Fonction::NBRE_ARMSTRONG :{
				int valeur,
					 valeurMin = 0,
					 valeurMax = 1000;
				string texteFonction4 = "     - debut : [" + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
				cout << "Determiner les nombres de Armstrong compris dans un intervalle" << endl;
				verifSaisie(texteFonction4, valeur, valeurMin, valeurMax);
				valeurMin = valeur;
				texteFonction4 = "     - fin   : [" + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
				verifSaisie(texteFonction4, valeur, valeurMin, valeurMax);
				valeurMax = valeur;
				for(int i = valeurMin; i <= valeurMax; ++i){
					if(nbreArmstrong(i)){
						cout << "Le nombre " << i << " est un nombre de Armstrong" << endl;
					}
				}
			}
			case Fonction::RANDOM :{
			   // Déclaration des valeurs min et max par défaut
            int valeur,
               valeurMin = -100,
               valeurMax = 100,
               qteMin = 0,
               qteMax = 100;

            // Choix de la valeur min
            string texteFonction5 = "     - min   : [" + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
            verifSaisie(texteFonction5, valeur, valeurMin, valeurMax);
            valeurMin = valeur;

            // Choix de la valeur max
            texteFonction5 = "     - max   : [" + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
            verifSaisie(texteFonction5, valeur, valeurMin, valeurMax);
            valeurMax = valeur;

            // Choix de nombre d'élément à générer
            texteFonction5 = "     - nbre  : [" + to_string(qteMin) + " - " + to_string(qteMax) + "] : ";
            verifSaisie(texteFonction5, valeur, qteMin, qteMax);

            // Génération et affichage des nombres aléatoires
            cout << "Voici des valeurs aleatoires [" + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : " << endl;
            for(int noGeneration = 1; noGeneration <= valeur; ++noGeneration){
               cout << random(valeurMin, valeurMax);
               if(noGeneration != valeur){
                  cout << ", ";
               }
               if(noGeneration % 10 == 0){
                  cout << endl;
               }
            }
            cout << endl;

         }
				break;
			case Fonction::BUFFER : {
			   // Déclaration des variables pour stocker la saisie de l'utilisateur et exécuter la fonction buffer
            const char CHAR_MIN_BUFFER = 127;
            const char CHAR_MAJ_BUFFER = 0;
            string saisie;
            char lettreMin, lettreMaj;

            // Récupération de la saisie de l'utilisateur
            cout << "entrer une phrase : ";
            getline(cin, saisie);

            // Appel à la fonction buffer
            unsigned int nbreCharTraites = buffer(saisie, lettreMin, lettreMaj);

            // Affichage des informations traitées par la fonction buffer
            if (lettreMin != CHAR_MIN_BUFFER) {
               cout << "la plus petite minuscule : " << lettreMin << endl;
            }

            if (lettreMaj != CHAR_MAJ_BUFFER) {
               cout << "la plus grande majuscule : " << lettreMaj << endl;
            }

               cout << "le nbre de caracteres    : " << nbreCharTraites << endl << endl;

            break;
         }
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
		cout << texte;
		saisieOK = cin >> valeur && valeur >= borneInf && valeur <= borneSup;
		if(!saisieOK){
			cin.clear();
			cout << "Erreur de saisie" << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}while(!saisieOK);
}