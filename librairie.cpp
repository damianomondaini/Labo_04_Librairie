//
// Created by damia on 05.11.2020.
//

#include "librairie.h"
#include "cmath"

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