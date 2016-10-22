/*
 * donnees.h
 *
 *  Created on: 22 oct. 2016
 *      Author: Nicolas
 */

#ifndef DONNEES_H_
#define DONNEES_H_

#define TAILLEPLATEAU 10			//Dimension du plateau de jeu (un carré)

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
    char ligne1[20],ligne2[20],ligne3[20];
};

typedef struct GrilleCellule GrilleCellule;

struct GrilleCellule
{
    EtatCase grilleCellule[11][23];
};




#endif /* DONNEES_H_ */
