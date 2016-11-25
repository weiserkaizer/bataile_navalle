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

ListeAffichage *AffichageAction(char etatNavire[], int ligne, int colonne, char typeNavire[], ListeAffichage * tete)
{
	ListeAffichage *nouveau = malloc(sizeof(ListeAffichage));
	if(tete == NULL)
	{
		tete = malloc(sizeof(ListeAffichage));

	}

	return "";
}


Navire * initTypeNavire()
{
    Navire * typeNavire= malloc(sizeof(Navire)*5);

    strcpy((typeNavire[0]).nom, "Torpilleur"); strcpy((typeNavire[0]).acronyme, "TO"); (typeNavire[0]).taille = 2;
    strcpy((typeNavire[1]).nom, "Sous-Marin"); strcpy((typeNavire[1]).acronyme, "SM"); (typeNavire[1]).taille = 3;
    strcpy((typeNavire[2]).nom, "Contre-Torpilleur"); strcpy((typeNavire[2]).acronyme, "CT"); (typeNavire[2]).taille = 3;
    strcpy((typeNavire[3]).nom, "Croiseur");strcpy((typeNavire[3]).acronyme, "CR"); (typeNavire[3]).taille = 4;
    strcpy((typeNavire[4]).nom, "Porte-Avion"); strcpy((typeNavire[4]).acronyme, "PA"); (typeNavire[4]).taille = 5;
    strcpy(navireOrdinateur[5].acronyme, "ba");

    int i;
    for(i = 0; i<5; i++)
    {
    	(typeNavire[i].acronyme)[2] = '\0';

    	strcpy(navireJoueur[i].acronyme,typeNavire[i].acronyme);
    	navireJoueur[i].survivabilite = typeNavire[i].taille;

    	strcpy(navireOrdinateur[i].acronyme,typeNavire[i].acronyme);
    	navireOrdinateur[i].survivabilite = typeNavire[i].taille;
    }

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

void placerNavire(Navire *listeNavire, int numNavire, char orientationNavire[3], int ligne, int colonne, EtatCase ** plateau, char player)
{
    int ajoutLigne, ajoutColonne, i;
    EtatNavire *etatNavirePlayer;

	if(player == 'J')
	{
		etatNavirePlayer = navireJoueur;
	}
	else if(player == 'O')
	{
		etatNavirePlayer = navireOrdinateur;
	}
	//
    char orien[2];
	if ( strcmp(orientationNavire, "V+") == 0 )
	{
		ajoutLigne = -1;
		ajoutColonne = 0;
		strcpy(orien,"u");
		orien[1]='\0';
	}
	else if ( strcmp(orientationNavire, "V-") == 0 )
	{
		ajoutLigne = 1;
		ajoutColonne = 0;
		strcpy(orien,"d");
		orien[1]='\0';
	}
	else if ( strcmp(orientationNavire, "H+") == 0 )
	{
		ajoutLigne = 0;
		ajoutColonne = 1;
		strcpy(orien,"r");
		orien[1]='\0';
	}
	else if ( strcmp(orientationNavire, "H-") == 0 )
	{
		ajoutLigne = 0;
		ajoutColonne = -1;
		strcpy(orien,"l");
		orien[1]='\0';
	}

	//
	etatNavirePlayer[numNavire].ligneExtrem1 = ligne;
	etatNavirePlayer[numNavire].colonneExtrem1 = colonne;

	for(i = listeNavire[numNavire].taille; i > 0; i--)
    {
		char position[3];
		itoa (i,position,10);								//convertie i en ASCII en base 10
        strcpy(plateau[ligne][colonne].cel,listeNavire[numNavire].acronyme);
		strcpy(plateau[ligne][colonne].position, position);
		strcpy(plateau[ligne][colonne].etat, "n");
		strcpy(plateau[ligne][colonne].orientation, orien);
		ligne += ajoutLigne;
        colonne += ajoutColonne;
    }

	etatNavirePlayer[numNavire].ligneExtrem2 = (ligne - ajoutLigne);
	etatNavirePlayer[numNavire].colonneExtrem2 = (colonne - ajoutColonne);
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

		placerNavire(listeNavire, i, orientation, ligne, colonne, plateauOrdi, 'O');
	}
}

int verificationTire(EtatCase **plateau, int ligne, int colonne)
{
	//Si bateau est déjà touché à cette position on retourne 2; si on le touche on retourne 1; si c'est de l'eau on retourne 0

	if ( strcmp(plateau[ligne][colonne].cel, "celVide") == 0 )
	{
		return 0;
	}
	else if ( strcmp(plateau[ligne][colonne].etat, "n") == 0)
	{
		return 1;
	}
	else if ( (strcmp(plateau[ligne][colonne].etat, "t") == 0) || (strcmp(plateau[ligne][colonne].etat, "c") == 0) )
	{
		return 2;
	}

	return -1;
}

void coulerNavire(EtatCase **plateauAAfficher, EtatCase **plateau, int ligneExtrem1, int ligneExtrem2, int colonneExtrem1, int colonneExtrem2)
{
	int ecartLigne = ligneExtrem2 - ligneExtrem1;
	int ecartColonne = colonneExtrem2 - colonneExtrem1;

	if(ecartLigne == 0)
	{
		if(ecartColonne < 0)
		{
			while(colonneExtrem1 >= colonneExtrem2)
			{
				strcpy(plateauAAfficher[ligneExtrem1][colonneExtrem1].etat,"c");
				strcpy(plateauAAfficher[ligneExtrem1][colonneExtrem1].cel,plateau[ligneExtrem1][colonneExtrem1].cel);
				strcpy(plateauAAfficher[ligneExtrem1][colonneExtrem1].position,plateau[ligneExtrem1][colonneExtrem1].position);
				colonneExtrem1--;
			}
		}
		else
		{
			while(colonneExtrem2 >= colonneExtrem1)
			{
				strcpy(plateauAAfficher[ligneExtrem1][colonneExtrem2].etat,"c");
				strcpy(plateauAAfficher[ligneExtrem1][colonneExtrem2].cel,plateau[ligneExtrem1][colonneExtrem2].cel);
				strcpy(plateauAAfficher[ligneExtrem1][colonneExtrem2].position,plateau[ligneExtrem1][colonneExtrem2].position);
				colonneExtrem2--;
			}
		}
	}
	else
	{
		if(ecartLigne < 0)
		{
			while(ligneExtrem1 >= ligneExtrem2)
			{
				strcpy(plateauAAfficher[ligneExtrem1][colonneExtrem1].etat,"c");
				strcpy(plateauAAfficher[ligneExtrem1][colonneExtrem1].cel,plateau[ligneExtrem1][colonneExtrem1].cel);
				strcpy(plateauAAfficher[ligneExtrem1][colonneExtrem1].position,plateau[ligneExtrem1][colonneExtrem1].position);
				ligneExtrem1--;
			}
		}
		else
		{
			while(ligneExtrem2 >= ligneExtrem1)
			{
				strcpy(plateauAAfficher[ligneExtrem2][colonneExtrem1].etat,"c");
				strcpy(plateauAAfficher[ligneExtrem2][colonneExtrem1].cel,plateau[ligneExtrem2][colonneExtrem1].cel);
				strcpy(plateauAAfficher[ligneExtrem2][colonneExtrem1].position,plateau[ligneExtrem2][colonneExtrem1].position);
				ligneExtrem2--;
			}
		}
	}

}

int toucherNavire(EtatCase ** plateauAAfficher, EtatCase **plateau, char player, int ligne, int colonne)
{
	int i = 0;
	char *navire = plateauAAfficher[ligne][colonne].cel;
	EtatNavire *etatNavirePlayer;

	if(player == 'J')
	{
		etatNavirePlayer = navireJoueur;
	}
	else if(player == 'O')
	{
		etatNavirePlayer = navireOrdinateur;
	}

	while(strcmp(navire, etatNavirePlayer[i].acronyme) != 0)
	{
		i++;
	}

	if(etatNavirePlayer[i].survivabilite == 1)
	{
		coulerNavire(plateauAAfficher, plateau,etatNavirePlayer[i].ligneExtrem1, etatNavirePlayer[i].ligneExtrem2, etatNavirePlayer[i].colonneExtrem1, etatNavirePlayer[i].colonneExtrem2);

		etatNavirePlayer[i].survivabilite -= 1;
	}
	else
	{
		strcpy(plateauAAfficher[ligne][colonne].etat,"t");

		etatNavirePlayer[i].survivabilite -= 1;
	}

	return i;
}

void tirer(EtatCase ** plateau, EtatCase **plateauAffichage, char player,int ligne,int colonne)
{
	int verifieTire, numeroNavire;

	verifieTire = verificationTire(plateau, ligne, colonne);

	if(player == 'J')
	{
		switch(verifieTire)
		{
		case 0: strcpy(plateau[ligne][colonne].etat, "t");
				break;
		case 1:	numeroNavire = toucherNavire(plateau, plateau,player, ligne, colonne);
		//case 2: tirer(plateau, player);
			break;
			//case -1: tirer(plateau, player);
			//		break;
		default :break;
		}
	}
	else
	{
		switch(verifieTire)
				{
				case 0: strcpy(plateau[ligne][colonne].etat, "t");
						strcpy(plateauAffichage[ligne][colonne].etat, "t");
						break;
				case 1:	numeroNavire = toucherNavire(plateau, plateau,player, ligne, colonne);

						strcpy(plateauAffichage[ligne][colonne].cel, "ba");
						strcpy(plateauAffichage[ligne][colonne].orientation, plateau[ligne][colonne].orientation);

						navireOrdinateur[5].survivabilite = navireOrdinateur[numeroNavire].survivabilite + 1;

						navireOrdinateur[5].ligneExtrem1 = navireOrdinateur[numeroNavire].ligneExtrem1;
						navireOrdinateur[5].ligneExtrem2 = navireOrdinateur[numeroNavire].ligneExtrem2;
						navireOrdinateur[5].colonneExtrem1 = navireOrdinateur[numeroNavire].colonneExtrem1;
						navireOrdinateur[5].colonneExtrem2 = navireOrdinateur[numeroNavire].colonneExtrem2;

						toucherNavire(plateauAffichage, plateau, player, ligne, colonne);
				//case 2: tirer(plateau, player);
					break;
					//case -1: tirer(plateau, player);
					//		break;
				default :break;
				}

	}

}

void tireAutomatique(EtatCase ** plateau)
{
	int ligne, colonne;

	positionAleatoire(&ligne, &colonne);

	tirer(plateau, plateau, 'J', colonne, ligne);
}



void runIntro()
{
    int choix = 0;
    while(choix<1 || choix>3)
    {

        printf("\tBienvenue joueur\n\n");
        printf("\tQu'est ce que sa sera Aujourd'hui?\n\n");
        printf("\tEntre 1 pour commencer une nouvelle partie\n\n");
        printf("\tEntre 2 pour charger une partie\n\n");
        printf("\tEntre 3 pour revisionner une partie\n\n");
        scanf("%d",&choix);
    }
    switch(choix)
    {
        case 1 : printf("jouons"); jeu(); break;
        case 2 : printf("chargeons"); reprise(); break;
        case 3 : printf("visionnons"); replay(); break;
        default : printf("erreur"); break;
    }

}

void jeu()
{

}

void reprise()
{

}

void replay()
{

}



















