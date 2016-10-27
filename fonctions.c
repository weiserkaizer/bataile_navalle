/*
 * fonctions.c

 *
 *  Created on: 30 sept. 2016
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "donnees.h"
#include "fonction_graph.h"


Navire * initTypeNavire()
{
    Navire * typeNavire= malloc(sizeof(Navire)*5);
    strcpy((typeNavire[0]).nom, "Torpilleur"); (typeNavire[0]).taille = 2;
    strcpy((typeNavire[1]).nom, "Sous-Marin"); (typeNavire[1]).taille = 3;
    strcpy((typeNavire[2]).nom, "Contre-Torpilleur"); (typeNavire[2]).taille = 3;
    strcpy((typeNavire[3]).nom, "Croiseur"); (typeNavire[3]).taille = 4;
    strcpy((typeNavire[4]).nom, "Porte-Avion"); (typeNavire[4]).taille = 5;

    return typeNavire;
}

EtatCase ** initialisationJoueur()
{
	int i,j;
	EtatCase ** grilleJoueur = malloc(sizeof(EtatCase *) * TAILLEPLATEAU);

	for(i = 0; i < 10; i++)
	{
		grilleJoueur[i] = malloc(sizeof(EtatCase)* TAILLEPLATEAU);
	}

	for(i = 0; i < TAILLEPLATEAU; i++)
	{
		for(j = 0; j < TAILLEPLATEAU; j++)
		{
			grilleJoueur[i][j] = creeVarEtat("celVide", "NONE", "n", "NONE");
		}
	}

	return grilleJoueur;
}

int saisieCoord(int *ligne, int *colonne)
{
	const int tailleSaisie = 10;//nombre maximal de cararctere que peut entrer l'utilisateur
	char saisie[tailleSaisie];
	int row, line, change = 0;
	int i = 0, okLettre = 0, okChiffre = 0;
	/* saisie : tableau de caractere contenant la saisie utilisateur ; i : compteur ;
	okLettre : variable pour verifier que l'on prend en compte une seule lettre (la 1er); okChiffre : idem mais pour les chiffres */

	printf("Saisir case : ");
	gets(saisie);
	//Récupére la saisie utilisateur(~ scanf()) avec prise en compte des espaces

	while((saisie[i] != '\0') || (i < tailleSaisie))		//Boucle permettant de convertir les coordonnees saisie par l'utilisateur
	{														//en coordonnees (chiffrés) allant de 0 -> 9
		if(((saisie[i] == 'q') ||  (saisie[i] == 'Q')) && (okLettre == 0) && (okChiffre == 0))
		{
			return -1;
		}
		if((saisie[i] >= 'A') && (saisie[i] <= 'J') && (okLettre == 0))
		{
			row = saisie[i] - 'A';
			okLettre += 1;
		}
		else if((saisie[i] >= 'a') && (saisie[i] <= 'j')  && (okLettre == 0))
		{
			row = saisie[i] - 'a';
			okLettre += 1;
		}
		else if((saisie[i] >= '2') && (saisie[i] <= '9')  && (okChiffre == 0))
		{
			line = saisie[i] - '1';
			change = 1;
			okChiffre += 1;
		}
		else if((saisie[i] == '1')  && (okChiffre == 0))
		{
			if( ((i+1) < tailleSaisie) && (saisie[i+1] == '0') )
			{
				line = 9;
				change = 1;
				okChiffre += 1;
			}
			else
			{
				line = 0;
				change = 1;
				okChiffre += 1;
			}
		}
		else if(((saisie[i] >= 'A') && (saisie[i] <= 'J')) || ((saisie[i] >= 'a') && (saisie[i] <= 'j')))
		{
			okLettre += 1;
		}
		else if ((saisie[i] >= '0') && (saisie[i] <= '9') && (line!= 9)) //ligne !=9 dans le cas ou l'utilisateur saisie 10
		{
			okChiffre += 1;
		}
		i++;
	}

	if((okChiffre == 1) && (okLettre == 1) && (change == 1))		//Verifie si la saisie était correct
	{											// si okChiffre + okLettre == 2 alors saisie correct
		*colonne = row;							// sinon saisie incorrect
		*ligne = line;
		return 1;
	}
	else
	{
		return 0;
	}
}


int saisieOrient(char orient[3])
{
	const int tailleSaisie = 10;//nombre maximal de cararctere que peut entrer l'utilisateur
	char saisie[tailleSaisie];
	int i = 0, okOrient1 = 0, okOrient2 = 0;

	printf("Saisir orientation : ");
	gets(saisie);

	while((saisie[i] != '\0') || (i < tailleSaisie) )
	{
		if(((saisie[i] == 'q') ||  (saisie[i] == 'Q')) && ((okOrient1 == 0) && (okOrient2 == 0)))
		{
			return -1;
		}
		if(((saisie[i] == 'H') || (saisie[i] == 'h')) && (okOrient1 == 0))
		{
			okOrient1 = 1;
		}
		else if(((saisie[i] == 'V') || (saisie[i] == 'v')) && (okOrient1 == 0))
		{
			okOrient1 = -1;
		}
		else if((saisie[i] == '+') && (okOrient2 == 0))
		{
			okOrient2 = 1;
		}
		else if((saisie[i] == '-')  && (okOrient2 == 0))
		{
			okOrient2 = -1;
		}
		i++;
	}

	switch(okOrient1)
	{
	case 1 : if(okOrient2 == 1)
			{
				orient[0] = 'H';
				orient[1] = '+';
			}
			else if(okOrient2 == -1)
			{
				orient[0] = 'H';
				orient[1] = '-';
			}
	break;
	case -1 : if(okOrient2 == 1)
			{
				orient[0] = 'V';
				orient[1] = '+';
			}
			else if(okOrient2 == -1)
			{
				orient[0] = 'V';
				orient[1] = '-';
			}
	break;
	default : return 0;
	}
	orient[2] = '\0';

	return 1;
}

int verifieCoordonnee(int tailleNavire, char orientationNavire[3], int ligne, int colonne, EtatCase ** plateau)
{
	int ajoutLigne, ajoutColonne;
	//
	if ( strcmp(orientationNavire, "V+") == 0 )
	{
		ajoutLigne = -1;
		ajoutColonne = 0;
	}
	else if ( strcmp(orientationNavire, "V-") == 0 )
	{
		ajoutLigne = 1;
		ajoutColonne = 0;
	}
	else if ( strcmp(orientationNavire, "H+") == 0 )
	{
		ajoutLigne = 0;
		ajoutColonne = 1;
	}
	else if ( strcmp(orientationNavire, "H-") == 0 )
	{
		ajoutLigne = 0;
		ajoutColonne = -1;
	}
	//
	int testLigne = ligne + (ajoutLigne * (tailleNavire -1));
	int testColonne = colonne + (ajoutColonne * (tailleNavire -1));

	if( (strcmp((plateau[ligne][colonne]).cel, "celVide") == 0) && (testLigne >= 0) && (testLigne <= (TAILLEPLATEAU - 1))
			&& (testColonne >= 0) && (testColonne <= (TAILLEPLATEAU - 1)) )
	{
		int i;

		for(i = 1; i < tailleNavire; i++)
		{
			ligne += ajoutLigne;
			colonne += ajoutColonne;

			if( strcmp((plateau[ligne][colonne]).cel, "celVide") != 0 )
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

void placerNavire(int tailleNavire, char orientationNavire[3], int ligne, int colonne, EtatCase ** plateau)
{
    int ajoutLigne, ajoutColonne, i;
	//
	if ( strcmp(orientationNavire, "V+") == 0 )
	{
		ajoutLigne = -1;
		ajoutColonne = 0;
	}
	else if ( strcmp(orientationNavire, "V-") == 0 )
	{
		ajoutLigne = 1;
		ajoutColonne = 0;
	}
	else if ( strcmp(orientationNavire, "H+") == 0 )
	{
		ajoutLigne = 0;
		ajoutColonne = 1;
	}
	else if ( strcmp(orientationNavire, "H-") == 0 )
	{
		ajoutLigne = 0;
		ajoutColonne = -1;
	}

	//
	for(i = 0; i<tailleNavire; i++)
    {
        strcpy(plateau[ligne][colonne].cel,"bateau");
		strcpy(plateau[ligne][colonne].etat, "n");
		ligne += ajoutLigne;
        colonne += ajoutColonne;
    }
}

void positionAleatoire(int *ligne, int *colonne)
{
	// Génére 2 nombre pseudo-aléatoire entre [0,TAILLEPLATEAU[
	*ligne = (int)( rand() / (double) RAND_MAX * (TAILLEPLATEAU - 1));
	*colonne = (int)( rand() / (double) RAND_MAX * (TAILLEPLATEAU - 1));
}


void orientationAleatoire(char orientation[3])
{
	if ( rand() <= RAND_MAX/4 )
	{
		strcpy(orientation, "H+");
	}
	else if ( (rand() > RAND_MAX/4) && (rand() <= RAND_MAX/2) )
	{
		strcpy(orientation, "V+");
	}
	else if ( (rand() > RAND_MAX/2) && (rand() <= 3*(RAND_MAX/4)) )
	{
		strcpy(orientation, "H-");
	}
	else
	{
		strcpy(orientation, "V-");
	}
	orientation[2] = '\0';
}

void placementNavireOrdinateur(EtatCase ** plateauOrdi, Navire *listeNavire)
{
	int ligne , colonne, i;
	char orientation[3];

	for (i = 4; i >= 0; i--)
	{
		do
		{
			positionAleatoire(&ligne, &colonne);
			orientationAleatoire(orientation);
		}while(verifieCoordonnee(listeNavire[i].taille, orientation, ligne, colonne, plateauOrdi) == 0);

		placerNavire(listeNavire[i].taille, orientation, ligne, colonne, plateauOrdi);
	}
}










