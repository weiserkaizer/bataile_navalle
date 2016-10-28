/*
 * main.c
 *
 *  Created on: 22 oct. 2016
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"
#include "fonction_graph.h"
#include "donnees.h"

int main()
{
	srand(time(NULL)); //Initialisation de la seed avec le temps machine pour la génération de nombre pseudo-aléatoire
    system("CLS");

	Navire * typeNavire = initTypeNavire();
	EtatCase **joueur = initialisationJoueur();
	EtatCase **ordinateur = initialisationJoueur();

    intro();
	afficher(joueur, ordinateur);

	int i;

	for(i = 4; i >= 0; i--)
	{

		int ligne,colonne, bonneCoord, bonneOrientation;
		char orientation[3];

		do
		{
		    printf("\nVeulliez placer le %s (%d cases) : ", typeNavire[i].nom, typeNavire[i].taille);

			do
			{
				bonneCoord = saisieCoord(&ligne, &colonne);

				if(bonneCoord == -1)
				{
					return 0;
				}
			}while(bonneCoord == 0);

			do
			{
				bonneOrientation = saisieOrient(orientation);

				if(bonneOrientation == -1)
				{
					return 0;
				}
			}while(bonneOrientation == 0);

		}while(verifieCoordonnee(typeNavire[i].taille, orientation, ligne, colonne, joueur) == 0);
		placerNavire(typeNavire, i, orientation, ligne, colonne, joueur,'J');
		//system("CLS");
		afficher(joueur, ordinateur);
	}

	placementNavireOrdinateur(ordinateur, typeNavire);

	afficher(joueur, ordinateur);

	while(1)
	{
		tirer(ordinateur, 'O');
		afficher(joueur, ordinateur);
	}

	system("pause");

	return 0;
}
