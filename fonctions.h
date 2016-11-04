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

Navire * initTypeNavire();
EtatCase ** initialisationJoueur();
int saisieCoord(int *ligne, int *colonne); // demande saisie des coordonnees et renvoie un booleen sur la véracité de la saisie
int saisieOrient(char orientation[3]);
int verifieCoordonnee(int tailleNavire, char orientationNavire[3], int ligne, int colonne, EtatCase ** plateau);
void placerNavire(Navire *navire, int numNavire,char orientationNavire[3], int ligne, int colonne, EtatCase ** plateau, char player);
void positionAleatoire(int *ligne, int *colonne);
void orientationAleatoire(char *orientation);
void placementNavireOrdinateur(EtatCase ** plateauOrdi, Navire *listeNavire);

int verificationTire(EtatCase **plateau, int ligne, int colonne);
void coulerNavire(EtatCase **plateau, int ligneExtrem1, int ligneExtrem2, int colonneExtrem1, int colonneExtrem2);
void toucherNavire(EtatCase ** plateau, char player, int ligne, int colonne);
void tirer(EtatCase ** plateau, char player, int ligne, int colonne);
void tireAutomatique(EtatCase ** plateau);

void runIntro();

#endif /* FONCTIONS_H_ */
