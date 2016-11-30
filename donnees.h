/*
 * donnees.h
 *
 *  Created on: 22 oct. 2016
 *      Author: Nicolas
 */

#ifndef DONNEES_H_
#define DONNEES_H_


#define TAILLEPLATEAU 10	//Dimension du plateau de jeu (un carré)

//TO : Torpilleur, SM: Sous-Marin, CT : Contre-Torpilleur, CR : Croiseur, PA : Porte-Avion

typedef struct EtatCase EtatCase;
struct EtatCase
{
    char cel[20];
    char position[20];
    char etat[20];
    char orientation[20];
};

typedef struct cellule cellule;
struct cellule
{
    char ligne1[20],ligne2[20],ligne3[20],ligne4[20],ligne5[20];
};

typedef struct GrilleCellule GrilleCellule;

struct GrilleCellule
{
    EtatCase grilleCellule[11][23];
};

typedef struct Navire Navire;
struct Navire
{
	char nom[20];
	char acronyme[3];
	int taille;
};

typedef struct EtatNavire EtatNavire;
struct EtatNavire
{
	char acronyme[3];
	int survivabilite;
	int ligneExtrem1, ligneExtrem2;
	int colonneExtrem1, colonneExtrem2;

};

EtatNavire navireJoueur[5], navireOrdinateur[6];


typedef struct ListeAffichage ListeAffichage;
struct ListeAffichage
{
    char *phrase;
    ListeAffichage *suivant;

};


#endif /* DONNEES_H_ */
