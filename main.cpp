/*
  ---------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Labo 04 Librairie
  Auteur(s)   : Anthony Jost, Damiano Mondaini
  Date        : 05.11.200
  But         : - Ecrire une librairie mettant à disposition les 8 fonctions
                  suivantes:

                  1) estPair
                  2) sommeChiffres
                  3) nbre1er
                  4) nbreArmstrong
                  5) random
                  6) buffer
                  7) trigo
                  8) repondOui
                - La librairie doit être réutilisable (pas de valeurs en dur)

  Remarque(s) : - La librairie doit être externe au fichier principal
                  (compilation séparée)
                - Utilisation de types énumérés, boucles et fonctions
                  demandée
  Compilateur : Mingw-w64 g++ 8.1.0
  ---------------------------------------------------------------------------
*/

#include <iostream>                 // Gestion du flux
#include <cstdlib>                  // EXIT_SUCCESS et EXIT_FAILURE
#include <string>                   // Utilisation du type string et ses méthodes


#include "librairie.h"              // Librairie personnalisée

using namespace std;

// Enumération pour trouver quelle fonction exécuter lors de la saisie de l'utilisateur
enum class Fonction {REPOND_OUI, EST_PAIR, SOMME_CHIFFRES, NBRE1ER, NBRE_ARMSTRONG, RANDOM, BUFFER, TRIGO};

// Fonction permettant de demander à l'utilisateur d'entrer une valeur entre deux bornes incluses tant que la
// valeur n'est pas entre les deux bornes
void verifSaisie(const string& texte, int& valeur, int borneInf, int borneSup);

int main() {

	int choixOptions; // Récupère le choix de l'utilisateur
	bool veutQuitter = false;

	// Boucle affichant le menu et permettant de lancer les fonctions tant que l'utilisateur ne souhaite pas quitter
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

		// Vérification de la saisie de l'utilisateur
		const int CHOIX_MIN = 0,
                CHOIX_MAX = 7;
		string choixTexte = "votre choix [" + to_string(CHOIX_MIN) + " - " + to_string(CHOIX_MAX) + "] : ";
		verifSaisie(choixTexte, choixOptions, CHOIX_MIN, CHOIX_MAX);

		// Test pour savoir quelle fonction a été choisie par l'utilisateur
		switch((Fonction) choixOptions){

			case Fonction::EST_PAIR : {
            // Déclaration des valeurs min et max par défaut
            int valeur,
					 valeurMin = 0,
					 valeurMax = 1000;

            // Saisie et vérification de l'entrée utilisateur
				string texteFonction1 = "entrer une valeur ["
				                        + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
				verifSaisie(texteFonction1, valeur, valeurMin, valeurMax);

				// Affichage si la valeur est paire ou impaire
				cout << valeur << " est une valeur ";
				if(!estPair(valeur)) {
					cout << "im";
				}
				cout << "pair" << endl << endl;

				break;
			}

			case Fonction::SOMME_CHIFFRES :{
            // Déclaration des valeurs min et max par défaut
            int valeur,
					 valeurMin = 0,
					 valeurMax = 1000;

            // Saisie et vérification de l'entrée utilisateur
            string texteFonction2 = "entrer une valeur ["
                                    + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
				verifSaisie(texteFonction2, valeur, valeurMin, valeurMax);

				// Affichage de la somme
				cout << "La somme des chiffres de " << valeur << " = " << sommeChiffres(valeur) << endl << endl;

				break;
			}

			case Fonction::NBRE1ER :{
            // Déclaration des valeurs min et max par défaut
            int valeur,
					 valeurMin = 0,
					 valeurMax = 1000;

            // Saisie et vérification de l'entrée utilisateur pour la borne inférieure
            string texteFonction3 = "     - debut : ["
                                    + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
				cout << "Determiner les nombres premiers compris dans un intervalle" << endl;
				verifSaisie(texteFonction3, valeur, valeurMin, valeurMax);
				valeurMin = valeur;

				// Saisie et vérification de l'entrée utilisateur pour la borne supérieure
				texteFonction3        = "     - fin   : ["
				                        + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
				verifSaisie(texteFonction3, valeur, valeurMin, valeurMax);
				valeurMax = valeur;

				// Appels à la fonction nombre1er pour les valeurs entre les bornes sasies
				for(int i = valeurMin; i <= valeurMax; ++i){
					if(nbre1er(i)){
						cout << "Le nombre " << i << " est un nombre premier" << endl;
					}
				}

            break;
			}

			case Fonction::NBRE_ARMSTRONG :{
            // Déclaration des valeurs min et max par défaut
            int valeur,
					 valeurMin = 0,
					 valeurMax = 1000;

            // Saisie et vérification de l'entrée utilisateur pour la borne inférieure
            string texteFonction4 = "     - debut : ["
                                    + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
				cout << "Determiner les nombres de Armstrong compris dans un intervalle" << endl;
				verifSaisie(texteFonction4, valeur, valeurMin, valeurMax);
				valeurMin = valeur;

            // Saisie et vérification de l'entrée utilisateur pour la borne supérieure
            texteFonction4        = "     - fin   : ["
                                  + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
				verifSaisie(texteFonction4, valeur, valeurMin, valeurMax);
				valeurMax = valeur;

            // Appels à la fonction nbreArmstrong pour les valeurs entre les bornes sasies
            for(int i = valeurMin; i <= valeurMax; ++i){
					if(nbreArmstrong(i)){
						cout << "Le nombre " << i << " est un nombre de Armstrong" << endl;
					}
				}

            break;
			}

			case Fonction::RANDOM :{
			   // Déclaration des valeurs min et max par défaut
            int valeur,
               valeurMin = -100,
               valeurMax = 100,
               qteMin = 0,
               qteMax = 100;

            // Choix de la valeur min
            string texteFonction5 = "     - min   : ["
                                  + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
            verifSaisie(texteFonction5, valeur, valeurMin, valeurMax);
            valeurMin = valeur;

            // Choix de la valeur max
            texteFonction5        = "     - max   : ["
                                  + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
            verifSaisie(texteFonction5, valeur, valeurMin, valeurMax);
            valeurMax = valeur;

            // Choix de nombre d'élément à générer
            texteFonction5        = "     - nbre  : ["
                                  + to_string(qteMin) + " - " + to_string(qteMax) + "] : ";
            verifSaisie(texteFonction5, valeur, qteMin, qteMax);

            // Génération et affichage des nombres aléatoires
            cout << "Voici des valeurs aleatoires ["
                    + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : " << endl;

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

            break;
         }

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

			case Fonction::TRIGO : {
            // Déclaration des valeurs min et max par défaut et sin, cos et tan.
            int valeur,
               valeurMin = 0,
               valeurMax = 360;
            double sin, cos, tan;

            // Récupération de la saisie de l'utilisateur
            string texteFonction7 = "entrer une valeur ["
                                  + to_string(valeurMin) + " - " + to_string(valeurMax) + "] : ";
            verifSaisie(texteFonction7, valeur, valeurMin, valeurMax);

            // Appel à la fonction trigo
            trigo(valeur, sin, cos, tan);

            // Affichage des valeurs du cos, sin et tan de l'angle saisie
            cout << "sin(" << valeur << ") = " << sin << endl;
            cout << "cos(" << valeur << ") = " << cos << endl;
            cout << "tan(" << valeur << ") = " << tan << endl << endl;

				break;
			}

			case Fonction::REPOND_OUI : {
			   veutQuitter = repondOui("voulez-vous quitter ? [o - n]", 'o', 'n');
            break;
         }

		}

	} while(!veutQuitter);

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