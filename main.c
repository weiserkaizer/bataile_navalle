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
    //runIntro();
	system("color 1F");
	srand(time(NULL)); //Initialisation de la seed avec le temps machine pour la génération de nombre pseudo-aléatoire
    system("CLS");

	Navire * typeNavire = initTypeNavire();
	EtatCase **joueur = initialisationJoueur();
	EtatCase **ordinateur = initialisationJoueur();
	EtatCase **ordinateurAffichage = initialisationJoueur();

	int  ligne,colonne, verifieSaisie;

    intro();
	afficher(joueur, ordinateurAffichage);

	int i;

	for(i = 4; i >= 0; i--) printf("%s %d\n", navireJoueur[i].acronyme, navireJoueur[i].survivabilite);

	for(i = 4; i >= 0; i--)
	{

		int bonneCoord, bonneOrientation;
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
		afficher(joueur, ordinateurAffichage);
	}

	placementNavireOrdinateur(ordinateur, typeNavire);

	afficher(joueur, ordinateurAffichage);

	while(1)
	{
		do
		{
			verifieSaisie = saisieCoord(&ligne, &colonne);
		}while(verifieSaisie == 0);

		tirer(ordinateur, ordinateurAffichage, 'O', ligne, colonne);
		tireAutomatique(joueur);
		afficher(joueur, ordinateurAffichage);
	}

	system("pause");


	return 0;
}
