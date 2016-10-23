/*
 * main.c
 *
 *  Created on: 22 oct. 2016
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "fonction_graph.h"
#include "donnees.h"

int main()
{
	Navire * typeNavire = initTypeNavire();
	EtatCase **joueur = initialisationJoueur();
	EtatCase **ordinateur = initialisationJoueur();
	afficher(joueur, ordinateur);

	int i;

	for(i = 0; i < 5; i++)
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
		placerNavire(typeNavire[i].taille, orientation, ligne, colonne, joueur);
		system("CLS");
		afficher(joueur, ordinateur);
	}

	return 0;
}
