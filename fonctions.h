/*
 * fonctions.h

 *
 *  Created on: 30 sept. 2016
 *      Author: Nicolas
 */

#ifndef FONCTIONS_H_
#define FONCTIONS_H_
//#include "donnees.h"
#include "fonction_graph.h"


int saisieCoord(int *ligne, int *colonne); // demande saisie des coordonnees et renvoie un booleen sur la véracité de la saisie
int saisieOrient(char orientation[2]);
EtatCase ** initialisationJoueur();
int verifieCoordonnee(int ligne, int colonne);


#endif /* FONCTIONS_H_ */
